#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to preprocess the pattern and create the longest prefix suffix (lps) array
void computeLPSArray(const string &pattern, vector<int> &lps)
{
    int m = pattern.length();
    int length = 0;
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm to search for occurrences of the pattern in the text
void KMPSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    // Create lps[] that will hold the longest prefix suffix values for the pattern
    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    return 0;
}
