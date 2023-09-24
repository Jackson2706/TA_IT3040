#include <iostream>
#include <vector>
using namespace std;

struct dict{
    int key;
    int value;
};

void sort_vector(vector<dict> &source){
    int value, key;
    for (int i = 0; i < source.size(); i++){
        for( int j = i+1; j < source.size(); j++){
            if(source[i].value <= source[j].value){
                key = source[i].key;
                value = source[i].value;
                source[i].key = source[j].key;
                source[i].value = source[j].value;
                source[j].key = key;
                source[j].value = value;
            }
            if ((source[i].value == source[j].value) && (source[i].key <= source[j].key)){
                key = source[i].key;
                value = source[i].value;
                source[i].key = source[j].key;
                source[i].value = source[j].value;
                source[j].key = key;
                source[j].value = value;
            }
        }
    }
}

void print_vector(vector<dict> source){
    for(int i = 0; i < source.size(); i++){
        cout << source[i].key << " " << source[i].value << endl;
    }
}
int main(){
    vector<dict> list;
    int n, key, value;
    dict tmp;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> key >> value;
        tmp.key = key;
        tmp.value = value;
        list.push_back(tmp);
    }
    sort_vector(list);
    cout << endl;
    print_vector(list);
}