#include <bits/stdc++.h>
using namespace std;

int evaluatePrefix(string exp) {
    stack<int> st;
    for(int i = exp.size()-1; i >= 0; i--) {
        if(isdigit(exp[i]))
            st.push(exp[i]-'0');
        else {
            
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
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
    cout << "Prefix expression: ";
    cin >> exp;
    cout << "Result: ";
    cout << evaluatePrefix(exp);

    return 0;
}
