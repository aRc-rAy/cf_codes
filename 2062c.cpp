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
vector<vector<ll>> pascal;
void getpascal()
{
      pascal.push_back({1});
      pascal.push_back({1, 1});
      for (int i = 1; i < 100; i++)
      {
            ll n = pascal.size();
            vector<ll> cur;
            cur.push_back(1);
            for (int i = 1; i < pascal[n - 1].size(); i++)
            {
                  cur.push_back(pascal[n - 1][i] + pascal[n - 1][i - 1]);
            }
            cur.push_back(1);
            pascal.push_back(cur);
      }
      // for (auto it : pascal)
      // {
      //       for (auto i : it)
      //       {
      //             cout << i << " ";
      //       }
      //       cout << endl;
      // }
      // cout << endl;
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
      ll ans = accumulate(begin(v), end(v), 0LL);
      while (n > 1)
      {
            vector<ll> temp;
            for (int i = 1; i < v.size(); i++)
            {
                  temp.push_back(v[i] - v[i - 1]);
            }
            ll cur = accumulate(begin(temp), end(temp), 0LL);
            ans = max(ans, abs(cur));
            v = temp;
            n--;
      }
      cout << ans << endl;
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      getpascal();
      int t = 1;
      cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}