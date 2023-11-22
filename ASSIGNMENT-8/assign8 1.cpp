#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* root, int key);
    Node* remove(Node* root, int key);
    void inorderTraversal(Node* root);
    void preorderTraversal(Node* root);
    void postorderTraversal(Node* root);
    Node* findMin(Node* root);
public:
    BinarySearchTree();
    void insert(int key);
    void remove(int key);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
};

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

Node* BinarySearchTree::insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

Node* BinarySearchTree::remove(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = remove(root->left, key);
    } else if (key > root->key) {
        root->right = remove(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = remove(root->right, temp->key);
    }

    return root;
}

void BinarySearchTree::inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

void BinarySearchTree::preorderTraversal(Node* root) {
    if (root != nullptr) {
        std::cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void BinarySearchTree::postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->key << " ";
    }
}

Node* BinarySearchTree::findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

void BinarySearchTree::insert(int key) {
    root = insert(root, key);
}

void BinarySearchTree::remove(int key) {
    root = remove(root, key);
}

void BinarySearchTree::inorderTraversal() {
    inorderTraversal(root);
    std::cout << std::endl;
}

void BinarySearchTree::preorderTraversal() {
    preorderTraversal(root);
    std::cout << std::endl;
}

void BinarySearchTree::postorderTraversal() {
    postorderTraversal(root);
    std::cout << std::endl;
}

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order traversal: ";
    bst.inorderTraversal();

    std::cout << "Pre-order traversal: ";
    bst.preorderTraversal();

    std::cout << "Post-order traversal: ";
    bst.postorderTraversal();

    bst.remove(20);
    std::cout << "In-order traversal after removing 20: ";
    bst.inorderTraversal();

    return 0;
}
