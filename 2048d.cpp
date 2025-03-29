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
      ll n, m;
      cin >> n >> m;

      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      vector<ll> p(m);
      for (auto &it : p)
      {
            cin >> it;
      }

      sort(begin(p), end(p));
      ll me = v[0];

      sort(begin(v), end(v));

      ll my = -1;
      for (int i = 0; i < n; i++)
      {
            if (v[i] == me)
            {
                  my = i;
                  break;
            }
      }

      ll st = 0;
      vector<ll> ans;

      for (int i = 0; i < m; i++)
      {
            ll dif = p[i];
            while (st < n && v[st] < dif)
            {
                  st++;
            }
            ll tans = 1;
            if (my >= st)
            {
                  tans = 1;
            }
            else
            {
                  tans = n - st;
            }

            ans.push_back(tans);
      }
      for (auto it : ans)
      {
            cout << it << " ";
      }
      cout << endl;
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