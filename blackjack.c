#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

double saldo=1000; 

void menu();
void regras(); 
void desenhoCarta(int num);
double rodada(double saldo);
int numeroCarta(); 
int pontuacaoCarta(int num); 
int finalRodada(int somaj,int somam);
int validacaoEstouro(int somaj,int somam);
double adicionarSaldo(double saldoant);

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
            printf("SALDO DISPONÍVEL: R$%.2lf\n",saldo); 
            printf("1. JOGAR\n");
            printf("2. REGRAS\n");
            printf("3. ADICIONAR SALDO\n");
            printf("4. SAIR\n"); 

            do{
                esc=getch(); 
            }while(esc!='1' && esc!='2' && esc!='3' && esc!='4');

            switch(esc){
                case '1': saldo=rodada(saldo);
                break;
                case '2': regras();
                break;
                case '3': saldo=adicionarSaldo(saldo); //fazendo que o novo saldo , seja oq retornou da função
                break;
                case '4': puts("Saindo do jogo...");
                break;
            }

        }while(esc!='4'); 

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

int finalRodada(int somaj,int somam){
    if(somaj>somam){
        printf(" ==========================================================================\n");
        puts("|                               VOCÊ GANHOU!                               |");
        printf("|              A SUA PONTUAÇÃO FOI SUPERIOR QUE A DA MÁQUINA            \n"); 
        printf(" ==========================================================================\n");
        puts("");
        return 2; 
    }else if(somam>somaj){
        printf(" ==========================================================================\n");
        puts("|                               VOCÊ PERDEU!                               |");
        printf("|              A SUA PONTUAÇÃO FOI INFERIOR QUE A DA MÁQUINA               \n"); 
        printf(" ==========================================================================\n");
        puts("");
        return 1;
    }else{
        printf(" ==========================================================================\n");
        puts("|                               EMPATE!                                    |");
        printf("|                    AS PONTUAÇÕES FORAM AS MESMAS                       \n"); 
        printf(" ==========================================================================\n");
        puts("");
        return 3;
    }
}

int validacaoEstouro(int somaj, int somam){
    if(somaj>21){
        printf(" ==========================================================================\n");
        puts("|                               VOCÊ PERDEU!                               |");
        printf("|                    SUA PONTUAÇÃO, %d, ULTRAPASSOU 21                 \n",somaj); 
        printf(" ==========================================================================\n");
        puts("");
        return 1;
    }
    if(somam>21){
        printf(" ==========================================================================\n");
        puts("|                               VOCÊ GANHOU!                              |");
        printf("|                 A PONTUAÇÃO DA MÁQUINA, %d, ULTRAPASSOU 21          \n",somam); 
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

double adicionarSaldo(double saldoant){
    double totaln,saldoadd;
    system("CLS"); 
    printf(" ==========================================================================\n");
    puts("|                          ADICIONANDO SALDO                               |"); 
    printf(" ==========================================================================\n");
    puts("Quantos R$ você quer adicionar?");
    scanf("%lf",&saldoadd);
    getchar(); 
    totaln=saldoant+saldoadd; 
    puts("");
    printf("O seu novo saldo é de R$%.2lf\n",totaln);
    puts("Aperte ENTER para voltar ao MENU INICIAL...");
    getch(); 
    return totaln; 

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

double rodada(double saldo){
    int num,somaPontosJ=0,somaPontosM=0,i; 
    int cartasJ[10], cartasM[10];
    int qCartasJ=0,qCartasM=0; 
    char esc,escp;
    double apostado;
    int aposta=0; 
    int dentroap=0;

    system("CLS"); 
    puts("Você deseja apostar alguma quantia nessa rodada?");
    printf("SALDO ATUAL -> R$%.2lf\n",saldo);
    puts("S-SIM ou N-NÃO");
    do{
        escp=getch();
    }while(escp!='S' && escp!='s' && escp!='n' && escp!='N'); 
    puts(""); 
    if(escp=='S' || escp=='s'){
        if(saldo<=0){
            puts("Você está quebrado! Jogue na brincadeira mesmo...");
            Sleep(2000);
        }else{
            dentroap=1;
            do{
                puts("Quanto você gostaria de apostar?");
                scanf("%lf",&apostado);
                if(apostado>saldo){
                    puts("Você não tem saldo suficiente para essa aposta!");
                }else if(apostado<=0){
                    puts("A sua aposta não pode ser menor ou igual a 0");
                }
                getchar();
            }while(apostado>saldo || apostado<=0); //validação quanto é apostado
                
                saldo=saldo-apostado;
                printf("A sua aposta foi aceita! Novo saldo: R$%.2lf\n",saldo); 
                printf("Caso você ganhe, receberá R$%.2lf\n",2*apostado);
                puts(""); 
        }
    }
    puts("Aperte ENTER para que a rodada seja iniciada...");
    getch(); 

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
                if(dentroap==1){
                    puts("Você também perdeu a aposta :(");
                    printf("Saldo atual: R$%.2lf\n",saldo);
                    Sleep(2000);
                    puts("Aperte ENTER para voltar ao MENU INICIAL...");
                    getch();
                }else{
                    puts("Aperte ENTER para voltar ao MENU INICIAL...");
                    getch();
                }
                return saldo;
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


    while(somaPontosM<17){
        puts("Aperte ENTER para a máquina puxar suas cartas...");
        getch();

        Sleep(2000);
        num=numeroCarta();
        desenhoCarta(num); 
        somaPontosM+=pontuacaoCarta(num);
        if(validacaoEstouro(somaPontosJ,somaPontosM)==2){
            if(dentroap==1){
                puts("Você também ganhou a aposta :)");
                printf("Saldo atual: R$%.2lf\n",saldo+(2*apostado));
                saldo=saldo+(2*apostado);
                Sleep(2000);
            }
            puts("Aperte ENTER para voltar ao MENU INICIAL...");
            getch();
            return saldo; 
        }
    printf("Nova pontuação da máquina: %d \n",somaPontosM);
    }
    puts("Aperte ENTER para continuar a RODADA...");
    getch();    
    

    system("CLS"); 

    aposta=finalRodada(somaPontosJ,somaPontosM);
    if(aposta==1 && dentroap==1){
        puts("Você também perdeu a aposta :(");
        printf("Saldo atual: R$%.2lf\n",saldo);
        Sleep(2000); 
    }else if(aposta==2 && dentroap==1){
        puts("Você também ganhou a aposta :)");
        printf("Saldo atual: R$%.2lf\n",saldo+(2*apostado));
        saldo=saldo+(2*apostado);
        Sleep(2000);
    }else if(aposta==3 && dentroap==1){
        puts("Como foi empate, seu dinheiro foi devolvido :|");
        saldo=saldo+apostado; //recuperou o dinheiro  
        Sleep(2000);
    }
    puts("Aperte ENTER para voltar ao MENU INICIAL...");
    getch();
    return saldo;
}