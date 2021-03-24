#include <iostream>
#include <deque>
#include <unordered_set>
#include <vector>
#include <fstream>
/*


 lexer

 word ::= letter(letter|digit)*
 Num ::= digit digit*


 digit ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9;
 letter ::= a-zA-Z_
 sign ::= '+' | '-' | '*' | '/' | '(' | ')' | '<' | '>' | '&' | '^' | '~' |;
 relop ::= '=' | "==
 */

//无法识别a<<b 与 <<b>c>, 但C应该不用考虑

/*
    KEYWORD_AUTO, KEYWORD_BREAK, KEYWORD_CASE, KEYWORD_CHAR, KEYWORD_CONST, KEYWORD_CONTINUE,
    KEYWORD_DEFAULT, KEYWORD_DO, KEYWORD_DOUBLE, KEYWORD_ELSE, KEYWORD_ENUM, KEYWORD_EXTERN,
    KEYWORD_FLOAT, KEYWORD_FOR, KEYWORD_GOTO, KEYWORD_IF, KEYWORD_INT, KEYWORD_LONG, KEYWORD_REGISTER,
    KEYWORD_RETURN, KEYWORD_SHORT, KEYWORD_SIGNED, KEYWORD_SIZEOF, KEYWORD_STATIC, KEYWORD_STRUCT,
    KEYWORD_SWITCH, KEYWORD_TYPEDEF, KEYWORD_UNION, KEYWORD_UNSIGNED, KEYWORD_VOID, KEYWORD_VOLATILE,
    KEYWORD_WHILE, KEYWORD_INLINE, KEYWORD_RESTRICT,
 */
enum struct TokenType {
    ADD, SUB, MUL, DIV, MOD, ADD_D, SUB_D, // +, -, *, /, %, ++, -- 0-6
    GT, LT, EQ, GE, LE, NE, // >, <, ==, >=, <=, !=         7-12
    AND, OR, NOT,          // &&, ||, !        13-15
    AND_B, OR_B, NOT_B, XOR_B, LEFT_MOVE, RIGHT_MOVE, //&, |, ~, ^, <<, >>  16-21
    ASSIGN, ASSIGN_ADD, ASSIGN_SUB, ASSIGN_MUL, ASSIGN_DIV, ASSIGN_MOD, //=, +=, -=, *=, /=, %=  22-27
    ASSIGN_AND_B, ASSIGN_OR_B, ASSIGN_XOR_B, ASSIGN_LEFT_MOVE, ASSIGN_RIGHT_MOVE, //&=, |=, ^=, <<=, >>= 28-32
    COMMA, SEMICOLON, //,, ; 33-34
    LEFT_P, RIGHT_P, LEFT_B, RIGHT_B, LEFT_BR, RIGHT_BR, //(, ), [, ], {, } 35-40
    ARROW, POINT, //->, .   41-42
    COND_FRONT, COND_BACK,//?, : 43-44
    QUOTATION_S, QUOTATION_D, //',"  45-46
    INTEGER, DOUBLE, //47-48
    KEY_WORD, //49
    IDENTIFIER,  //50
    COMMENT, //51
    STRING, //52
};

template<typename T>
std::ostream &operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type &stream, const T &e) {
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

struct Token {
    TokenType type;
    std::string value;
    int line;

    Token(TokenType type, int line) : type(type), line(line) {}

    Token(TokenType type, std::string value, int line) : type(type), value(value), line(line) {}
};




std::ostream &operator<<(std::ostream &out, const Token &token) {
    out << "<" << token.line << ",\t" << token.type;
    if (token.type == TokenType::STRING || token.type == TokenType::INTEGER || token.type == TokenType::DOUBLE ||
        token.type == TokenType::IDENTIFIER || token.type == TokenType::KEY_WORD) {
        out << ",\t" << token.value;
    }
    out << ">";
    return out;
}


struct Error {
    int line;
    std::string errorInfo;

    Error(int line, const std::string info) : line(line), errorInfo(info) {}
};

std::ostream &operator<<(std::ostream &out, const Error &error) {
    out << "<" << error.line << ",\t" << error.errorInfo << ">";
    return out;
}

struct Identifier {
    std::string name;
    int line;
    int addr;

    Identifier(int line, int addr, std::string name) : line(line), addr(addr), name(name) {}

};

std::ostream &operator<<(std::ostream& out, const Identifier& identifier){
    out << "<" << identifier.line << ",\t" <<   identifier.name << ",\t" << identifier.addr << ">";
    return out;
}

class Lexer {

private:
    std::deque<Token> tokens;
    std::deque<Error> errors;
    std::deque<Identifier> identifiers;
    int addr = 0;
    int line = 1;

    void skip_ws(const char *&p) {
        while (*p && *p == ' ' || *p == '\t' || *p == '\n') {
            if (*p == '\n')
                line++;
            p++;
        }
    }

public:
//针对: 已预处理过的文件,无包括头文件#include<iostream>,
//无法分析a<<b和<<b>c>
//数字有一定限度
//能否处理浮点数?
    void lex(const std::string &src) {
        std::unordered_set<std::string> keyWords = {"auto", "break", "case", "char", "const", "continue",
                                                    "default", "do", "double", "else", "enum", "extern",
                                                    "float", "for", "goto", "if", "int", "long", "register",
                                                    "return", "short", "signed", "sizeof", "static", "struct",
                                                    "switch", "typedef", "union", "unsigned", "void", "volatile",
                                                    "while", "inline", "restrict"};
        const char *p = src.c_str();

        while (*p) {
            skip_ws(p);
            int i = 0;
            if (*p == '+') {
                ++p;
                if (*p == '+') {
                    tokens.emplace_back(TokenType::ADD_D, line);
                    ++p;
                    continue;
                } else if (*p == '=') {
                    tokens.emplace_back(TokenType::ASSIGN_ADD, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::ADD, line);
                continue;
            }

            if (*p == '-') {
                ++p;
                if (*p == '-') {
                    tokens.emplace_back(TokenType::SUB_D, line);
                    ++p;
                    continue;
                } else if (*p == '=') {
                    tokens.emplace_back(TokenType::ASSIGN_SUB, line);
                    ++p;
                    continue;
                } else if (*p == '>') {
                    tokens.emplace_back(TokenType::ARROW, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::ADD, line);
                continue;
            }

            if (*p == '*') {
                ++p;
                if (*p == '=') {
                    tokens.emplace_back(TokenType::ASSIGN_MUL, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::MUL, line);
                continue;
            }

            if (*p == '/') {
                ++p;
                if (*p == '=') {
                    tokens.emplace_back(TokenType::ASSIGN_DIV, line);
                    ++p;
                    continue;
                } else if (*p == '*') {//注释,不加入token
                    ++p;
                    while (true) {
                        while (*p && *p != '*') {
                            if(*p == '\n')
                                line++;
                            ++p;
                        }
                        if (!*p) {
                            errors.emplace_back(line, "unterminated comment");
                            break;
                        }
                        ++p;
                        if (!*p) {
                            errors.emplace_back(line, "unterminated comment");
                            break;
                        }
                        if (*p != '/')
                            continue;
                        else
                            break;
                    }
                    ++p;
                    continue;
                } else if (*p == '/') {// 注释,不加入token
                    while (true) {
                        ++p;
                        if (*p == '\n' || !*p)
                        {
                            if(*p == '\n')
                                line++;
                            break;
                        }
                    }
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::DIV, line);
                continue;
            }

            if (*p == '%') {
                ++p;
                if (*p == '=') {
                    tokens.emplace_back(TokenType::ASSIGN_MOD, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::MOD, line);
                continue;
            }

            if (*p == '&') {
                ++p;
                if (*p == '&') {
                    tokens.emplace_back(TokenType::AND, line);
                    ++p;
                    continue;
                } else if (*p == '=') {
                    tokens.emplace_back(TokenType::ASSIGN_AND_B, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::AND_B, line);
                continue;
            }

            if (*p == '|') {
                ++p;
                if (*p == '|') {
                    tokens.emplace_back(TokenType::OR, line);
                    ++p;
                    continue;
                } else if (*p == '=') {
                    tokens.emplace_back(TokenType::ASSIGN_OR_B, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::OR_B, line);
                continue;
            }

            if (*p == '!') {
                ++p;
                if (*p == '=') {
                    tokens.emplace_back(TokenType::NE, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::NOT, line);
                continue;
            }

            if (*p == '~') {
                ++p;
                tokens.emplace_back(TokenType::NOT_B, line);
                continue;
            }

            if (*p == '^') {
                ++p;
                if (*p == '=') {
                    tokens.emplace_back(TokenType::ASSIGN_XOR_B, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::XOR_B, line);
                continue;
            }

            if (*p == '>') {
                ++p;
                if (*p == '>') {
                    ++p;
                    if (*p == '=') {
                        tokens.emplace_back(TokenType::ASSIGN_RIGHT_MOVE, line);
                        ++p;
                        continue;
                    }
                    tokens.emplace_back(TokenType::RIGHT_MOVE, line);
                    continue;
                } else if (*p == '=') {
                    tokens.emplace_back(TokenType::GE, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::GT, line);
                continue;
            }

            if (*p == '<') {
                ++p;
                if (*p == '<') {
                    ++p;
                    if (*p == '=') {
                        tokens.emplace_back(TokenType::ASSIGN_LEFT_MOVE, line);
                        ++p;
                        continue;
                    }
                    tokens.emplace_back(TokenType::LEFT_MOVE, line);
                    continue;
                } else if (*p == '=') {
                    tokens.emplace_back(TokenType::LE, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::LT, line);
                continue;
            }

            if (*p == '=') {
                ++p;
                if (*p == '=') {
                    tokens.emplace_back(TokenType::EQ, line);
                    ++p;
                    continue;
                }
                tokens.emplace_back(TokenType::ASSIGN, line);
                continue;
            }

            if (*p == ',') {
                tokens.emplace_back(TokenType::COMMA, line);
                ++p;
                continue;
            }

            if (*p == ';') {
                tokens.emplace_back(TokenType::SEMICOLON, line);
                ++p;
                continue;
            }

            if (*p == '(') {
                tokens.emplace_back(TokenType::LEFT_P, line);
                ++p;
                continue;
            }

            if (*p == ')') {
                tokens.emplace_back(TokenType::RIGHT_P, line);
                ++p;
                continue;
            }

            if (*p == '[') {
                tokens.emplace_back(TokenType::LEFT_B, line);
                ++p;
                continue;
            }

            if (*p == ']') {
                tokens.emplace_back(TokenType::RIGHT_B, line);
                ++p;
                continue;
            }

            if (*p == '{') {
                tokens.emplace_back(TokenType::LEFT_BR, line);
                ++p;
                continue;
            }

            if (*p == '}') {
                tokens.emplace_back(TokenType::RIGHT_BR, line);
                ++p;
                continue;
            }

            if (*p == '.') {
                tokens.emplace_back(TokenType::POINT, line);
                ++p;
                continue;
            }

            if (*p == '?') {
                tokens.emplace_back(TokenType::COND_FRONT, line);
                ++p;
                continue;
            }

            if (*p == ':') {
                tokens.emplace_back(TokenType::COND_BACK, line);
                ++p;
                continue;
            }

            //Num
            if (*p >= '0' && *p <= '9') {
                bool state = false;
                while (*p && *p >= '0' && *p <= '9') {
                    p++;
                    i++;
                }
                if (*p == '.') {
                    p++;
                    i++;
                    if (*p >= '0' && *p <= '9') {
                        while (*p && *p >= '0' && *p <= '9') {
                            p++;
                            i++;
                        }
                    }
                    state = true;
                }

                if (*p && (*p == 'E' || *p == 'e')) {
                    p++;
                    i++;
                    if (*p && (*p == '+' || *p == '-')) {
                        p++;
                        i++;
                    }
                    if (*p && *p >= '0' && *p <= '9') {
                        while (*p && *p >= '0' && *p <= '9') {
                            p++;
                            i++;
                        }
                    } else {
                        errors.emplace_back(line, std::string(
                                "unexpected'") + *p + "', expected digits");
                    }
                    state = true;
                }
                if (state == false)
                    tokens.emplace_back(TokenType::INTEGER, std::string(p - i, p), line);
                else
                    tokens.emplace_back(TokenType::DOUBLE, std::string(p - i, p), line);
                continue;
            } else if (isalpha(*p) || *p == '_') {
                while (*p && (isalpha(*p) || (*p >= '0' && *p <= '9') || *p == '_')) {
                    p++;
                    i++;
                }
                std::string word = std::string(p - i, p);
                if (keyWords.find(word) != keyWords.end())
                    tokens.emplace_back(TokenType::KEY_WORD, word, line);
                else {
                    tokens.emplace_back(TokenType::IDENTIFIER, word, line); //符号表
                    int temp_addr = 0;
                    auto iter = identifiers.begin();
                    for (; iter != identifiers.end(); iter++) {
                        if (iter->name == word) {
                            temp_addr = iter->addr;
                            break;
                        }
                    }
                    if (iter == identifiers.end()) {
                        addr++;
                        temp_addr = addr;
                    }
                    identifiers.emplace_back(line, temp_addr, word);
                }
                continue;
            } else if (*p == '"') {
                p++;
                tokens.emplace_back(TokenType::QUOTATION_D, line);
                while (*p && *p != '"') {
                    p++;
                    i++;
                }
                if (!*p)
                    errors.emplace_back(Error(line, std::string("expected \"")));
                tokens.emplace_back(TokenType::STRING, std::string(p - i, p), line);
                p++;
                tokens.emplace_back(TokenType::QUOTATION_D, line);
            } else if (*p == '\'') {
                p++;
                tokens.emplace_back(TokenType::QUOTATION_S, line);
                while (*p && *p != '\'') {
                    p++;
                    i++;
                }
                if (!*p)
                    errors.emplace_back(Error(line, std::string("expected \"")));
                tokens.emplace_back(TokenType::STRING, std::string(p - i, p), line);
                p++;
                tokens.emplace_back(TokenType::QUOTATION_S, line);
            } else {
                if (*p)
                    errors.emplace_back(line, std::string("unexpected characters:  " + *p));
            }
        }
    }

    const std::deque<Token> &getTokens() const {
        return tokens;
    }

    const std::deque<Error> &getErrors() const {
        return errors;
    }

    const std::deque<Identifier> &getIdentifiers() const {
        return identifiers;
    }
};

int main() {
    std::string filename = "C:/CPP/2020_5/test.txt";
    std::fstream fs;
    fs.open(filename, std::ios::in);
    std::string sp;
    bool newline = false;
    while (!fs.eof()) {
        std::string s;
        std::getline(fs, s);
        if (newline)
            s = '\n' + s;
        newline = true;
        sp += s;
    }
    std::cout << sp << std::endl;
    Lexer lexer;
    lexer.lex(sp);
    std::deque<Token> tokens = lexer.getTokens();
    std::deque<Error> errors = lexer.getErrors();
    std::deque<Identifier> identifiers = lexer.getIdentifiers();
    std::cout << "--------tokens--------" << std::endl;
    std::cout << "line\t"  << "type\t" << "value" << std::endl;
    for (const auto &e : tokens) {
        std::cout << e << std::endl;
    }
    std::cout << "--------errors--------" << std::endl;
    std::cout << "line\t"  << "info\t" << std::endl;
    for (const auto &e : errors) {
        std::cout << e << std::endl;
    }
    std::cout << "------identifiers------" << std::endl;
    std::cout << "line\t"  << "name\t" << "address" << std::endl;
    for (const auto &e : identifiers) {
        std::cout << e << std::endl;
    }
    return 0;
}