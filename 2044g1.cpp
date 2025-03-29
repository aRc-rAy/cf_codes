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

class DSU
{
public:
      vector<ll> par;
      vector<ll> tot;

      DSU(ll n)
      {
            par.resize(n);
            tot.resize(n, 1);

            for (int i = 0; i < n; i++)
            {
                  par[i] = i;
            }
      }

      ll find_par(ll n)
      {
            if (par[n] == n)
            {
                  return n;
            }
            return par[n] = find_par(par[n]);
      }

      void union_all(ll n, ll m)
      {

            ll a = find_par(n);
            ll b = find_par(m);

            if (a == b)
                  return;

            ll sa = tot[a];
            ll sb = tot[b];

            if (sa < sb)
            {
                  tot[a] += tot[b];
                  par[b] = a;
            }
            else
            {
                  tot[b] += tot[a];
                  par[a] = b;
            }
      }
};
void solve(ll test)
{
      ll n;
      cin >> n;
      vector<ll> v(n + 1);
      vector<ll> inn(n + 1);
      vector<ll> graph[n + 1];
      for (int i = 1; i <= n; i++)
      {
            cin >> v[i];
            inn[i]++;
            inn[v[i]]++;
            graph[i].push_back(v[i]);
            graph[v[i]].push_back(i);
      }

      queue<ll> q;
      for (int i = 1; i <= n; i++)
      {
            if (inn[i] == 1)
            {
                  q.push(i);
            }
      }
      ll ans = 0;
      while (q.size())
      {
            ll k = q.size();
            for (ll t = 0; t < k; t++)
            {
                  ll num = q.front();
                  // cout << num << " ";
                  q.pop();

                  for (auto adj : graph[num])
                  {
                        inn[adj]--;
                        if (inn[adj] == 1)
                        {
                              q.push(adj);
                        }
                  }
            }
            // cout << endl;
            ans++;
      }
      cout << ans + 2 << endl;
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