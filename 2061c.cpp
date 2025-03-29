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
void solve(ll test)
{
      ll n;
      cin >> n;
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      map<vector<ll>, ll> omp;
      if (v[0] == 0)
      {
            omp[{0, 0}] = 1;
            omp[{1, 1}] = 1;
      }
      else
      {
            omp[{1, 1}] = 1;
            omp[{0, 0}] = 0;
      }

      if (n == 1)
      {
            if (v[0] == 0)
            {
                  cout << 2 << endl;
            }
            else
            {
                  cout << 1 << endl;
            }
            return;
      }

      for (int i = 1; i < n; i++)
      {
            map<vector<ll>, ll> nmp;
            // i is honest
            nmp[{v[i], 0}] = (omp[{v[i], 0}] + omp[{v[i], 1}]) % mod;
            // i is liar
            nmp[{v[i - 1] + 1, 1}] = omp[{v[i - 1], 0}];

            omp = nmp;
      }

      cout << (omp[{v[n - 1], 0}] + omp[{v[n - 2] + 1, 1}]) % mod << endl;
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