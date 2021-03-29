//
// Created by XM on 2021/3/25.
//

#include <CM_Lexer.hpp>

#include <iostream>
#include <fstream>
#include <vector>

class lineInfo final : public cm::token_base{

    std::string info;
public:
    lineInfo(int l, int c, std::string info): cm::token_base(l,c), info(info){}

    ~lineInfo() = default;

    std::string get_string() const override
    {
        return info;
    }

    cm::token_type get_type() const override{
        return cm::token_type::null_type;
    }

    std::ostream & show(std::ostream &out) override{
        out << line << ":" << info;
        return out;
    }

    std::string  get_show_info() const override{
        return std::string(std::to_string(line) + ":" + this->get_string());
    }

};

int get_info(std::string &sp, const std::string &filename, std::vector<cm::token_base *> &lineinfo){
    std::fstream fs;
    fs.open(filename, std::ios::in);
    bool newline = false;
    int l = 1;
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
    return l;
}

void write_info(const std::deque<cm::token_base *> &tokens, const std::string& write_filename){
    std::fstream fs;
    fs.open(write_filename, std::ios::out);
    for(auto iter = tokens.begin(); iter != tokens.end(); iter++){
        if((*iter)->get_type() != cm::token_type::null_type)
            fs << '\t';
        fs << (*iter)->get_show_info() << std::endl;
    }
}

int main(int argc, char** argv){
    if(argc != 2){
        std::cerr << "wrong parameters" << std::endl;
        exit(-1);
    }
    std::cout << "argc is : " << argc << "  argv is :  " << argv[0] << "   "  << argv[1] << std::endl;
    std::string filename = argv[1];
    std::string sp;
    std::vector<cm::token_base *> lineinfo;
    int line = get_info(sp, filename, lineinfo);
//get text info

    std::cout << sp;
    cm::Lexer * lexer = new cm::Lexer(sp);
    lexer->Lex();
    std::deque<cm::token_base *> tokens = lexer->getTokens();
//    get tokens


    std::deque<cm::token_base *> show_tokens;
    int j = 0;
    for(int i = 1; i < line + 1; i++){
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

//   put tokens in order

    for(auto iter = show_tokens.begin(); iter != show_tokens.end(); iter++){
        if(!((*iter)->get_type() == cm::token_type::null_type))
            std::cout << "\t";
        std::cout << (*iter)->get_show_info() << std::endl;
    }
//write into files
    write_info(show_tokens, "c1.txt");
}