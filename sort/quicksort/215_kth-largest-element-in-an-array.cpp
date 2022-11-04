// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
215_kth-largest-element-in-an-array LeetCode

Solution: 
    - quickselect (divide and conquer)
        - apply to Median finding
*/

#include <iostream>
#include <sstream> // stringstream, istringstream, ostringstream
#include <string> // to_string(), stoi()
#include <cctype> // isalnum, isalpha, isdigit, islower, isupper, isspace; toupper, tolower
#include <climits> // INT_MAX 2147483647
#include <cmath> // pow(3.0, 4.0)
#include <cstdlib> // rand() % 100 + 1
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set> // unordered_set, unordered_multiset
#include <set> // set, multiset
#include <unordered_map> // unordered_map, unordered_multimap
#include <map> // map, multimap
#include <utility> // pair<>
#include <tuple> // tuple<>
#include <algorithm> // reverse, sort, transform, find, remove, count, count_if
#include <memory> // shared_ptr<>, make_shared<>
#include <stdexcept> // invalid_argument

using namespace std;

class Solution {
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    int partition(vector<int>& nums, int l, int r) {
        // 2 1 3 6 4 5
        // 5 4 6
        // 4 5
        // 4
        int random_i = l + rand() % (r - l + 1); // #include <cstdlib>
        int pivot = nums[random_i];
        swap(nums, random_i, r);
        int start = l;
        int end = r-1;
        while (start <= end) {
            if (nums[start] < pivot) {
                start++;
                continue;
            }
            if (nums[end] >= pivot) {
                end--;
                continue;
            }
            swap(nums, start, end);
        }
        swap(nums, start, r);
        return start;
    }
    int findKthLargestHelper(vector<int>& nums, int l, int r, int k) {
        int pivot_i = partition(nums, l, r);
        int n = nums.size();
        // 3 1 2 6 4 5
        // 2 1 3 6 4 5
        // i = 2;
        if (pivot_i == n-k) {
            return nums[pivot_i];
        } else if (pivot_i < n-k) {
            return findKthLargestHelper(nums, pivot_i+1, r, k);
        } else {
            return findKthLargestHelper(nums, l, pivot_i-1, k);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return findKthLargestHelper(nums, 0, n-1, k);
    }
};