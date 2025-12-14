#include <iostream>
#include <stack>
#include <string>
using namespace std;
//priority function
int prec(char c){
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    if(c == '^')
        return 3;
    return 0;
}
//Infix to postfix
string infixToPostfix(string s){

    stack<char> st;
    string res = "";

    for(int i = 0; i < s.length(); i++){

        char c = s[i];

        if(isalnum(c)){
            res += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(st.top()) >= prec(c)){
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    return res;
}
//Infix to prefix
string infixToPrefix(string s){

    // reverse
    reverse(s.begin(), s.end());

    // swap brackets
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }

    string postfix = infixToPostfix(s);

    // reverse to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}
//Postfix evaluation
int evaluatePostfix(string s){

    stack<int> st;

    for(int i = 0; i < s.length(); i++){

        char c = s[i];

        if(isdigit(c)){
            st.push(c - '0');
        }
        else{

            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            switch(c){
                case '+': st.push(b + a); break;
                case '-': st.push(b - a); break;
                case '*': st.push(b * a); break;
                case '/': st.push(b / a); break;
            }
        }
    }

    return st.top();
}
int main(){

    string exp = "(A+B)*C-D";

    cout << "postfix: " << infixToPostfix(exp) << endl;
    cout << "prefix: " << infixToPrefix(exp) << endl;

    string post = "53+82-*";  // example
    cout << "postfix result: " << evaluatePostfix(post) << endl;

    return 0;
};