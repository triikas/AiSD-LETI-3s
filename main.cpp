#include <iostream>
#include <set>
using namespace std;

set<int> set_generate() {
    set<int> S;
    int start = 0;
    int end = 600;
    for (int i = 0; i < 200; ++i) S.insert(rand() % (end - start + 1) + start);
    return S;
}

set<int> e_create() {
    set<int> E;

    return E;
}

int main() {
    set<int> A = set_generate();
    set<int> B = set_generate();
    set<int> C = set_generate();
    set<int> D = set_generate();
    for (int n : A)
        cout << n << "\t";
    cout << endl;
    return 0;
}
