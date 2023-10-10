#ifndef MWORD_H
#define MWORD_H
#include <iostream>
#include <set>
using namespace std;
class Mword {
private:
    int S;
    static int n;
    string s = "qwertyuiopasdfghjklzxcvbnm";
public:
    Mword(set<char> inp_set);

    int len() {return n;}
    Mword& invers();
    void show();
    Mword& operator |= (const Mword& mv);
    Mword& operator &= (const Mword& mv);
};


Mword::Mword(set<char> inp_set) {
    S = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (inp_set.find(s[i]) != inp_set.end()) {
            S |= 1 << (s[i] - 'a');
        }
    }
}


Mword& Mword::invers() {
    S = ~S;
    return *this;
}


Mword& Mword::operator|=(const Mword &mv) {
    S |= mv.S;
    return *this;
}


Mword& Mword::operator&=(const Mword &mv) {
    S &= mv.S;
    return *this;
}


void Mword::show() {
    for (int i = 0; i < 27; ++i) {
        if ((S>>i)&1) {
            cout << char (i + 'a') << " ";
        }
    }
}

#endif //MWORD_H
