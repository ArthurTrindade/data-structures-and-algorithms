// #include <iostream>
// #include <memory>

// template <typename T>
// class TreeNode {
// public:
//     T data;
//     std::shared_ptr<TreeNode<T>> left;
//     std::shared_ptr<TreeNode<T>> right;

//     TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
// };

// template <typename T>
// class BinarySearchTree {
// public:
//     BinarySearchTree() : root(nullptr) {}

//     void insert(T val) {
//         root = insertRecursive(root, val);
//     }

//     void displayInOrder() {
//         inOrderTraversal(root);
//         std::cout << std::endl;
//     }

// private:
//     std::shared_ptr<TreeNode<T>> root;

//     std::shared_ptr<TreeNode<T>> insertRecursive(std::shared_ptr<TreeNode<T>> node, T val) {
//         if (!node) {
//             return std::make_shared<TreeNode<T>>(val);
//         }

//         if (val < node->data) {
//             node->left = insertRecursive(node->left, val);
//         } else if (val > node->data) {
//             node->right = insertRecursive(node->right, val);
//         }

//         return node;
//     }

//     void inOrderTraversal(std::shared_ptr<TreeNode<T>> node) {
//         if (node) {
//             inOrderTraversal(node->left);
//             std::cout << node->data << " ";
//             inOrderTraversal(node->right);
//         }
//     }
// };

// int main() {
//     BinarySearchTree<int> bst;
//     bst.insert(50);
//     bst.insert(30);
//     bst.insert(70);
//     bst.insert(20);
//     bst.insert(40);
//     bst.insert(60);
//     bst.insert(80);

//     std::cout << "In-order traversal of the BST: ";
//     bst.displayInOrder(); // Output: 20 30 40 50 60 70 80

//     return 0;
// }
