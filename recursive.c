#include <stdio.h>
#include <stdlib.h>

int my(int x, int n){
    if(n == 0)
        return 1;
    if(n % 2 == 0){
        int y = my(x, n/2);
        return y*y;
    }else{
        int y = my(x, (n-1)/2);
        return x*y*y;
    }
}

int main(){
    int res = my(-7,3);
    printf("result = %d\n", res);
}


