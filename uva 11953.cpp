#include<bits/stdc++.h>
using namespace std;

char graph[110][110];
int visit[110][110];
int n,cas=1;

void flood_fill(int i, int j)
{
    if(i<0 or j<0 or i>=n or j>=n) return;
    if(graph[i][j]=='.' or visit[i][j]==cas) return;
    visit[i][j]=cas;
    flood_fill(i+1,j);
    flood_fill(i-1,j);
    flood_fill(i,j+1);
    flood_fill(i,j-1);

    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%s",graph[i]);
        int cnt=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(graph[i][j]=='x' and visit[i][j]!=cas)
                {
                    cnt++;
                    flood_fill(i,j);
                }
        printf("Case %d: %d\n",cas++,cnt);
    }
    return 0;
}
