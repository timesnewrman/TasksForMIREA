#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Проверка: можно ли разбить на D групп с разбросом не более X
bool canSplit(const vector<int>& a, int D, int X) {
    int groups = 1;
    int start = 0;
    for (int i = 1; i < (int)a.size(); ++i) {
        if (a[i] - a[start] > X) {
            ++groups;
            start = i;
            if (groups > D) return false;
        }
    }
    return groups <= D;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end());

    int lo = 0, hi = a[N - 1] - a[0], ans = hi;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canSplit(a, D, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}