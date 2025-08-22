#include "iter.hpp"


template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

int main() {

    try
    {
        const int intArray[] = {1, 2, 3, 4, 5};
        size_t intArraySize = sizeof(intArray) / sizeof(int);
        
        std::cout << "Printing elements of intArray: ";
        iter(intArray, intArraySize, printElement<const int>);
        std::cout << std::endl;

        const double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
        size_t doubleArraySize = sizeof(doubleArray) / sizeof(double);

        std::cout << "Printing elements of doubleArray: ";
        iter(doubleArray, doubleArraySize, printElement<const double>);
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<"\n";
    }

    return 0;
}