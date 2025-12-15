#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = (int)1e18;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        edges[i][0] = a - 1;
        edges[i][1] = b - 1;
        edges[i][2] = wt;
    }

    vector<int> dist(n, 0);
    vector<int> parent(n, -1);
    int x = -1;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] + wt < dist[v])
            {
                dist[v] = max(-inf, dist[u] + wt);
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
        cout << "NO" << endl;

    else
    {
        int y = x;
        for (int i = 0; i < n-1; i++)
        {
            y = parent[y];
        }

        vector<int> cycle;
        int curr = y;

        do
        {
            cycle.push_back(curr);
            curr = parent[curr];
        } while (curr != y);

        cycle.push_back(y);
        reverse(cycle.begin(), cycle.end());
        cout << "YES" << endl;
        for (int v : cycle)
        {
            cout << v + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}