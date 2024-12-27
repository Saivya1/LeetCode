#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {0, -1};
    sort(nums.begin(), nums.end());
    for (int n : nums)
    {
        cout << n;
    }
}