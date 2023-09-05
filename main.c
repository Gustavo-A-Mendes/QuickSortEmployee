#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.c"


int main(void)
{
    Funcionario *funcionario = NULL;
    int n = 0, opcao;
    int valorValido=0;
    do
    {
        printf("\nMenu:\n");
        printf("1 - Cadastrar funcionario\n");
        printf("2 - Ver funcionarios\n");
        printf("3 - Encerrar programa\n");
        printf("Escolha uma opcao: ");
        while (!valorValido) {
           if (scanf("%d", &opcao) == 1) {
                // A leitura foi bem-sucedida, o valor é um número inteiro
                if (opcao <= 3) {
                    // Verifica se o número é menor ou igual a 3
                    valorValido = 1;
                } else {
                    printf("Digite uma das opcoes do menu.\n");
                }
            } else {
                // A leitura não foi bem-sucedida, o valor não é um número inteiro
                printf("Digite uma das opcoes do menu.\n");
                while (getchar() != '\n');
            }
        }
        valorValido=0;

        switch (opcao)
        {
        case 1:
            
            while (opcao != 2){
            funcionario = (Funcionario *)realloc(funcionario, (n+1) * sizeof(Funcionario));

            if (funcionario == NULL) {
                    printf("Memória insuficiente!\n");
                    exit(1);
            }

            preencher(&funcionario[n]); // Passa o endereço do funcionário atual
            n++;

            printf("Registrar novo funcionário?\n1 = Sim, 2 = Não: ");
            while (!valorValido) {
                if (scanf("%d", &opcao) == 1) {
                    // A leitura foi bem-sucedida, o valor é um número inteiro
                    if (opcao == 1) {
                        valorValido = 1; // Se o usuário escolher 1, o loop continua
                    } else if (opcao == 2) {
                        valorValido = 1; // Se o usuário escolher 2, o loop termina
                    } else {
                        printf("Digite uma das opções do menu (1 ou 2).\n");
                    }
                } else {
                    // A leitura não foi bem-sucedida, o valor não é um número inteiro
                    printf("Digite uma das opções do menu (1 ou 2).\n");
                    while (getchar() != '\n');
                }
            }
            valorValido = 0;
            }
            criarArquivo(funcionario,n);
            free(funcionario);
            funcionario = NULL;
            n=0;
            ordenarLinhasArquivo();

        break;
        case 2:
            ordenarLinhasArquivo();
            imprimirArquivo();
            break;

        case 3:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("\nOpcao invalida. Tente novamente.\n");
            break;
        }

    } while (opcao != 3);


    free(funcionario);

    return 0;
}
