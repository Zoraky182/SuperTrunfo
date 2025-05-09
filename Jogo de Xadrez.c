#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Definição do tabuleiro (como no exemplo acima)

// Funções (protótipos)
void imprimirTabuleiro();
int lerMovimento(char movimento[6]);
int validarMovimento(char tabuleiro[8][8], char jogador, int origemLinha, int origemColuna, int destinoLinha, int destinoColuna);
void moverPeca(char tabuleiro[8][8], int origemLinha, int origemColuna, int destinoLinha, int destinoColuna);
int estaEmXeque(char tabuleiro[8][8], char jogador);
int estaEmXequeMate(char tabuleiro[8][8], char jogador);
int verificarEmpate(char tabuleiro[8][8]);

int main() {
    char jogadorAtual = 'w'; // 'w' para branco, 'b' para preto
    char movimento[6];
    int origemLinha, origemColuna, destinoLinha, destinoColuna;

    while (1) {
        imprimirTabuleiro();
        printf("Jogador %s, sua vez (digite o movimento em notacao algebrica, ex: e2e4): ", (jogadorAtual == 'w' ? "Branco" : "Preto"));

        if (!lerMovimento(movimento)) {
            printf("Entrada invalida.\n");
            continue;
        }

        // Converter notacao algebrica para indices do array
        origemColuna = movimento[0] - 'a';
        origemLinha = 7 - (movimento[1] - '1');
        destinoColuna = movimento[2] - 'a';
        destinoLinha = 7 - (movimento[3] - '1');

        if (origemColuna < 0 || origemColuna > 7 || origemLinha < 0 || origemLinha > 7 ||
            destinoColuna < 0 || destinoColuna > 7 || destinoLinha < 0 || destinoLinha > 7) {
            printf("Movimento fora do tabuleiro.\n");
            continue;
        }

        if (tabuleiro[origemLinha][origemColuna] == ' ' || (isupper(tabuleiro[origemLinha][origemColuna]) && jogadorAtual == 'b') || (islower(tabuleiro[origemLinha][origemColuna]) && jogadorAtual == 'w')) {
            printf("Movimento invalido: casa de origem vazia ou peca errada.\n");
            continue;
        }

        if (validarMovimento(tabuleiro, jogadorAtual, origemLinha, origemColuna, destinoLinha, destinoColuna)) {
            moverPeca(tabuleiro, origemLinha, origemColuna, destinoLinha, destinoColuna);

            if (estaEmXequeMate(tabuleiro, (jogadorAtual == 'w' ? 'b' : 'w'))) {
                imprimirTabuleiro();
                printf("Xeque-mate! Jogador %s venceu.\n", (jogadorAtual == 'w' ? "Branco" : "Preto"));
                break;
            }

            if (verificarEmpate(tabuleiro)) {
                imprimirTabuleiro();
                printf("Empate.\n");
                break;
            }

            jogadorAtual = (jogadorAtual == 'w' ? 'b' : 'w');
        } else {
            printf("Movimento ilegal.\n");
        }
    }

    return 0;
}

// Implementacoes das funcoes (imprimirTabuleiro, lerMovimento, validarMovimento, etc.)