#include <stdio.h>

void rotate(int &x, int &y, int &z){
    int t = x;
    x = y;
    y = z;
    z = t;
}

int main(){
    int x,y,z;
    scanf("%d%d%d", &x, &y, &z);
    printf("Before : %d, %d, %d\n", x, y, z);
    rotate(x,y,z);
    printf("After : %d, %d, %d\n", x, y, z);
    return 0;
}