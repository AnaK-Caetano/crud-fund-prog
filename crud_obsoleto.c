#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_STR 40
#define TAM_MAX_RGT 3

typedef struct _Fazenda {
    unsigned short int matricula;
    char dono[TAM_MAX_STR];
    char animais[TAM_MAX_RGT][TAM_MAX_STR];
} Fazenda;

typedef struct _Registro {
    Fazenda registro_fazendas[TAM_MAX_RGT];
    unsigned short int total_fazendas;
} RegistroFazenda;

RegistroFazenda registroFazenda = { .total_fazendas = 0 };

Fazenda cadastrarFazenda();
void listarFazendas();
void atualizarFazenda();
void gravarDados();
void excluirFazenda();

int menu();
void opcao_menu(int opcao);

int main() {
    int opcao_escolhida;

    do {
        opcao_escolhida = menu();
        opcao_menu(opcao_escolhida);
    } while (opcao_escolhida != 6);

    return 0;
}

// Funções de menu
int menu() {
    int opcao;

    printf("====MENU====\n");
    printf("1 - Cadastrar nova fazenda: \n");
    printf("2 - Listar Fazendas cadastradas\n");
    printf("3 - Atualizar dados da Fazenda\n");
    printf("4 - Gravar \n");
    printf("5 - Excluir\n");
    printf("6 - Sair\n");

    printf("Digite uma opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void opcao_menu(int opcao) {
    switch (opcao) {
        case 1:
            if (registroFazenda.total_fazendas >= TAM_MAX_RGT) {
                printf("Limite máximo de fazendas cadastradas alcançado.\n");
            } else {
                Fazenda novaFazenda = cadastrarFazenda();
                
                registroFazenda.registro_fazendas[registroFazenda.total_fazendas] = novaFazenda;
                registroFazenda.total_fazendas++;
                printf("Fazenda cadastrada com sucesso!\nMatrícula: %hu | Dono: %s", novaFazenda.matricula, novaFazenda.dono);
                
                for (int i = 0; i < TAM_MAX_RGT && novaFazenda.animais[i][0] != '\0'; i++) {
                    printf(" | Animal %d: %s", i + 1, novaFazenda.animais[i]);
                }
                printf("\n");
            }
            break;
        case 2:
            printf("ok");
            break;
        case 3:
            printf("ok");
            break;
        case 4:
            // gravar();
            break;
        case 5:
            printf("ok");
            break;
        case 6:
            printf("Programa finalizado!\n");
            break;
        default:
            printf("Digite uma opção válida!\n");
            break;
    }
}

Fazenda cadastrarFazenda() {
    Fazenda fazenda;
    int len;
    
    getchar();

    printf("Digite a matrícula: ");
    scanf("%hu", &fazenda.matricula);
    getchar(); // Limpar o buffer

    printf("Digite o nome do fazendeiro: ");
    fgets(fazenda.dono, TAM_MAX_STR, stdin);
    len = strlen(fazenda.dono);
    if (len > 0 && fazenda.dono[len - 1] == '\n') {
        fazenda.dono[len - 1] = '\0';  // Remove o '\n'
    }

    for (int i = 0; i < TAM_MAX_RGT; i++) {
        printf("Digite o nome do animal %d (ou pressione Enter para finalizar): ", i + 1);
        fgets(fazenda.animais[i], TAM_MAX_STR, stdin);

        len = strlen(fazenda.animais[i]);
        if (len > 0 && fazenda.animais[i][len - 1] == '\n') {
            fazenda.animais[i][len - 1] = '\0';
        }

        if (fazenda.animais[i][0] == '\0') {
            break;
        }
    }

    return fazenda;
}

    void gravarDados() {
        FILE* registro;

        registro = fopen("registro_fazendas.txt", "w");

        if (registro == NULL) {
            printf("Problemas na criação do arquivo.\n");
        } else {

        for (int i = 0; i < registroFazenda.total_fazendas; i++) {
                fwrite(&registroFazenda.registro_fazendas[i], sizeof(Fazenda), 1, registro);
            }
        
        fclose(registro);
        
        printf("Arquivo criado com sucesso.\n");
        
        }

    }
