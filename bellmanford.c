#include<stdio.h>
#include<stdlib.h>

int maxi=999;

void bellman(int g[10][3],int v,int e,int s)
{
    int dis[10];
    int i;
    for(i=0;i<v;i++)
        dis[i]=maxi;
    
    dis[s]=0;
    int j;
    
    for(i=0;i<v-1;i++)
    {
        for(j=0;j<e;j++)
        {
            int u=g[j][0];
            int v=g[j][1];
            int wt=g[j][2];

            if(dis[u]!=maxi && dis[u] + wt<dis[v])
                dis[v]=dis[u] + wt;
        }
    }
    //checking negative cycle optional
    for(i=0;i<e;i++)
    {
        int u=g[i][0];
        int v=g[i][1];
        int wt=g[i][2];

        if(dis[u]!=maxi && dis[u]+wt<dis[v])
        {
            printf("graph contain negative cycle\n");
            return;
            
        }
    }

    printf("Vertex distance    source\n");
    for(i=0;i<v;i++)
        printf("%d             %d\n",i,dis[i]);

}
int main()
{
    int v;
    int e;

    printf("Enter the number of edges\n");
    scanf("%d",&e);

    printf("Enter the number of vertex\n");
    scanf("%d",&v);

    int g[10][3];
    int i,j;

    printf("Enter the graph(u,v,weight)\n");
    for(i=0;i<e;i++)
    {
        for(j=0;j<3;j++)
            scanf("%d",&g[i][j]);
    }

    int s=0;
    printf("Enter the source\n");
    scanf("%d",&s);
    
    bellman(g,v,e,s);
    return 0;
}