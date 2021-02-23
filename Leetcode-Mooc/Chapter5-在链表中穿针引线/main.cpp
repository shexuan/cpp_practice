#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

int main() {
    // std::cout << "Hello, World!" << std::endl;
//    int a = 3, b=4;
//    cout << b%a << endl;
    vector<int> v = {1,2,3,4};
    deque<int> deq = {1,2,3,4};
    set<int> s = {1,2,3,4};
    cout << *v.erase(v.begin()) << endl;
    cout << *s.erase(s.begin())<< endl;
    v.insert(v.begin(), 10);
    return 0;
}