#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;
};

class TBT {
    Node* root;

public:
    TBT() {
        root = NULL;
    }

    Node* createNode(int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->left = temp->right = NULL;
        temp->lthread = temp->rthread = true;
        return temp;
    }
    void insert(int data) {
        Node* ptr = root;
        Node* parent = NULL;

        while (ptr != NULL) {
            if (data == ptr->data) {
                cout << "Duplicate not allowed\n";
                return;
            }
            parent = ptr;

            if (data < ptr->data) {
                if (!ptr->lthread)
                    ptr = ptr->left;
                else
                    break;
            } else {
                if (!ptr->rthread)
                    ptr = ptr->right;
                else
                    break;
            }
        }

        Node* temp = createNode(data);

        if (parent == NULL) {
            root = temp;
            temp->left = temp->right = NULL;
        }
        else if (data < parent->data) {
            temp->left = parent->left;
            temp->right = parent;
            parent->lthread = false;
            parent->left = temp;
        }
        else {
            temp->left = parent;
            temp->right = parent->right;
            parent->rthread = false;
            parent->right = temp;
        }
    }
    void inorder() {
        Node* ptr = root;

        if (ptr == NULL) {
            cout << "Tree is empty\n";
            return;
        }
        while (!ptr->lthread)
            ptr = ptr->left;

        while (ptr != NULL) {
            cout << ptr->data << " ";

            if (ptr->rthread)
                ptr = ptr->right;
            else {
                ptr = ptr->right;
                while (ptr != NULL && !ptr->lthread)
                    ptr = ptr->left;
            }
        }
        cout << endl;
    }
    void search(int key) {
        Node* ptr = root;

        while (ptr != NULL) {
            if (key == ptr->data) {
                cout << "Element found\n";
                return;
            }

            if (key < ptr->data) {
                if (!ptr->lthread)
                    ptr = ptr->left;
                else
                    break;
            } else {
                if (!ptr->rthread)
                    ptr = ptr->right;
                else
                    break;
            }
        }
        cout << "Element not found\n";
    }
};

int main() {
    TBT t;
    int choice, val;

    do {
        cout << "\n Threaded Binary Tree\n";
        cout << "1. Insert\n2. Inorder Traversal\n3. Search\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                t.insert(val);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                t.inorder();
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                t.search(val);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}