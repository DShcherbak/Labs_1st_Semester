#include <bits/stdc++.h>

using namespace std;


set <string> variables;
map<string,string> value;
string Str;
int i = 0, len = 0;
double n1 = 0, n2 = 0, n = 0;

void NumFind(int i, string S, double & num)
{
	if('0' <= S[i] && S[i] <= '9'){
		num = num*10 + (int)(S[i] - '0');
	}
}

void NumFind1(int i, string S, double & num, double Power)
{
	if('0' <= S[i] && S[i] <= '9'){
		num += Power*(int)(S[i] - '0');
	}
}

void PlMin(int i, string S, double & n, double n1, double n2)
{
    if (S[i] == '-')
    {
        n = n2 - n1;
    }
    else if (S[i] == '+')
    {
        n = n2 + n1;
    }
}

void calculate(string S)
{
    stack <double> steck;
    int StrSize = 0;
    bool Var = false, Num = false;
    double num = 0;
    bool flag = false;
    double Power = 0.1;

    value[""] = 9;
    value["a"] = 1;
    value["a3"] = 2;
    StrSize = S.size();

    while (i < StrSize)
    {
  //  	cout << i << " " << S[i] << endl;
        if ((S[i] == 'l') && (S[i+1] == 'n'))
        {
            n1 = steck.top();
            cout << n1 << "&\n";
            steck.pop();
            n = log(n1);
            steck.push(n);
            Var = false;
            Num = false;
            i++;
        }
        else if ((S[i] == 'A') || (S[i] == 'a') || (S[i] == 'B') || (S[i] == 'b') || (S[i] == 'C') || (S[i] == 'c') || (S[i] == 'D') || (S[i] == 'd') || (S[i] == 'E') || (S[i] == 'e') || (S[i] == 'F') || (S[i] == 'f') || (S[i] == 'G') || (S[i] == 'g') || (S[i] == 'H') || (S[i] == 'h') || (S[i] == 'I') || (S[i] == 'i') || (S[i] == 'J') || (S[i] == 'j') || (S[i] == 'K') || (S[i] == 'k') || (S[i] == 'L') || (S[i] == 'l') || (S[i] == 'M') || (S[i] == 'm') || (S[i] == 'N') || (S[i] == 'n') || (S[i] == 'O') || (S[i] == 'o') || (S[i] == 'P') || (S[i] == 'p') || (S[i] == 'Q') || (S[i] == 'q') || (S[i] == 'R') || (S[i] == 'r') || (S[i] == 'S') || (S[i] == 's') || (S[i] == 'T') || (S[i] == 't') || (S[i] == 'U') || (S[i] == 'u') || (S[i] == 'V') || (S[i] == 'v') || (S[i] == 'W') || (S[i] == 'w') || (S[i] == 'X') || (S[i] == 'x') || (S[i] == 'Y') || (S[i] == 'y') || (S[i] == 'Z') || (S[i] == 'z'))
        {
            VarFind(i, S, Str);
            Var = true;
            Num = false;
        }
        else if (((S[i] == '1') || (S[i] == '2') || (S[i] == '3') || (S[i] == '4') || (S[i] == '5') || (S[i] == '6') || (S[i] == '7') || (S[i] == '8') ||(S[i] == '9') || (S[i] == '0')) && (Var == true) && (Num == false))
        {
            VarFind1(i, S, Str);
        }
        else if (((S[i] == '1') || (S[i] == '2') || (S[i] == '3') || (S[i] == '4') || (S[i] == '5') || (S[i] == '6') || (S[i] == '7') || (S[i] == '8') || (S[i] == '9') || (S[i] == '0')) && (flag == false) && (Var == false) && (Num == false))
        {
            NumFind(i, S, num);
            Var = false;
            Num = true;
        }
        else if (((S[i] == '1') || (S[i] == '2') || (S[i] == '3') || (S[i] == '4') || (S[i] == '5') || (S[i] == '6') || (S[i] == '7') || (S[i] == '8') ||(S[i] == '9') || (S[i] == '0') || (S[i] == '.')) && (Var == false) && (Num == true) && (flag == true))
        {
            if (S[i - 1] == '.')
                NumFind1(i, S, num, Power);
            else
            {
                Power = Power * Power;
                NumFind1(i, S, num, Power);
            }
        }
        else if (S[i] == '.')
            flag = true;
        else if ((S[i] == '+') || (S[i] == '-'))
        {
            n1 = steck.top();
            steck.pop();
            n2 = steck.top();
            steck.pop();
            PlMin(i, S, n, n1, n2);
            steck.push(n);
            Var = false;
            Num = false;
        }
        else if (S[i] == ' ')
        {
            if (Num == true)
            {
                steck.push(num);
            }
            Var = false;
            Num = false;
            Str = "";
            num = 0;
            flag = false;
            Power = 0.1;
            n = 0;
        }
        if (i + 1 == StrSize)
        {
            if (Var == true)
            {
                steck.push(atof(value[Str].c_str()));
            }
            else if (Num == true)
            {
                steck.push(num);
            }
            Var = false;
            Num = false;
            Str = "";
            num = 0;
            flag = false;
            Power = 0.1;
        }
        i++;
    }
    cout << steck.top();
}




void enter(string &s, int id, char to_add = '0'){
    string result = "";
    for(int i = 0; i < id; i++)
        result += s[i];
    result+=to_add;
    for(int i = id, l = s.length(); i < l; i++)
        result += s[i];
    s = result;
}

void preresq(string &s){
    if(s[0] == '-') enter(s,0);
    for(int i = 0; i < s.length(); i++){
        if(i < s.length()-1 && s[i] == '(' && s[i+1] == '-'){
            enter(s,i+1);
        }
    }
}

string read_value(string s, int &i){
    string result = "";
    while('0' <= s[i] && s[i] <= '9')
        result+=s[i++];
    if(s[i] != '.')
        return result;
    result+=s[i++];
    while('0' <= s[i] && s[i] <= '9')
        result+=s[i++];
    return result;
}

string read_variable(string s, int &i){
    string result = "";
    while(('0' <= s[i] && s[i] <= '9') ||
          ('a' <= s[i] && s[i] <= 'z') ||
          ('A' <= s[i] && s[i] <= 'Z'))
        result+=s[i++];
    if(variables.find(result) == variables.end()){
        variables.insert(result);
        cout << "Please, enter the value of " << result << " here: ";
        cin >> value[result];
        cout << "\n";
    }
    return value[result];
}

string polish_notation(string s){
    string result = "";
    stack <char> stk;
    int l = s.length();
    int i = 0;
    while(i < l){
        if('0' <= s[i] && s[i] <= '9'){
            result += read_value(s,i);
            result += " ";
        }
        else if(i < l-4 && s[i] == 'l' && s[i+1] == 'n' && s[i+2] == '('){
            i = i+2;
            stk.push('l');
        }
        else if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')){
            result += read_variable(s,i);
            result += " ";
        }
        else if(s[i] == '('){
            stk.push('(');
            i++;
        }
        else if(s[i] == ')'){
            while(stk.top() != '(') {
                result += stk.top();
                result += " ";
                stk.pop();
            }
            stk.pop();
            if(!stk.empty() && (stk.top() == 'l')){
                result += "ln ";
                stk.pop();
            }
            i++;
        }
        else if(s[i] == '+' || s[i] == '-'){
            if(!stk.empty() && (stk.top() == '+' || stk.top() == '-')){
                result+=stk.top();
                result += " ";
                stk.pop();

            }
            stk.push(s[i++]);
        }
        else
            i++;
    }
    //cout << "^" << result;
    while(!stk.empty()){
        result += stk.top();
        result += " ";
        stk.pop();
    }
    return result;
}

//2.44      1.0235 -  9  8 1.12
//test level 1
int main(){
    string s,result = "";
    getline(cin,s);
    preresq(s);
    result = polish_notation(s);
    cout << result << endl;
    calculate(result);
    return 0;
}
