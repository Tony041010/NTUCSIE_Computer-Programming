#include <stdio.h>

typedef struct tile
{
    int x;
    int y;
}Tile;
 
void put_tile(int type,Tile tiles[],int x,int y,int length,int l,int m) /* length represents sliced length */
{
    if(x>l-m && y>l-m)
        return;
    if(length>=1){
        printf("%d %d %d\n",type,x,y);
        length /= 2;
        if(type == 1){
            put_tile(0,tiles,x-length,y-length,length,l,m);
            put_tile(3,tiles,x-length,y+length,length,l,m);
            put_tile(1,tiles,x+length,y-length,length,l,m);
            put_tile(0,tiles,x+length,y+length,length,l,m);
        }
        else if(type == 2){
            put_tile(1,tiles,x+length,y-length,length,l,m);
            put_tile(2,tiles,x+length,y+length,length,l,m);
            put_tile(0,tiles,x-length,y-length,length,l,m);
            put_tile(1,tiles,x-length,y+length,length,l,m);
        }
        else if(type == 2){
            put_tile(2,tiles,x+length,y+length,length,l,m);
            put_tile(3,tiles,x-length,y+length,length,l,m);
            put_tile(1,tiles,x+length,y-length,length,l,m);
            put_tile(2,tiles,x-length,y-length,length,l,m);
        }
        else if(type == 3){
            put_tile(3,tiles,x-length,y+length,length,l,m);
            put_tile(2,tiles,x+length,y+length,length,l,m);
            put_tile(0,tiles,x-length,y-length,length,l,m);
            put_tile(3,tiles,x+length,y-length,length,l,m);
        }
    }
    return;
}
int main(){
    int l, m;
    scanf("%d%d", &l,&m);
    Tile tiles[4] = {{-1,-1}, {1,-1}, {1,1}, {-1,1}};
    int x = l/2,y=l/2;
    printf("%d %d %d\n",1,x,y);
    put_tile(2,tiles,x+l/4,y+l/4,l/4,l,m);
    put_tile(0,tiles,x-l/4,y-l/4,l/4,l,m);
    put_tile(3,tiles,x-l/4,y+l/4,l/4,l,m);
    put_tile(1,tiles,x+l/4,y-l/4,l/4,l,m);
    return 0;
}