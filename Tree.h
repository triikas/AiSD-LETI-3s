#ifndef AISD_LETI_3S_TREE_H
#define AISD_LETI_3S_TREE_H
#include <iostream>
#include <ctime>
#include <cstring>
#include <map>

using namespace std;

class Knot {
private:
    char let;
    Knot* father;
    Knot* left = NULL;
    Knot* center = NULL;
    Knot* right = NULL;
public:
    Knot(char let_inp);
    void add_father(Knot* father_inp);
    void add_kid(Knot* kid_inp, int knot_num);
    char get_let() {return let;};
    Knot* get_left() {return left;};
    Knot* get_center() {return center;};
    Knot* get_right() {return right;};
};

class Tree {
private:
    Knot root = NULL;
    string s = "qwertyuioplkjhgfdsazxcvbnm";
public:
    Tree();
    void create_simple_tree();
    void add_knot(char let_inp, Knot* father_inp, int knot_num);
//    void del_knot(char let_inp);
    void show(string prefix, Knot* kn, int kid_num);
    Knot* get_root() {return &root;};
};

Knot::Knot(char let_inp) {
    let = let_inp;
}

void Knot::add_father(Knot *father_inp) {
    father = father_inp;
}

void Knot::add_kid(Knot *kid_inp, int knot_num) {
    if (knot_num == 1) {
        left = kid_inp;
    } else if (knot_num == 2) {
        center = kid_inp;
    } else {
        right = kid_inp;
    }
}

Tree::Tree() {
    root = Knot('a');
}

void Tree::add_knot(char let_inp, Knot *father_inp, int knot_num) {
    for (int i = 0; i < 26; ++i) {
        if (father_inp->get_let() == s[i] && i != 25) {
            Knot kn(s[i+1]);
            kn.add_father(father_inp);
            father_inp->add_kid(&kn, knot_num);
        }
    }
}

void Tree::create_simple_tree() {
    Knot kid('.');
    for (int i = 0; i < 3; ++i) {
        kid = Knot(s[i+1]);
        root.add_kid(&kid, i+1);

    }
    for (int j = 0; j < 3; ++j) {
        kid = Knot(s[4+j]);
        root.get_left()->add_kid(&kid, j+1);
    }
    for (int j = 0; j < 3; ++j) {
        kid = Knot(s[7+j]);
        root.get_left()->add_kid(&kid, j+1);
    }
    for (int j = 0; j < 3; ++j) {
        kid = Knot(s[10+j]);
        root.get_left()->add_kid(&kid, j+1);
    }
    kid = Knot(s[14]);
    root.get_center()->get_center()->add_kid(&kid, 2);
}

void Tree::show(string prefix, Knot* kn, int kid_num) {
    if (kn != NULL){
        cout << prefix;
        if (kid_num != 1) {
            cout << "├──";
        } else {
            cout << "└──";
        }
        cout << kn->get_let() << endl;
        show(prefix + (kid_num == 1 ? "    " : "│   "), kn->get_right(), 3);
        show(prefix + (kid_num == 1 ? "    " : "│   "), kn->get_center(), 2);
        show(prefix + (kid_num == 1 ? "    " : "│   "), kn->get_left(), 1);
    }



}






#endif //AISD_LETI_3S_TREE_H
