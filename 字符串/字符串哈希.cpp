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
		//（这个位置有数 && （编号不相同 || 字符串不相同））  
		if(++i == mo)	i = 0;//查找下一个 
	return i;//返回编号 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",t.w);//读入字符串 
		t.len = strlen(t.w);//长度 
		t.c = 1;
		for(int z=0;z<=t.len;++z){
			t.c = (t.c*131 + t.w[z] + z) % mo;//随机优化成数字 
		}
		j = hx();
		if(!f[j].len)
		ans++,f[j] = t;//放进去 
	}
	printf("%d",ans);
	return 0;
}
