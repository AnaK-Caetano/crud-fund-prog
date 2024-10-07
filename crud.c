#include <stdio.h>
#include <stdlib.h>


#define TAM_MAX_STR 40
#define TAM_MAX_RGT 3

void cadastrarFazenda();
void listarFazendas();
void atualizarFazenda();
void gravarDados();
void excluirFazenda();
int menu();
void opcao_menu();

typedef struct _Fazenda{
    unsigned short int matricula;
    char nome_fazendeiro[TAM_MAX_STR];
    char animais[TAM_MAX_RGT][TAM_MAX_STR];
}Fazenda;

typedef struct _Registro{
    Fazenda registro_fazendas[TAM_MAX_RGT];
    unsigned short int total_fazendas; 
}RegistroFazenda;



int main()
{
    int opcao_escolhida;
    
    do{
        opcao_escolhida = menu(); 
        opcao_menu(opcao_escolhida);
    } while(opcao_escolhida != 6);

    return 0;
}


// Funções de menu
int menu(){
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

void opcao_menu(int opcao){
    
    switch(opcao){
        case 1: 
        printf("aaa");
        break;
        case 2: 
        printf("ok");
        break;
        case 3: 
        printf("ok");
        break;
        case 4: 
        printf("ok");
        break;
        case 5: 
        printf("ok");
        break;
        case 6: 
        printf("Programa finalizado!");
        break;
        default:
        printf("Digite uma opçao valida!");
        break;
    }   
}

void cadastrarFazenda(RegistroFazenda *registro){
    if(!RegistroFazenda->total_fazendas>TAM_MAX_RGT){
        printf("Limite máximo de propriedades cadastradas. Não é possível cadastrar mais fazendas. \n");
        return
    }else{
        
        printf("Digite a matrícula: ");
        scanf("%hu", &nova_fazenda.matricula);

        printf("Digite o nome do fazendeiro: ");
        fgets(fazenda->nome_fazendeiro, TAM_MAX_STR, stdin);

        for (int i = 0; i < TAM_MAX_RGT; i++) {
            printf("Digite o nome do animal %d (ou pressione Enter para finalizar): ", i + 1);
            fgets(fazenda->animais[i], TAM_MAX_STR, stdin);

            // Remove o '\n' deixado pelo fgets
            len = strlen(fazenda->animais[i]);
            if (len > 0 && fazenda->animais[i][len - 1] == '\n') {
                fazenda->animais[i][len - 1] = '\0';
            }

            if (fazenda->animais[i][0] == '\0') {
                break;
            }
        }
    }
}

void gravarDados(){
    FILE* registro;

    registro = fopen("registro__fazendas.txt", "b");

    if(registro == NULL){
        printf("Problemas na criação do arquvo. \n");
    }else{
        printf("Arquivo criado com sucesso. \n");
    }

    for (int i = 0; i < TAM_MAX_RGT; i++) {
        fwrite(&registro->registro_fazendas[i], sizeof(Fazenda), 1, arquivo);
    }

    fclose(registro); 
}