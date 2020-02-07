#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int > pa;
int tot=0,n,m,ts,te,fir[5000],dis[5000];
struct Edge{
    int u,v,nxt,w;
}e[100000];
void addedge(int x,int y,int w)
{
    e[++tot].u=x;
    e[tot].v=y;
    e[tot].w=w;
    e[tot].nxt=fir[x];
    fir[x]=tot;
}
void dijkstra()
{
    priority_queue<pa,vector<pa >,greater<pa> >     q;
    q.push(make_pair(ts,0));
    for(int i=1;i<=n;i++)
      dis[i]=100001938;
    dis[ts]=0;  
    while(!q.empty())
    {
        int now=q.top().first;
        int val=q.top().second;
        q.pop();
        for(int i=fir[now];i;i=e[i].nxt)
        {
            int to=e[i].v;
            if(dis[to]>val+e[i].w)
            {
                dis[to]=val+e[i].w;
                q.push(make_pair(to,dis[to]));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&ts,&te);
    int x,y,w;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        addedge(x,y,w);
        addedge(y,x,w);
    }
    dijkstra();
    printf("%d",dis[te]);
    return 0;
}