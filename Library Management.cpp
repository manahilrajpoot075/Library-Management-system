#include <iostream>
#include <string>

using namespace std;

// Structure to represent a Book
struct Book {
    string title;
    bool isIssued;
};

// Function to add a book
void addBook(Book books[], int &bookCount, string title) {
    if (bookCount < 5) {
        books[bookCount].title = title;
        books[bookCount].isIssued = false; // Initially, the book is not issued
        bookCount++;
        cout << "Book added successfully!" << endl;
    } else {
        cout << "Library is full! Cannot add more books." << endl;
    }
}

// Function to issue a book
void issueBook(Book books[], int bookCount, string title) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title) {
            if (books[i].isIssued) {
                cout << "Sorry, the book is already issued." << endl;
            } else {
                books[i].isIssued = true;
                cout << "Book issued successfully!" << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

// Function to return a book
void returnBook(Book books[], int bookCount, string title) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title) {
            if (books[i].isIssued) {
                books[i].isIssued = false;
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "The book was not issued." << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

// Function to search for a book
void searchBook(Book books[], int bookCount, string title) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title) {
            cout << "Book found: " << books[i].title 
                 << (books[i].isIssued ? " (Issued)" : " (Available)") << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

int main() {
    // Predefined books (5 books already in the system)
    Book books[5] = {
        {"Microsoft", false},
        {"Physics", false},
        {"Cinderella", false},
        {"FairyTale", false},
        {"CPP", false}
    };
    
    int bookCount = 5;  // Since we have 5 books initialized
    int choice;
    string title;

    // Menu loop for user interaction
    while (true) {
        // Display the menu
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Search Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the input buffer for getline

        switch (choice) {
            case 1:
                cout << "Enter book title to add: ";
                cin >> title;  // Using cin instead of getline
                addBook(books, bookCount, title);
                break;

            case 2:
                cout << "Enter book title to issue: ";
                cin >> title;  // Using cin instead of getline
                issueBook(books, bookCount, title);
                break;

            case 3:
                cout << "Enter book title to return: ";
                cin >> title;  // Using cin instead of getline
                returnBook(books, bookCount, title);
                break;

            case 4:
                cout << "Enter book title to search: ";
                cin >> title;  // Using cin instead of getline
                searchBook(books, bookCount, title);
                break;

            case 5:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

