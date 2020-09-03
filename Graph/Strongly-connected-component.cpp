//printing all strongly connected components in O(n+m)
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector< vector<int> > graph,rgraph;
vector<int> tout;
bool visited[10010];
void dfs1(int node)
{
	visited[node]=true;
	for(auto x: graph[node])
	{
		if(!visited[x])
			dfs1(x);
	}
	tout.emplace_back(node);
}

void dfs2(int node)
{
	visited[node]=true;
    printf("%d ",node);
	for(auto x: rgraph[node])
	{
		if(!visited[x])
			dfs2(x);
	}
}

void solve()
{
    printf("Number of nodes and edges:\n");
	scanf("%d %d",&n,&m);
	graph=vector<vector<int>> (n+1);
    rgraph=vector<vector<int> > (n+1);
	memset(visited,false,sizeof(visited));
	tout.clear();
    printf("Enter the edges: \n");
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		graph[u].emplace_back(v);
        rgraph[v].emplace_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			dfs1(i);
	}
	memset(visited,false,sizeof(visited));
	int cnt=1;
	for(int i=0;i<n;i++)
	{
		int node=tout[n-i-1];
        if(!visited[node])
        {
            printf("SCC - %d :\n",cnt++);
            dfs2(node);
        }
        printf("\n");
	}
}
int main()
{
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		printf("Case %d: ",cn);
		solve();
	}
    return 0;
}

