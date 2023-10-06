#include <iostream>

#include "bst.hpp"

int main() {
    
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order traversal of the BST: ";
    bst.print_in_order(); 

    std::cout << "pre-order traversal of the BST: ";
    bst.print_pre_order();

    std::cout << "post-order traversal of the BST: ";
    bst.print_post_order();

    return 0;
}
