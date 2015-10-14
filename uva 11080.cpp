#include<bits/stdc++.h>
using namespace std;

vector<int>vc[300];
int color[300];
int node,edge;

int bipartite(int s)
{
    queue<int>q;
    q.push(s);
    color[s]=1;
    int one=1;
    int zero=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<vc[u].size();i++)
        {

            int v=vc[u][i]; //cout<<u<<"****"<<v<<endl;
            if(color[v]==-1)
            {
                color[v]=1-color[u];
                if(color[v]==1) one++;
                else if(color[v]==0) zero++;
                q.push(v);
            }
            else if(color[u]==color[v]) return -1;
        }
    }
    if(zero==0) return one;
    return min(zero,one);
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&node,&edge);
        for(int i=0 ;i<edge; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            vc[u].push_back(v);
            vc[v].push_back(u);
        }
        for(int i=0;i<node; i++)    color[i]=-1;
        int ans=0;
        for(int i=0; i<node; i++)
        {
            if(color[i]==-1)
            {
                int tmp=bipartite(i);
               // cout<<i<<" "<<tmp<<endl;
                if(tmp==-1)
                {
                    ans=-1;
                    break;
                }
                else ans+=tmp;
            }
        }
        printf("%d\n",ans);
        for(int i=0; i<node; i++)   vc[i].clear();
    }
    return 0;
}
