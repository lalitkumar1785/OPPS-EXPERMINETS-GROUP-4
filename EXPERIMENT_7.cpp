// Develop a program to sort a file consisting of books’ details in the alphabetical order of author 
// names. 
// The details of books include book_id, author_name, price, no_of_pages, publisher, 
// year_of_publishing. 


#include <iostream>

template <typename T>
T findMax(T a, T b, T c) {
    T max = a; 
    if (b > max) {
        max = b;
        }

    if (c > max) {
        max = c; 
    }

    return max; 
}

int main() {
   
    int a = 5, b = 9, c = 3;
    std::cout << "The largest integer is: " << findMax(a, b, c) << std::endl;

    double x = 5.7, y = 9.1, z = 3.4;
    std::cout << "The largest double is: " << findMax(x, y, z) << std::endl;

    char p = 'a', q = 'z', r = 'm';
    std::cout << "The largest character is: " << findMax(p, q, r) << std::endl;

    return 0;
}
