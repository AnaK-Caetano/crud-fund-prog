#include <stdio.h>

int main()
{
    int opcao = 0;
    
    
    do{
        printf("====MENU====\n");
        printf("1 - Inserir\n");
        printf("2 - Listar\n");
        printf("3 - Atualizar\n");
        printf("4 - Gravar\n");
        printf("5 - Excluir\n");
        printf("6 - Sair\n");
        printf("digite uma opçao do menu: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1: 
            printf("ok");
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
        
        
        
        
        
        
        
    }while(opcao != 6);
    

    return 0;
}