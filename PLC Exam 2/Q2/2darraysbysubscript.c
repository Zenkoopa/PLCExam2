//for question 2

//using subscript

#include "stdio.h"

int main(){
    int twoDeeArrayExample [120][120];

    int i, j, k;
    k = 0;

    for (i = 0; i < 120; i++){
        for (j = 0; j < 120; j++){
            twoDeeArrayExample[i][j] = k;
            printf("%d\n", twoDeeArrayExample[i][j]);
            k++;
        }
    }

    //execution results in IDE as:
    //0.807 seconds
    //0.820 seconds
    //0.804 seconds
    //0.801 seconds
}
