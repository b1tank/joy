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

int main()
{
    stringstream ss("");
    string ext;
    ss.peek(); // make empty ss reach EOF !!!
    ss >> ext;
    cout << "ext is " << ext << "!" << endl;
    if (ss.eof()) {
        cout << "eof" << endl;
    } else {
        cout << "not eof" << endl;
    }

    int i = 'A' - 'a';
    cout << "i = " << i << endl;
        
    return 0;
}