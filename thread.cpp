#include <iostream>
#include <thread>
#include <mutex>

unsigned int number;
std::mutex mtx;

void increment() {
    mtx.lock();
    for(int i = 0; i < 1000000; i++){
        number++;
    }
    mtx.unlock();
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << number << std::endl;
    return 0;
}