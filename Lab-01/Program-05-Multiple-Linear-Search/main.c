#include <stdio.h>
#include<stdlib.h>

int main(){
    int n,m;
    printf("Enter the size of Inventory: ");
    scanf("%d",&n);

    int *inventory = malloc(n * sizeof(int));
    printf("Enter the items in the inventory: ");
    for(int i =0; i<n; i++){
        scanf("%d",&inventory[i]);
    }

    printf("enter the size of items to searvch: ");
    scanf("%d",&m);
    int *items = malloc(m * sizeof(int));
    printf("Enter the items to search: ");
    for(int i =0; i<m; i++){
        scanf("%d",&items[i]);
    }
    //for each item in the items array, we will search it in the inventory array
    for(int  i = 0 ; i < m; i++){
        int j; // declare j outside the loop to use it after the loop
        for( j = 0 ; j < n; j++){
            if(items[i] == inventory[j]){
                printf("Item %d found at index %d\n",items[i],j+1);
                break;
            }
        }
        // naturally, if the loop completes without finding the item, j will be equal to n
        if(j == n){
            printf("Item %d not found in the inventory\n",items[i]);
        }
    }
    
    free(inventory);
    free(items);
    return 0;
}