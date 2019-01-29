#include <iostream>
#include <cmath>
#include <vector>

#define x first
#define y second
using namespace std;

struct polynom{
    bool exist = false;
    int length = 0;
    vector <double> k;

    print(){
        bool first = true;
       if(!exist) cout << "No such polynom.\n";
        else{
            for(int  i = length-1; i > 0; i--){
                if(k[i] != 0){
                  if(k[i] > 0 && !first) cout << "+";
                    if(k[i] == 1){}
                    else if(k[i] == -1){cout << "-";}
                    else{ cout << k[i];}
                    first = false;
                    cout << "x";
                    if(i > 1) cout << "^" << i;
                }
            }
            if(k[0] != 0){
                if(k[0] > 0) cout << '+';
                cout << k[0];
            }
            cout << endl;
        }
    }


};


vector <vector <polynom>> poly;
vector <pair <double, double>> point;

void make_copy(polynom &a, polynom b){
    a.exist = true;
    a.length = b.length;
    a.k.resize(a.length);
    for(int i = 0, l = a.length; i < l; i++){
        a.k[i] = b.k[i];
    }
}

polynom substract(polynom a, polynom b){
    polynom result;
    result.exist = true;
    result.length = a.length;
    result.k.resize(a.length);
    for(int i = 0, k = a.length; i < k; i++){
        result.k[i] = a.k[i] - b.k[i];
    }
    return result;
}

polynom mult(polynom a, double b){
    polynom result;
    result.exist = true;
    result.length = a.length+1;
    result.k.resize(a.length+1);
    result.k[a.length] = a.k[a.length-1];
    for(int i = a.length-1; i > 0 ; i--){
        result.k[i] = a.k[i-1]  - a.k[i]*b;

    }
    result.k[0] = (-1.0)*a.k[0]*b;

    return result;
}

polynom merge_poly(polynom a, polynom b, int l, int r){
    polynom result;
    result.exist = true;
    result.length = r-l+2;
    result.k.resize(r-l+2);
    result = substract(mult(b,point[l].x), mult(a,point[r].x));
    for(int i = 0; i < result.length; i++){
        result.k[i] /= (point[r].x - point[l].x);
    }
    return result;
}

polynom build_poly(int l, int r){
    if(poly[l][r].exist) return poly[l][r];
     poly[l][r].exist = true;
     if(l == r) {
        poly[l][r].exist = true;
        poly[l][r].length = 1;
        poly[l][r].k.resize(1);
        poly[l][r].k[0] = point[l].y;
        cout << "A polynom of ("  << l << "," << r;
        cout << ") is: ";
        poly[l][r].print();
        return poly[l][r];
     }
     poly[l][r] = merge_poly(build_poly(l,r-1),build_poly(l+1,r),l,r);
    cout << "A polynom of ("  << l << "," << r;
    cout << ") is: ";
    poly[l][r].print();
    return poly[l][r];

}

int main(){
    int n;
    cin >> n;
    point.resize(n);
    poly.resize(n, vector <polynom>(n));
    for(int i  = 0; i < n ; i++){
        cin >> point[i].x >> point[i].y;
    }
    polynom result = build_poly(0,n-1);
    cout << "**************************************\n\n";
    cout << "Answer: ";
    result.print();
    cout << "\n**************************************";
    return 0;
}
