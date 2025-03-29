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
      multiset<int> s;
      int n;
      cin >> n;
      s.insert(0);
      s.insert(0);
      s.insert(0);
      s.insert(1);
      s.insert(2);
      s.insert(2);
      s.insert(3);
      s.insert(5);

      vector<int> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      int t = 1;
      for (auto it : v)
      {
            if (s.find(it) != s.end())
            {
                  s.erase(s.find(it));
            }
            if (s.size() == 0)
            {
                  cout << t << endl;
                  return;
            }
            t++;
      }
      cout << 0 << endl;
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