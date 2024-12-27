
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(string &forth)
{
    // Create a string of the same size as forth, initialized to '\0'
    string rev(forth.size(), '\0');

    reverse_copy(forth.begin(), forth.end(), rev.begin());

    unordered_map<char, char> opposite = {
        {'N', 'S'},
        {'S', 'N'},
        {'E', 'W'},
        {'W', 'E'}};

    string res;
    char last = 'N';

    for (char dir : rev)
    {
        char opp = opposite[dir];
        if (opp != last)
        {
            res += opp;
            last = opp;
        }
        else
        {
            res += (opp == 'N' || opp == 'S') ? 'E' : 'N';
            last = (opp == 'N' || opp == 'S') ? 'E' : 'N';
        }
    }

    return res;
}

// Example usage:
#include <iostream>
int main()
{
    string forth = "NEENWN";
    string shortestPathBack = solution(forth);
    cout << "Shortest path back home: " << shortestPathBack << endl;
    return 0;
}
