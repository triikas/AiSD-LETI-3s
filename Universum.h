#ifndef UNIVERSUM_H
#define UNIVERSUM_H
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
class Universum {
private:
    static int n;
    string s = "qwertyuioplkjhgfdsazxcvbnm";
    bitset<27> S;
public:
    Universum(set<char> inp_set);

    int len() {return n;}
    Universum& invers();
    void show();
    Universum& operator |= (const Universum& un);
    Universum& operator &= (const Universum& un);

};


Universum& Universum::operator|=(const Universum& un) {
    S = S |= un.S;
    return *this;
}


Universum& Universum::operator&=(const Universum& un) {
    S = S &= un.S;
    return *this;
}


void Universum::show() {
    for (int i = 0; i < 27; i++) {
        if (S[i] == 1) {
            cout << s[i] << " ";
        }
    }
//    cout << endl;
}


Universum::Universum(set<char> inp_set) {
    S.reset();
    for (int i = 0; i < s.length(); i++) {
        if (inp_set.count(s[i]) != 0) S.set(i, true);
    }
//    n = inp_set.size();
}


Universum& Universum::invers() {
    S.flip();
    return *this;
}


#endif
