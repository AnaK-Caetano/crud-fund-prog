typedef struct{
    int matricula;
    float media; 
} Aluno; 

void lerPonteiro(Aluno *aluno){
    printf("matricula: ");
    scanf("%d", &aluno->matricula);
    printf("media: ");
    scanf("%f", &aluno->media);
}

Aluno lerRetorno(){
    Aluno aluno; 
    printf("matricula: ");
    scanf("%d", &aluno->matricula);
    printf("media: ");
    scanf("%f", &aluno->media);

    return aluno;

}

void cadastrar(Aluno aluno){
    printf(" MAtrícula: %d\n", aluno.matricula);
    printf(" Média: %f\n", aluno.media);
}

int main(){
    Aluno aluno; 
    lerPonteiro(&aluno);

    aluno = lerRetorno();


    cadastrar(aluno);




    return 0; 
}