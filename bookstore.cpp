#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    float price;
    Book* left;
    Book* right;

    Book(string t, string a, float p) {
        title = t;
        author = a;
        price = p;
        left = right = NULL;
    }
};
Book* insert(Book* root, string title, string author, float price) {
    if (root == NULL)
        return new Book(title, author, price);

    if (title < root->title)
        root->left = insert(root->left, title, author, price);
    else
        root->right = insert(root->right, title, author, price);

    return root;
}

Book* search(Book* root, string title) {
    if (root == NULL || root->title == title)
        return root;

    if (title < root->title)
        return search(root->left, title);
    else
        return search(root->right, title);
}

Book* findMin(Book* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}
Book* deleteBook(Book* root, string title) {
    if (root == NULL) return root;

    if (title < root->title)
        root->left = deleteBook(root->left, title);
    else if (title > root->title)
        root->right = deleteBook(root->right, title);
    else {
        if (root->left == NULL) {
            Book* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Book* temp = root->left;
            delete root;
            return temp;
        }

        Book* temp = findMin(root->right);
        root->title = temp->title;
        root->author = temp->author;
        root->price = temp->price;
        root->right = deleteBook(root->right, temp->title);
    }
    return root;
}

void update(Book* root, string title) {
    Book* temp = search(root, title);
    if (temp != NULL) {
        cout << "Enter new author: ";
        cin >> temp->author;
        cout << "Enter new price: ";
        cin >> temp->price;
        cout << "Book updated successfully!\n";
    } else {
        cout << "Book not found!\n";
    }
}

void display(Book* root) {
    if (root != NULL) {
        display(root->left);
        cout << "Title: " << root->title
             << ", Author: " << root->author
             << ", Price: " << root->price << endl;
        display(root->right);
    }
}

int main() {
    Book* root = NULL;
    int choice;
    string title, author;
    float price;

    do {
        cout << "\n--- Online Bookstore Menu ---\n";
        cout << "1. Add Book\n2. Search Book\n3. Delete Book\n4. Update Book\n5. Display Catalog\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin >> title;
                cout << "Enter author: ";
                cin >> author;
                cout << "Enter price: ";
                cin >> price;
                root = insert(root, title, author, price);
                break;

            case 2:
                cout << "Enter title to search: ";
                cin >> title;
                if (search(root, title))
                    cout << "Book found!\n";
                else
                    cout << "Book not found!\n";
                break;

            case 3:
                cout << "Enter title to delete: ";
                cin >> title;
                root = deleteBook(root, title);
                break;

            case 4:
                cout << "Enter title to update: ";
                cin >> title;
                update(root, title);
                break;

            case 5:
                display(root);
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}