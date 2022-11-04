// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
273_integer-to-english-words LeetCode

Solution: 
    - "hashmap" of integer -> vector
    - recursion to solve (with proper base case)
    - edge cases
        - handling zero
        - handling zero Thousands/Millions
        - handling trailing whitespaces
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    vector<string> UNDER20 {
        "",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen"
    };
    vector<string> TENS {
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety"
    };
    vector<string> THOUSANDS {
        "",
        "Thousand",
        "Million",
        "Billion"
    };
    string trimEnd(string r) {
        for (int i = r.length()-1; i >= 0; i--) {
            if (r[i] != ' ') return r.substr(0, i+1);
        }
        return "";
    }
    string helper(int n) {
        string ret;
        if (n < 20) {
            ret = UNDER20[n];
        } else if (n < 100) {
            ret = TENS[n/10-2] + " " + helper(n%10);
        } else if (n < 1000) {
            ret = UNDER20[n/100] + " Hundred " + helper(n%100);
        } else {
            int i = 0;
            while (n > 0) {
                if (n % 1000 != 0) { // skip empty "Thousand"/"Million"
                    ret = helper(n%1000) + " " + THOUSANDS[i] + " " + ret;
                }
                n /= 1000;
                i++;
            }
        }
        return trimEnd(ret); // make sure no trailing whitespaces; need to append " " after help(n%1000)
    }
public:
    string numberToWords(int num) {
        // 1.234.567.891
        // One Billion
        // Two Hundred Thirty Four Million
        // Five Hundred Sixty Seven Thousand
        // Eight Hundred Ninety One
        
        return num ? helper(num) : "Zero";
        
        // if (num == 0) return "Zero";
        // 
        // unordered_map<int, string> um0 {
        //     {1, "One"},
        //     {2, "Two"},
        //     {3, "Three"},
        //     {4, "Four"},
        //     {5, "Five"},
        //     {6, "Six"},
        //     {7, "Seven"},
        //     {8, "Eight"},
        //     {9, "Nine"}
        // };
        // unordered_map<int, string> um1 {
        //     {0, "Ten"},
        //     {1, "Eleven"},
        //     {2, "Twelve"},
        //     {3, "Thirteen"},
        //     {4, "Fourteen"},
        //     {5, "Fifteen"},
        //     {6, "Sixteen"},
        //     {7, "Seventeen"},
        //     {8, "Eighteen"},
        //     {9, "Nineteen"}
        // };
        // unordered_map<int, string> um2 {
        //     {2, "Twenty"},
        //     {3, "Thirty"},
        //     {4, "Forty"},
        //     {5, "Fifty"},
        //     {6, "Sixty"},
        //     {7, "Seventy"},
        //     {8, "Eighty"},
        //     {9, "Ninety"}
        // };
        // unordered_map<int, string> um3 {
        //     {1, "Thousand"},
        //     {2, "Million"},
        //     {3, "Billion"},
        //     {4, "Trillion"}
        // };
        // 
        // int i = 0; // every digit
        // int j = 0; // every three digits
        // int prev = -1; // look back
        // bool all_zeros = true; // all zeros within every three digits
        // 
        // vector<string> v;
        // 
        // while (num > 0)  {
        //     // extract last digit
        //     int ld = num % 10;
        //     string ld_str = "";
        //     
        //     if (i == 3) {
        //         i = 0;
        //         j++;
        //         if (all_zeros && !v.empty()) v.pop_back(); // e.g. One Million "Thousand" Ten
        //         all_zeros = true; // every three digits, all_zeros flag needs to be reset
        //         v.push_back(um3[j]);
        //     }
        //     
        //     // if ld is zero, skip
        //     if (i == 0) {
        //         if (ld != 0) ld_str = um0[ld];
        //     } else if (i == 1) {
        //         if (ld == 1) {
        //             if (prev != 0) v.pop_back(); // check if prev is zero !!!
        //             ld_str = um1[prev];
        //         } else if (ld >= 2) {
        //             ld_str = um2[ld];
        //         }
        //     } else {
        //         if (ld != 0) ld_str = um0[ld] + " Hundred";
        //     }
        //     
        //     if (!empty(ld_str)) { 
        //         v.push_back(ld_str);
        //         all_zeros = false; // all_zeros is false within this batch of three digits
        //     }
        //     
        //     prev = ld;
        //     i++;
        //     num = num / 10;
        // }
        // 
        // string ret = *v.rbegin();
        // for (auto it = v.rbegin()+1; it != v.rend(); it++) {
        //     ret += " " + *it;
        // }
        // return ret;
    }
};