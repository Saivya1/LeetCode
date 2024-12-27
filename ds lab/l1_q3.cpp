#include <iostream>

int main(){
    int arr[]={2,1,5,6,3,7,8,9};
    int maxInd=0;

    for (int n=0;n<8;n++){
        maxInd = arr[n]>arr[maxInd] ? n : maxInd;
    }

    arr[maxInd] = 0 ;

    maxInd = 0;

    for (int n : arr){
        maxInd = arr[n]>arr[maxInd] ? n : maxInd;
    }

    std::cout << arr[maxInd];


}