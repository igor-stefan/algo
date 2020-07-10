#include <bits/stdc++.h>

using namespace std;

int typeOf(char a){
    if(a == '(' || a == ')') return 0;
    else if(a == '[' || a == ']') return 1;
    return 2;
}
bool validParentheses(string s){
    stack <char> element;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            element.push(s[i]);
        else if(!element.empty() && typeOf(element.top()) == typeOf(s[i])){
            element.pop();
        } else return false;
    }
    return element.empty();
}



int main () {
    string s;
    cin >> s;
    cout << validParentheses(s) << endl; 
    return 0;
}