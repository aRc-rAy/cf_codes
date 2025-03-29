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
void find(auto &v, int n, ll pow)
{
      if (n == 1)
      {
            v[0] = 1;
            return;
      }

      if ((1LL << pow) >= n)
      {
            find(v, n, pow - 1);
      }
      else
      {
            ll rem = n - (1LL << pow);
            find(v, rem, pow);

            for (int t = 0; t < rem; t++)
            {
                  v[n - 1 - t] = v[t];
            }
      }
}
void solve(ll test)
{
      ll n, k;
      cin >> n >> k;
      vector<ll> v(n);

      find(v, n, 32);

      for (auto it : v)
      {
            cout << it * k << " ";
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