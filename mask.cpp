#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

char cur = ' ';
vector <char> letter;
vector <set <int>> gap;
int cnt_letters = 0;

bool is_alpha(char c){
    if((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

string read_word(){
    string result = "";
    while((int)cur != -1 && !is_alpha(cur)){
        cout << cur;
        cur = getchar();
    }
    while((int)cur != -1 && is_alpha(cur)){
        result += cur;
        cur = getchar();
    }
    return result;
}

void parse_key(string key){
    int len = key.length();
    int min_pos = 0, max_pos = 0;
    int i = 0;
    if(is_alpha(key[0])){
            cout << "here.." << endl;
        gap[0].insert(0);
        cout << "here.." << endl;
    }
    else{
        while(i < len && !is_alpha(key[i])){
            min_pos = max_pos = 0;
            if(key[i] == '?') max_pos++;
            else if(key[i] == '.') min_pos++, max_pos++;
            else if(key[i] == '+') gap[0].insert(-1);
            else if(key[i] == '*'){
                gap[0].insert(-1);
                gap[0].insert(0);
            }
            else
                min_pos++,max_pos++;
            i++;
        }
        if(gap[0].find(-1) == gap[0].end()){
            for(int j = min_pos; j <= max_pos; j++){
                gap[0].insert(j);
            }
        }

    }

    while(i < len){
        while(i < len && is_alpha(key[i])){
            letter.push_back(key[i]);
            cnt_letters++;
            i++;
            min_pos =0;
            max_pos = 0;
            while(i < len && !is_alpha(key[i])){
                i++;
                if(i == len){min_pos++,max_pos++;break;}
                if(key[i] == '?') max_pos++, i++;
                else if(key[i] == '.') min_pos++, max_pos++;
                else if(key[i] == '+') gap[cnt_letters].insert(-1), i++;
                else if(key[i] == '*'){
                    gap[cnt_letters].insert(-1);
                    gap[cnt_letters].insert(0);
                    i++;
                }
                else
                    min_pos++,max_pos++;
            }
            if(gap[cnt_letters].find(-1) == gap[cnt_letters].end()){
                for(int j = min_pos; j <= max_pos; j++){
                    gap[cnt_letters].insert(j);
                }
            }
        }

    }
}

bool good(string s, int st, int fin, int num){
 //   cout << "Is it good? from " << st << " to " << fin << "?\n";
    if(fin == st+1 && gap[num].find(0) == gap[num].end()) return false;
    if(fin == st+1) return true;
    if(gap[num].find(-1) != gap[num].end()) return true;
    if(gap[num].find(fin-st-1) != gap[num].end()) return true;
    return false;
}

bool fits_pref(string s, int num, int it){
 //   cout <<"Checking... "<<  num << endl;
    int i = it, len = s.length();
    while(i < len){
        while(i < len && s[i] != letter[num])i++;
        if(i == len) continue;
        if(good(s,it,i,num)){
   //     cout << "level 2..." << i  << endl;
            if(num == cnt_letters){
                if(good(s,i,len,num+1))return true;
                else {
                    i++;
                    continue;
                }
            }
            else
                if(fits_pref(s,num+1,i)) return true;
        }
        i++;

    }
    return false;
}

bool fits_key(string s){
    return fits_pref(s,0,-1);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string key, s;
    cin >> key;
    cout << key;
    gap.resize(key.length()+1);
    parse_key(key);
    cnt_letters--;
    cur = getchar();
    while((int)cur != -1){
        s = read_word();
        if(!fits_key(s))
            cout << s;
    }
    return 0;
}
