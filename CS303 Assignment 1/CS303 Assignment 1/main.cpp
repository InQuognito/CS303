#include "main.h"

int main() {
    array_manipulator arrayManipulator;
    arrayManipulator.read_file("input.txt");
    arrayManipulator.display();

    int searchValue = 5;
    int index = arrayManipulator.find(searchValue);
    if (index != -1) {
        cout << "Value " << searchValue << " found at index " << index << endl;
    }
    else {
        cout << "Value " << searchValue << " not found in the array." << endl;
    }

    int modifyIndex = 2;
    int newValue = 10;
    int oldValue = arrayManipulator.modify(modifyIndex, newValue);
    if (oldValue != -1) {
        cout << "Modified value at index " << modifyIndex << ". Old value: " << oldValue << ", New value: " << newValue << endl;
    }
    else {
        cout << "Invalid index." << endl;
    }

    int newValueToAdd = 20;
    arrayManipulator.add(newValueToAdd);
    arrayManipulator.display();

    int replaceOrRemoveIndex = 1;
    arrayManipulator.replace_or_remove(replaceOrRemoveIndex);
    arrayManipulator.display();

    return 0;
}
