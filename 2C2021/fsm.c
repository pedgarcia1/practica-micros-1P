#include <stdio.h>

char runFSM(char in);

enum{S1, S2, S3};
char estado;

int main (void){
    estado = S1;
    char in;
    while(1){
        printf("Ingrese el in (1 o 2) o q para salir: \n");
        in = getchar();
        
        while (in != '0' && in != '1' && in != 'q'){
            in = getchar();
        }
        if(in == 'q'){
            break;
        }
        if(in == '0' || in == '1'){
            printf("Estado S%d\n\n", runFSM(in) + 1);
        }
    }
    return 0;

}

char runFSM(char in){
    switch (estado)
    {
    case S1:
        if(in == '1'){
            estado = S2;
        }
        break;
    case S2:
        if(in == '1'){
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
        else if(in == '1'){
            estado = S3;
        }
        break;
    }
    return (estado);
}