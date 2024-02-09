#pragma once

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

class array_manipulator {
private:
    int arr[MAX_SIZE];
    int size;

public:
    array_manipulator() {
        size = 0;
    }

    // Read data from file into array
    void read_file(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Unable to open file: " << filename << endl;
            return;
        }

        size = 0;
        while (inputFile >> arr[size] && size < MAX_SIZE) {
            size++;
        }
        inputFile.close();
    }

    // Check for integer exists in the array and return the index of its first appearance
    int find(int value) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // Modifies the value of an integer at a given index and return the old value
    int modify(int index, int newValue) {
        if (index >= 0 && index < size) {
            int oldValue = arr[index];
            arr[index] = newValue;
            return oldValue;
        }
        return -1;
    }

    // Adds a new integer to the end of the array
    void add(int value) {
        if (size < MAX_SIZE) {
            arr[size] = value;
            size++;
        }
    }

    // Replace the value at the provided index with 0 or remove it
    void replace_or_remove(int index, bool remove = false) {
        if (index >= 0 && index < size) {
            if (remove) {
                for (int i = index; i < size - 1; ++i) {
                    arr[i] = arr[i + 1];
                }
                size--;
            }
            else {
                arr[index] = 0;
            }
        }
    }

    // Displays the array
    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
