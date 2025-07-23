#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
    int daysBorrowed;
};

Book books[MAX_BOOKS];
int bookCount = 0;

// Function to add a new book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Book database is full!\n";
        return;
    }

    cin.ignore(); // Clear input buffer
    cout << "Enter book title: ";
    getline(cin, books[bookCount].title);

    cout << "Enter author name: ";
    getline(cin, books[bookCount].author);

    cout << "Enter ISBN: ";
    getline(cin, books[bookCount].isbn);

    books[bookCount].isAvailable = true;
    books[bookCount].daysBorrowed = 0;

    bookCount++;
    cout << "Book added successfully!\n";
}

// Function to search for a book
void searchBook() {
    cin.ignore();
    string key;
    cout << "Enter title/author/ISBN to search: ";
    getline(cin, key);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == key || books[i].author == key || books[i].isbn == key) {
            cout << "\nBook Found:\n";
            cout << "Title: " << books[i].title << "\n";
            cout << "Author: " << books[i].author << "\n";
            cout << "ISBN: " << books[i].isbn << "\n";
            cout << "Status: " << (books[i].isAvailable ? "Available" : "Checked out") << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "No matching book found.\n";
}

// Function to check out a book
void checkOutBook() {
    cin.ignore();
    string isbn;
    cout << "Enter ISBN to check out: ";
    getline(cin, isbn);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].isbn == isbn) {
            if (books[i].isAvailable) {
                books[i].isAvailable = false;
                cout << "Enter number of days borrowed: ";
                cin >> books[i].daysBorrowed;
                cout << "Book checked out successfully!\n";
            } else {
                cout << "Book is already checked out.\n";
            }
            return;
        }
    }

    cout << "Book with ISBN not found.\n";
}

// Function to return a book
void returnBook() {
    cin.ignore();
    string isbn;
    cout << "Enter ISBN to return: ";
    getline(cin, isbn);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].isbn == isbn) {
            if (!books[i].isAvailable) {
                books[i].isAvailable = true;
                cout << "Book returned successfully!\n";
                int daysLate;
                cout << "Enter number of days late (0 if on time): ";
                cin >> daysLate;

                if (daysLate > 0) {
                    int fine = daysLate * 2; // ₹2 fine per day
                    cout << "Fine to be paid: ₹" << fine << endl;
                } else {
                    cout << "No fine. Thank you!\n";
                }

                books[i].daysBorrowed = 0;
            } else {
                cout << "This book was not checked out.\n";
            }
            return;
        }
    }

    cout << "Book with ISBN not found.\n";
}

// Function to show all books
void showAllBooks() {
    if (bookCount == 0) {
        cout << "No books in the library.\n";
        return;
    }

    cout << "\nList of Books:\n";
    for (int i = 0; i < bookCount; i++) {
        cout << i + 1 << ". " << books[i].title << " | " << books[i].author
             << " | ISBN: " << books[i].isbn
             << " | Status: " << (books[i].isAvailable ? "Available" : "Checked Out") << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n==== LIBRARY MANAGEMENT SYSTEM ====\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Check Out Book\n";
        cout << "4. Return Book\n";
        cout << "5. View All Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: checkOutBook(); break;
            case 4: returnBook(); break;
            case 5: showAllBooks(); break;
            case 6: cout << "Exiting system. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
