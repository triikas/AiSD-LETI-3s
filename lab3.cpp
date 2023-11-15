#include <iostream>
#include "Tree.h"
#include <map>
#include <vector>
#include <chrono>

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
        if (kn->get_left() == NULL && kn->get_right() == NULL && kn->get_center() == NULL && kn->get_father()->get_right() == kn) num_RL++;
        FRL_in(kn->get_left());
        cout << kn->get_let() << " ";
        FRL_in(kn->get_center());
        FRL_in(kn->get_right());
    }
}

//void FRL(Tree* tr) {
vector<string> Split(const string& str, const char& delimiter) {
    vector<string> result; // контейнер для хранения подстрок

    stringstream ss(str); // создаем поток из строки
    string substring; // временная переменная для хранения подстрок

    while (getline(ss, substring, delimiter)) { // пока есть подстроки
        result.push_back(substring); // добавляем их в контейнер
    }

    return result; // возвращаем контейнер со всеми подстроками
}
//    Knot* kn = tr->get_root();
//    vector<char> v = {kn->get_let()};
void GBH(Tree* tr, Knot* kkn) {
    string inp;
    vector<string> v;
    while (inp != "out") {
        cin >> inp;
        if (inp == "show") {
            tr->show("", tr->get_root(), 1);
        } else {
            v = Split(inp, '-');
            if (v[0] == "root" && v.size() > 1) {
                bool add = false;
//                Knot* kkn = tr->get_root();
                for (int i = 1; i < v.size(); ++i) {
                    if (v[i] == "r" && !add) {
                        kkn = kkn->get_right();
                    } else if (v[i] == "c" && !add) {
                        kkn = kkn->get_center();
                    } else if (v[i] == "l" && !add) {
                        kkn = kkn->get_left();
                    } else if (v[i] == "add" && !add) {
                        add = true;
                    } else if (v[i] == "r" && add) {
                        Knot* kon = new Knot(v[i+1][0]);
                        kkn->add_kid(kon, 3);
                        kon->add_father(kkn);
                        break;
                    } else if (v[i] == "l" && add) {
                        Knot* kon = new Knot(v[i+1][0]);
                        kkn->add_kid(kon, 1);
                        kon->add_father(kkn);
                        break;
                    } else if (v[i] == "c" && add) {
                        Knot* kon = new Knot(v[i+1][0]);
                        kkn->add_kid(kon, 2);
                        kon->add_father(kkn);
                        break;
                    }
                }
            }

        }
    }
}


//}



int main() {
    Tree tr;
//    tr.create_simple_tree();
    string inp;
    cout << "do you want to generate tree by hand?" << endl;
    cin >> inp;
    if (inp == "y") {
        GBH(&tr, tr.get_root());
    } else {
        tr.create_random_tree();
        tr.show("", tr.get_root(), 1);
        num_RL = 0;
        cout << endl << "infix bypass ";
        auto t1 = chrono::high_resolution_clock::now();
        FRL_in(tr.get_root());
        auto t2 = chrono::high_resolution_clock::now();
        cout << endl << "result:  " << num_RL << endl;
        cout << "result time: " << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microseconds" << endl;
    }

    return 0;
}