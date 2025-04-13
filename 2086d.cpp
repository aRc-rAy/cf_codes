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

#define debug(x) cerr << "Line " << __LINE__ << ": " << #x << " has " << x << endl;

ll fac[500005];
ll ifac[500005];

ll binpow(ll a, ll b)
{
      if (b == 0)
            return 1LL;

      if (b == 1)
            return a;

      ll temp = binpow(a, b / 2);

      ll ans = (temp * temp) % mod;

      if (b % 2)
      {
            ans = (ans * a) % mod;
      }
      return ans;
}

void fill()
{
      fac[0] = 1;
      ifac[0] = 1;
      for (int i = 1; i < 500005; i++)
      {
            fac[i] = i * (i - 1 ? fac[i - 1] : 1);
            fac[i] %= mod;
            ifac[i] = binpow(fac[i], mod - 2);
            ifac[i] %= mod;
      }
}

ll find(vector<vector<ll>> &dp, ll sum, ll id, vector<int> &weight, ll &capacity)
{
      if (sum == capacity)
      {
            return 1;
      }

      if (id >= 26 || sum > capacity)
      {
            return 0;
      }

      ll &an = dp[sum][id];

      if (an != -1)
            return an;

      ll take = 0;
      ll no_take = 0;

      // take
      if (weight[id])
            take = find(dp, sum + weight[id], id + 1, weight, capacity);

      // no_take
      no_take = find(dp, sum, id + 1, weight, capacity);

      an = take + no_take;
      return an;
}
void solve(ll test)
{
      vector<int> v(26);
      for (auto &it : v)
      {
            cin >> it;
      }

      ll tot_sum = accumulate(begin(v), end(v), 0LL);

      // ll ans = 0;

      vector<vector<ll>> dp((tot_sum), vector<ll>(27, -1));

      ll capacity = (tot_sum) / 2;
      debug(capacity);

      ll ways = find(dp, 0, 0, v, capacity);
      debug(ways);

      ways = (ways * fac[capacity]) % mod;
      debug(ways);

      ll rem = tot_sum - capacity;
      ways = (ways * fac[rem]) % mod;
      debug(ways);

      for (auto it : v)
      {
            ways = (ways * ifac[it]) % mod;
      }
      debug(ways);
      cout << ways << endl;
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      fill();
      int t = 1;
      cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}