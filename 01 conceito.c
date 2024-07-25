// conceitos basicos da orientação objeto 

// classe: define a estrutura de dados 

// objeto: instancia de uma classe 

// escapsulamento: restrição do acesso direito a alguns dos componentes 

// herança: mecaninismo onde as classes podem herdar membros 

// polifismo: capacidade  de uma variavel função ou objeto de assumir 

// abstração:  processo de esconder os detalhe de implementação e mostrar apenas funcionalidade 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Pessoa
struct Pessoa {
    char nome[50];
    int idade;
    char profissao[50];
};

// Função para criar uma nova Pessoa
struct Pessoa* nova_Pessoa() {
    struct Pessoa* pessoa = (struct Pessoa*) malloc(sizeof(struct Pessoa));
    return pessoa;
}

// Funções para configurar os dados da Pessoa
void setNome(struct Pessoa* pessoa, const char* nome) {
    strcpy(pessoa->nome, nome);
}

void setIdade(struct Pessoa* pessoa, int idade) {
    pessoa->idade = idade;
}

void setProfissao(struct Pessoa* pessoa, const char* profissao) {
    strcpy(pessoa->profissao, profissao);
}

// Funções para obter os dados da Pessoa
const char* getNome(struct Pessoa* pessoa) {
    return pessoa->nome;
}

int getIdade(struct Pessoa* pessoa) {
    return pessoa->idade;
}

const char* getProfissao(struct Pessoa* pessoa) {
    return pessoa->profissao;
}
// como ativar os novos cadrastros 
int main() {
    int numPessoas, idade;
    char nome[50], profissao[50];
    printf("Quantas pessoas deseja cadrastar? ");
    scanf("%d",&numPessoas);

    struct Pessoa* pessoas[numPessoas];

    for(int i = 0; i < numPessoas; i++) {
        pessoas[i] = nova_Pessoa();

        printf("\nDigite o nome da pessoa %d: ", i + 1);
        scanf("%s", nome);
        setNome(pessoas[i], nome);

        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &idade);
        setIdade(pessoas[i], idade);

        printf("Digite a profissão da pessoa %d: ", i + 1);
        scanf("%s", profissao);
        setProfissao(pessoas[i], profissao);
    }

    printf("\nDados das pessoas cadastradas:\n");
    for(int i = 0; i < numPessoas; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s\n", getNome(pessoas[i]));
        printf("Idade: %d\n", getIdade(pessoas[i]));
        printf("Profissão: %s\n", getProfissao(pessoas[i]));

        // Liberar memória alocada para cada pessoa
        free(pessoas[i]);
    }

    return 0;
    
}
