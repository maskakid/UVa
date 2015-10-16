/*
    Author      : Akid (CSE'11,CUET)

    Resources   : http://www.algorithmist.com/index.php/Euler's_Phi_function
*/

#include<bits/stdc++.h>
#define LL long long int
using namespace std;

LL phi_function(LL n)
{
    if(n==1)    return 1LL;
    LL ans=n;

    if(n%2==0)
    {
        ans-=(ans/2);
        while(n%2==0)   n/=2;
    }

    for(LL i=3; i*i <=n ; i+=2)
    {
        if(n%i==0)
        {
            ans-=(ans/i);
            while(n%i==0)   n/=i;
        }
    }

    if(n>1) ans-=(ans/n);
    return ans;
}

int main()
{
    LL n;
    while(scanf("%lld",&n) and n>0)
        printf("%lld\n",phi_function(n));
    return 0;
}
