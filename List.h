#ifndef LIST_H
#define LIST_H
#include <set>
#include <iostream>

struct Node {
    char data;
    Node* next;
};

class List {
    private:
        Node *head;
    public:
        List() = default;
        List(std::set<char> s);
        List(Node *new_head);
        Node *getList() const { return this->head; }
        List findMissingCharacters(List List2, List List3, List List4);
        void SetList(Node *new_head);
        void ShowList();

        
};

List::List(std::set<char> charSet) {
    Node* head = nullptr;
    Node* current = nullptr;
    for (auto ch : charSet) {
        Node* newNode = new Node;
        newNode->data = ch;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    SetList(head);
}

List::List(Node *new_head) {
    SetList(new_head);
}

void List::SetList(Node *new_head) {
    this->head = new_head;
}

bool contains(Node* list, int value) {
    Node* current = list;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

List List::findMissingCharacters(List list2, List list3, List list4) {
    Node* fifthList = nullptr;

    Node* current1 = this->head;
    Node* current2 = list2.head;
    Node* current3 = list3.head;

    while (current1 != nullptr || current2 != nullptr || current3 != nullptr) {
        if (current1 != nullptr && !contains(list4.head, current1->data)) {
            Node* newNode = new Node;
            newNode->data = current1->data;
            newNode->next = fifthList;
            fifthList = newNode;
        }
        if (current2 != nullptr && !contains(list4.head, current2->data)) {
            Node* newNode = new Node;
            newNode->data = current2->data;
            newNode->next = fifthList;
            fifthList = newNode;
        }
        if (current3 != nullptr && !contains(list4.head, current3->data)) {
            Node* newNode = new Node;
            newNode->data = current3->data;
            newNode->next = fifthList;
            fifthList = newNode;
        }

        if (current1 != nullptr) current1 = current1->next;
        if (current2 != nullptr) current2 = current2->next;
        if (current3 != nullptr) current3 = current3->next;

    }
    List new_list{fifthList};
    return new_list;
}

void List::ShowList() {
    Node *head = this->head;
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

#endif