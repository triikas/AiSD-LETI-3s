#ifndef ARRAY_H
#define ARRAY_H
#include <set>
#include <iostream>


class Array {
private:
    char *array;
public:
    Array() = default;
    Array(std::set<char> s);
    Array(char *new_array);
    char *getArray() const { return this->array; }
    Array findMissingCharacters(Array array2, Array array3, Array array4);
    void SetArray(char *new_array);
    void ShowArray();


};

Array::Array(std::set<char> charSet) {
    char* array = new char[charSet.size() + 1];
    int ind = 0;
    for (char ch : charSet) {
        array[ind++] = ch;
    }
    SetArray(array);
}

Array::Array(char *new_array) {
    SetArray(new_array);
}

void Array::SetArray(char *new_array) {
    this->array = new_array;
}


bool contains(char* array, char value) {
    for (int i = 0; i < strlen(array); ++i) {
        if (value == array[i]) {
            return true;
        }
    }
    return false;
}


Array Array::findMissingCharacters(Array array2, Array array3, Array array4) {
    char* newArray = (char*)calloc(26, sizeof(char));
    int ind = 0;
    for (int i = 0; i < strlen(this->array); ++i) {
        if (!contains(newArray, this->array[i]) && !contains(array4.array, this->array[i])) {
            newArray[ind] = this->array[i];
            ind++;
        }
    }
    for (int i = 0; i < strlen(array2.array); ++i) {
        if (!contains(newArray, array2.array[i]) && !contains(array4.array, array2.array[i])) {
            newArray[ind] = array2.array[i];
            ind++;
        }
    }
    for (int i = 0; i < strlen(array3.array); ++i) {
        if (!contains(newArray, array3.array[i]) && !contains(array3.array, this->array[i])) {
            newArray[ind] = array3.array[i];
            ind++;
        }
    }
    Array new_array{newArray};
    return new_array;
}

void Array::ShowArray() {
    char *array = this->array;
    for(int i = 0; i < strlen(array); i++) {
        std::cout << array[i] << " ";
    }
}

#endif