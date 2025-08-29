#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxN = 1e3+5;

const int M = 8;
const int h[M] = {2, 2, 1, -1, -2, -2, -1, 1};
const int v[M] = {-1, 1, 2, 2, 1, -1, -2, -2};

int N;
int dist[maxN][maxN];

bool in_bounds(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
    cin >> N;

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            dist[i][j] = INT_MAX;

    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<>> pq;

    dist[0][0] = 0;
    pq.push({0,{0,0}});

    while (!pq.empty()) {
        auto [d, p] = pq.top(); pq.pop();
        int x = p.first, y = p.second;
        if (d > dist[x][y]) continue; 

        for (int k=0; k<M; k++) {
            int nx = x + h[k], ny = y + v[k];
            if (in_bounds(nx, ny)) {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    pq.push({dist[nx][ny], {nx,ny}});
                }
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cout << dist[i][j] << (j==N-1?'\n':' ');
    }
}
