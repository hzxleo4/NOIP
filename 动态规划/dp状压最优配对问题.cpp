#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[105],b[105],c[105];
double dp[10000005];
double dis(int x, int y)//�ռ���빫ʽ 
{
    return sqrt(
	(a[x] - a[y]) * (a[x] - a[y])+
	(b[x] - b[y]) * (b[x] - b[y])+
	(c[x] - c[y]) * (c[x] - c[y])
	);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){//�������� 
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	memset(dp,127,sizeof(dp));
	dp[0] = 0;
	for(int i=1;i<=(1<<n);++i){//������ö��ÿһ��״̬ 
		int x,y;
		for(x=0;x<=n-1;++x){//��һ������ƥ��ĵ� 
			if(i & (1<<x))	break;
		}
		for(y=x+1;y<=n-1;++y){//�ڶ�������ƥ��ĵ� 
			if(i & (1<<y)){
				dp[i] = min(dp[i],
				dp[i^(1<<x)^(1<<y)]+dis(x+1,y+1));//dp 
				/*û�����������״̬*/
			}
		}
	}
	printf("%.3lf",dp[(1<<n)-1]);//��� 
	return 0;
}
