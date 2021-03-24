#include <iostream>
#include <queue>

int Node[22][22];
int num;

struct pos {
    int x = 0;
    int y = 0;

    pos(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    pos() : pos(0, 0) {}
};

bool reachable(int x, int y) {
    auto data = Node[x][y];
    if (data < 0)
        return false;
    return true;
}


void bfs(std::queue<pos> &Queue, int height, int weight) {
    auto data = Queue.front();
    int x = data.getX();
    int y = data.getY();
    auto time = Node[x][y];
    if (reachable(x + 1, y)) {
        if (Node[x + 1][y] == 0) {
            Node[x + 1][y] = 1;
            Num++;
            Queue.emplace(pos(x + 1, y));
//            std::cout << "Add pos: " << x + 1 << " " << y << std::endl;
        }
    }
    if (reachable(x - 1, y)) {
        if (Node[x - 1][y] == 0) {
            Node[x - 1][y] = 1;
            Num++;
            Queue.emplace(pos(x - 1, y));
//            std::cout << "Add pos: " << x - 1 << " " << y << std::endl;
        }
    }
    if (reachable(x, y + 1)) {
        if (Node[x][y + 1] == 0) {
            Node[x][y + 1] = 1;
            Num++;
            Queue.emplace(pos(x, y + 1));
//            std::cout << "Add pos: " << x << " " << y + 1 << std::endl;
        }
    }
    if (reachable(x, y)) {
        if (Node[x][y - 1] == 0) {
            Node[x][y - 1] = 1;
            Num++;
            Queue.emplace(pos(x, y - 1));
//            std::cout << "Add pos: " << x << " " << y - 1 << std::endl;
        }
    }
    Queue.pop();
}

int main() {
    int Term = 0;
    std::cin >> Term;
    while (Term--) {
        for (int i = 0; i < 22; i++) {
            for (int j = 0; j < 22; j++)
                Node[i][j] = -1;
        }
        Num = 1;
        std::queue<pos> Queue;
        int height, width;
        std::cin >> height >> width;
        char M[width];
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= width; j++) {
                std::cin >> M[j];
                switch (M[j]) {
                    case '@': {
                        Node[i][j] = 1;
                        Queue.emplace(pos(i, j));
                        break;
                    }
                    case '#': {
                        Node[i][j] = 0;
                        break;
                    }
                    case '.': {
                        Node[i][j] = -1;
                        break;
                    }
                }
            }
        }
//        std::cout << "your geometry is:  \n";
//        for(int i = 1; i <= height; ++i)
//        {
//            for (int j = 1; j <= width; ++j) {
//                switch (Node[i][j]) {
//                    case 1:
//                        std::cout << "@ ";
//                        break;
//                    case 0:
//                        std::cout << "# ";
//                        break;
//                    case -1:
//                        std::cout << ". ";
//                        break;
//                }
//            }
//            std::cout << std::endl;
//        }
        while (!Queue.empty()) {
            bfs(Queue, height, width);
        }
        std::cout << Num << std::endl;
    }

    return 0;
}