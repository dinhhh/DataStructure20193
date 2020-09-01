#include <stdio.h>
#define max 20

int boolean[max] = { 0 };
int n;
int A[max];

void print(){
    int i;
    for(i = 1; i <= n; i++)
        printf("%d", A[i]);
    printf("\n");
}

void function(int k){
    int i;
    for(i = 1; i <= n; i++){
        if(!boolean[i]){
            A[k] = i;
            boolean[i] = 1; 
            if(k == n)
                print();
            else
                function(k+1);
            boolean[i] = 0;
        }
    }
}

int main(){
    printf("Nhap n: ");
    scanf("%d", &n);
    function(1);
    
}

