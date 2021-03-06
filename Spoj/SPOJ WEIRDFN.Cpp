#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
ll f[200009];
ll MOD=1000000007;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      ll a,b,c,n;
      scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
      ll ans=0;
      f[1]=1;
      ans+=1;

      priority_queue<ll> gr;
      priority_queue< ll, vector<ll>, greater<ll> > ls;
      gr.push(1);
      for(int i=2;i<=n;i++)
      {
         ll m=gr.top();


          f[i]=(1ll*a*m + 1ll*b*i+c)%MOD;
          ans+=f[i];

          if(f[i]>gr.top())
            ls.push(f[i]);
          else
            gr.push(f[i]);

          while(sz(gr)-1>sz(ls))
           ls.push(gr.top()),gr.pop();

          while(sz(ls)>sz(gr))
            gr.push(ls.top()),ls.pop();


      }

      printf("%lld\n",ans);
    }
}

