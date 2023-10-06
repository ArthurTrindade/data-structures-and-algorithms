#include <iostream>
#include <memory>

template<typename T>
class Node {
public:
    T data;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;

    Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert_recursive(const T& data) {
        root = recursive(root, data);
        return;
    }

    void insert(const T& data) {
        interactive(data);
        return;
    }

    void print_in_order() {
        in_order(root);
        std::cout << '\n';
    }

    void print_pre_order() {
        pre_order(root);
        std::cout << '\n';
    }

    void print_post_order() {
        post_order(root);
        std::cout << '\n';
    }

private:
    std::shared_ptr<Node<T>> root;

    void interactive(const T& data) {

        auto new_node = std::make_shared<Node<T>>(data);

        auto aux = root;
        std::shared_ptr<Node<T>> prev;

        while (aux) {
            prev = aux;
            if (data < aux->data) {
                aux = aux->left;
            } else {
                aux = aux->right;
            }
        }

        if (!prev) {
            root = new_node;
        } else if (data < prev->data) {
            prev->left = new_node;
        } else {
            prev->right = new_node;
        }
    }

    std::shared_ptr<Node<T>> 
    recursive(std::shared_ptr<Node<T>> root, const T& data) {
        if (!root) {
            return std::make_shared<Node<T>>(data);
        } else if (data < root->data) {
            root->left = insert_recursive(root->left, data);
        } else if (data > root->data) {
            root->right = insert_recursive(root->right, data);
        }

        return root;
    }

    void pre_order(std::shared_ptr<Node<T>> root) {
        if (root != nullptr) {
            std::cout << root->data << ' ';
            pre_order(root->left);
            pre_order(root->right);
        }
    }

    void in_order(std::shared_ptr<Node<T>> root) {
        if (root != nullptr) {
            in_order(root->left);
            std::cout << root->data << ' ';
            in_order(root->right);
        }
    }

    void post_order(std::shared_ptr<Node<T>> root) {
        if (root != nullptr) {
            post_order(root->left);
            post_order(root->right);
            std::cout << root->data << ' ';
        }
    }

};
