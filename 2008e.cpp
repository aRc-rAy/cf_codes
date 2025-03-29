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

ll find(auto &le, auto &lo, auto &re, auto &ro, ll n)
{
      ll om = n;

      ll em = n;

      n = n / 2;

      for (int i = 0; i < 26; i++)
      {
            ll toto = lo[i] + ro[i];

            ll tote = le[i] + re[i];

            ll oans = n - toto;
            ll eans = n - tote;

            om = min(om, oans);
            em = min(em, eans);
      }

      return om + em;
}
void solve(ll test)
{
      ll n;
      cin >> n;

      string s;
      cin >> s;

      map<char, ll> od;
      map<char, ll> ev;

      ll mxo = 0;
      ll mxe = 0;

      vector<ll> vo(n), ve(n);

      vector<vector<ll>> vecto(n, vector<ll>(26, 0));
      vector<vector<ll>> vecte(n, vector<ll>(26, 0));
      vector<vector<ll>> Rvecto(n, vector<ll>(26, 0));
      vector<vector<ll>> Rvecte(n, vector<ll>(26, 0));

      for (int i = 0; i < n; i++)
      {
            if (i % 2 == 0)
            {
                  od[s[i]]++;
                  mxo = max(mxo, od[s[i]]);
                  vecto[i][s[i] - 'a']++;
            }
            else
            {
                  ev[s[i]]++;
                  mxe = max(mxe, ev[s[i]]);
                  vecte[i][s[i] - 'a']++;
            }

            for (int j = 0; j < 26; j++)
            {
                  vecto[i][j] += (i ? vecto[i - 1][j] : 0);
                  vecte[i][j] += (i ? vecte[i - 1][j] : 0);
            }
      }

      if (n % 2 == 0)
      {
            ll rem = n - mxo - mxe;
            cout << rem << endl;
            return;
      }

      for (int i = n - 1; i >= 0; i--)
      {

            if (i % 2 == 0)
            {
                  Rvecto[i][s[i] - 'a']++;
            }
            else
            {

                  Rvecte[i][s[i] - 'a']++;
            }

            for (int j = 0; j < 26; j++)
            {
                  Rvecto[i][j] += (i != (n - 1) ? Rvecto[i + 1][j] : 0);
                  Rvecte[i][j] += (i != (n - 1) ? Rvecte[i + 1][j] : 0);
            }
      }

      if (n == 1)
      {
            cout << 1 << endl;
            return;
      }

      ll ans = n;

      for (int i = 0; i < n; i++)
      {
            vector<ll> temp(26, 0);
            // delete this index and calculate the ans
            ll cur = 0;
            if (i % 2 == 0)
            {
                  if (i == 0)
                  {
                        cur = find(temp, temp, Rvecto[i + 1], Rvecte[i + 1], n);
                  }
                  else if (i == n - 1)
                  {
                        cur = find(vecto[i - 1], vecte[i - 1], temp, temp, n);
                  }
                  else
                  {
                        cur = find(vecte[i - 1], vecto[i - 1], Rvecto[i + 1], Rvecte[i + 1], n);
                  }
            }
            else
            {
                  cur = find(vecte[i - 1], vecto[i - 1], Rvecto[i + 1], Rvecte[i + 1], n);
            }
            // cout << cur << endl;
            ans = min(cur, ans);
      }

      cout << ans + 1 << endl;
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