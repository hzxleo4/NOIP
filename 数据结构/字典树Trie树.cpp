#include<cstdio>
using namespace std;
int top;
char w[1005];
struct node{
	int w;
	int next[30],n[30];
}d[10005];
void input(char *str){//传入第一个地址 
    int k;
    int now = 0;
    while(*str){//如果这个地址还有值 
        k = *(str++) - 'a';//取出这个值 
        if(d[now].next[k]){//如果这个前缀已经出现 
            d[now].n[k]++;
			now = d[now].next[k];//走向下一个
        }
        else{//如果没出现 
			d[now].n[k]++;
            now = d[now].next[k] = ++top;//新建一个前缀 
            
        }
    }
    d[now].w = 1;//结尾做好单词标识 
}
int query(char * str){//跟加入没啥区别 
	int k;
	int now=0;
	while(*str){
		k = *(str++) - 'a';
		if(d[now].next[k])
			now = d[now].next[k];
		else
			return 0;
	}
	return d[now].w;
}
int main(){
	int n,q;
	scanf("%d",&n);//n次操作 
	for(int i=1;i<=n;++i){
		scanf("%d%*c",&q);//0询问 1添加  
		scanf("%s",&w[0]);
		if(q)
			input(w);
		else
			printf("%d",query(w));
	}
	return 0;
}
