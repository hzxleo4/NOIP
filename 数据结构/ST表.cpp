#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int st[20][100005],a[100005],n,m;
int main(){
	scanf("%d",&n);//st�� �����ѯO(1) 
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		st[0][i] = a[i];
	}

	for(int i=1;i<=20;++i){//��ʮ�㣬ÿ�㶼��2��n�η� 
		for(int j=1;j+(1<<i)-1 <= n;++j){//ö��ÿһ���ÿһ��ֵ 
			st[i][j] = min(st[i-1][j],st[i-1][j+(1<<(i-1))]);//ѡ��һ�����С/��ֵ 
		}
	}
	for(int i=0;i<=5;++i){
		for(int j=1;j<=n;++j){
			printf("%d ",st[i][j]);
		}
		printf("\n");
	}
		scanf("%d",&m);//m��ѯ�� 
	for(int i=1;i<=m;++i){
		int x;
		int y;
		scanf("%d%d",&x,&y);
		int z=log2(y-x+1);//�ҵ�(x,y)�ڵĲ��� 
		printf("%d\n",min(st[z][x],st[z][y+1-(1<<z)]));//ѡһ����С/��ֵ 
	}
	return 0;
}
