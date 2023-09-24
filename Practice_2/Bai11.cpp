#include <iostream>
#include <vector>
#include <string>
using namespace std;

int multiply_polynomials_matrix(const vector<int> &a, const vector<int> &b, string(*decimalToBinary)(int), int(*binaryToDecimal)(string), string(*xorBinary)(string, string)){
    vector<int> c(a.size()+b.size() - 1, 0);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            c[i+j] += a[i]*b[j];
        }
    }
    string result = "";
    for(int i = 0; i < c.size(); i++){
        result = xorBinary(result, decimalToBinary(c[i]));
    }
    return binaryToDecimal(result);
}

string decimalToBinary(int decimal){
    string binary = "";
    while (decimal > 0)
    {
        binary = to_string(decimal%2) + binary;
        decimal/=2;
    }
    return binary;
}

int binaryToDecimal(const string binary){
    int decimal = 0;
    int len = binary.length();
    for(int i = 0; i < len; i++){
        if(binary[i] == '1'){
            decimal += (1 << (len - 1 - i));
        }
    }
    return decimal;
}

string xorBinary(string binary1, string binary2){
    int maxLength = max(binary1.length(), binary2.length());
    binary1 = string(maxLength - binary1.length(), '0') + binary1;
    binary2 = string(maxLength - binary2.length(), '0') + binary2;
    string resultBinary = "";

    for(int i = 0; i < maxLength; i++){
        if(binary1[i] != binary2[i]){
            resultBinary += '1';
        } else {
            resultBinary += '0';
        }
    }

    return resultBinary;
}


int main(){
    string(*decimalToBinary_)(int) = NULL;
    int(*binaryToDecimal_)(string) = NULL;
    string(*xorBinary_)(string, string) = NULL;



    decimalToBinary_ = decimalToBinary;
    binaryToDecimal_ = binaryToDecimal;
    xorBinary_ = xorBinary;

    int n,m,tmp;
    vector<int> a,b;
    cin >> n;
    for(int i = 0; i <= n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }

    cin >> m;
    for(int i = 0; i <= m; i++){
        cin >> tmp;
        b.push_back(tmp);
    }

    cout<< multiply_polynomials_matrix(a,b, decimalToBinary_, binaryToDecimal_, xorBinary_) << endl;
}