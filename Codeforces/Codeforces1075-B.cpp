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
const int N = 2e5+7;
int T,n,m;
int a[N];
VI b;
int ans[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int len = 0;
    cin >> n >> m;
    rep(i, 1, n+m + 1) cin >> a[i];
    rep(i,1,n+m+1){
        int x;
        cin >> x;
        if(x==1){
            b.pb(i);
            len++;
        }
    }
    n = n + m;
    ans[b[0]] += b[0] - 1;
    ans[b[len-1]] += n - b[len-1];
    int i = 0, j = 1;
    while(j<len){
        int k = b[i];
        while(k<b[j] && a[b[j]]-a[k] >= a[k]-a[b[i]]) k++;
        // printf("k:%d\n", k);
        ans[b[i]] += max(0, k - b[i] - 1);
        ans[b[j]] += max(0, b[j] - k);
        // printf("i;j;%d %d\n", b[i], b[j]);
        i++, j++;
    }

    rep(i,0,len){
        printf(i==len?"%d\n":"%d ", ans[b[i]]);
    }

    return 0;
}