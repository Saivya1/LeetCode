#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    vector<int> arr;
    unordered_set<int> us;

    int n;

    cout << "Enter the number of elements in the array : ";
    cin >> n;
    cout << " \n Enter the numbers : ";

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (us.find(arr[i]) == us.end())
        {
            us.insert(arr[i]);
        }
    }

    cout << "\n"
         << us.size();
}