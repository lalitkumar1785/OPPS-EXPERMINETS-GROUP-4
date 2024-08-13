// Develop a program to sort a file consisting of books’ details in the alphabetical order of author 
// names. 
// The details of books include book_id, author_name, price, no_of_pages, publisher, 
// year_of_publishing. 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class Book {
public:
    std::string book_id;
    std::string author_name;
    std::string price;
    std::string no_of_pages;
    std::string publisher;
    std::string year_of_publishing;

    Book(std::string book_id, std::string author_name, std::string price, std::string no_of_pages, std::string publisher, std::string year_of_publishing)
        : book_id(book_id), author_name(author_name), price(price), no_of_pages(no_of_pages), publisher(publisher), year_of_publishing(year_of_publishing) {}
};

std::vector<Book> read_books_from_file(const std::string& file_name) {
    std::vector<Book> books;
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string book_id, author_name, price, no_of_pages, publisher, year_of_publishing;
        if (!(std::getline(ss, book_id, ',') &&
              std::getline(ss, author_name, ',') &&
              std::getline(ss, price, ',') &&
              std::getline(ss, no_of_pages, ',') &&
              std::getline(ss, publisher, ',') &&
              std::getline(ss, year_of_publishing, ','))) {
            throw std::runtime_error("Failed to parse line");
        }
        books.emplace_back(book_id, author_name, price, no_of_pages, publisher, year_of_publishing);
    }
    return books;
}

void write_books_to_file(const std::string& file_name, const std::vector<Book>& books) {
    std::ofstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open output file");
    }

    for (const auto& book : books) {
        file << book.book_id << ", " << book.author_name << ", " << book.price << ", " << book.no_of_pages << ", " << book.publisher << ", " << book.year_of_publishing << std::endl;
    }
}

bool compare_by_author(const Book& a, const Book& b) {
    return a.author_name < b.author_name;
}

int main() {
    try {
        std::string input_file = "books.csv";
        std::string output_file = "sorted_books.csv";

        // Step 1: Read books from file
        std::vector<Book> books = read_books_from_file(input_file);

        // Step 2: Sort books by author name
        std::sort(books.begin(), books.end(), compare_by_author);

        // Step 3: Write sorted books to file
        write_books_to_file(output_file, books);

        std::cout << "Books have been sorted and written to " << output_file << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
