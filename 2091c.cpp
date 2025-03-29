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
      int n;
      cin >> n;

      if (n % 2 == 0)
      {
            cout << -1 << endl;
            return;
      }

      vector<int> pos(n + 1);

      int mid = (n + 1) / 2;
      for (int i = mid; i <= n; i++)
      {
            pos[i] = i - mid;
      }
      for (int i = 1; i < mid; i++)
      {
            pos[i] = pos[n] + i;
      }
      vector<int> ans(n + 1);
      for (int i = 1; i <= n; i++)
      {
            int move = pos[i];

            // front me
            int front = n - i;
            if (move <= front)
            {
                  ans[i] = i + move;
            }
            else
            {
                  move -= front;
                  ans[i] = move;
            }
      }
      for (int i = 1; i <= n; i++)
      {
            cout << ans[i] << " ";
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