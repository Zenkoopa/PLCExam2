//for question 2

//using pointer

#include "stdio.h"

int main(){
    int twoDeeArrayExample [120][120];

    int* arrayIndex = (int*)twoDeeArrayExample;
    int arrayOffset = 0;

    for (; (arrayIndex + arrayOffset) < (int*)twoDeeArrayExample+120*120; arrayOffset+=1){
        *(arrayIndex+arrayOffset) = arrayOffset;
        printf("%d\n", *(arrayIndex+arrayOffset));
    }

    //execution results in IDE as:
    //0.813 seconds
    //0.830 seconds
    //0.829 seconds
    //0.826 seconds
}
