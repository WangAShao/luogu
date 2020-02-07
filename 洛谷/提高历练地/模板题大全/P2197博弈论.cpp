#include<cstdio>
using namespace std;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=1; i<=n; ++i){
            int shu;
            scanf("%d",&shu);
            ans^=shu;
        }
        if(!ans) printf("No\n");
        else printf("Yes\n");
    }
}