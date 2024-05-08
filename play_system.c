#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo o sistema de ataque do jogo de pokemon (Objetivo: Realizar um ataque)
int ataque(int atk1, int def2, int vid2){
        if(atk1 > def2){
            vid2 -= (atk1 - def2); // Alterando a vida do defensor
        } else{
            vid2 -= 1; // Alterando a vida do defensor
        }
    return vid2;
}

// Definindo o sistema de jogadas do jogo de pokemon (Objetivo: Descobrir qual pokemon vence)
void jogadas(char* pk1, int atk1, int def1, int vid1, char* pk2, int atk2, int def2, int vid2){
    int flag = 0; // Definindo um sistema de pausa do loop da jogada.
    int jogador = 1; // Definindo o primeiro jogador como o primeiro a realizar a jogada
    while (flag == 0){
        if (jogador==1){
            if(ataque(atk1, def2, vid2) <= 0){ // Verificando o caso de após aplicar o ataque o adversario (jogador 2) ter sido derrotado
                printf("O vencedor foi: %s", pk1);
                flag++; // Quebrando o loop pela ocorrência de uma vitória no confronto
            } else{
                vid2 = ataque(atk1, def2, vid2); // Caso não tenha sido derrotado, aplica-se o ataque a vida do jogador2
                jogador++; // Passando a vez para o jogador 2
            } 
        } else{
            if(ataque(atk2, def1, vid1) <= 0){// Verificando o caso de após aplicar o ataque o adversario (jogador 1) ter sido derrotado
                printf("O vencedor foi: %s", pk2);
                flag++; // Quebrando o loop pela ocorrência de uma vitória no confronto
            } else{
                vid1 = ataque(atk2, def1, vid1); // Caso não tenha sido derrotado, aplica-se o ataque a vida do jogador1
                jogador--; // Passando a vez para o jogador 1
            } 
        }    
    }
}


int main(void){
    // {Settings}

        // Definindo uma variável estruturada do que é um pokemon
        typedef struct pokemon {
            char nome[100];
            int ataque;
            int defesa;
            int vida;
            char tipo[100];
            int status;
        } pokemon;

        // Criando meus pokemons para batalha
        pokemon pok1;
        pokemon pok2;

        // Definir o estado de vida dos meus pokemons como 1 (vivo)
        pok1.status = 1;
        pok2.status = 1; // Serve para controle

    // {...}
    
    // Atribuição de valores a um pokemon
    scanf("%s %d %d %d %s\n", pok1.nome, &pok1.ataque, &pok1.defesa, &pok1.vida, pok1.tipo);
    scanf("%s %d %d %d %s", pok2.nome, &pok2.ataque, &pok2.defesa, &pok2.vida, pok2.tipo);
    
    // Implementando um sistema para determinar o vencedor com as jogadas
    jogadas(pok1.nome, pok1.ataque, pok1.defesa, pok1.vida, pok2.nome, pok2.ataque, pok2.defesa, pok2.vida);
}