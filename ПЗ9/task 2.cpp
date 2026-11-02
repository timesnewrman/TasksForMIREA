#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in1("input1.txt");
    ifstream in2("input2.txt");
    ofstream out("output.txt");

    string X, Y;
    getline(in1, X);
    getline(in2, Y);

    if (X.find(Y) != string::npos) out << "yes";
    else out << "no";

    return 0;
}
