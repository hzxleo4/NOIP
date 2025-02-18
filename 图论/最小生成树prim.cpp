#include <iostream>
#include<cstring>
#define maxn 25025048;
using namespace std;
int n,m,a[5001][5001]={0},dis[100001]={0},f[100001]={0};
int main()
{
    cin>>n>>m;
    memset(a,1,sizeof(a));
    for(int i=1,u,v,d;i<=m;i++){
    	 cin>>u>>v>>d;
        if(d<a[u][v])
			a[u][v]=d,a[v][u]=d;//---因为有重边，所以读入时选择最小的边
	}
       
    memset(dis,1,sizeof(dis)); //---赋最大值
    for(int i=1;i<=n;i++)f[i]=1;//---把所有点赋值为蓝点
    dis[1]=0;//---第一个点赋值为白点
    for(int i=1;i<=n;i++)
    {
        int k=0;
        for(int j=1;j<=n;j++)
			if(f[j]==1 && (dis[j]<dis[k]))
				k=j;//---找出最小的蓝点
        f[k]=0;//---将它标记为白点
        printf("%d\n",k);
        for(int j=1;j<=n;j++)
            if( f[j]==1 && (a[k][j]<dis[j]))
				dis[j]=a[k][j];//---修改与k相连的所有蓝点
    	for(int z=1;z<=n;++z){
			printf("%d ",dis[z]);
		}
		printf("\n");
	}
    int s=0;//---累加答案
    for(int i=1;i<=n;i++)s+=dis[i];//---加
    cout<<s;//---输出
    return 0;
}
