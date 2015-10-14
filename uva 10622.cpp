#include<bits/stdc++.h>
#define LL long long int
using namespace std;

LL n;

LL solve(LL n)
{
    for(LL i=32; i>1; i--)
    {
        double nn=pow(double(n),1/(double)i);
        LL nnn=(LL)(nn+1e-9);
        if(fabs(nn-nnn)<1e-9)
        {
            LL cnt=1;
            for(int j=0; j<i; j++)
                cnt*=nnn;
            if(cnt==n)  return i;
        }
    }
    return 1;
}

int main()
{
#ifdef akid
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    while(scanf("%lld",&n) and n!=0)
    {
        bool ok=1;
        if(n<0) n*=-1,ok=0;
        LL ans=solve(n);
        if(ok==0)   while(ans%2==0) ans/=2;
        printf("%lld\n",ans);
    }
    return 0;
}
