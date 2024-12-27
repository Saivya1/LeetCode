#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> &arr){

    int size= arr.size();
    int temp;
    for(int i = 0;i<size/2;i++){
        temp=*(arr.begin()+i);
        *(arr.begin()+i)=*(arr.end()-(i+1));
        *(arr.end()-(i+1))=temp;

    }

    return arr;

}

int main(){
    vector<int> arr{1,2,3,4,5};
    vector <int> reversedArr;
    reversedArr=reverse(arr);


    for(int x: reversedArr){
        cout << x;
    }

    return 0;
}

//                                                      Another method


/*
// Iterative C++ program to reverse an array
#include <bits/stdc++.h>;
using namespace std;


void reverseArray(int arr[], int start, int end)
{
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };

    int n = sizeof(arr) / sizeof(arr[0]);

    // To print original array
    printArray(arr, n);

    // Function calling
    reverseArray(arr, 0, n - 1);

    cout << "Reversed array is" << endl;

    // To print the Reversed array
    printArray(arr, n);

    return 0;
}



another

int main()
{
    int originalArray[] = { 1, 2, 3, 4, 5 };
    int length
        = sizeof(originalArray) / sizeof(originalArray[0]);

    // Using inbuilt method in C++
    std::reverse(originalArray,originalArray+size);

    // Print the reversed array
    for (int i = 0; i < length; i++) {
        std::cout << originalArray[i] << " ";
    }

    return 0;
}
    */