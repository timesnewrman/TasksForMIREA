#include <vector>
#include <stdexcept>
using namespace std;

class MinStack {
    vector<int> data;
    vector<int> mins;
public:
    void push(int x) {
        data.push_back(x);
        mins.push_back(mins.empty() ? x : min(x, mins.back()));
    }
    void pop() {
        if (data.empty()) throw runtime_error("empty");
        data.pop_back();
        mins.pop_back();
    }
    int top() const {
        if (data.empty()) throw runtime_error("empty");
        return data.back();
    }
    int getMin() const {
        if (mins.empty()) throw runtime_error("empty");
        return mins.back();
    }
    bool empty() const { return data.empty(); }
};
