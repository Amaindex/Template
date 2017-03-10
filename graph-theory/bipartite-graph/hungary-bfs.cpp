// Copyright 2016 Parallelc
#include <bits/stdc++.h>
using namespace std;  // NOLINT
int hungary(const vector<vector<int>>& lj, int m) {
    int n = lj.size();
    vector<int> llink(n, -1), rlink(m, -1), pre(n, -1), us(m, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (llink[i] == -1) {
            queue<int> q;
            q.push(i);
            bool flag = 0;
            while (!q.empty() && !flag) {
                int u = q.front();
                q.pop();
                for (auto v : lj[u]) {
                    if (us[v] != i) {
                        us[v] = i;
                        if (rlink[v] != -1) {
                            q.push(rlink[v]);
                            pre[rlink[v]] = u;
                        } else {
                            flag = 1;
                            while (u != -1) {
                                int temp = llink[u];
                                rlink[v] = u;
                                llink[u] = v;
                                u = pre[u];
                                v = temp;
                            }
                            break;
                        }
                    }
                }
            }
        }
        if (llink[i] != -1) ans++;
    }
    return ans;
}
