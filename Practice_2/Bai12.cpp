#include <iostream>
#include <vector>
using namespace std;

struct dict{
    int key;
    int value;
};

void swap(dict &source1, dict &source2){
    int value, key;
    key = source1.key;
    value = source1.value;
    source1.key = source2.key;
    source1.value = source2.value;
    source2.key = key;
    source2.value = value;
}

void sort_vector(vector<dict> &source){
    for (int i = 0; i < source.size(); i++){
        for( int j = i+1; j < source.size(); j++){
            if(source[i].value <= source[j].value){
                swap(source[i], source[j]);
            }
            if ((source[i].value == source[j].value) && (source[i].key <= source[j].key)){
                swap(source[i], source[j]);

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