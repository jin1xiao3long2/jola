/*
unit ::= expr ;

expr ::= term '+' term
       | term '-' term
       | term
       ;

term ::= factor '*' factor
       | factor '/' factor
       | factor
       ;

factor ::= '(' expr ')'
         | num
         | id
         ;

id ::= alpha ( alpha | digit )*

num ::= son '%' mon
      | son
      | '(' sign son ')'
      | '(' sign son '%' mon ')'
      ;

son ::= digit+ ;
mon ::= digit+ ;

sign ::= '-';
digit ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 ;
alpha ::= [a-zA-Z] ;
*/

#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <unordered_map>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


class Num {
private:
    int son;
    int mon;

public:
    Num() : Num(0, 1) {}

    void simplify() {
        int g = gcd(son, mon);
        son /= g;
        mon /= g;
    }

    Num(int son, int mon) : son(son), mon(mon) {
        simplify();
    }

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

// Lexer : String -> List<Token>

enum struct TokenType {
    ADD, SUB, MUL, DIV,
    LEFT_B, RIGHT_B,
    NUM, ID,
};

struct Token {
    TokenType type;
    Num num;
    std::string id;

    Token(std::string id) : type(TokenType::ID), id(std::move(id)) {}

    Token(TokenType type) : type(type) {}

    Token(Num num) : type(TokenType::NUM), num(num) {}
};

using CharP = const char *;

void skip_ws(CharP &p) {
    while (*p && (*p == ' ' || *p == '\t' || *p == '\n')) { //\n is unnecessary for this project
        p++;
    }
}

std::deque<Token> lex(const std::string &src) {
    std::deque<Token> result;
    const char *p = src.c_str();
    bool catch_num = false;
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
            catch_num = true;
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
            bool sign = true;  // true -> '+', false -> '-'


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
                    throw std::runtime_error(std::string("expected digit"));
                }
            } else {
                mon = 1;
            }


            result.emplace_back(Num(son, mon));
            continue;
        }

        if (std::isalpha(*p)) {
            std::string id;
            while (*p && (std::isalpha(*p) || std::isdigit(*p))) {
                id.push_back(*p);
                p++;
            }
            result.emplace_back(id);
            continue;
        }
        throw std::runtime_error(std::string(
                "Syntax Error: unexpected'") + *p + "', expected operators or digits");
    }

    return result;
}

class Interpreter {
    std::unordered_map<std::string, Num> table;
};

// Parser : List<Token> -> Unit
struct Term;

struct Node {
    virtual Num eval() = 0;
};

struct Expr : public Node {
    Term *lhs{};
    Term *rhs{};
    TokenType op;

    Num eval() override;

    ~Expr();
};

struct Factor : public Node {
    Expr *expr{};
    Num num;
    std::string id;

    Num eval() override {
        return expr == nullptr ? num : expr->eval();
    }

    ~Factor() {
        delete expr;
    }
};

struct Term : public Node {
    Factor *lhs{};
    Factor *rhs{};
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
    Expr *expr{};

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
        if (isEOF()) {
            throw std::runtime_error("Syntax Error: Unexpected EOF");
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
                throw std::runtime_error("Syntax Error: expected operator");
            }
        }
    }

    void consume() {
        ensure();
        tokens.pop_front();
    }

    void consume_type(TokenType type) {
        if (peek() != type) {
            throw std::runtime_error(std::string("Syntax Error: unexpected token"));
        }
        consume();
    }

    Num consume_num() {
        if (peek() != TokenType::NUM) {
            throw std::runtime_error(std::string("Syntax Error: expected num"));
        }
        Num num = tokens.front().num;
        consume();
        return num;
    }

    std::string consume_id() {
        if (peek() != TokenType::ID) {
            throw std::runtime_error(std::string("Syntax Error: expected id"));
        }
        auto id = tokens.front().id;
        consume();
        return id;
    }

    bool isEOF() {
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
            case TokenType::ID: {
                factor->id = consume_id();
                break;
            }
            default: {
                throw std::runtime_error(std::string("Syntax Error: expected '(' or num"));
            }
        }
        return factor;
    }

    Term *parseTerm() {
        Term *term = new Term;
        term->lhs = parseFactor();
        // lookahead
        if (!isEOF()) {
            switch (peek()) {
                case TokenType::MUL:
                case TokenType::DIV: {
                    term->op = consumeOp();
                    term->rhs = parseFactor();
                    break;
                }
            }
        }
        return term;
    }

    Expr *parseExpr() {
        Expr *expr = new Expr;
        expr->lhs = parseTerm();
        // lookahead
        if (!isEOF()) {
            switch (peek()) {
                case TokenType::ADD:
                case TokenType::SUB: {
                    expr->op = consumeOp();
                    expr->rhs = parseTerm();
                    break;
                }
            }
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
