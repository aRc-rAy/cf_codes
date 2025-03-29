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
      ll n, k, l;
      cin >> n >> k >> l;

      k = k << 1;
      l = l << 1;

      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
            it = it << 1;
      }

      ll time = v[0];
      v[0] = 0;
      ll pos = v[0] + k;

      ll ptr = 1;

      while (ptr < n && pos < l)
      {
            if (v[ptr] > pos)
            {
                  v[ptr] = max(pos, v[ptr] - time);
                  ll dis = (v[ptr] - pos) / 2;
                  time += dis;
                  v[ptr] -= dis;
                  pos = v[ptr] + k;
            }
            else
            {
                  v[ptr] = min(v[ptr] + time, pos);
                  pos = v[ptr] + k;
            }
            // cout << ptr << " " << pos << " " << time << endl;
            ptr++;
      }
      if (pos < l)
      {
            time += l - pos;
      }
      cout << time << endl;
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