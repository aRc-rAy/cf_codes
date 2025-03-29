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
      string a;
      cin >> a;
      string b = "";
      int n = a.size();
      for (int i = n - 1; i >= 0; i--)
      {
            if (a[i] == 'p')
            {
                  b += 'q';
            }
            else if (a[i] == 'w')
            {
                  b += 'w';
            }
            else
            {
                  b += 'p';
            }
      }
      cout << b << endl;
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