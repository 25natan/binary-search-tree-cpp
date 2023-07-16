#include <iostream>
enum class Travers {
    InOrder,
    PreOrder,
    PostOrder
};
template <typename T>
class Bst {
public:
    Bst() {};
    Bst(const std::initializer_list<T>& dataList) {
        for(const T& data: dataList)
            insert(data);
    }
    struct Node
    {
        T _data;
        Node *_right, *_left;
        Node() = delete;
        Node(const T& data): _data(data), _right(nullptr), _left(nullptr) {}
    };
    Bst& insert(const T& data) {
        Node** current = &_root;
        while(*current)
            current = data <= (*current)->_data ? &((*current)->_left) : &((*current)->_right);
        *current = new Node(data);
        return *this;
    }
    Bst& insert(const std::initializer_list<T>& dataList) {
        for(const T& data: dataList)
            insert(data);
        return *this;
    }
    Bst& printData(Travers travers) {
        switch (travers)
        {
        case Travers::InOrder:
            printDataInOrder(_root);
            break;
        case Travers::PreOrder:
            printDataPreOrder(_root);
            break;
        case Travers::PostOrder:
            printDataPostOrder(_root);
            break;
        }
        std::cout << std::endl;
        return *this;
    }
    Node *getRoot() {
        return _root;
    }
    bool find(const T& data) {
        return find(_root, data);
    }
    ~Bst() {
        freeMemory(_root);
    }
private:
    Node* _root = nullptr;
    bool find(Node *node, const T& data) {
        return node && (node->_data == data || find(node->_left, data) || find(node->_right, data));
    }
    void printDataInOrder(Node *node) {
        if(!node)
            return;
        printDataInOrder(node->_left);
        std::cout << node->_data << ' ';
        printDataInOrder(node->_right);
    }
    void printDataPreOrder(Node *node) {
        if(!node)
            return;
        std::cout << node->_data << ' ';
        printDataPreOrder(node->_left);
        printDataPreOrder(node->_right);
    }
    void printDataPostOrder(Node *node) {
        if(!node)
            return;
        printDataPostOrder(node->_left);
        printDataPostOrder(node->_right);
        std::cout << node->_data << ' ';
    }
    void freeMemory(Node *node) {
        if(!node)
            return;
        freeMemory(node->_left);
        freeMemory(node->_right);
        delete node;
    }
};
