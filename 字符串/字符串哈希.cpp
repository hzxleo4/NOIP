#include<cstdio>
#include<cstring>
const int mo = 50001;
using namespace std;
struct node{
	int len,c;
	char w[1500];
}f[mo],t;
int n,ans,j;
int hx(){
	int i = t.c % mo;
	while (f[i].len && (t.c != f[i].c || strcmp(f[i].w,t.w)))
		//�����λ������ && ����Ų���ͬ || �ַ�������ͬ����  
		if(++i == mo)	i = 0;//������һ�� 
	return i;//���ر�� 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",t.w);//�����ַ��� 
		t.len = strlen(t.w);//���� 
		t.c = 1;
		for(int z=0;z<=t.len;++z){
			t.c = (t.c*131 + t.w[z] + z) % mo;//����Ż������� 
		}
		j = hx();
		if(!f[j].len)
		ans++,f[j] = t;//�Ž�ȥ 
	}
	printf("%d",ans);
	return 0;
}
