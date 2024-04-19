#include <iostream>

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end of the list
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert a new node at a specific index
    void insertAtIndex(int index, int value) {
        if (index < 0) {
            std::cerr << "Invalid index." << std::endl;
            return;
        }
        if (index == 0) {
            insert(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cerr << "Index out of range." << std::endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node with given data
    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cerr << "Node with value " << value << " not found." << std::endl;
            return;
        }
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }

    // Function to update the value of a node at a specific index
    void update(int index, int value) {
        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cerr << "Index out of range." << std::endl;
            return;
        }
        temp->data = value;
    }

    // Function to get the value at a specific index
    int get(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cerr << "Index out of range." << std::endl;
            return -1; // Assuming -1 represents an invalid value
        }
        return temp->data;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Destructor to release memory
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insertAtTail(4);
    list.insertAtIndex(2, 5);
    list.display(); // Output: 3 2 5 1 4
    list.deleteNode(2);
    list.update(1, 6);
    std::cout << "Value at index 1: " << list.get(1) << std::endl; // Output: Value at index 1: 6
    list.display(); // Output: 3 6 5 1 4

    return 0;
}
