#include<cstdio>
using namespace std;
int s[10000005],a[1000005],ac,xiao[1000005];
int main(){
    int n,m; 
    scanf("%d%d",&m,&n);//m的范围，n次询问 
    s[1] = s[0] = 1;//1 0 不是质数 
    for(int i=2;i<=m;++i){
        if (!s[i])
        a[++ac] = i;//是素数就入队 
        for(int j=1;j<=ac,i * a[j] <=m;++j){
            s[i * a[j]] = 1;
            if(i % a[j] == 0)//如果i % a[j] == 0那么，后面i = (i*i/a[j])时 
            //i * a[j] 会重复  
            break;
        }
    }
    //方法2
    for(int i = 2; i <= m; i++){
        if(!xiao[i]) a[++ac] = xiao[i] = i;
        for(int j = 1; j <= ac; j++){
            int t = a[j] * i;
            s[t] = 1;
            if(t > m) break;
            xiao[t] = a[j];
            if(a[j] == xiao[i]) break;
        }
    }
    for(int i=1;i<=ac;++i){//素数表 
        printf("%d ",a[i]);
    }
    for(int i=1;i<=n;++i){//询问 
        scanf("%d",&ac);
        if (s[ac])    printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
