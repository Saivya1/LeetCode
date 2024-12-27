#include <iostream>

int sum(int arr[], int max){
    int tot=0;
    for (int i=0;i<max;i++){
        tot+=arr[i];
    }
    return tot;
}

int main(){
    int max =0;

    std::cout << "Enter the size of the array : ";
    std::cin >> max;
    int * arr = new int[max];

    for(int i=0;i<max;i++){
        std::cout << "Enter the the element  :" << "\n";
        std:: cin >> arr[i] ; 
    }

    for(int j=0 ; j<max;j++){
        std::cout << arr[j];
    }

    std::cout << "The sum of the array is : " << sum(arr,max);

}