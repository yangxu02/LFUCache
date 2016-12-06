#include "LFUCache.h"

int main(int argc, char* argv[]) {
    LFUCache lfu(1);
    std::cerr << lfu.repr() << std::endl;
    lfu.set(1, 1);
    std::cerr << lfu.repr() << std::endl;
    lfu.get(1);
    std::cerr << lfu.repr() << std::endl;
    lfu.set(1, 2);
    std::cerr << lfu.repr() << std::endl;
    lfu.set(1, 1);
    std::cerr << lfu.repr() << std::endl;
    lfu.set(1, 1);
    std::cerr << lfu.repr() << std::endl;

    lfu.set(2, 1);
    std::cerr << lfu.repr() << std::endl;
    std::cerr << lfu.get(3) << std::endl;
    lfu.set(3, 1);
    std::cerr << lfu.repr() << std::endl;
    lfu.set(4, 1);
    std::cerr << lfu.repr() << std::endl;

    return 0;


}
