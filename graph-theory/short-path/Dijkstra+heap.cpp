// Copyright 2017 Parallelc
// o((E+V)logV)
#include <bits/stdc++.h>
using namespace std;  // NOLINT
using LL = int64_t;
using T = int;
const T INF = 0x3f3f3f3f;
struct edge {
    int v;
    T w;
    bool operator< (const edge& e) const {return w > e.w;}
};
T dij(const vector<vector<edge>>& lj, int S, int N) {
    vector<int> us(lj.size());
    int n = lj.size() - 1;
    vector<int> pre(n + 1);
    vector<T> a(n + 1, INF);
    priority_queue<edge> q;
    q.push({S, 0});
    edge mini{0, 0};
    while (!q.empty()) {
        do {
            mini = q.top();
            q.pop();
        }while(us[mini.v] == 1 && !q.empty());
        if (us[mini.v] == 0) {
            us[mini.v] = 1;
            if (mini.v == N) break;
            for (auto& i : lj[mini.v]) {
                if (us[i.v] == 0) {
                    T k = mini.w + i.w;
                    if (a[i.v] > k) {
                        a[i.v] = k;
                        q.push({i.v, k});
                        pre[i.v] = mini.v;
                    }
                }
            }
        }
    }
    if (us[N] == 1) {
        function<void(int)> pri = [&](int k)->void {
            if (k != S) pri(pre[k]);
            cout << k;
            if (k != N) cout << ' ';
        };
        pri(N);
        return a[N];
    } else {
        return INF;
    }
}
