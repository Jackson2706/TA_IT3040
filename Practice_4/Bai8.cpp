#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b){
    map<T, double> result = a;
    for(const auto &e: b){
        if(result.count(e.first)){
            result[e.first] = max(result[e.first], e.second);
        } else {
            result.insert(e);
        }
    }
    return result;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b){
    map<T, double> result;
    for(const auto &x: a){
        const auto it = b.find(x.first);
        if(it != b.end()){
            result[x.first] = min(x.second, it->second);
        }
    }
    return result;
}

template<class T>
void print_fuzzy_set(const map<T, double> &a){
    cout << "{ ";
    for(const auto &x: a){
        cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}" << endl;
}

int main(){
    map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    cout << "A= ";
    print_fuzzy_set(a);
    cout << "B= ";
    print_fuzzy_set(b);
    map<int, double> c = fuzzy_set_union(a, b);
    map<int, double> d = fuzzy_set_intersection(a, b);
    cout << "Union: ";
    print_fuzzy_set(c);
    cout << "Intersection: ";
    print_fuzzy_set(d);
}