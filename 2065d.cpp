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
      vector<vector<ll>> v(n, vector<ll>(m));
      for (auto &it : v)
      {
            for (auto &i : it)
            {
                  cin >> i;
            }
      }
      sort(begin(v), end(v), [&](auto &a, auto &b)
           {
            ll cnt=1;
            ll sa=0;
            ll sb=0;
            for(int i=0;i<m;i++){
                  sa+=a[i];
                  sb+=b[i];
            }

            if(sa>sb)return true;
            return false; });
      ll num = n * m;

      ll ans = 0;
      for (auto it : v)
      {
            for (auto i : it)
            {
                  ans = ans + num * i;
                  num--;
            }
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