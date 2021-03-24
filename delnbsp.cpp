#include <iostream>
#include <fstream>

int main(){
    std::fstream fs;
    fs.open("D:\\JAVAprojects\\SmartClass\\src\\zrkc\\group\\new_ui\\view\\sample.fxml");
    std::string s;
    std::string str;
    while(!fs.eof()){
        std::string tmp = "";
        bool flag = false;
        std::getline(fs, str);
        for(auto &e : str){
            if(e == '<' || (isalpha(e)))
                flag = true;
            if(flag)
                tmp += e;
            else
                tmp += ' ';
        }

        s += tmp;
        if(!fs.eof())
            s += '\n';
    }
    std::cout << s << std::endl;
    return 0;
}