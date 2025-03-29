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
      set<ll> st;

      set<ll> has;
      ll n;
      cin >> n;
      vector<ll> v(n);
      for (int i = 1; i <= 2 * n; i++)
      {
            st.insert(i);
      }
      for (auto &it : v)
      {
            cin >> it;
            st.erase(it);
      }
      for (int i = 0; i < n; i++)
      {
            if (has.find(v[i]) == has.end())
            {
                  has.insert(v[i]);
                  cout << v[i] << " ";
            }
            else
            {
                  cout << *st.begin() << " ";
                  st.erase(*st.begin());
            }
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