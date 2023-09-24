#include <iostream>

using namespace std;

template<class T> 
T arr_sum(T a[], int n, T b[], int m){
    T c =0;
    int i;
    for(i = 0; i<n; i++){
        c += a[i];
    }
    for(i = 0; i<m; i++){
        c += b[i];
    }
    return c;
}

int main(){
    int val;
    cin >> val;
    {
        int a[] = {3,2,0,val};
        int b[] = {5,6,1,2,7};
        cout << arr_sum(a,4,b,5) << endl;
    }
    {
        double a[] = {3.0,2,0,val*1.0};
        double b[] = {5.0,6.1,1,2.3,7};
        cout << arr_sum(a,4,b,5) << endl;
    }

    return 0;
}