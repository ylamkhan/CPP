#ifndef ARRAY_HPP
#define ARRAY_HPP



#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
    private:
        T* A;
        size_t size1;
    public:
        Array() : A(NULL), size1(0) {}
        Array(size_t n) : A(new T[n]), size1(n) {
            for (size_t i = 0; i < size1; ++i)
                A[i] = T();
        }
        Array(const Array& other) : A(new T[other.size1]), size1(other.size1) {
            for (size_t i = 0; i < size1; ++i)
                A[i] = other.A[i];
        }
        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] A;
                A = new T[other.size1];
                size1 = other.size1;
                for (size_t i = 0; i < size1; ++i)
                    A[i] = other.A[i];
            }
            return *this;
        }
        ~Array() {
            delete[] A;
        }
        T& operator[](size_t index) const{
            if (index >= size1)
                throw std::out_of_range("Index out of bounds");
            return A[index];
        }
        size_t size() const {
            return size1;
        }

};


#endif
