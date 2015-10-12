#include<bits/stdc++.h>
using namespace std;

int A[100010];
vector<int>vc[100010];
int n,m,cas=1;

void dfs(int u)
{
    if(A[u]==cas)   return;
    A[u]=cas;
    for(int i=0 ; i<vc[u].size(); i++)
    {
        if(A[vc[u][i]]!=cas)
        dfs(vc[u][i])  ;
    }
    return;
}

int main()
{
    while(scanf("%d %d",&n,&m) and (n>0 and m>0))
    {
        int ans=0;
        for(int k=0; k<m;k++)
        {
            int i,j;
            scanf("%d %d",&i,&j);
            vc[i].push_back(j);
            vc[j].push_back(i);
        }

        for(int i=1; i<=n; i++)
            A[i]!=cas ? dfs(i),ans+=1,A[i]=cas : ans;

        printf("Case %d: %d\n",cas++,ans);

        for(int i=1;i<=n;i++) vc[i].clear();
    }
    return 0;
}
