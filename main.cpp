#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <bitset>
using namespace std;

bitset<27> set_to_bv(set<char> inp_set) {
    string s = "qwertyuioplkjhgfdsazxcvbnm";
    bitset<27> S;
    S.reset();
    for (int i = 0; i < s.length(); i++) {
        if (inp_set.count(s[i]) != 0) S.set(i, true);
    }
    return S;
}

long long universum(set<char> A, set<char> B, set<char> C, set<char> D) {
    bitset<27> E;
    E.reset();
    bitset<27> AA = set_to_bv(A);
    bitset<27> BB = set_to_bv(B);
    bitset<27> CC = set_to_bv(C);
    bitset<27> DD = set_to_bv(D);
    auto t1 = chrono::high_resolution_clock::now();
    E = (AA |= BB |= CC) &= DD.flip();
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
    return duration;
}

set<char> set_generate() {
    srand(rand());
    set<char> S;
    int start = 0;
    int end = 26;
    for (int i = 0; i < (rand() % 27); ++i) {
        char let = 'a' + rand() % 26;
        while (S.count(let) != 0) {
            let = 'a' + rand() % 26;
        }
        S.insert(let);
    }
    return S;
}

long long sett(set<char> A, set<char> B, set<char> C, set<char> D) {
    set<char> E;
    string s = "qwertyuioplkjhgfdsazxcvbnm";
    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 27; i++) {
        if (A.find(s[i]) != A.end() && B.find(s[i]) != B.end() && C.find(s[i]) != C.end() && D.find(s[i]) == D.end()) E.insert(s[i]);
    }
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
    return duration;
}

char* generateCharArray(set<char> charSet) {
    char* array = new char[charSet.size()];
    for (int i = 0; i < strlen(array); i++) {
        array[i] = 'a' + rand() % 26;
    }
    return array;
}

char *findMissingCharacters(char* array1, char* array2, char* array3, char* array4) {
    set<char> charSet;

    for (int i = 0; i < strlen(array1); ++i) {
        charSet.insert(array1[i]);
    }

    for (int i = 0; i < strlen(array2); ++i) {
        charSet.insert(array2[i]);
    }

    for (int i = 0; i < strlen(array3); ++i) {
        charSet.insert(array3[i]);
    }

    for (int i = 0; i < strlen(array4); ++i) {
        charSet.erase(array4[i]);
    }
    
    char* resultArray = new char[charSet.size()];
    int resultIndex = 0;
    for (char ch: charSet) {
        resultArray[resultIndex] = ch;
        resultIndex++;
    }
    return resultArray;
}

struct Node {
    char data;
    Node* next;
};

Node* generateLinkedList(set<char> charSet) {
    Node* head = nullptr;
    Node* current = nullptr;
    for (char ch : charSet) {
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
    return head;
}

Node* findMissingCharacters(Node* list1, Node* list2, Node* list3, Node* list4) {
    set<char> charSet;
    Node* current = list1;
    while (current != nullptr) {
        charSet.insert(current->data);
        current = current->next;
    }

    current = list2;
    while (current != nullptr) {
        charSet.insert(current->data);
        current = current->next;
    }

    current = list3;
    while (current != nullptr) {
        charSet.insert(current->data);
        current = current->next;
    }

    current = list4;
    while (current != nullptr) {
        charSet.erase(current->data);
        current = current->next;
    }
    
    Node *resultHead = nullptr;
    Node *resultCurrent = nullptr;
    for (char ch : charSet) {
        Node* newNode = new Node;
        newNode->data = ch;
        newNode->next = nullptr;
        if (resultHead == nullptr) {
            resultHead = newNode;
            resultCurrent = newNode;
        } else {
            resultCurrent->next = newNode;
            resultCurrent = newNode;
        }
    }

    return resultHead;
}

long long arrayt(set<char> A, set<char> B, set<char> C, set<char> D) {
    char* array1 = generateCharArray(A);
    char* array2 = generateCharArray(B);
    char* array3 = generateCharArray(C);
    char* array4 = generateCharArray(D);

    auto t1 = chrono::high_resolution_clock::now();
    char* missingCharsArray = findMissingCharacters(array1, array2, array3, array4);
    auto t2 = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
    return duration.count();
}

long long listt(set<char> A, set<char> B, set<char> C, set<char> D) {
    Node* list1 = generateLinkedList(A);
    Node* list2 = generateLinkedList(B);
    Node* list3 = generateLinkedList(C);
    Node* list4 = generateLinkedList(D);

    auto t1 = chrono::high_resolution_clock::now();
    Node* missingCharsList = findMissingCharacters(list1, list2, list3, list4);
    auto t2 = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
    return duration.count();
}



int main() {
    setlocale(LC_ALL, "Rus");
    set<char> A = set_generate();
    set<char> B = set_generate();
    set<char> C = set_generate();
    set<char> D = set_generate();
    cout << "Array representation: " << arrayt(A, B, C, D) << " nanoseconds" << endl;
    cout << "Linked list representation: " << listt(A, B, C, D) << " nanoseconds" << endl;
    cout << "Representation through a set: " << sett(A, B, C, D) << " nanoseconds" << endl;
    cout << "Representation through mapping to the universe: " << universum(A, B, C, D) << " nanoseconds" << endl;
    return 0;
}
// норм