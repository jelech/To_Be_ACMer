#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e5+7;
int T, n;
ll m,ans;
int a[N];
ll sorted[N], pre[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i,1,n+1){
        scanf("%d", a + i);
        sorted[i] = a[i];
    }
    sort(sorted + 1, sorted + 1 + n);
    rep(i,1,n+1){
        pre[i] = pre[i - 1] + sorted[i];
    }
    while(m>=sorted[1]){
        int len = upper_bound(sorted + 1, sorted + 1 + n, m) - (sorted + 1);
        if (len >= 1 && pre[len] <= m){
            ans += len * 1ll * (m / pre[len]);
            m %= pre[len];
        }
        else{
            rep(i,1,n) if(a[i]<=m){
                ans++, m -= a[i];
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}