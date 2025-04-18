#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[36m"
#define RESET "\033[0m"
#define debug(x) cerr << YELLOW << "Line [" << __LINE__ << "]\t" << #x << " -> " << x << RESET << endl;
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}
void solve(ll test)
{
      ll n, k;
      cin >> n;
      cin >> k;

      string a;
      string b;

      cin >> a >> b;
      unordered_set<char> st;
      for (auto it : a)
      {
            st.insert(it);
      }
      vector<char> avl(begin(st), end(st));

      ll len = avl.size();

      ll ans = 0;
      vector<bool> take(26);
      for (ll i = 0; i <= (1LL << len) - 1; i++)
      {

            ll cans = 0;
            ll cnt = 0;

            ll match = 0;
            for (ll j = 0; j < len; j++)
            {
                  if ((1ll << j) & i)
                  {
                        take[avl[j] - 'a'] = 1;
                        match++;
                  }
            }

            if (match > k)
            {
                  for (int j = 0; j < 26; j++)
                        take[j] = 0;
                  continue;
            }

            for (int j = 0; j < n; j++)
            {
                  if (a[j] == b[j] || take[a[j] - 'a'])
                  {
                        cnt++;
                        continue;
                  }

                  cans += ((cnt * (cnt + 1)) / 2);
                  cnt = 0;
            }

            cans += ((cnt * (cnt + 1)) / 2);
            ans = max(ans, cans);

            for (int j = 0; j < 26; j++)
                  take[j] = 0;
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