bool isBipartite(int G[][MAX],int V)
{
    int i, v, u;
    int color[V];
    for(int i=0;i<V;i++)
       color[i]=-1;

    color[0]=1;

    for(u=0; u<V; u++)
    {
        if(G[u][u]==1)
            return false;

        for(v=0; v<V; v++)
        {
            if(G[u][v]==1 && color[v]==-1)
            {
                color[v]=1-color[u];
            }

            else if(G[u][v]==1 && color[u]==color[v])
                return false;

        }
     }

     return true;
}
