#include <iostream>

int lsearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int size;
    int target;

    std::cout << "Enter the size of the array : ";
    std::cin >> size;

    int* arr = new int[size];
    
    for(int i=0;i<size;i++){
        std::cout << "Enter the the element  :" << "\n";
        std:: cin >> arr[i] ; 
    }

    

    std::cout << "Enter the target element : ";
    std::cin >> target;

    for(int j=0 ; j<size;j++){
        std::cout << arr[j];
    }

    std::cout << "The element is in : " << lsearch(arr,size,target) << " Index";
}