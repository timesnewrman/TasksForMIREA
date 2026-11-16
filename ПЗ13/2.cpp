#include <iostream>
#include <string>
#include <set>
#include <locale>
#include <codecvt>
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    string s;
    getline(cin, s);

    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring ws = conv.from_bytes(s);

    set<wstring> words;
    wstring cur;

    for (wchar_t ch : ws) {
        if (iswalpha(ch) || ch == L'-' || ch == L'\'') {
            cur += towlower(ch);
        } else if (!cur.empty()) {
            words.insert(cur);
            cur.clear();
        }
    }
    if (!cur.empty()) words.insert(cur);

    for (auto& w : words) wcout << w << L'\n';
}
