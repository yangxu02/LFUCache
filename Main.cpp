#include "LFUCache.h"

int main(int argc, char* argv[]) {
    LFUCache lfu(2);
    std::cerr << lfu.repr() << std::endl;
    lfu.set(1, 1);
    std::cerr << lfu.repr() << std::endl;
    lfu.set(2, 2);
    std::cerr << lfu.repr() << std::endl;
    std::cerr << lfu.get(1) << std::endl;
    std::cerr << lfu.repr() << std::endl;
    lfu.set(3, 3);
    std::cerr << lfu.repr() << std::endl;
    std::cerr << lfu.get(2) << std::endl;
    std::cerr << lfu.repr() << std::endl;
    std::cerr << lfu.get(3) << std::endl;
    std::cerr << lfu.repr() << std::endl;
    lfu.set(4, 4);
    std::cerr << lfu.repr() << std::endl;
    std::cerr << lfu.get(1) << std::endl;
    std::cerr << lfu.repr() << std::endl;
    std::cerr << lfu.get(3) << std::endl;
    std::cerr << lfu.repr() << std::endl;
    std::cerr << lfu.get(4) << std::endl;
    std::cerr << lfu.repr() << std::endl;


    std::cerr << "===================" << std::endl;
    LFUCache lfu2(3);
    std::cerr << lfu2.repr() << std::endl;
    lfu2.set(2, 2);
    std::cerr << lfu2.repr() << std::endl;
    lfu2.set(1, 1);
    std::cerr << lfu2.repr() << std::endl;
    std::cerr << lfu2.get(2) << std::endl;
    std::cerr << lfu2.repr() << std::endl;
    std::cerr << lfu2.get(1) << std::endl;
    std::cerr << lfu2.repr() << std::endl;
    std::cerr << lfu2.get(2) << std::endl;
    std::cerr << lfu2.repr() << std::endl;
    lfu2.set(3, 3);
    std::cerr << lfu2.repr() << std::endl;
    lfu2.set(4, 4);
    std::cerr << lfu2.repr() << std::endl;
    std::cerr << lfu2.get(3) << std::endl;
    std::cerr << lfu2.repr() << std::endl;
    std::cerr << lfu2.get(2) << std::endl;
    std::cerr << lfu2.repr() << std::endl;
    std::cerr << lfu2.get(1) << std::endl;
    std::cerr << lfu2.repr() << std::endl;
    std::cerr << lfu2.get(4) << std::endl;
    std::cerr << lfu2.repr() << std::endl;



    return 0;


}
