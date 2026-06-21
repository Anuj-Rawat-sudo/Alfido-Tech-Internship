#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:

    Node* insert(Node* root, int val) {

        if (root == NULL) {
            cout << "Inserted " << val << endl;
            return new Node(val);
        }

        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    bool search(Node* root, int key) {

        if (root == NULL)
            return false;

        if (root->data == key)
            return true;

        if (key < root->data)
            return search(root->left, key);

        return search(root->right, key);
    }

    Node* findMin(Node* root) {

        while (root->left != NULL)
            root = root->left;

        return root;
    }

    Node* deleteNode(Node* root, int key) {

        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);

        else if (key > root->data)
            root->right = deleteNode(root->right, key);

        else {

            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right =
                deleteNode(root->right, temp->data);
        }

        return root;
    }

    void inorder(Node* root) {

        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {

    cout << "===== BINARY SEARCH TREE IMPLEMENTATION =====\n\n";

    BST tree;
    Node* root = NULL;

    cout << "Performing Insert Operations...\n";

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);

    cout << "\nBST Inorder Traversal:\n";
    tree.inorder(root);

    cout << "\n\nSearching Elements...\n";

    if (tree.search(root, 40))
        cout << "40 Found in BST" << endl;
    else
        cout << "40 Not Found" << endl;

    if (tree.search(root, 100))
        cout << "100 Not Found in BST" << endl;
    else
        cout << "100 Not Found in BST" << endl;

    cout << "\nDeleting Node 30...\n";
    root = tree.deleteNode(root, 30);

    cout << "\nBST After Deletion (Inorder Traversal):\n";
    tree.inorder(root);

    cout << "\n\n===== END OF PROGRAM =====\n";

    return 0;
}