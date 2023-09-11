#include <iostream>
#include <vector>
using namespace std;

const int MAX = 201;

int arr[MAX];
int graph[MAX][MAX];

int Find(int x) {
    if (x == arr[x])
        return x;
    return arr[x] = Find(arr[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y) {
        arr[y] = x;
    }
}

bool IsUnion(int x, int y) {
    return Find(x) == Find(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] && graph[j][i]) {
                Union(i, j);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    int root = Find(v[0]);
    for (int i = 1; i < m; i++) {
        if (root != Find(v[i])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}
