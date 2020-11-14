
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "cliente.h"

// retorna 1 se o cpf e valido 
int cpf_valido(std::string) {
	// A SE IMPLEMENTAR
	return 1;
}

// funcao que diz a quantidade de clientes registrados 
int quantidade_clientes_registrados() {
	int tamanho = 0;
	std::string linha;
	// le arquivo 
	std::ifstream clientes("./data/clientes.csv");
	while (getline(clientes, linha)) {
		tamanho++;
	}
	return tamanho;
}

Cliente** clintes_registrados(int n_clientes) {
	// aloca memoria 
	Cliente** clientes_vetor = new Cliente*[n_clientes];
	std::string linha, nome, cpf, endereco;
	// le arquivo 
	std::ifstream clientes("./data/clientes.csv");
	for (int i = 0; i < n_clientes; i++) {
		// le o cliente 
		getline(clientes, linha);
		// cria um stream baseado na linha
        std::stringstream ss(linha);
        std::getline(ss, cpf, ';');
        std::getline(ss, nome, ';');
        std::getline(ss, endereco, ';');
        // cria cliente e adiciona valores
        clientes_vetor[i] = new Cliente();
        clientes_vetor[i]->nome = nome.c_str();
        clientes_vetor[i]->CPF = cpf.c_str();
        clientes_vetor[i]->endereco = endereco.c_str();
        //std::cout<<clientes_vetor[i]->CPF<<", "<<clientes_vetor[i]->nome<<", "<<clientes_vetor[i]->endereco<<", "<<std::endl;
	}

	return clientes_vetor;
}

Cliente* procurar_cliente(Cliente** clientes, int tamanho, std::string cpf) {
	// para cada cliente no vetor 
	for (int i = 0; i < tamanho; i++) {
		// se o cliente possui o cpf passado, retorna o valor
		if (clientes[i]->CPF == cpf) {
			return clientes[i];
		}
	}

	return NULL;
}

// funcao para cadastrar cliente 
int cadastrar_cliente() {
	std::string nome, cpf, endereco;

	// obtem valores do usuario 
	std::cout<<"Nome:"<<std::endl;
	do {
		getline(std::cin, nome);
	}
	while (nome.length() < 3);
	std::cout<<"Valor: "<<nome<<std::endl;

	std::cout<<"Endereço:"<<std::endl;
	do {
		getline(std::cin, endereco);
	}
	while (endereco.length() < 3);
	std::cout<<"Valor: "<<endereco<<std::endl;

	std::cout<<"CPF:"<<std::endl;
	do {
		getline(std::cin, cpf);
	}
	while (cpf_valido(cpf) != 1);

	// PARA IMPLEMENTAR: Checar se o valor do CPF Passsado ja nao existe na tabela 
	std::cout<<"Valor: "<<cpf<<std::endl;

	// abre e adicionar os valores no arquivo
	std::ofstream clientes("./data/clientes.csv");
	clientes << cpf << ";" << nome << ";" << endereco << "\n";
	// fecha arquivo
    clientes.close();

	return 1;
}