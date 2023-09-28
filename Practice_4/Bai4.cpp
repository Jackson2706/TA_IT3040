#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector (const vector<int> &a){
    for(int v: a){
        cout << v<<endl;
    }
    cout << endl;
}

void delete_even(vector<int> &a){
    a.erase(remove_if(a.begin(), a.end(),[](int i){ 
        return !(i%2);
        }),
         a.end());
}

void sort_decrease(vector<int> &a){
    sort(a.rbegin(), a.rend());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b){
    vector<int> c;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c), greater<int>());
    return c;
}

int main(){
    int m, n, u;
    vector<int> a, b;
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> u;
        a.push_back(u);
    }

    for(int i = 0; i < n; i++){
        cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasing elements of a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasing elements of b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c:  ";
    print_vector(c);

    return 0;
}