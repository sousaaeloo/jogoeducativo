#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

bool isInteger(float value) { // verificar se o numero vai ser inteiro pra evitar aquele problema do N do weldes
    return value == (int)value;
}

typedef struct { // struct de valores globais
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

Calcular calc;

int vortex; // controla a quantidade de pontos comparado com o nivel de dificuldade

void Aleatorio(int x) { // funcao pra gerar 2 numeros aleatorios
    int maxValor;

    // Define o valor maximo com base no calc.dificuldade
    switch (x) {
        case 1:
            maxValor = 10;
        break;
        case 2:
            maxValor = 100;
        break;
        case 3:
            maxValor = 1000;
        break;
        case 4:
            maxValor = 10000;
        break;
        default:
            maxValor = 10;
        break;
    }

    // Gera dois valores aleat�rios entre 1 e maxValor

    calc.valor1 = (rand() % maxValor) + 1 ;
    calc.valor2 = (rand() % maxValor) + 1 ;
}


void geraroperacao() {
    retry:
    // Gera um n�mero aleat�rio entre 0 e 2 para definir a opera��o

    int j = 0;
    int resultadocorreto;
    int cincoperguntas = 0;
    int static pontuacao=0;

    int vidas = 3;

    char respostaretry;


    //comeco do loop das perguntas e respostas, 3 vidas
    for (int i = 0; i <= 5; ++i){
        if (vidas == 0) {
            while (1) { // Loop para garantir uma resposta v�lida
                return;

            }
        }

        //faz a geracao aleatoria dos numeros e da operacao
        calc.operacao = rand() % 3;
        Aleatorio(calc.dificuldade);


        // Calcula o resultado com base na opera��o sorteada
        switch (calc.operacao) {


            case 0:

                resultadocorreto = calc.valor1 + calc.valor2;
                printf("qual o resultado: %d + %d?\n",calc.valor1, calc.valor2);




            break;
            case 1:

                resultadocorreto = calc.valor1 - calc.valor2;
                printf("qual o resultado: %d - %d?\n",calc.valor1, calc.valor2);



            break;
            case 2:


                resultadocorreto = calc.valor1 * calc.valor2;
                printf("qual o resultado: %d * %d?\n",calc.valor1, calc.valor2);
            break;
        }
        // incrementa somente fora da funcao pra evitar aquele probleminha de repetir a mesma coisa durante o codigo
        scanf("%d", &calc.resultado);


        if (calc.resultado == resultadocorreto) {
            printf("Voce acertou a resposta!\n");
            j++; // controla pra ver se a pessoa acertou todas as respostas
            pontuacao += vortex;

        }
        else {
            printf("Voce errou\n!");
            vidas -= 1;
            printf("Vidas restantes: %d\n", vidas);
        }
    }
    if (j == cincoperguntas) {
        printf("Parab�ns! Voc� acertou todas as perguntas!\n");
        printf("pontuacao: %d\n", pontuacao);
        return;

    }
    else {
        printf("Sua pontuacao final: %d pontos em 5 perguntas.\n", pontuacao);
        return;



    }
++cincoperguntas;
}

void dificuldade() {
    int dificuldade_valida = 0;

    do {
        printf("-----------------------------------------\n");
        printf("Escolha sua dificuldade:\n"
               "Dificuldade 1 (1 ate 10)\n"
               "Dificuldade 2 (1 ate 100)\n"
               "Dificuldade 3 (1 ate 1000)\n"
               "Dificuldade 4 (1 ate 10000)\n");
        printf("-----------------------------------------\n");

        if (scanf("%d", &calc.dificuldade) != 1) {
            printf("Entrada invalida. Por favor, digite apenas um numero.\n");
            while (getchar() != '\n');
            continue;
        }

        if (calc.dificuldade >= 1 && calc.dificuldade <= 4) {
            dificuldade_valida = 1;
        } else {
            printf("Dificuldade invalida. Escolha novamente.\n");
        }

        while (getchar() != '\n');
    } while (!dificuldade_valida);


    switch (calc.dificuldade) {
        case 1:
            vortex = 5;
        break;
        case 2:
            vortex = 10;
        break;
        case 3:
            vortex = 15;
        break;
        case 4:
            vortex = 20;
        break;
    }
}



void regras() {

    printf("--------------------------------------------\n");
    printf("regras do jogo:\n"
           "5 perguntas com operadores aleatorios\n"
           "se errar 3 perguntas voce perde\n"
           "voce acumula pontos por cade questao acertada, os pontos aumentam conforme a complexidade da operacao\n"
           "o nivel da dificuldade escolhido impacta no tamanho dos numeros\n"
           "divirta-se!\n");
    printf("--------------------------------------------\n");
    printf("digite qualquer telca para comecar!\n");
    getch();


}



void jogar() {

    geraroperacao();
    return;


}


int main() {
    int controlador = 0;
    int dificuldadejogo;
    char recomecar;

    srand(time(NULL));

    do {
        regras();
        dificuldade();
        dificuldadejogo = calc.dificuldade;

        jogar(); // Executa o jogo principal

        printf("Voce deseja jogar novamente? (s/n): ");
        do {
            getchar(); // Limpa o buffer de entrada
            scanf("%c", &recomecar);

            if (recomecar == 's' || recomecar == 'S') {
                controlador = 1;
                break;
            } else if (recomecar == 'n' || recomecar == 'N') {
                controlador = 0;
                break;
            } else {
                printf("Entrada invalida! Por favor, digite 's' para sim ou 'n' para nao.\n");
            }
        } while (1); // Loop entrada v�lida
    } while (controlador == 1); // Continua o jogo

    printf("Obrigado por jogar!.\n");
    return 0;
}

