#include <string>
#include <iostream>
#include <iomanip>
#include <vector> 

void int_by_ref(int& ref) { ref = 1;}
void int_by_ptr(int* ptr) { *ptr = 2;}

template <arr_size N>;
void arr_by_ref(int (&arr)[]){ 
    arr[0] = 55;
    std::cout << "Array sige is " << sizeof(arr) << std::endl;
}


// void changeArray(int* ptr2myArray) {
//     if(ptr2myArray[0] > 9) ptr2myArray[0] = 4444;
// }

// void changeVector(std::vector<int>* ptr2myVector) {
//     if((*ptr2myVector)[0] > 9) (*ptr2myVector)[0] = 9999;
// }

int main() {
    int i{};
    int_by_ref(i); std::cout << "Integer changed by reference: " << i << std::endl;
    int_by_ptr(&i); std::cout << "Integer changed by pointer: " << i << std::endl;
    
    int myArray[]{0, 1, 2};
    arr_by_ref(myArray); std::cout << "myArray[0] changed by reference:" << myArray[0] << std::endl;

    // changeArray(&myArray[0]); // pass the address of first element of myArray
    // // OR use this
    // // changeArray(myArray); // this will pass the address of the first element of myArray automaticaly
    // // because myArray is a pointer to the first element of the array
    // // shoud be used with care because changeArray() will not know the size of the array
    // std::cout << "myArray[0]: " << myArray[0] << std::endl;

    // std::vector<int> myVector{10, 20, 30, 40, 50};
    // changeVector(&myVector); //pass the address of myVector
    // std::cout << "myVector[0]: " << myVector[0] << std::endl;

    return 0;
}
