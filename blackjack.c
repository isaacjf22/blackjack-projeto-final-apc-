#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

void menu();
void regras(); 
void desenhoCarta(int num);
void rodada();
int numeroCarta(); 
int pontuacaoCarta(int num); 
void finalRodada(int somaj,int somam);
int validacaoEstouro(int somaj,int somam);

int main(){
    srand(time(NULL)); //define onde começa o aleatório 
    setlocale(LC_ALL,"portuguese");
    menu(); 
    return 0; 
}

void menu(){
    int esc;
        do{
            system("CLS"); 
            printf("\n"); 
            printf(" ==========================================================================\n");
            printf("  ______  __  __  _____   _        ____    _____    ______      ___    __ \n");
            printf(" |  ____| \\ \\/ / |  __ \\ | |      / __ \\  |  __ \\  |  ____|    |__ \\  /_ |\n");
            printf(" | |__     \\  /  | |__) || |     | |  | | | |  | | | |__          ) |  | |\n");
            printf(" |  __|    >  <  |  ___/ | |     | |  | | | |  | | |  __|        / /   | |\n");
            printf(" | |____   /  \\  | |     | |____ | |__| | | |__| | | |____      / /_   | |\n");
            printf(" |______| /_/\\_\\ |_|     |______| \\____/  |_____/  |______|    |____|  |_|\n");
            printf("\n");
            printf(" ==========================================================================\n");
            printf("\n");
            printf("1. JOGAR\n");
            printf("2. REGRAS\n");
            printf("3. SAIR\n"); 

            do{
                esc=getch(); 
            }while(esc!='1' && esc!='2' && esc!='3');

            switch(esc){
                case '1': rodada();
                break;
                case '2': regras();
                break; 
                case '3': puts("Saindo do jogo...");
                break;
            }

        }while(esc!='3'); 

        return; 

}

void regras(){
    system("CLS"); 
    printf(" ==========================================================================\n");
    puts("|                       COMO JOGAR O EXPLODE 21?                           |"); 
    printf(" ==========================================================================\n");
    puts(""); 
    puts("Esse jogo é uma adaptação do jogo 21/Blackjack"); 
    puts("");
    puts("Objetivo: Vencer a máquina conseguindo uma pontuação maior");
    puts("que a dela, mas sem ultrapassar o limite de 21 pontos"); 
    puts("");
    puts("Valores das Cartas: "); 
    puts("  + Carta Ás(A): Vale 1 ponto"); 
    puts("  + Cartas numéricas (2 a 9): Valem o número da carta"); 
    puts("  + Cartas 10, J, Q, K: Valem 10 pontos ");
    puts(""); 
    puts("Funcionamento do Jogo: ");
    puts("  + Você começa com 2 cartas");
    puts("  + O jogo vai perguntar se você quer PEDIR mais carta ou MANTER a mão atual");
    puts("  + O jogo continua até você ESTOURAR ou MANTER sua mão");
    puts("  + Após a sua jogada, a máquina irá comprar até ter pelo menos 17 pontos"); 
    puts(""); 
    puts("Condição de Vitória/Derrota: ");
    puts("  + DERROTA: Explodir a sua mão(passar de 21 pontos) OU a máquina ter mais pontos que você no final");
    puts("  + EMPATE:  Ninguém estoura a mão E possuem a mesma pontuação");
    puts("  + VITÓRIA: Não explodir a sua mão E ter mais pontos que a máquina no final OU a máquina explodir"); 
    puts("             a mão dela(passar de 21 pontos)");
    puts(""); 
    printf(" ==========================================================================\n");
    puts("Aperte ENTER para voltar ao MENU INICIAL...");
    getch();

    return; 
}

void finalRodada(int somaj,int somam){
    if(somaj>somam){
        printf(" ==========================================================================\n");
        puts("|                               VOCÊ GANHOU!                               |");
        printf("|              A SUA PONTUAÇÃO FOI SUPERIOR QUE A DA MÁQUINA            |\n"); 
        printf(" ==========================================================================\n");
        puts("");
        return; 
    }else if(somam>somaj){
        printf(" ==========================================================================\n");
        puts("|                               VOCÊ PERDEU!                               |");
        printf("|              A SUA PONTUAÇÃO FOI INFERIOR QUE A DA MÁQUINA               |\n"); 
        printf(" ==========================================================================\n");
        puts("");
        return;
    }else{
        printf(" ==========================================================================\n");
        puts("|                               EMPATE!                                    |");
        printf("|                    AS PONTUAÇÕES FORAM AS MESMAS                       |\n"); 
        printf(" ==========================================================================\n");
        puts("");
        return;
    }
}

int validacaoEstouro(int somaj, int somam){
    if(somaj>21){
        printf(" ==========================================================================\n");
        puts("|                               VOCE PERDEU!                               |");
        printf("|                    SUA PONTUAÇÃO , %d , ULTRAPASSOU 21                 |\n",somaj); 
        printf(" ==========================================================================\n");
        puts("");
        return 1;
    }
    if(somam>21){
        printf(" ==========================================================================\n");
        puts("|                               VOCE GANHOU!                              |");
        printf("|                 A PONTUAÇÃO DA MÁQUINA , %d , ULTRAPASSOU 21          |\n",somam); 
        printf(" ==========================================================================\n");
        puts("");
        return 2;
    }
    return 0; 
}

int numeroCarta(){
    int num;
    num=((rand()%13)+1);
    return num; 
}

void desenhoCarta(int num){
    puts("");
    printf("+-----+\n");
    printf("|     |\n"); 
    switch(num){
        case 1:printf("|  A  |\n");
        break;
        case 2:printf("|  2  |\n");
        break;
        case 3:printf("|  3  |\n");
        break;
        case 4:printf("|  4  |\n");
        break;
        case 5:printf("|  5  |\n");
        break;
        case 6:printf("|  6  |\n");
        break;
        case 7:printf("|  7  |\n");
        break;
        case 8:printf("|  8  |\n");
        break;
        case 9:printf("|  9  |\n");
        break;
        case 10:printf("|  10 |\n");
        break;
        case 11:printf("|  J  |\n");
        break;
        case 12:printf("|  Q  |\n");
        break;
        case 13:printf("|  K  |\n");
        break;
    }
    printf("|     |\n"); 
    printf("+-----+\n");
    puts(""); 
    return; 
}

int pontuacaoCarta(int num){
    if(num>=10){
        return 10; 
    }
    else{
        return num; 
    }
}

void rodada(){
    int num,somaPontosJ=0,somaPontosM=0,i; 
    int cartasJ[10], cartasM[10];
    int qCartasJ=0,qCartasM=0; 
    char esc;

    system("CLS");
    printf(" ==========================================================================\n");
    puts("|                          INICIO DA RODADA                               |"); 
    printf(" ==========================================================================\n");
    puts(""); 
    puts("+ Mão do Jogador");  
    for(i=0;i<=1;i++){ 
        qCartasJ++;
        num=numeroCarta();
        cartasJ[i]=num; 
        desenhoCarta(num); 
        somaPontosJ+=pontuacaoCarta(num);
        Sleep(1000); 
    }
    printf("A pontuação do JOGADOR = %d\n",somaPontosJ);
    puts("");
    puts("+ Mão da MÁQUINA"); 
    for(i=0;i<=1;i++){ 
        qCartasM++;
        num=numeroCarta();
        cartasM[i]=num;
        desenhoCarta(num); 
        somaPontosM+=pontuacaoCarta(num);
        Sleep(1000); 
    }
    printf("A pontuação da MÁQUINA = %d\n",somaPontosM);
    puts("");
    puts("Aperte ENTER para continuar a rodada...");
    getch();

    system("CLS");
    
    printf(" ==========================================================================\n");
    puts("|                          VEZ DO JOGADOR                                  |"); 
    printf(" ==========================================================================\n");
    puts(""); 
    printf("Pontuação do JOGADOR: %d\n",somaPontosJ);
    printf("Pontuação da MÁQUINA: %d\n",somaPontosM); 
    puts("");
    puts("Mão atual do JOGADOR:");
    for(i=0;i<=qCartasJ-1;i++){
        desenhoCarta(cartasJ[i]);
        Sleep(1000); 
    }
    
    do{
        puts("Deseja puxar mais uma carta? M-MANTER / P-PUXAR");
        puts("");
        do{
            esc=getch(); 
        }while(esc!='m' && esc!='M' && esc!='P' && esc!='p');
        
        if(esc=='P' || esc=='p'){
            Sleep(2000); 
            qCartasJ++; 
            num=numeroCarta();
            cartasJ[qCartasJ-1]=num; 
            desenhoCarta(num);
            somaPontosJ+=pontuacaoCarta(num);
            if(validacaoEstouro(somaPontosJ,somaPontosM)==1){
                puts("Aperte ENTER para voltar ao MENU INICIAL...");
                getch(); 
                return;
            } 
            printf("Nova pontuação do jogador: %d \n",somaPontosJ); 
        }
    }while(esc!='m' && esc!='M');
    
    puts("Aperte ENTER para continuar a RODADA...");
    getch(); 

    system("CLS");

    printf(" ==========================================================================\n");
    puts("|                          VEZ DA MÁQUINA                          |"); 
    printf(" ==========================================================================\n");
    puts("");
    printf("Pontuação do JOGADOR: %d\n",somaPontosJ);
    printf("Pontuação da MÁQUINA: %d\n",somaPontosM);
    puts(""); 
    puts("Mão atual da MÁQUINA: "); 

    for(i=0;i<=qCartasM-1;i++){
        desenhoCarta(cartasM[i]);
        Sleep(1000); 
    } 

    puts("Aperte ENTER para a máquina puxar suas cartas...");
    getch(); 

    do{
        Sleep(2000);
        num=numeroCarta();
        desenhoCarta(num); 
        somaPontosM+=pontuacaoCarta(num);
        if(validacaoEstouro(somaPontosJ,somaPontosM)==2){
            puts("Aperte ENTER para voltar ao MENU INICIAL...");
            getch(); 
            return;
        }
    printf("Nova pontuação da máquina: %d \n",somaPontosM);
    puts("Aperte ENTER para continuar a RODADA...");
    getch();    
    }while(somaPontosM<17);

    system("CLS"); 

    finalRodada(somaPontosJ,somaPontosM);
    puts("Aperte ENTER para voltar ao MENU INICIAL...");
    getch();

    return; 
}



    

    
    

    
    

