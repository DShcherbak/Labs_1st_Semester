#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define X first.first
#define Y first.second
#define Z second

const int Nmax = 10001;

using namespace std;

vector <long long> a;
vector <pair <pair<int,int>, int> > triple;

bool acute_triangle(int a, int b, int c){
    if(c >= a+b) return false; // трикутник не існує
    if(c*c >= a*a + b*b) return false; //трикутник не гострокутний
    return true;
}

int main(){
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(),a.end());
    for(int i = n-1; i > 1; i--)
        for(int j = i-1; j > 0; j--)
            for(int k = j-1; k >=0; k--){
                if(acute_triangle(a[k],a[j],a[i]))
                    triple.push_back({{a[k],a[j]},a[i]});
        }
    sort(triple.begin(), triple.end());
    for(int i = 0, l = triple.size(); i < l; i++){
        if(i != 0 && triple[i] != triple[i-1])
        cout << "(" << triple[i].X << "," << triple[i].Y << "," << triple[i].Z << ");\n";
    }
    return 0;
}
