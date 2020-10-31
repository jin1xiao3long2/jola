#include <iostream>
#include <queue>

long int Node[100001];

void bfs(std::queue<int> &Queue) {
    auto data = Queue.front();
//    std::cout << "front: " << data << std::endl;
    int time = Node[data] + 1;
//    std::cout << "time: " << time << std::endl;
//    std::cout << "time d+1, d-1, 2d" <<
//              Node[data + 1] << " " << Node[data - 1] << " " << Node[data * 2] << std::endl;
    if (data + 1 < 100001) {
        if (time < Node[data + 1]) {
            Node[data + 1] = time;
            Queue.push(data + 1);
//            std::cout << "    Data + 1 " << data + 1 << std::endl;
        }
    }
    if (data - 1 > 0) {
        if (time < Node[data - 1]) {
            Node[data - 1] = time;
            Queue.push(data - 1);
//            std::cout << "    Data - 1 " << data - 1 << std::endl;
        }
    }
    if (data * 2 < 100001) {
        if (time < Node[data * 2]) {
            Node[data * 2] = time;
            Queue.push(data * 2);
//            std::cout << "    Data * 2 " << data * 2 << std::endl;
        }
    }
    Queue.pop();
}

int main() {
    int Term = 0;
    std::cin >> Term;
    while (Term--) {
        for (int i = 0; i < 100001; i++)
            Node[i] = 100000;
        std::queue<int> Queue;
        int pos_d, pos_c, time = 0;
        std::cin >> pos_d >> pos_c;
        Node[pos_d] = 0;
        if (pos_d >= pos_c) {
            std::cout << pos_d - pos_c << std::endl;
            continue;
        }

        Queue.push(pos_d);
        while (!Queue.empty()) {
            bfs(Queue);
//            std::cout << "Queue.front:  " << Queue.front() << std::endl;
            if (Queue.front() == pos_c) {
                std::cout << Node[pos_c] << std::endl;
                break;
            }
        }
    }
    return 0;
}