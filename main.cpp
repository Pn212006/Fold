#include <iostream>
#include <vector>
#include <functional>

using namespace std;


int fold(const vector<int>& v, function<int(int,int)> f, int index = 0) {
    if (index == v.size() - 1) {
        return v[index]; 
    }
    return f(v[index], fold(v, f, index + 1));
}


int fold_iter(const vector<int>& v, function<int(int,int)> f) {
    if (v.empty()) throw invalid_argument("Vector is empty!");
    int result = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        result = f(result, v[i]);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    
    auto sum = [](int a, int b) { return a + b; };

    
    auto product = [](int a, int b) { return a * b; };

    cout << "Recursive sum: " << fold(nums, sum) << "\n";
    cout << "Recursive product: " << fold(nums, product) << "\n";

    cout << "Iterative sum: " << fold_iter(nums, sum) << "\n";
    cout << "Iterative product: " << fold_iter(nums, product) << "\n";
}
