#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;
    for(int i = 0; exp[i] != '\0'; i++) {
        if(isdigit(exp[i]))
            st.push(exp[i]-'0');
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (exp[i]) {
                case '+': st.push(op1+op2); break;
                case '-': st.push(op1-op2); break;
                case '*': st.push(op1*op2); break;
                case '/': st.push(op1/op2); break;
                case '^': st.push(op1^op2); break;
            }
        }
    }
    
    return st.top();
}

int main()
{
    string exp;
    cout << "Postfix expression: ";
    cin >> exp;
    cout << "Result: ";
    cout << evaluatePostfix(exp);

    return 0;
}
