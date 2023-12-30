#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>

#define MAXN 101
#define MAXK 101
#define MAXM 65

bool disjoint(uint64_t a, uint64_t b){
    return((a & b) == 0);
}

void printClub(int club[], int num)
{
    for(int i = 0 ; i < num ; i++){
        printf("%d\n", club[i]);
    }
    return;
}

bool findDisjointSet(int club, int numClub, uint64_t clubMember[],  uint64_t peopleSelected, int numClubSelected, int numClubToSelect, int clubSelected[])
{
    if(numClubSelected == numClubToSelect){
        printClub(clubSelected, numClubToSelect);
        return true;
    }
    if(club >= numClub){
        return false;
    }

    /* we choose the "club" if its member is disjoint with peopleSelected*/
    if(disjoint(peopleSelected, clubMember[club])){ //choose
        clubSelected[numClubSelected] = club;
        if(findDisjointSet(club+1, numClub, clubMember, peopleSelected | clubMember[club], numClubSelected+1, numClubToSelect, clubSelected)){
            return true;
        }
    }
    return findDisjointSet(club+1, numClub, clubMember, peopleSelected, numClubSelected, numClubToSelect, clubSelected); // don't choose
}

int main()
{
    int numClub, numClubToSelect;
    scanf("%d%d", &numClub, &numClubToSelect);

    uint64_t clubMember[numClub];
    for(int club = 0 ; club < numClub ; club++){
        clubMember[club] = 0;
        int numMember;
        scanf("%d", &numMember);
        int index;
        for(int m = 0 ; m < numMember ; m++){
            scanf("%d", &index);
            clubMember[club] |= (((uint64_t)1) << index);
        }
    }

    int clubSelected[MAXN] = {0};
    findDisjointSet(0, numClub, clubMember, 0, 0, numClubToSelect, clubSelected);

    return 0;
}