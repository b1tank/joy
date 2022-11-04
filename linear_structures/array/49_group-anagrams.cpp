// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
49_group-anagrams LeetCode

Solution: 
    - 
*/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    void counting_sort(string& str) {
        vector<int> count(26, 0);
        for (auto c : str) {
            ++count[c-'a'];
        }
        int j = 0;
        for (int i = 0; i < 26; ++i) {
            while (count[i] != 0) {
                str[j++] = 'a' + i;
                --count[i];
            }
        }
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> um;
        for (auto s : strs) {
            string origin = s;
            counting_sort(s);
            if (um.find(s) == um.end()) {
                vector<string> vs{origin};
                um[s] = vs;
            } else {
                um[s].push_back(origin);
            }
        }
        for (auto it : um) {
            res.push_back(it.second);
        }
        return res;
    }
};