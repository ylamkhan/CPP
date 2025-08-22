#include "easyfind.hpp"

int main() {
    try {
        std::vector <int> t;
        for (size_t i = 0; i < 10; i++)
                t.push_back(i);
        std::vector<int>::iterator it = easyfind(t,5); 
        std::cout<< *it<<"\n";

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
