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
void solve(ll test)
{
      ll n;
      cin >> n;

      vector<ll> inn(n + 1);
      set<pair<ll, ll>> st;

      vector<vector<ll>> graph(n + 1);

      for (int i = 0; i < n - 1; i++)
      {
            ll a, b;
            cin >> a >> b;

            st.insert({a, b});
            st.insert({b, a});
            inn[a]++;
            inn[b]++;

            graph[a].push_back(b);
            graph[b].push_back(a);
      }

      vector<pair<ll, ll>> node;
      for (int i = 1; i <= n; i++)
      {
            node.push_back({inn[i], i});
      }
      sort(rbegin(node), rend(node));

      ll cur = 1;
      ll ans = 0;

      for (int i = 0; i < node.size(); i++)
      {
            // connected only
            auto a = node[i];
            int j = i + 1;
            bool one = 1;
            for (; j < node.size(); j++)
            {
                  auto b = node[j];

                  if (st.count({b.second, a.second}))
                  {
                        if (one)
                        {
                              cur = a.first + b.first - 2;
                              ans = max(ans, cur);
                              one = 0;
                        }
                  }
                  else
                  {
                        break;
                  }
            }

            for (; j < node.size(); j++)
            {
                  auto b = node[j];
                  if (st.count({b.second, a.second}) == 0)
                  {
                        cur = a.first + b.first - 1;
                        ans = max(ans, cur);
                        break;
                  }
            }

            // not connected only
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