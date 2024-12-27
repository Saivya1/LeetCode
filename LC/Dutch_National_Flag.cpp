#include <iostream>
#include <algorithm>
using namespace std;

void dutchNationalFlagSort(int arr[], int size) {
    int lo = 0;
    int hi = size - 1;
    int mid = 0;

    while (mid <= hi) {
        switch (arr[mid]) {
            case 0:
                swap(arr[lo++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[hi--]);
                break;
        }
    }
}

int main() {
    int arr[] = {0, 1, 1, 0, 2, 1, 2, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    dutchNationalFlagSort(arr, size);

    for (int n : arr) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
