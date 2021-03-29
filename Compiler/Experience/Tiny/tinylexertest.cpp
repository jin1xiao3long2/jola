//
// Created by XM on 2021/3/24.
//

#include <Tiny_Lexer.hpp>
#include <iostream>
#include <fstream>
#include <vector>

class lineInfo final : public tn::token_base{

    std::string info;
public:
    lineInfo(int l, int c, std::string info): tn::token_base(l,c), info(info){}

    ~lineInfo() = default;

    std::string get_string() const override
    {
        return info;
    }

    tn::token_type get_type() const override{
        return tn::token_type::null_type;
    }

    std::ostream & show(std::ostream &out) override{
        out << line << ":" << info;
        return out;
    }

};

int main(){
    std::string filename = "C:/CPP/2020_5/Compiler/Experience/Tiny/sample.tny";
    std::fstream fs;
    fs.open(filename, std::ios::in);
    std::string sp;
    bool newline = false;
    int l = 1;
    std::vector<tn::token_base *> lineinfo;
    while (!fs.eof()) {
        std::string s;
        std::getline(fs, s);

        lineinfo.push_back(new lineInfo(l, 0, s));
        if (newline)
            s = '\n' + s;
        newline = true;
        sp += s;
        l++;
    }
    lineinfo.push_back(new lineInfo(l, 0, "EOF"));
    std::cout << sp << std::endl;

    tn::Lexer * lexer = new tn::Lexer(sp);
    lexer->Lex();
    std::deque<tn::token_base *> tokens = lexer->getTokens();
    std::deque<tn::token_base *> show_tokens;
    int j = 0;
    for(int i = 1; i < l + 1; i++){
        show_tokens.push_back(lineinfo.at(i-1));
        for(j; j < tokens.size(); ){
            if(tokens.at(j)->get_line() == i)
            {
                show_tokens.push_back(tokens.at(j));
                j++;
            }else{
                break;
            }
        }
    }
    for(auto iter = show_tokens.begin(); iter != show_tokens.end(); iter++){
        if((*iter)->get_type() != tn::token_type::null_type)
            std::cout << "\t";
        (*iter)->show(std::cout);
        std::cout << std::endl;
    }

}