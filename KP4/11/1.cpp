#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    // dp[i][j] — максимальная сумма на пути до клетки (i, j)
    vector<vector<long long>> dp(n, vector<long long>(m, 0));

    dp[0][0] = a[0][0];

    
    for (int j = 1; j < m; ++j)
        dp[0][j] = dp[0][j - 1] + a[0][j];

    for (int i = 1; i < n; ++i)
        dp[i][0] = dp[i - 1][0] + a[i][0];

    // основное заполнение
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i][j - 1]);

    cout << "Максимальная сумма: " << dp[n - 1][m - 1] << "\n";

    // Восстановление пути от (n-1, m-1) к (0, 0)
    vector<pair<int, int>> path;
    int i = n - 1, j = m - 1;
    while (true) {
        path.push_back({i, j});
        if (i == 0 && j == 0) break;
        if (i == 0) {
            --j;
        } else if (j == 0) {
            --i;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(path.begin(), path.end());

    cout << "Маршрут:\n";
    for (auto& [x, y] : path)
        cout << x << " " << y << "\n";

    return 0;
}
