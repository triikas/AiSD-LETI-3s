#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <bitset>
#include "Universum.h"
#include "Mword.h"
//#include "List.h"
//#include "Array.h"
using namespace std;


set<char> set_generate() {
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


int main() {
//    {
        setlocale(LC_ALL, "Rus");
        srand(static_cast<unsigned>(time(nullptr)));
        set<char> A = set_generate();
        set<char> B = set_generate();
        set<char> C = set_generate();
        set<char> D = set_generate();
        set<char> E;
        string s = "qwertyuioplkjhgfdsazxcvbnm";
        for (int i = 0; i < 27; i++) {
            if ((A.find(s[i]) != A.end() || B.find(s[i]) != B.end() || C.find(s[i]) != C.end()) && D.find(s[i]) == D.end()) E.insert(s[i]);
        }
        cout << "Set A:  ";
         for(char ch : A) {
             cout << ch << " ";
         }
         cout << endl;
         cout << "Set B:  ";
         for(char ch : B) {
             cout << ch << " ";
         }
         cout << endl;
         cout << "Set C:  ";
         for(char ch : C) {
             cout << ch << " ";
         }
         cout << endl;
         cout << "Set D:  ";
         for(char ch : D) {
             cout << ch << " ";
         }
         cout << endl;
         cout << "Result: ";

         for (char ch : E) {
             cout << ch << " ";
         }
        cout << endl;
        cout << endl;

//        Array array1(A);
//        Array array2(B);
//        Array array3(C);
//        Array array4(D);
//        auto t1 = chrono::high_resolution_clock::now();
//        array1.ShowArray();
//        auto t2 = chrono::high_resolution_clock::now();
//        cout << "\nArray print: " << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microseconds" << endl;
//
//        //     auto t1 = chrono::high_resolution_clock::now();
//        //     array1.findMissingCharacters(array2, array3, array4);
//        //     auto t2 = chrono::high_resolution_clock::now();
//        //     cout << "Array representation: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
//
//
//        List list1(A);
//        List list2{B};
//        List list3{C};
//        List list4{D};
//
//        t1 = chrono::high_resolution_clock::now();
//        list1.ShowList();
//        t2 = chrono::high_resolution_clock::now();
//
//        cout << "\nLinked list print: " << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microseconds" << endl;


        Universum universum1(A);
        Universum universum2(B);
        Universum universum3(C);
        Universum universum4(D);

        auto t1 = chrono::high_resolution_clock::now();
        universum3.show();
        auto t2 = chrono::high_resolution_clock::now();
        cout << "\nUniversum print: " << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microseconds";

        t1 = chrono::high_resolution_clock::now();
        Universum universum5 = (universum1 |= universum2 |= universum3) &= universum4.invers();
        t2 = chrono::high_resolution_clock::now();
        cout << "\nUniversum algorithm: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
        cout <<endl;

        Mword mword1(A);
        Mword mword2(B);
        Mword mword3(C);
        Mword mword4(D);

        t1 = chrono::high_resolution_clock::now();
        mword4.show();
        t2 = chrono::high_resolution_clock::now();
        cout << "\nMword print: " << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microseconds";

        t1 = chrono::high_resolution_clock::now();
        Mword mword5 = (mword1 |= mword2 |= mword3) &= mword4.invers();
        t2 = chrono::high_resolution_clock::now();
        cout << "\nMword algorithm: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;


        getchar();
         return 0;
//    }(cin.get());
}