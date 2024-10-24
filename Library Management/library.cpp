#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// Structure to store book details
struct Book {
    string title;
    string author;
    bool isBorrowed = false;  // Check if the book is borrowed
};

// Structure to store user details
struct User {
    string password;
    vector<string> borrowedBooks;  // Books borrowed by the user
    bool isLoggedIn = false;
};

// Map to store users (key: User ID, value: User details)
map<string, User> users;

// Map to store books (key: Book ID, value: Book details)
map<int, Book> books;
int bookIDCounter = 1;  // Counter to assign unique IDs to books

// Function to create an account
void createAccount() {
    string userID, password;
    cout << "Enter a new User ID: ";
    cin >> userID;

    // Check if the user ID is already taken
    if (users.find(userID) != users.end()) {
        cout << "User ID already exists. Please try a different one.\n";
        return;
    }

    cout << "Create your password: ";
    cin >> password;

    // Add the new user to the system
    users[userID] = {password, {}, false};
    cout << "Account created successfully!\n";
}

// Function to login
bool login(string& userID) {
    cout << "Enter User ID: ";
    cin >> userID;

    // Check if the user exists
    if (users.find(userID) == users.end()) {
        cout << "User not found. Please register first.\n";
        return false;
    }

    string password;
    cout << "Enter Password: ";
    cin >> password;

    // Check if the password is correct
    if (users[userID].password == password) {
        users[userID].isLoggedIn = true;
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Incorrect password. Try again.\n";
        return false;
    }
}

// Function to logout
void logout(string& userID) {
    users[userID].isLoggedIn = false;
    cout << "Logged out successfully!\n";
}

// Function to add books to the system (for admins)
void addBook() {
    string title, author;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter Book Author: ";
    getline(cin, author);

    books[bookIDCounter++] = {title, author, false};
    cout << "Book added successfully!\n";
}

// Function to display available books
void displayBooks() {
    cout << "\n--- Available Books ---\n";
    for (const auto& pair : books) {
        int id = pair.first;
        const Book& book = pair.second;
        if (!book.isBorrowed) {
            cout << "Book ID: " << id << ", Title: " << book.title << ", Author: " << book.author << "\n";
        }
    }
    cout << "-----------------------\n";
}

// Function to borrow a book
void borrowBook(string& userID) {
    int bookID;
    displayBooks();
    cout << "Enter the Book ID you want to borrow: ";
    cin >> bookID;

    if (books.find(bookID) != books.end() && !books[bookID].isBorrowed) {
        books[bookID].isBorrowed = true;
        users[userID].borrowedBooks.push_back(books[bookID].title);
        cout << "Book borrowed successfully!\n";
    } else {
        cout << "Invalid Book ID or the book is already borrowed.\n";
    }
}

// Function to return a borrowed book
void returnBook(string& userID) {
    if (users[userID].borrowedBooks.empty()) {
        cout << "You have no borrowed books to return.\n";
        return;
    }

    cout << "\n--- Borrowed Books ---\n";
    for (size_t i = 0; i < users[userID].borrowedBooks.size(); ++i) {
        cout << i + 1 << ". " << users[userID].borrowedBooks[i] << "\n";
    }
    cout << "----------------------\n";

    int choice;
    cout << "Enter the number of the book you want to return: ";
    cin >> choice;

    if (choice >= 1 && choice <= users[userID].borrowedBooks.size()) {
        string bookTitle = users[userID].borrowedBooks[choice - 1];
        // Find the book in the books map
        for (auto& pair : books) {
            int id = pair.first;
            Book& book = pair.second;
            if (book.title == bookTitle) {
                book.isBorrowed = false;
                break;
            }
        }
        users[userID].borrowedBooks.erase(users[userID].borrowedBooks.begin() + (choice - 1));
        cout << "Book returned successfully!\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

// Function to display the user menu
void userMenu(string& userID) {
    int choice;
    while (users[userID].isLoggedIn) {
        cout << "\n--- User Menu ---\n";
        cout << "1. Borrow Book\n";
        cout << "2. Return Book\n";
        cout << "3. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                borrowBook(userID);
                break;
            case 2:
                returnBook(userID);
                break;
            case 3:
                logout(userID);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Function to display the main menu
void mainMenu() {
    int choice;
    string userID;

    while (true) {
        cout << "\n--- Smart Library System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Add Book (Admin)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                if (login(userID)) {
                    userMenu(userID);
                }
                break;
            case 3:
                addBook();
                break;
            case 4:
                cout << "Exiting the system...\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
