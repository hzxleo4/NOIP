//bilibili KMP算法 
#include<cstdio>
#include<cstring>
using namespace std;
char s1[1000005],s2[1005]; 
int ans1[1000005],l1,l2,next1[1000005],t;
int main(){
	scanf("%s",s1);
	scanf("%s",s2);
	l1 = strlen(s1);
	l2 = strlen(s2);
	int j = 0;
	for(int i=1;i<l2;++i){	
		while(j && s2[i] != s2[j]){//找不到就一直往前跳 
				j = next1[j-1];
		}
 		if(s2[i] == s2[j]){//如果相同就i++，j++一起往前走 
			next1[i] = ++j;
		}
	}
	j = 0;//赋值 
	for(int i=0;i<l1;++i){
		while(j && s1[i] != s2[j]){//如果两个字符串不匹配就往前跳 
			j = next1[j-1];
		}
		if(s1[i] == s2[j]){//找到了就i++，j++一起往回走 
			++j;
		}
		if(j == l2){
			printf("%d\n",i+2-j);
			j = next1[j-1];//找到就往前跳 
		}	
		
	}
	for(int i=0;i<l2;++i){
		printf("%d ",next1[i]);
	}
	return 0;
}
