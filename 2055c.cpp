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

void fixHor(auto &v, ll i, ll j, auto &s, ll t)
{
      ll n = s.size();

      ll vn = v.size();
      ll vm = v[0].size();

      if (t + 1 < n)
      {
            // need to check
            if (s[t] == 'R')
            {
                  return;
            }

            ll cur = 0;

            for (int cj = 0; cj < vm; cj++)
            {
                  if (cj == j)
                        continue;
                  cur += v[i][cj];
            }
            v[i][j] = -cur;
      }
      else
      {
            ll cur = 0;
            for (int cj = 0; cj < vm; cj++)
            {
                  if (cj == j)
                        continue;
                  cur += v[i][cj];
            }
            v[i][j] = -cur;
      }
}
void fixVer(auto &v, ll i, ll j, auto &s, ll t)
{
      ll n = s.size();

      ll vn = v.size();
      ll vm = v[0].size();

      if (t + 1 < n)
      {
            // need to check
            if (s[t] == 'D')
            {
                  return;
            }

            ll cur = 0;
            for (int ci = 0; ci < vn; ci++)
            {
                  if (ci == i)
                        continue;
                  cur += v[ci][j];
            }
            v[i][j] = -cur;
      }
      else
      {
            ll cur = 0;
            for (int ci = 0; ci < vn; ci++)
            {
                  if (ci == i)
                        continue;
                  cur += v[ci][j];
            }
            v[i][j] = -cur;
      }
}

void solve(ll test)
{
      ll n, m;
      cin >> n >> m;
      string s;
      cin >> s;
      vector<vector<ll>> v(n, vector<ll>(m, 0));

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < m; j++)
            {
                  cin >> v[i][j];
            }
      }

      ll ci = 0;
      ll cj = 0;

      ll si = 0;

      ll tot = 0;

      for (int i = 0; i < n + m - 2; i++)
      {

            if (s[i] == 'D')
            {
                  // hor
                  fixHor(v, ci, cj, s, i);
                  ci++;
            }
            else
            {
                  // ver
                  fixVer(v, ci, cj, s, i);
                  cj++;
            }

            // cout << ci << " " << cj << endl;
      }
      // hor
      fixHor(v, n - 1, m - 1, s, 0);

      // ver
      fixVer(v, n - 1, m - 1, s, 0);

      for (auto it : v)
      {
            for (auto i : it)
            {
                  cout << i << " ";
            }
            cout << endl;
      }
      // cout << endl;
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