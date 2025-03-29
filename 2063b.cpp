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
      ll n, l, r;
      cin >> n >> l >> r;
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      l--;
      r--;
      vector<ll> a, b;
      for (int i = 0; i <= r; i++)
      {
            a.push_back(v[i]);
      }
      for (int i = l; i < n; i++)
      {
            b.push_back(v[i]);
      }
      sort(begin(a), end(a));
      sort(begin(b), end(b));

      ll ma = accumulate(begin(a), begin(a) + (r - l + 1), 0LL);
      ll mb = accumulate(begin(b), begin(b) + (r - l + 1), 0LL);

      cout << min(ma, mb) << endl;
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