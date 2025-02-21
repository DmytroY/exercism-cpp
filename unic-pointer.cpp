#include <iostream>
#include <memory>

struct aStruct {
    std::string name;
    aStruct(std::string name = "default name") : name(name) {
        std::cout << "aStruct constructor called" << std::endl;
    }
    void printA() {
        std::cout << "A" << std::endl;
    }
};

int main() {
    // --- manual memory management ---
    // when use any of this equivalent syntax, the object will be created on the heap
    // do not forget to delete it !
    // aStruct* p1 = new aStruct(); //highly readable - is best practice aside from smart pointers
    // auto p1 = new aStruct(); 
    // aStruct* p1(new aStruct()); // direct initialization of p1, constructor-style syntax
    auto p1(new aStruct());
    
    // p1->printA();
    (*p1).printA();
    delete p1;

    // --- automatic memory management ---
    // when use any of this equivalent syntax, the object will be created on the stack
    // aStruct s1; //variable(object) declaration only. This creates an object on the stack, but members of object will have garbage values
    // auto s1 = aStruct(); // create an object on the stack then initialize members to 0, or default values by constructor
    // aStruct s1(); //avoid this, it will be interpreted as a  declaration function s1() which returns aStruct type
    // aStruct s1{}; //this is the correct way to create an object on the stack + initialize members to 0
    aStruct s1{};


    s1.printA();

    // --- smart pointer ---
    // when use any of this equivalent syntax, the object will be created on the heap
    // the object will be automatically deleted when it goes out of scope
    //
    // std::unique_ptr<aStruct> p2(new aStruct()); // old way
    // std::unique_ptr<aStruct> p2 = std::make_unique<aStruct>(); //recommended
    auto p2 = std::make_unique<aStruct>(); // same as above, simplified by auto
    p2->printA();

    return 0;
}