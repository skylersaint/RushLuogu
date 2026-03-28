#include <bits/stdc++.h>
const int MAXN=1005;
int m,n,a;
struct node{
    float x;
    float y;
    float dis(){
        return std::sqrt(x*x+y*y);
    }
};
node points[MAXN];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    double res;
    std::cin>>n>>a;
    m=0;
    for(int i=1;i<=n;i++){
        std::cin>>points[i].x>>points[i].y;
        if(points[i].dis()<=a){
            m++;
        }
    }
    res=4*m*1.0/n;
    std::cout<<std::setprecision(6)<<res<<"\n";

    return 0;
}
