/*
unit ::= expr ;

expr ::= term ('+' term)+
       | term ('-' term)+
       | term
       ;

term ::= factor ('*' factor)+
       | factor ('/' factor)+
       | factor
       ;

factor ::= '(' expr ')'
         | num
         ;

num ::= son '%' mon
      | son
      ;

son ::= digit+ ;
mon ::= digit+ ;

digit ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 ;
*/


#include <iostream>
#include <string>
#include <deque>

//递归求最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


class Num {
private:
    int son;
    int mon;

public:
    Num() : Num(0, 1) {}

    //Simplify func
    void simplify() {
        int g = gcd(son, mon); //gcd
        son /= g;
        mon /= g;
    }

    //Cons
    Num(int son, int mon) : son(son), mon(mon) {
        simplify();             //ensure every num is simplified
    }

    // + - * /
    Num operator+(const Num &rhs) const {
        return Num(
                this->son * rhs.mon + this->mon * rhs.son,
                this->mon * rhs.mon
        );
    }

    Num operator-(const Num &rhs) const {
        return Num(
                this->son * rhs.mon - this->mon * rhs.son,
                this->mon * rhs.mon
        );
    }

    Num operator*(const Num &rhs) const {
        return Num(
                this->son * rhs.son,
                this->mon * rhs.mon
        );
    }

    Num operator/(const Num &rhs) const {
        if (rhs.son == 0) {
            throw std::runtime_error("Divide by zero");
        }
        return this->operator*(Num(rhs.mon, rhs.son));
    }

    //Getter
    int getSon() const {
        return son;
    }

    int getMon() const {
        return mon;
    }
};

std::ostream &operator<<(std::ostream &out, const Num &num) {
    if (num.getMon() != 1)
        out << num.getSon() << " % " << num.getMon();
    else
        out << num.getSon();
    return out;
}

// Lexer : String -> List<Token>  (Deque<Token>)

//identity
enum struct TokenType {
    ADD, SUB, MUL, DIV,
    LEFT_B, RIGHT_B,
    NUM,
};

struct Token {
    TokenType type;  //for symbol
    Num num;         //for num
    Token(TokenType type) : type(type) {}

    Token(Num num) : type(TokenType::NUM), num(num) {}
};

void skip_ws(const char *&p) {
    while (*p && (*p == ' ' || *p == '\t')) { //\n is unnecessary for this project
        p++;
    }
}

std::deque<Token> lex(const std::string &src) {
    std::deque<Token> result;
    const char *p = src.c_str();
    while (*p) {
        skip_ws(p);

        if (*p == '+') {
            result.emplace_back(TokenType::ADD);
            ++p;
            continue;
        }

        if (*p == '-') {
            result.emplace_back(TokenType::SUB);
            ++p;
            continue;
        }

        if (*p == '*') {
            result.emplace_back(TokenType::MUL);
            ++p;
            continue;
        }

        if (*p == '/') {
            result.emplace_back(TokenType::DIV);
            ++p;
            continue;
        }

        if (*p == '(') {
            result.emplace_back(TokenType::LEFT_B);
            ++p;
            continue;
        }

        if (*p == ')') {
            result.emplace_back(TokenType::RIGHT_B);
            ++p;
            continue;
        }

        // num
        if (*p >= '0' && *p <= '9') {
            int son = 0;
            int mon = 0;
            while (*p && *p >= '0' && *p <= '9') {
                son = son * 10 + (*p - '0');
                ++p;
            }

            skip_ws(p);

//            if (*p != '%') {
//                //
//                throw std::runtime_error(std::string(
//                        "Syntax Error: expected '%', but got '") + *p + "'");
//            }

//          Integer permitted 
            if (*p == '%') {
                // consume '%'
                ++p;

                skip_ws(p);

                if (*p && isdigit(*p)) {
                    while (*p && *p >= '0' && *p <= '9') {
                        mon = mon * 10 + (*p - '0');
                        ++p;
                    }
                } else {
                    throw std::runtime_error(std::string("expected digit after '%'"));
                }
            } else {
                mon = 1;
            }


            result.emplace_back(Num(son, mon));
            continue;
        }

        throw std::runtime_error(std::string(
                "unexpected'") + *p + "', expected operators or digits");
    }

    return result;
}

// Parser : List<Token> -> Unit
struct Term;

struct Node {
    virtual Num eval() = 0;

    virtual ~Node() = default;
};

struct Expr : public Node {
    Node *lhs{};
    Node *rhs{};
    TokenType op;

    Num eval() override;

    ~Expr();
};

struct Factor : public Node {
    Node *expr{};
    Num num;

    Num eval() override {
        return expr == nullptr ? num : expr->eval();
    }

    ~Factor() {
        delete expr;
    }
};

struct Term : public Node {
    Node *lhs{};
    Node *rhs{};
    TokenType op;

    Num eval() override {
        Num l = lhs->eval();
        if (rhs) {
            Num r = rhs->eval();
            switch (op) {
                case TokenType::MUL:
                    return l * r;
                case TokenType::DIV:
                    return l / r;
            }
        }
        return l;
    }

    ~Term() {
        delete lhs;
        delete rhs;
    }
};

struct Unit : public Node {
    Node *expr{};

    Num eval() override {
        return expr->eval();
    }

    ~Unit() {
        delete expr;
    }
};

Num Expr::eval() {
    Num l = lhs->eval();
    if (rhs) {
        Num r = rhs->eval();
        switch (op) {
            case TokenType::ADD:
                return l + r;
            case TokenType::SUB:
                return l - r;
        }
    }
    return l;
}

Expr::~Expr() {
    delete lhs;
    delete rhs;
}


struct Parser {
    std::deque<Token> tokens;

    void ensure() {
        if (isEnd()) {
            throw std::runtime_error("Unexpected End");
        }
    }

    TokenType consumeOp() {
        ensure();
        switch (tokens.front().type) {
            case TokenType::ADD:
            case TokenType::SUB:
            case TokenType::MUL:
            case TokenType::DIV: {
                TokenType type = tokens.front().type;
                tokens.pop_front();
                return type;
            }
            default: {
                throw std::runtime_error("expected operator");
            }
        }
    }

    void consume() {
        ensure();
        tokens.pop_front();
    }

    void consume_type(TokenType type) {
        if (peek() != type) {
            throw std::runtime_error(std::string("unexpected token"));
        }
        consume();
    }

    Num consume_num() {
        if (peek() != TokenType::NUM) {
            throw std::runtime_error(std::string("expected num"));
        }
        Num num = tokens.front().num;
        consume();
        return num;
    }

    bool isEnd() {
        return tokens.empty();
    }

    TokenType peek() {
        ensure();
        return tokens.front().type;
    }

    explicit Parser(std::deque<Token> tokens) : tokens(std::move(tokens)) {}

    Factor *parseFactor() {
        Factor *factor = new Factor;
        // lookahead
        switch (peek()) {
            case TokenType::LEFT_B: {
                consume();
                factor->expr = parseExpr();
                consume_type(TokenType::RIGHT_B);
                break;
            }
            case TokenType::NUM: {
                factor->num = consume_num();
                break;
            }
            default: {
                throw std::runtime_error(std::string("expected '(' or num"));
            }
        }
        return factor;
    }

    Term *parseTerm() {
        Term *term = new Term;
        term->lhs = parseFactor();
        // lookahead
        bool break_while = false;
        while (!isEnd()) {
            switch (peek()) {
                case TokenType::MUL:
                case TokenType::DIV: {
                    term->op = consumeOp();
                    term->rhs = parseFactor();
                    Term *next = new Term();
                    next->lhs = term;
                    term = next;
                    break;
                }
                default: {
                    break_while = true;
                    break;
                }
            }
            if (break_while)
                break;
        }
        return term;
    }

    Expr *parseExpr() {
        Expr *expr = new Expr;
        expr->lhs = parseTerm();
        // lookahead
        bool break_while = false;
        while (!isEnd()) {
            switch (peek()) {
                case TokenType::ADD:
                case TokenType::SUB: {
                    expr->op = consumeOp();
                    expr->rhs = parseTerm();
                    Expr *next = new Expr();
                    next->lhs = expr;
                    expr = next;
                    break;
                }
                default: {
                    break_while = true;
                    break;
                }
            }
            if (break_while)
                break;
        }
        return expr;
    }

    Unit *parseUnit() {
        Unit *unit = new Unit;
        unit->expr = parseExpr();
        return unit;
    }
};

void Run(const std::string &line) {
    try {
        Parser parser(lex(line));
        Unit *unit = parser.parseUnit();
        std::cout << unit->eval() << std::endl;
        delete unit;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    std::string line;

    while (true) {
        std::cout << "> ";
        std::cout.flush();
        if (!std::getline(std::cin, line)) {
            break;
        }
        if (line == ":q")
            break;
        Run(line);
    }

    return 0;
}
