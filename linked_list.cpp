#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        cout << "Inserted " << val << " into Linked List" << endl;
    }

    // Search
    bool search(int key) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == key)
                return true;

            temp = temp->next;
        }

        return false;
    }

    // Delete
    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << "Deleted " << key << endl;
            return;
        }

        Node* curr = head;

        while (curr->next != NULL &&
               curr->next->data != key) {
            curr = curr->next;
        }

        if (curr->next == NULL) {
            cout << key << " not found!" << endl;
            return;
        }

        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        cout << "Deleted " << key << endl;
    }

    // Display
    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {

    cout << "===== LINKED LIST IMPLEMENTATION =====\n\n";

    LinkedList list;

    cout << "Performing Insert Operations...\n";
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "\nCurrent Linked List:\n";
    list.display();

    cout << "\nSearching Elements...\n";

    if (list.search(20))
        cout << "20 Found in Linked List" << endl;
    else
        cout << "20 Not Found" << endl;

    if (list.search(100))
        cout << "100 Found in Linked List" << endl;
    else
        cout << "100 Not Found" << endl;

    cout << "\nDeleting Element 20...\n";
    list.deleteNode(20);

    cout << "\nLinked List After Deletion:\n";
    list.display();

    cout << "\n===== END OF PROGRAM =====\n";

    return 0;
}