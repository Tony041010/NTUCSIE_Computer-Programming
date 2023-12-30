#include<stdio.h>

void putTiles(int direction, int x, int y, int length, int l, int m)
{
    if(length >= 1 && l/m >= 2){
        printf("%d %d %d\n", direction, x, y);
        length /= 2;
        if(direction == 1){
            putTiles(1, x+length, y+length, length, l/2, m);
            putTiles(4, x-length, y+length, length, l/2, 1);
            putTiles(1, x-length, y-length, length, l/2, 1);
            putTiles(2, x+length, y-length, length, l/2, 1);
        }
        else if(direction == 2){
            putTiles(2, x-length, y+length, length, l/2, m);
            putTiles(1, x-length, y-length, length, l/2, 1);
            putTiles(2, x+length, y-length, length, l/2, 1);
            putTiles(3, x+length, y+length, length, l/2, 1);
        }
        else if(direction == 3){
            putTiles(3, x-length, y-length, length, l/2, m);
            putTiles(2, x+length, y-length, length, l/2, 1);
            putTiles(3, x+length, y+length, length, l/2, 1);
            putTiles(4, x-length, y+length, length, l/2, 1);
        }
        else if(direction == 4){
            putTiles(4, x+length, y-length, length, l/2, m);
            putTiles(3, x+length, y+length, length, l/2, 1);
            putTiles(4, x-length, y+length, length, l/2, 1);
            putTiles(1, x-length, y-length, length, l/2, 1);
        }
    }
    return;
} 

int main()
{
    int l, m;
    scanf("%d%d", &l, &m);
    int length = l/2;
    putTiles(1, l/2, l/2, length, l, m);
    return 0;
}