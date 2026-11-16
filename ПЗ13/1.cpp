#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);  // читаем всю строку, включая пробелы

    stack<char> st;
    bool ok = true;

    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (st.empty() || st.top() != '(') {
                ok = false;
                break;
            }
            st.pop();
        }
    }

    ok = ok && st.empty();

    cout << (ok ? "yes" : "no") << endl;
    return 0;
}
