#include<cstdio>
#include<cstring>
using namespace std;
int link[10001];
int v[10001],mp[1005][1005],n,m,k,a,b,ans;
int dfs(int a){
	for(int i=1;i<=m;++i){
		if (mp[a][i] && !v[i]){//������������� 
			v[i] = 1;
			if (!link[i] || dfs(link[i])){//����㻹ûƥ�� || ������ԭƥ�仹������ƥ�� 
				link[i] = a;//��� 
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);//n���ˣ�m���ˣ�k����ϵ 
	for(int i=1;i<=k;++i){
		scanf("%d%d",&a,&b);
		//if(b > m)	continue;
		mp[a][b] = 1;
	}
	for(int i=1;i<=n;++i){
		memset(v,0,sizeof(v));
		if(dfs(i))//���ƥ��ɹ� 
		ans++;
	}
	printf("%d",ans);
	return 0;
}
