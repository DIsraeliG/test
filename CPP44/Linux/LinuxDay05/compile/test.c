#include <stdio.h>
void foo(int i){
     printf("from foo: i = %d\n", i);
}
     
int main(){
    int j = 0;
    int arr[] = {1, 2, 3};
    arr[2] = 30;
    int *p = arr;

    foo(j);
    
    for(int i = 0; i < 10; i++){
	printf("love\n");
    }

    return 0;
}
