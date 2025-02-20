#include <iostream>
#include <memory>

struct aStruct {
    void printA() {
        std::cout << "A" << std::endl;
    }
};

int main() {
    // --- manual memory management ---
    // when use any of this equivalent syntax, the object will be created on the heap
    // do not forget to delete it
    // aStruct* p1 = new aStruct();
    // auto p1 = new aStruct();
    // aStruct* p1(new aStruct());
    auto p1(new aStruct());
    
    // p1->printA();
    (*p1).printA();
    delete p1;

    // --- automatic memory management ---
    // when use any of this equivalent syntax, the object will be created on the stack
    aStruct s1;
    s1.printA();

    // --- smart pointer ---
    // when use any of this equivalent syntax, the object will be created on the heap
    // the object will be automatically deleted when it goes out of scope
    // std::unique_ptr<aStruct> p2(new aStruct());
    // auto p2 = std::make_unique<aStruct>();
    auto p2 = std::make_unique<aStruct>();
    p2->printA();

    return 0;
}