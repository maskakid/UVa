#include<bits/stdc++.h>
using namespace std;

int parent[10001];
int n,m,A;

struct edge
{
    int u,v,w;
    edge(int _u, int _v, int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
    edge() {}
};

bool comp(edge a, edge b)
{
    return a.w<b.w;
}

vector<edge>vc;

int _find(int r)
{
    if(parent[r]==r)    return r;
    return parent[r]=_find(parent[r]);
}

int MST()
{
    sort(vc.begin(),vc.end(),comp);
    int cnt=0;
    int sum=0;
    for(int i=0; i<vc.size() and vc[i].w<A; i++)
    {
        int x=vc[i].u;
        int y=vc[i].v;
        x=_find(x);
        y=_find(y);
        if(x!=y)
        {
            parent[x]=y;
            cnt++;
            sum+=vc[i].w;
            if(cnt==n-1)    break;
        }
    }
    return sum;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&A);
        for(int i=0; i<m; i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            vc.push_back(edge(x,y,z));
        }

        for(int i=1; i<= n ; i++)    parent[i]=i;
        int ans=MST();
       // cout<<ans<<endl;
        set<int>ss;
        for(int i=1; i<=n; i++)
            ss.insert(_find(i));

        ans+=(ss.size()*A);

        printf("Case #%d: %d %d\n",cas++,ans,ss.size());
        vc.clear();
    }
    return 0;
}
