#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

void changeInt(int* myInt) {
    if ((*myInt) > 9) (*myInt) = 1111;
}

void changeArray(int* ptr2myArray) {
    if(ptr2myArray[0] > 9) ptr2myArray[0] = 4444;
}

void changeVector(std::vector<int>* ptr2myVector) {
    if((*ptr2myVector)[0] > 9) (*ptr2myVector)[0] = 9999;
}

int main() {
    int myInt{10};
    changeInt(&myInt); // pass the address of myInt
    std::cout << "myInt: " << myInt << std::endl;

    int myArray[]{10, 20, 30, 40, 50};
    changeArray(&myArray[0]); // pass the address of first element of myArray
    // OR use this
    // changeArray(myArray); // this will pass the address of the first element of myArray automaticaly
    // because myArray is a pointer to the first element of the array
    // shoud be used with care because changeArray() will not know the size of the array
    std::cout << "myArray[0]: " << myArray[0] << std::endl;

    std::vector<int> myVector{10, 20, 30, 40, 50};
    changeVector(&myVector); //pass the address of myVector
    std::cout << "myVector[0]: " << myVector[0] << std::endl;

    return 0;
}
