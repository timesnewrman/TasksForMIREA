#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string forbidden = "useragreement";
    bool bad[256] = {false};
    for (char c : forbidden) {
        bad[(unsigned char)tolower(c)] = true;
        bad[(unsigned char)toupper(c)] = true;
    }

    string line;
    while (getline(in, line)) {
        for (char c : line) {
            if (!bad[(unsigned char)c]) out << c;
        }
        out << '\n';
    }
    return 0;
}