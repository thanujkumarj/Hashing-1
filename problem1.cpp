// Time Complexity : O(nk)
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : Yes
// We use a map with key as double and value as vector of string, we make use of prime numbers and make a key from them.
// We push the string in vector with the help of key. we get all anagrams into a vector.
// at last we store them into a vector of vector of strings and return it.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<double,vector<string>> map;
        for(int i =0;i<strs.size();i++)
        {
            string s = strs[i];
            double key = makeKey(s);
            map[key].push_back(s);
        }      
        for(auto v: map)
        {
            result.push_back(v.second);
        }
        return result;
    }
    double makeKey(string s)
    {
        vector<char>v = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        double result = 1;
        for(int i =0;i<s.size();i++)
        {
            char ch = s[i];
            result = result * v[ch - 'a'];
        }
        return result;
    }

};