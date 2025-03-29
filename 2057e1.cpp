#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005

void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}

multiset<ll> lower;
multiset<ll> upper;
ll maxi = -1;

void ins(ll num)
{
      if (upper.size())
      {
            if (upper.size() == maxi)
            {
                  if (*upper.begin() > num)
                  {
                        lower.insert(num);
                  }
                  else
                  {
                        upper.insert(num);
                        lower.insert(*upper.begin());
                        upper.erase(upper.find(*upper.begin()));
                  }
            }
            else
            {
                  upper.insert(num);
            }
      }
      else
      {
            upper.insert(num);
      }
}

void ers(ll num)
{
      if (lower.find(num) != lower.end())
      {
            lower.erase(lower.find(num));
      }
      else
      {
            upper.erase(upper.find(num));
            if (lower.size())
            {
                  upper.insert(*lower.rbegin());
                  lower.erase(lower.find(*lower.rbegin()));
            }
      }
}

ll findK()
{
      return *upper.begin();
}

void find(auto &graph, ll st, ll en, ll par, ll &cans, auto &dp)
{
      if (dp[st])
      {
            return;
      }
      if (st == en)
      {
            ll ans = findK();
            cans = min(cans, ans);
            return;
      }
      dp[st] = 1;
      for (auto it : graph[st])
      {
            if (it.first == par)
                  continue;
            ins(it.second);
            find(graph, it.first, en, st, cans, dp);
            ers(it.second);
      }
      dp[st] = 0;
}

void solve(ll test)
{
      ll n, m, q;
      cin >> n >> m >> q;
      vector<vector<pair<ll, ll>>> graph(n + 1);
      for (int i = 1; i <= m; i++)
      {
            ll a, b, w;
            cin >> a >> b >> w;
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
      }
      vector<ll> dp(n + 1, 0);
      for (int t = 1; t <= q; t++)
      {
            ll a, b, k;
            cin >> a >> b >> k;
            ll cans = 1e10;
            lower.clear();
            upper.clear();
            maxi = k;
            find(graph, a, b, -1, cans, dp);
            cout << cans << " ";
      }
      cout << endl;
}

int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t;
      cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}
