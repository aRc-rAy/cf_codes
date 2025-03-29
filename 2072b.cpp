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
      ll n;
      cin >> n;
      string s;
      cin >> s;

      ll a = 0;
      ll b = 0;

      for (auto it : s)
      {
            if (it == '-')
            {
                  a++;
            }
            else
            {
                  b++;
            }
      }

      ll half = a / 2;

      ll ahalf = half + (a % 2 ? 1 : 0);

      cout << (half * ahalf * b) << endl;
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