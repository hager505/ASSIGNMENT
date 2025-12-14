#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[idx])
                idx = j;
        }
        int t = v[i];
        v[i] = v[idx];
        v[idx] = t;
    }
}

// Bubble Sort
void bubbleSort(vector<int>& v) {

    for (int i = 0; i < v.size() - 1; i++) {

        for (int j = 0; j < v.size() - i - 1; j++) {

            if (v[j] > v[j+1]) {

                int t = v[j];
                v[j] = v[j+1];
                v[j+1] = t;
            }
        }
    }
}
