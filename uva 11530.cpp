#include<bits/stdc++.h>
using namespace std;

int A[]= {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        string ss;
        getline(cin,ss);
        int ans=0;
        for(int i=0; i<ss.size(); i++)
            ss[i]==' '? ans+=1 : ans+=(A[ss[i]-'a']);
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
