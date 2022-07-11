typedef struct dados{
    char nome_aluno[100];
    int matricula_aluno;
    char curso_aluno[100];
    char email_aluno[100];
    char nome_orientador[100];
    int frequencia_aluno;
    char nome_avaliador[100];
    char nome_instituicao[100];
    char email_avaliador[100];
    char banca_titulo[100];
    char banca_resumo[600];
    char banca_horario[100];
    char banca_local[100];

    struct dados * prox;
    struct dados * ant;
}dados;