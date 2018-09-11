#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e6+7;
int T,n,k,a[N];
ll m;

bool check(int mid)
{
    int r = 1, num = 0;
    ll ans = 0;
    for (int l = 1; l <= n; l++)
    {
        if (a[l] >= mid)
            num++;
        if (num == k)
        {
            ans += n - l + 1;
            while (a[r] < mid)
            {
                ans += n - l + 1;
                r++;
            }
            num--;
            r++;
        }
    }
    if (ans >= m)
        return true;
    else
        return false;
}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for (cin >> T; T;T--){
        cin >> n >> k >> m;
        int l=1, r = 0;
        rep(i,1,n+1){
            cin >> a[i];
            r = max(r, a[i]);
        }
        r = 1e9;
        while(l<r){
            int mid = (l + r) >> 1;
            if(check(mid)){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        cout << l-1 << endl;
    }
    return 0;
}

