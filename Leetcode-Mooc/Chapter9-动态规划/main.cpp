#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int b = 3;
    const int nums = b;
    const int amount = 3;
    int memo[nums][amount];
    const int a = nums;
    cout << a << endl;
    //for_each(std::begin(memo), std::end(memo), [](int a){cout << a << " ";});
    // for_each(std::begin(memo), std::end(memo), [amount](int arr[]){for_each(arr, arr+amount, [](int a){cout << a << " ";}); cout<< endl;});

    return 0;
}