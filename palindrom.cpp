#include <iostream>
#include <cmath>
#include <algorithm>

const int Nmax = 10001;

using namespace std;

bool palindrom(string s){
    bool result = true;
    int l = s.length()/2;
    for(int i = 0; i < l; i++){
        if(s[i] != s[s.length()-i-1]) result = false;
    }
    return result;
}

string head(string s){
    string result = s;
    for(int i = 0, l = s.length(); i <= l; i++){
        for(int j = l-i; j <= l-1; j++){
            result = s[j] + result;
        }
        if(palindrom(result)) return result;
        result = s;
    }
}

string tail(string s){
    string result = s;
    for(int i = 0, l = s.length()-1; i <= l; i++){
        for(int j = i-1; j >= 0; j--){
            result = result + s[j];
        }
        if(palindrom(result)) return result;
        result = s;
    }
}

int main(){
    string s, hd, tl;
    cin >> s;
    hd = head(s);
    tl = tail(s);
    cout << (hd.length() < tl.length() ? hd : tl) << endl;
    return 0;
}
