// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
5_longest-palindromic-substring LeetCode

Solution: 
    - DP O(n) space
    - expand from center O(1) space
*/

#include <string>
using namespace std;

class Solution {
private:
    void expand(const string& s, int l, int r, int& m, int& left, int& right) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r-l+1 > m) {
                m = r-l+1;
                left = l;
                right = r;
            }
            l -= 1;
            r += 1;
        }
        return;
    }
public:
    string longestPalindrome(string s) {
        size_t n = s.size(); // size_t is unsigned, so n - 1 could be large random number !!!!!!!
        int m = 0;
        int left = 0;
        int right = 0;
        for (auto i = 0; i < n; ++i) {
            // s[i] as center, expand 
            expand(s, i-1, i+1, m, left, right);
            // s[i] as left-of-center, expand 
            expand(s, i, i+1, m, left, right);
        }
        return s.substr(left, right-left+1);
    
        // Nicely-implemented DP solution from leetcode
        //
        // if(s.size()==0) return "";
        // int i = 0, j = 0;
        // int n = s.size();
        // //initialize P[n][n], we only need half of P, and initialize it like: (e.g. : s="abbc")
        // bool P[n][n]={false};
        // for(int x = 0;x<n;x++){
        //     P[x][x]=true;
        //     if(x==n-1) break;
        //     P[x][x+1] = (s[x]==s[x+1]);
        // }
        // //dp 
        // for(int i = n-3; i>=0; --i){
        //     for(int j = i+2;j<n; ++j){
        //         P[i][j] = (P[i+1][j-1] && s[i]==s[j]);     
        //     }
        // }
        // //get maxstr result
        // int max = 0;
        // string maxstr = "";
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(P[i][j]==true and j-i+1>max){
        //             max = j-i+1;
        //             maxstr = s.substr(i,j-i+1);
        //         }
        //     }
        // }
        // return maxstr;    
    }
};