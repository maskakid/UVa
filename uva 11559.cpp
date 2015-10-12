#include<bits/stdc++.h>
#define LL long long int
#define INF 0x3f3f3f3f3
using namespace std;

LL B, H ,W;
LL p;
LL n;

int main()
{
    while(~scanf("%lld %lld %lld %lld",&n,&B,&H,&W))
    {
        LL ans=INF;
        while(H--)
        {
            scanf("%lld",&p);
            for(int i=0; i<W; i++)
            {
                LL x;
                scanf("%lld",&x);
                x>=n and p*n<=B ? ans=min(ans,p*n): ans;
            }
        }
        ans==INF? printf("stay home\n"): printf("%lld\n",ans);
    }
    return 0;
}

