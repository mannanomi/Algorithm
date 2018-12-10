#include<bits/stdc++.h>
#define white 0
#define grey 1
#define black 2
using namespace std;

int graph[100][100],color[100],prev[100],d[100],f[100],v,x,y,sour,tim,low[100],a[100];

void create_graph()
{
    cout<< "Enter the number of nodes: ";
    cin>> v;
    printf("Enter the nodes\n");
    /*Enter 0 0 to end the loop*/
    while(1)
    {
        cin>>x>>y;
        if(x==0&&y==0)
        {
            break;
        }
        else if(x<0||y<0)
        {
            cout<<"\nInvalid Input\n";
            continue;
        }
        else if(x>v||y>v)
        {
            cout<<"\nInvalid Input\n";
            continue;
        }
        graph[x][y]=1;
        graph[y][x]=1;
    }
}

void DFS_Visit(int sour)
{
    color[sour]=grey;
    d[sour]=++tim;
    low[sour]=d[sour];
    for(int i=1; i<=v; i++)
    {
        if(graph[sour][i]==1&&color[i]==white)
        {
            prev[i]=sour;
            DFS_Visit(i);
            /*checking the articulation point*/
            if(low[i]>=d[sour]&&a[sour]==0)
            {
                int child=0;
                if(prev[sour]==-1)
                {
                    /*Count The number of childs*/
                    for(int j=1; j<=v; j++)
                    {
                        if(graph[sour][j]==1&&prev[j]==sour)
                        {
                            child++;
                        }
                    }
                }
                /*If the node is the source of the graph and has more than "1" child that
                the node is an articulation point*/
                if(prev[sour]==-1&&child>1)
                {
                    cout<<endl<<sour<< " is an articulation point\n";
                    a[sour]=1;
                }
                else if(child==0)
                {
                    cout<<endl<<sour<< " is an articulation point\n";
                    a[sour]=1;
                }

            }
            if(low[i]<low[sour])
            {
                low[sour]=low[i];
            }
        }
        else if(graph[sour][i]==1)
        {
            if(d[i]<low[sour])
            {
                low[sour]=d[i];
            }
        }
    }
    color[sour]=black;
    f[sour]=++tim;
}
/*Basic DFS Algorithm*/
void DFS()
{
    for(int i=1; i<=v; i++)
    {
        color[i]=white;
        prev[i]=-1;
        a[i]=0;
        d[i]=INT_MAX;
        f[i]=INT_MAX;
        low[i]=INT_MAX;
    }
    tim=0;
    for(int i=1; i<=v; i++)
    {
        if(color[i]==white)
        {
            DFS_Visit(i);
        }
    }
}

int main()
{
    create_graph();
    DFS();
    return 0;
}

