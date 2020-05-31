#include <iostream>
#include <cstring>

#define MAX_SIZE 1024

struct Book{
    char* title;
    char* authorName;
    char* genre;
    double price;
    size_t salesCount;
};

char* copyDynamic(char* source){
    char* result = new char[strlen(source) + 1];
    strcpy(result, source);
    return result;
}

void deleteDynamic(Book& b){
    delete[] b.title;
    delete[] b.authorName;
    delete[] b.genre;
}

void initialize(Book& b){
    char input[1024];

    std::cin.ignore();
    std::cout << "Input book title:";
    std::cin.getline(input, MAX_SIZE);
    b.title = copyDynamic(input);

    
    std::cout << "Input book author name:";
    std::cin.getline(input, MAX_SIZE);
    b.authorName = copyDynamic(input);
    
    std::cout << "Input book genre:";
    std::cin.getline(input, MAX_SIZE);
    b.genre = copyDynamic(input);
    
    std::cout << "Input book price:";
    std::cin >> b.price;

    std::cout << "Input book sales count:";
    std::cin >> b.salesCount;
}

void print(const Book& b){
    std::cout << "\n-----------BOOK-----------\n"; 
    std::cout << "Title: "  << b.title      << std::endl
              << "Author: " << b.authorName << std::endl
              << "Genre: "  << b.genre      << std::endl
              << "Price: "  << b.price      << std::endl
              << "Sales: "  << b.salesCount << std::endl;
}

void printBookWithLowestPrice(Book* books, size_t count){
    double min = books[0].price;
    size_t index = 0;

    if(count == 1){
        print(books[0]);
        return;
    }
    
    for(size_t i = 1; i < count ; i++){
        if(min > books[i].price){
            min = books[i].price;
            index = i;
        }
    }

    print(books[index]);
}

void printBookWithHighestPrice(Book* books, size_t count){
    double max = books[0].price;
    size_t index = 0;

    if(count == 1){
        print(books[0]);
        return;
    }
    
    for(size_t i = 1; i < count ; i++){
        if(max < books[i].price){
            max = books[i].price;
            index = i;
        }
    }

    print(books[index]);
}

Book& getBestBook(Book* books, size_t count){
    size_t maxSales = books[0].salesCount;
    size_t index = 0;

    if(count == 1){
        return books[index];
    }
    
    for(size_t i = 1; i < count ; i++){
        if(maxSales < books[i].salesCount){
            maxSales = books[i].salesCount;
            index = i;
        }
    }

    return books[index];
}

int main(){

    size_t n;
    std::cout << "Input number of books:";
    std::cin >> n;

    Book* books = new Book[n];

    for(size_t i = 0; i < n; i++){
        initialize(books[i]);
    }

    for(size_t i = 0; i < n; i++){
        print(books[i]);
    }

    printBookWithLowestPrice(books, n);
    printBookWithHighestPrice(books, n);

    Book bestBook  = getBestBook(books, n);
    print(bestBook);

    for(size_t i = 0; i < n; i++){
        deleteDynamic(books[i]);
    }

    return 0;
}