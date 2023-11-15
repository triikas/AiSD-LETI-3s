#include <iostream>
#include "Tree.h"
#include <map>
#include <vector>

using namespace std;

//char find_knot_out(Tree* tr) {
//    Knot* kn = tr->get_root();
//    while (kn->get_left() != NULL || kn->get_right() != NULL || kn->get_center() != NULL) {
//        if (kn->get_right() != NULL) {
//            kn = kn->get_right();
//        } else if ()
//    }
//}
int num_RL = 0;
//void FRL_in(vector<char> v, Tree* tr, Knot* kn) {
void FRL_in(Knot* kn) {
    if (kn != NULL) {
//        v.push_back(kn->get_let());
        if (kn->get_left() == NULL && kn->get_right() == NULL && kn->get_center() == NULL) num_RL++;
        FRL_in(kn->get_left());
        cout << kn->get_let();
        FRL_in(kn->get_center());
        FRL_in(kn->get_right());
    }
}

//void FRL(Tree* tr) {
//    Knot* kn = tr->get_root();
//    vector<char> v = {kn->get_let()};

//}

int main() {
    Tree tr;
    tr.create_simple_tree();
    tr.show("", tr.get_root(), 1);
//    num_RL = 0;
//    FRL_in(tr.get_root());
//    cout << "  " << num_RL << endl;
    return 0;
}