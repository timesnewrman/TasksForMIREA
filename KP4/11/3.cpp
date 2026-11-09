#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, L;
    cin >> N >> K >> L;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    // сортируем по убыванию стоимости
    sort(a.begin(), a.end(), greater<int>());

    unordered_map<int, int> used; // сколько раз взяли каждое значение
    long long sum = 0;
    int taken = 0;

    for (int i = 0; i < N && taken < K; ++i) {
        if (used[a[i]] < L) {
            used[a[i]]++;
            sum += a[i];
            ++taken;
        }
    }

    cout << sum << "\n";
    return 0;
}