/* Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".


Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2" */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class TimeMap
{
public:
    unordered_map<string, vector<pair<string, int>>> um;

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        um[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        if (um.find(key) == um.end())
            return "";
        if (timestamp < um[key][0].second)
            return "";
        int l = 0;
        int r = um[key].size() - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (um[key][mid].second == timestamp)
            {
                return um[key][mid].first;
            }
            else if (um[key][mid].second > timestamp)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return um[key][r].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */