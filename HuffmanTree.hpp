#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <map>

class HuffmanTree final {

private:

    class HuffmanTreeNode final {

    private:

        int Weight = 0;
        HuffmanTreeNode *parent = nullptr;
        HuffmanTreeNode *leftchild = nullptr;
        HuffmanTreeNode *rightchild = nullptr;
        char Character = '\0';
        bool is_LeafNode = false;

    public:

        HuffmanTreeNode() = delete;

        HuffmanTreeNode(char ch, int w, bool isLeaf = false,
                        HuffmanTreeNode *lc = nullptr, HuffmanTreeNode *rc = nullptr) :
                Character(ch), Weight(w), is_LeafNode(isLeaf), leftchild(lc),
                rightchild(rc) { parent = nullptr; }

        int getWeight() const {
            return this->Weight;
        }

        bool is_Leafnode() const {
            return this->is_LeafNode;
        }

        void setParent(HuffmanTreeNode *p) {
            this->parent = p;
        }

        char getCharacter() const {
            return this->Character;
        }

        HuffmanTreeNode *getParent() const {
            return this->parent;
        }

        HuffmanTreeNode *getLeftchild() const {
            return this->leftchild;
        }

        HuffmanTreeNode *getRightchild() const {
            return this->rightchild;
        }
    };

    std::vector<HuffmanTreeNode *> Tree;
    std::map<char, int> dataWeight;
    std::map<char, std::string> dataCode;
    std::map<std::string, char> codeData;
    std::string infileName;
    int CharSize = 0;

    void sort() {
        for (int i = 0; i < Tree.size() - 1; i++) {
            for (int j = 0; j < Tree.size() - 1 - i; j++) {
                if (Tree[j]->getWeight() > Tree[j + 1]->getWeight()) {
                    HuffmanTreeNode *tmpNode = Tree[j];
                    Tree[j] = Tree[j + 1];
                    Tree[j + 1] = tmpNode;
                }
            }
        }
    }

    void SetCode(HuffmanTreeNode *node, std::string str) {
        if (node != nullptr) {
            if (node->is_Leafnode()) {
                dataCode[node->getCharacter()] = str;
            }
            SetCode(node->getLeftchild(), str + "0");
            SetCode(node->getRightchild(), str + "1");
        }

    }

    void GetText_to_encode() {
        std::fstream file;
        file.open(infileName, std::ios::in);
        if (!file) {
            throw std::runtime_error("Failed opening file");
        } else {
            file >> std::noskipws;
            char ch;
            int alldata = 0;
            while (!file.eof()) {
                file >> ch;
                if (!file.eof()) {
                    if (dataWeight.find(ch) != dataWeight.end()) {
                        dataWeight[ch] = dataWeight[ch] + 1;
                    } else {
                        dataWeight[ch] = 1;
                    }
                }
            }
        }
        file.close();
    }

    bool Is_Decode_Text() {
        std::fstream file;
        file.open(infileName, std::ios::in);
        std::string is_coded = "";
        if (!file) {
            throw std::runtime_error("Failed opening file");
        } else {
            std::getline(file, is_coded);
            if (is_coded.substr(0, 12) != "is\tcode\tfile")
                return false;
            else {
                file.close();
                return true;
            }
        }
    }

    void CreateTree() {
        HuffmanTreeNode *tmpNode = nullptr;
        for (auto iter = dataWeight.begin(); iter != dataWeight.end(); iter++) {
            tmpNode = new HuffmanTreeNode(iter->first, iter->second, true);
            Tree.push_back(tmpNode);
            tmpNode = nullptr;
        }
        CharSize = Tree.size();
        HuffmanTreeNode *newNode = nullptr;
        for (int i = 0; i < CharSize - 1; i++) {
            this->sort();
            newNode = new HuffmanTreeNode('\0', Tree[0]->getWeight() + Tree[1]->getWeight(), false, Tree[0], Tree[1]);
            Tree[0]->setParent(newNode);
            Tree[1]->setParent(newNode);
            Tree.erase(Tree.begin());
            Tree.erase(Tree.begin());
            Tree.insert(Tree.begin(), newNode);
            newNode = nullptr;
        }
    }

    void Encode() {
        GetText_to_encode();
        CreateTree();
        SetCode(Tree[0], "");
        std::fstream file;
        file.open(infileName, std::ios::in);
        std::string code = "";
        if (!file) {
            throw std::runtime_error("Failed opening file");
        } else {
            file >> std::noskipws;
            char ch;
            while (!file.eof()) {
                file >> ch;
                if (!file.eof()) {
                    if (dataCode.find(ch) == dataCode.end()) {
                        throw std::runtime_error("Unable to encode!");
                    } else {
                        code += dataCode[ch];
                    }
                }
            }
            file.close();
            std::fstream file1;
            std::string outFileName = infileName.substr(0, infileName.length() - 4) + "code.txt";
            file1.open(outFileName, std::ios::out);
            file1 << "is\tcode\tfile" << CharSize << "\n";
            for (auto iter = dataCode.begin(); iter != dataCode.end(); iter++) {
                file1 << iter->first;
            }
            file1 << "\n";
            for (auto iter = dataCode.begin(); iter != dataCode.end(); iter++) {
                file1 << iter->second << " ";
            }
            file1 << "\n" << code;
            file1.close();
        }
    }

    void Decode() {
        if (!Is_Decode_Text()) {
            throw std::runtime_error("Not a coded file!");
        } else {
            std::fstream file1(infileName, std::ios::in);
            std::string str;
            std::getline(file1, str);
            CharSize = std::stoi(str.substr(12, str.length()));
            std::vector<char> charVec;
            std::vector<std::string> codeVec;
            std::string code = "";
            std::string text = "";

            file1 >> std::noskipws;
            char ch;
            for (int i = 0; i < CharSize; i++) {
                file1 >> ch;
                charVec.push_back(ch);
            }
            file1 >> ch;
            if (ch == '\n') {
                auto iter = charVec.begin();
                for (; iter != charVec.end(); iter++) {
                    code = "";
                    file1 >> ch;
                    while (ch != ' ') {
                        code += ch;
                        file1 >> ch;
                    }
                    codeVec.push_back(code);
                }
                iter = charVec.begin();
                for (auto iter1 = codeVec.begin(); iter1 != codeVec.end(); iter1++) {
                    codeData.insert(std::pair<std::string, char>(*iter1, *iter));
                    iter++;
                }
                file1 >> ch; //读掉回车
                code = "";
                while (!file1.eof()) {
                    file1 >> ch;
                    if (!file1.eof()) {
                        code += ch;
                        if (codeData.find(code) != codeData.end()) {
                            text += codeData[code];
                            code = "";
                        }
                    }
                }
            }

            file1.close();
            std::fstream file2;
            file2.open(infileName.substr(0, infileName.length() - 8) + ".txt", std::ios::out);
            if (!file2) {
                throw std::runtime_error("Failed creating file!");
            } else {
                file2 << text;
                throw std::runtime_error("");
                file2.close();
            }
        }
    }

    void DeleteNode(HuffmanTreeNode *node) {
        if (node != nullptr) {
            DeleteNode(node->getLeftchild());
            DeleteNode(node->getRightchild());
            delete node;
        }
    }

public:

    HuffmanTree() = delete;

    HuffmanTree(std::string filename, std::string mode) {
        infileName = filename;
        if (mode == "encode")
            Encode();
        else if (mode == "decode")
            Decode();
        else
            throw std::runtime_error("Undefined behavior");
    }

    ~HuffmanTree() {
        DeleteNode(Tree[0]);
    }
};