#include "Array.hpp"


int main() {
    try {
        Array<int> arr1;
        Array<int> arr2(5);
		for(size_t i = 0 ; i<5;i++)
				arr2[i]=i;
        Array<int> arr3 = arr2;
        Array<int> arr4;
        arr4 = arr2;
        arr2[0] = 100;
        std::cout << "arr3 elements: ";
        for (unsigned int i = 0; i < arr3.size(); ++i) {
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "arr4 elements: ";
        for (unsigned int i = 0; i < arr4.size(); ++i) {
            std::cout << arr4[i] << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
