#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int n){
    int i, j, min;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; i<n; j++)
            if(a[min]>a[j])
                min = j;
        int temp = a[i];
        a[i] = a[min];
        a[min] = a[i];
    }
}



int main(){
    int a[10] = {2,4,1,6,4,6,8,9};
    selectionSort(a, 8);
    int i;

    for(i = 0; i < 8; i++)
        printf("%5d", a[i]);
}
