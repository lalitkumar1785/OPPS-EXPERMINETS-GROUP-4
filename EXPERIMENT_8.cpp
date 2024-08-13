// Design a class template by name Vector and perform the following: 
// • Find the smallest of the element in the Vector. 
// • Search for an element in the Vector. 
// • Find the average of the element in the array.
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <numeric>

template <typename T>
class Vector {
private:
    std::vector<T> elements;

public:
    Vector() = default;

    void add_element(T element) {
        elements.push_back(element);
    }

    T smallest_element() {
        if (elements.empty()) {
            throw std::runtime_error("Vector is empty");
        }
        return *std::min_element(elements.begin(), elements.end());
    }

    bool search_element(T element) {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    double average() {
        if (elements.empty()) {
            throw std::runtime_error("Vector is empty");
        }
        return static_cast<double>(std::accumulate(elements.begin(), elements.end(), 0)) / elements.size();
    }
};

int main() {
    try {
        Vector<int> vec;
        vec.add_element(10);
        vec.add_element(20);
        vec.add_element(5);
        vec.add_element(15);

        std::cout << "Smallest element: " << vec.smallest_element() << std::endl;
        std::cout << "Is 15 in vector? " << (vec.search_element(15) ? "Yes" : "No") << std::endl;
        std::cout << "Is 25 in vector? " << (vec.search_element(25) ? "Yes" : "No") << std::endl;
        std::cout << "Average of elements: " << vec.average() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
