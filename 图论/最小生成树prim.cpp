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
			a[u][v]=d,a[v][u]=d;//---��Ϊ���رߣ����Զ���ʱѡ����С�ı�
	}
       
    memset(dis,1,sizeof(dis)); //---�����ֵ
    for(int i=1;i<=n;i++)f[i]=1;//---�����е㸳ֵΪ����
    dis[1]=0;//---��һ���㸳ֵΪ�׵�
    for(int i=1;i<=n;i++)
    {
        int k=0;
        for(int j=1;j<=n;j++)
			if(f[j]==1 && (dis[j]<dis[k]))
				k=j;//---�ҳ���С������
        f[k]=0;//---�������Ϊ�׵�
        printf("%d\n",k);
        for(int j=1;j<=n;j++)
            if( f[j]==1 && (a[k][j]<dis[j]))
				dis[j]=a[k][j];//---�޸���k��������������
    	for(int z=1;z<=n;++z){
			printf("%d ",dis[z]);
		}
		printf("\n");
	}
    int s=0;//---�ۼӴ�
    for(int i=1;i<=n;i++)s+=dis[i];//---��
    cout<<s;//---���
    return 0;
}
