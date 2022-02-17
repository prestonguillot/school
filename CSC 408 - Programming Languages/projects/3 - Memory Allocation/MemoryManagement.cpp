#include <stdlib.h>
#include <stdio.h>

int main() {
    
    const int size = 1048576;
    int x=0;
    
        while(malloc(size))
           printf("%d\n",++x);

        scanf("%d",&x); 
        return 0;
}