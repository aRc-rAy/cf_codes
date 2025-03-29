#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 998244353
#define MAXX 100005
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}
void find_level(auto &dis, auto &graph)
{
      ll level = 1;

      queue<ll> q;
      q.push(1);

      while (!q.empty())
      {
            ll sz = q.size();

            while (sz--)
            {
                  ll node = q.front();
                  q.pop();

                  dis[level].push_back(node);

                  for (auto adj : graph[node])
                  {
                        q.push(adj);
                  }
            }
            level++;
      }
}

void solve(ll test)
{
      ll n;
      cin >> n;

      vector<vector<ll>> graph(n + 1);
      vector<ll> father(n + 1);
      for (int i = 2; i <= n; i++)
      {
            ll p;
            cin >> p;

            graph[p].push_back(i);
            father[i] = p;
      }
      vector<ll> node_dis(n + 1);
      vector<vector<ll>> dis(n + 1);

      find_level(dis, graph);

      vector<ll> dp(n + 1);
      dp[0] = 1;
      ll ans = 0;
      ll prev = 0;

      for (int i = 1; i <= n; i++)
      {
            ll cur = 0;
            if (i <= 2)
            {
                  for (auto node : dis[i])
                  {
                        node_dis[node] += 1;
                        cur += node_dis[node];
                        cur %= mod;
                  }
            }
            else
            {
                  for (auto node : dis[i])
                  {
                        node_dis[node] += prev - node_dis[father[node]];
                        cur += node_dis[node];
                        cur %= mod;
                  }
            }

            ans = (ans + cur) % mod;
            ans = (mod + ans) % mod;
            prev = cur;
      }
      cout << ans << endl;
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}