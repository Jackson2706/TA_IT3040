#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int val1, val2;
    cin >> val1 >> val2;
    vector<vector<int>> a = {
        {1,3,7},
        {2,3,4,val1},
        {9,8,15},
        {10, val2},
    };

    sort(a.begin(), a.end(), [](const vector<int> p1, const vector<int> p2){
        return accumulate(p1.begin(), p1.end(), 0) > accumulate(p2.begin(), p2.end(), 0);
    });

    for (const auto v:a){
        for (int it: v){
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;

}