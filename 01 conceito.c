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

int main() {
    struct Pessoa* Fabio;
    Fabio = nova_Pessoa();
    setNome(Fabio, "Fabio");
    setIdade(Fabio, 30);
    setProfissao(Fabio, "Programador");

    printf("meu nome: %s\n", getNome(Fabio));
    printf("minha idade: %d\n", getIdade(Fabio));
    printf("minha profissão: %s\n", getProfissao(Fabio));

    // Importante liberar a memória alocada
    free(Fabio);

    return 0;
}
