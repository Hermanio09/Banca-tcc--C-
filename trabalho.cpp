#include <iostream>
#include <cstdlib>
#include "structs.h"
using namespace std;

dados * inicio = NULL;

int sair = 0;
int tam = 0;
FILE *p;
FILE *aux;


dados* gerar_banca(){
 
  dados *NOVO = (dados *)malloc(sizeof(dados));
 
  if(inicio == NULL){
    inicio = NOVO;
    tam++;
  }else{
    dados *aux = inicio;                   
    for(int i = 0; i < tam -1; i++){     
      aux = aux->prox;                
    }
    NOVO->prox = aux->prox;             
    aux->prox = NOVO;                                  
    tam++;                              
  }
  return NOVO;
}
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
void Salvar_informacoes(){
 
    FILE *arquivo;
    arquivo = fopen("aluno.txt", "w");
 
    dados *aux = inicio;
    for(int i =0; i<tam; i++){ 
        if(aux==NULL){
            break;
        }
        fprintf(arquivo,"Nome: %s",aux->nome_aluno);
        fprintf(arquivo,"Matricula: %d\n", aux->matricula_aluno);
        fprintf(arquivo,"Email: %s", aux->email_aluno);
        fprintf(arquivo,"Curso: %s", aux->curso_aluno);
        fprintf(arquivo,"Orientador: %s", aux->nome_orientador);
        fprintf(arquivo,"Frequencia: %d\n", aux->frequencia_aluno);
        fprintf(arquivo,"Avaliador: %s", aux->nome_avaliador);
        fprintf(arquivo,"Avaliador email: %s", aux->email_avaliador);
        fprintf(arquivo,"Intituicao: %s", aux->nome_instituicao);
        fprintf(arquivo,"Titulo: %s", aux->banca_titulo);
        fprintf(arquivo,"Local: %s", aux->banca_local);
        fprintf(arquivo,"Resumo: %s", aux->banca_resumo);
        fprintf(arquivo,"Horario: %s\n", aux->banca_horario);
        aux = aux->prox;
    }
    cout << "\t========================================\n"; 
    cout << "\t\tArquivos salvos com exito.\n";
    cout << "\t========================================\n"; 
    fclose(p);
}

void Cadastrar(){
    dados * nova_banca = gerar_banca();
    clean_stdin();
    cout <<"Informe Nome: \n";
    fgets(nova_banca -> nome_aluno, 100,stdin);
    cout <<"Informe Sua matricula: \n";
    cin >> nova_banca -> matricula_aluno;
    clean_stdin();
    cout <<"Informe seu Curso: \n";
    fgets(nova_banca -> curso_aluno, 100,stdin);
    cout << "Informe seu email: \n";
    fgets(nova_banca -> email_aluno, 100,stdin);
    cout << "Informe o nome do orientador: \n";
    fgets(nova_banca -> nome_orientador, 100,stdin);
    cout <<"Informe frequencia do aluno: \n";
    cin >> nova_banca -> frequencia_aluno;
    clean_stdin();
    cout << "Informe o nome do avaliador: \n";
    fgets(nova_banca -> nome_avaliador, 100,stdin);
    cout << "Informe instituicao: \n";
    fgets(nova_banca -> nome_instituicao, 100,stdin);
    cout << "Informe o email do avaliador: \n";
    fgets(nova_banca -> email_avaliador, 100,stdin);
    cout << "Informe o titulo da banca: \n";
    fgets(nova_banca -> banca_titulo, 100,stdin);
    cout << "Informe o resumo: \n";
    fgets(nova_banca -> banca_resumo, 100,stdin);
    cout << "Informe o horario: \n";
    fgets(nova_banca -> banca_horario, 100,stdin);
    cout << "Informe o local: \n";
    fgets(nova_banca -> banca_local, 100,stdin);
    Salvar_informacoes();
    
}

void Exibir(){
    int mat;
    cout << "digite a matricula da banca a ser exibida: \n";
    cin >> mat;
    dados * aux = inicio;
    for(int i = 0; i < tam; i++){
        if(aux->matricula_aluno == mat){
        cout << "Nome do aluno: " << aux -> nome_aluno << endl;
        cout << "Matricula: " << aux -> matricula_aluno << endl;
        cout << "Email do aluno: " << aux -> email_aluno << endl;
        cout << "Curso: " << aux -> curso_aluno << endl;
        cout << "Nome do Orientador: " << aux -> nome_orientador << endl;
        cout << "Frequencia do aluno: " << aux -> frequencia_aluno << endl;
        cout << "Nome do Avaliador: " << aux -> nome_avaliador << endl;
        cout << "Email do avaliador: " << aux -> email_avaliador << endl;
        cout << "Nome da instituicao: " << aux -> nome_instituicao << endl;
        cout << "Titulo da banca: " << aux -> banca_titulo << endl;
        cout << "Resumo da banca: " << aux -> banca_resumo << endl;
        cout << "Horario da banca: " << aux -> banca_horario << endl;
        cout << "Local da banca: " << aux -> banca_local << endl;
        aux = aux->prox;
    }else if(aux->matricula_aluno =! mat){
        aux = aux->prox;
    }else{
        cout << "banca não encontrada\n";
        }
    }
}
void atualizar(){

    int mat;
    printf("insira a matricula a ser atualizada: \n");
    scanf("%d", &mat);
    dados *aux = inicio;
    for (int i = 0; i < tam; i++){
        if(aux->matricula_aluno == mat){
            clean_stdin();
            cout << "Informe Nome: \n";
            fgets(aux -> nome_aluno, 100,stdin);
            cout << "Informe Sua matricula: \n";
            cin >> aux -> matricula_aluno;
            clean_stdin();
            cout << "Informe seu Curso: \n";
            fgets(aux -> curso_aluno, 100,stdin);
            cout << "Informe seu email: \n";
            fgets(aux -> email_aluno, 100,stdin);
            cout << "Informe o nome do orientador: \n";
            fgets(aux -> nome_orientador, 100,stdin);
            cout << "Informe frequencia do aluno: \n";
            cin >> aux -> frequencia_aluno;
            clean_stdin();
            cout << "Informe o nome do avaliador: \n";
            fgets(aux -> nome_avaliador, 100,stdin);
            cout << "Informe instituicao: \n";
            fgets(aux -> nome_instituicao, 100,stdin);
            cout << "Informe o email do avaliador: \n";
            fgets(aux -> email_avaliador, 100,stdin);
            cout << "Informe o titulo da banca: \n";
            fgets(aux -> banca_titulo, 100,stdin);
            cout << "Informe o resumo: \n";
            fgets(aux -> banca_resumo, 100,stdin);
            cout << "Informe o horario: \n";
            fgets(aux -> banca_horario, 100,stdin);
            cout << "Informe o local: \n";
            fgets(aux -> banca_local, 100,stdin);
            Salvar_informacoes();
        }else if(mat =! aux->matricula_aluno){
            aux = aux->prox;
        }else{
            cout << "matricula não encontrada\n";
        }
    }
    
}
void remover(){
    int mat;
    cout << "insira a matricula a ser removida: \n";
    cin >> mat;
    dados *aux = inicio;
    for (int i = 0; i < tam; i++){
       if(aux->matricula_aluno == mat){
            inicio = aux->prox;
            free(aux);
            tam--;
            Salvar_informacoes();
        }else if(aux->prox->matricula_aluno == mat){
            aux->prox = aux->prox->prox;
            tam--;
            free(aux);
            Salvar_informacoes();
        }else{
            aux = aux->prox;
        }
    }
    
}
int menu(){
    int op;
    cout << "1 - Cadastrar\n";
    cout << "2 - Exibir\n";
    cout << "3 - Atualizar\n";
    cout << "4 - Remover\n";
    cout << "5 - Sair\n";
    cin >> op;
    switch(op){
        case 1: Cadastrar();break;
        case 2: Exibir();break;
        case 3: atualizar();break;
        case 4: remover();break;
        case 5: sair = 1; return 0;
        default:cout << "Opçao invalida\n";break;
    }
}
    

int main(){
   p = fopen("aluno.txt", "wb");
   if(p == NULL){
       cout << "Erro para abrir arquivo\n";
       exit(1);
       
   }
   fclose(p);
   while(sair < 1){
       menu();
   }

}










