#include <iostream>
#include <cmath>
#include <algorithm>

const int Nmax = 10010;

using namespace std;

bool sign = true;

/*

This program is multiplying very long integers
If input is anything but an integer, program is terminated

*/
struct Tlong{
    int length;
    long long digit[Nmax];

    Tlong(string s){
        for(int i = 0; i < Nmax; i++) digit[i] = 0;
        length = 0;
        for(; s.length()-length-1 > 0; length++){
            digit[length] = (s[s.length()-length-1] - '0');
        }
        digit[length] = (s[0]-'0');
        length++;
    }
};

int to_int(string s){
    int a = 0;
    for(int i = 0, l = s.length(); i < l; i++){
        a*=10;
        a+=(s[i]-'0');
    }
    return a;
}

print_long(Tlong N){
    if(!sign) cout << "-";
    for(int i = N.length-1; i >= 0; i--){
        cout << N.digit[i];// << '.';
    }
    cout << endl;
}

void spec_add(Tlong &N, Tlong cur, int p){
    int rest = 0;
    for(int i = p, l = p+cur.length; i < l; i++){
        if(i == N.length) N.length++;
        N.digit[i] += cur.digit[i-p]+rest;
        rest = N.digit[i]/10;
        N.digit[i] %= 10;
    }
    if(rest){
        N.digit[N.length] = rest;
        N.length++;
    }
}

Tlong mult_short(Tlong N, long long a){
    if(a == 0){
        sign = true;
        N.length = 1;
        N.digit[0] = 0;
        return N;
    }
    long long rest = 0, temp = 0;
    for(int i = 0, l = N.length; i < l; i++){
        temp = N.digit[i]*a+rest;
        rest = temp/10;
        N.digit[i] = temp%10;
    }
    while(rest){
        N.digit[N.length] = rest%10;
        rest/=10;
        N.length++;
    }
    return N;
}

Tlong mult_long(Tlong N, Tlong A){
    Tlong res = *new Tlong("0");
    for(int p = 0, l = A.length; p < l; p++){
        Tlong cur = *(new Tlong("1"));
        cur = mult_short(N,A.digit[p]);
        spec_add(res,cur,p);
    }
    return res;
}


int main(){
    Tlong N = *(new Tlong("1"));
    string s;
    bool brk  = false;
    bool pls = true;
    cout << "Enter an integer to multiply. Enter anything else to quit.\n";
    do{
        cout << "Current value is: ";
        print_long(N);
        
        if(N.length == 1 && N.digit[0] == 0){
            zero:
            cout << "Current value is: 0\n";
            sign = true;
            cout << "\nSince our number is 0, multiplication makes no sence.\n";
            cout << "If you'd like to go on multiplying, enter a new number.\n";
            cout << "Print anything else otherwise.\n";
            cout << "Your input: ";

            cin >> s;
            for(int i = 0, l = s.length(); i < l; i++){
                if(s[i] < '0' || s[i] > '9')
                    if(i == 0 && s[i] == '-' && s.length() != 1) pls = false;
                    else brk = true; 
                }
            if(brk)
                break;
            if(!pls){
                s.erase(0,1);
                sign = false;
                pls = true;
            }

            if(s.length() == 1 && s[0] == '0')
                    goto zero;

            N = *(new Tlong(s));
            cout << "Current value is: ";
            print_long(N);
        }

        cout << "Your input: ";
        cin >> s;
        cout << endl;
        for(int i = 0, l = s.length(); i < l; i++){
            if(s[i] < '0' || s[i] > '9')
                if(i == 0 && s[i] == '-' && s.length() != 1) pls = false;
                else brk = true;
            }
        if(brk)
            break;
        if(!pls){
            s.erase(0,1); 
            sign = !sign; 
            pls = true;

        }
        if(s.length() == 1 && s[0] == '0')
            goto zero; 

        N = mult_long(N,*(new Tlong(s)));

    }while(1);
    cout << "\nGood bye!\n";
    return 0;
}
