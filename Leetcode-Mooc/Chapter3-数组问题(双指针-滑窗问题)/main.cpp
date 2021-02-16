#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;




int main() {
    // std::cout << "Hello, World!" << std::endl;
    // cout << int('9') << endl;
    vector<int> v = {1,2,3};
    cout << *v.end() << endl;
    cout << accumulate(v.begin(), --v.end(), 0) << endl;
    return 0;
}