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
#define debug(x) cerr << #x << " " << x << endl;

struct node
{
      vector<node *> arr;
      vector<int> cnt;
      bool isend;
      int maxIndex;
      node() : isend(false)
      {
            cnt.resize(2);
            arr.resize(2, nullptr);
            maxIndex = -1;
      }

      bool has(int ch)
      {
            return arr[ch] != nullptr;
      }

      void put(int ch)
      {
            arr[ch] = new node();
      }
      bool remove(int ch)
      {
            if (cnt[ch] == 1)
            {
                  arr[ch] = nullptr;
                  cnt[ch] = 0;
                  return true;
            }
            cnt[ch]--;
            return false;
      }
      // ~node()
      // {
      //       delete this;
      // }
};

struct trie
{
      node *root;
      ll n;
      trie()
      {
            root = new node();
            n = 40;
      }

      ll get_state(ll i, ll num)
      {
            return ((num >> i) & 1);
      }

      void insert(ll num)
      {

            node *head = root;
            for (ll i = n; i >= 0; i--)
            {
                  ll state = get_state(i, num);

                  if (!head->has(state))
                        head->put(state);
                  head->cnt[state]++;
                  head = head->arr[state];
            }
      }
      void insert(ll num, int id)
      {
            node *head = root;
            head->maxIndex = id;
            for (ll i = n; i >= 0; i--)
            {
                  ll state = get_state(i, num);

                  if (!head->has(state))
                        head->put(state);
                  head->cnt[state]++;
                  head = head->arr[state];
                  head->maxIndex = id;
            }
      }

      ll getmax(ll num)
      {
            ll ans = 0;
            node *head = root;
            for (int i = n; i >= 0; i--)
            {
                  ll state = get_state(i, num);
                  ll opp = 1 - state;
                  if (head->has(opp))
                  {
                        head = head->arr[opp];
                        ans = ans + (1LL << i);
                  }
                  else if (head->has(state))
                  {
                        head = head->arr[state];
                  }
                  else
                  {
                        return ans;
                  }
            }
            return ans;
      }
      ll getmax(ll num, ll id)
      {
            node *head = root;
            ll ans = 0;
            for (int i = n; i >= 0; i--)
            {
                  ll state = get_state(i, num);
                  ll opp = 1 - state;
                  if (head->has(opp) && head->arr[opp]->maxIndex >= id)
                  {
                        head = head->arr[opp];
                        ans = ans + (1LL << i);
                        continue;
                  }

                  head = head->arr[state];
            }
            return ans;
      }
      void remove(ll num)
      {
            node *head = root;
            // debug(num);
            for (int i = n; i >= 0; i--)
            {
                  ll state = get_state(i, num);
                  // debug(state);
                  // debug(head.cnt[state]);
                  if (head->remove(state))
                        return;
                  head = head->arr[state];
            }
      }
      ~trie()
      {
            delete root;
      }
};
void solve(ll test)
{
      ll n, k;
      cin >> n >> k;

      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      ll pi = 0;
      ll ans = 1e10;

      trie t;

      for (ll i = 0; i < n; i++)
      {
            t.insert(v[i], i);
            while (pi <= i && t.getmax(v[i], pi) >= k)
            {
                  ans = min(ans, i - pi + 1);
                  // t.remove(v[pi]);
                  pi++;
            }
            // debug(t.getmax(v[i], pi));

            // debug(t.root.cnt[0]);
            // debug(t.root.cnt[1]);
      }
      cout << (ans == 1e10 ? -1 : ans) << endl;
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