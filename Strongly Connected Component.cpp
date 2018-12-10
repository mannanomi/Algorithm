#include<bits/stdc++.h>
#define white 0
#define grey 1
#define black 2
using namespace std;

int graph[100][100],color[100],prev[100],d[100],f[100],v,x,y,u,tim,i,a[100];

void create_graph()
{
    printf("Enter the number of nodes: ");
    cin>>v;
    printf("Enter the Nodes: \n");
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
        }
        else if(x>v||y>v)
        {
            cout<<"\nInvalid Input\n";
        }
        else
        {
            graph[x][y]=1;
        }
    }
}

void insertion_sort()
{
    for(int j=2;j<=v;j++)
    {
        int key=a[j];
        int i=j-1;
        while(i>=1&&a[i]<key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
}

void transpose()
{
    for(int i=1;i<=v;i++)
    {
        for(int j=i+1;j<=v;j++)
        {
            swap(graph[i][j],graph[j][i]);
        }
    }
}

void DFS_Visit(int sour)
{
    color[sour]=grey;
    tim++;
    d[sour]=tim;
    for(int i=1;i<=v;i++)
    {
        if(graph[sour][i]&&color[i]==white)
        {
            prev[i]=sour;
            DFS_Visit(i);
        }
    }
    color[sour]=black;
    tim++;
    f[sour]=tim;
    a[sour]=f[sour];
}

void DFS_Visit1(int sour)
{
    color[sour]=grey;
    cout<<sour<< " ";
    for(int i=1;i<=v;i++)
    {
        if(graph[sour][i]&&color[i]==white)
        {
            //cout<<"Hello 3";
            prev[i]=sour;
            DFS_Visit1(i);
        }
    }
    color[sour]=black;
}
/*Initialize color again*/
void back_to_prev_color()
{
    for(int i=1;i<=v;i++)
    {
        color[i]=white;
    }
}

void DFS()
{
    for(int i=1; i<=v; i++)
    {
        color[i]=white;
        prev[i]=-1;
        d[i]=INT_MAX;
        f[i]=INT_MAX;
    }
    tim=0;
    cout<< "\nEnter the vertex you want to start with:";
    cin>>i;
    if(i<=v&&i>0&&color[i]==white)
    {
        DFS_Visit(i);
    }
    for(int i=1;i<=v;i++)
    {
        if(color[i]==white)
        {
            DFS_Visit(i);
        }
    }
    insertion_sort();
    //cout<<"Hello1 ";
    transpose();
    //cour<<"hello2 ";
    back_to_prev_color();
    cout<< "\nThe strongly connected components are:\n";
    for(int u=1;u<=v;u++)
    {
        int flag=0;
        for(int i=1;i<=v;i++)
        {
            if(a[u]==f[i]&&color[i]==0)
            {
                //cout<<"Hello 4";
                DFS_Visit1(i);
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            //cout<<"Hello 5";
            cout<<endl<<endl;
            flag=0;
        }
    }

}

int main()
{
    create_graph();
    DFS();
    return 0;
}
