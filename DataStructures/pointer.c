#include<stdio.h>
main(){
    int v = 10,*p;
    p = &v;
    printf("Value of v = %d\n",v);
    printf("Address of v = %p\n", p);  
    printf("Value of v using pointer = %d\n",*p);      

}