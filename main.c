#include <stdio.h>
#include <malloc.h>

int Tiro(){
    printf("m");
    return '1';
}

int APARTADO(char *Pr,int Dap){
    char *Estatico = Pr;
    int Numero;
    int Bandera=1;
    char *Aux;
    char AuxN;
    while (Bandera){
        Pr = Estatico;
        printf("Que dado quieres apartar?\n");
        for(int i =0; i<=4-Dap; i++) {
            printf("%i: %c \n", i+1,*Pr);
            Pr++;
        }
        Pr=Estatico;
        printf("Ingresa el numero de dado que quieres apartar\n");
        scanf("%i",&Numero);
        Aux=Pr+(Numero)-1;
        AuxN=*Aux;
        Pr=Pr+4-(Dap);
        *Aux=*Pr;
        *Pr = AuxN;
        printf("Quieres guardar otro dado?\n");
        printf("0: No\n");
        printf("1: Si\n");
        scanf("%i",&Bandera);
        Dap++;
    }
    return Dap;
}

void Menu(int Jugadores,int *Pr, char TiroC[5],char *Prc) {
    int Dap;
    for(int i = 0; i<Jugadores;i++) {
        for (int l = 0; l < 3; l++) {
            printf("\n Turno del jugador: %i\n", i);
            int desicion = 0;
            printf("0: Tirar dados\n");
            printf("1: Guardar dados\n");
            printf("2: Terminar\n");
            scanf("%i", &desicion);
            if (desicion==2) {
                break;
            } else if(desicion) {
                Dap = APARTADO(Prc,Dap);
            }else{
                printf("Tirada %i: %c,%c,%c,%c,%c", i+1, TiroC[0], TiroC[1], TiroC[2], TiroC[3], TiroC[4]);
            }
        }
    }
}

int main() {
    int Tiro[5] = {7,9,6,5,5};
    char TiroC[5] = {'7','9','6','5','5'};
    int Dap=0;
    char *Ptc = TiroC;
    int *Pt = Tiro;
    for (int i = 0; i <=4 ; ++i) {
        printf("%i\n",Tiro[i]);
    }
    int Jugadores=2;
    printf("Bienvenido al cubilete premium\n");
    printf("Ingresa la cantidad de jugadores:");
    scanf("%i", &Jugadores);
    while(1) {
        if (Jugadores < 2) {
            printf("Cantidad no valida vuelve a ingresarla\n");
        } else{
            Menu(Jugadores,Pt,TiroC,Ptc);
            break;
        }
    }


    return 0;
}
//hello world!