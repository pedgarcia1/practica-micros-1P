#include <stdio.h>

char runFSM(char in);

enum{S1, S2, S3};
char estado;

int main (void){
    estado = S1;
    char in;
    while (1){
        printf("Enter a number (q to quit): \n");
        scanf("%c", &in);
        printf("%c\n", in);
        printf("Estado: %d \n", runFSM(in));
        /* if (runFSM(in)){
            printf("S2\n");
        }
        else {
            printf("Not S2\n");
        } */
    }
    return 0;
}

char runFSM(char in){
    switch (estado)
    {
    case S1:
        if(in){
            estado = S2;
        }
        break;
    case S2:
        if(in){
            estado = S3;
        }
        else {
            estado = S1;
        }
        break;

    case S3:
        if(in == '0'){
            estado = S1;
        }
        break;
    

    }
    return (estado);
}

