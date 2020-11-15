
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "cliente.h"
#include <string.h>

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
		// copia a string
		char* c_nome = new char[nome.size()+1];
		std::copy(nome.begin(), nome.end(), c_nome);
		c_nome[nome.size()] = '\0';
        clientes_vetor[i]->nome = c_nome;
		// copia a string
		char* c_cpf = new char[cpf.size()+1];
		std::copy(cpf.begin(), cpf.end(), c_cpf);
		c_cpf[cpf.size()] = '\0';
        clientes_vetor[i]->CPF = c_cpf;
		// copia a string
		char* c_endereco = new char[endereco.size()+1];
		std::copy(endereco.begin(), endereco.end(), c_endereco);
		c_endereco[endereco.size()] = '\0';
        clientes_vetor[i]->endereco = c_endereco;
        //std::cout<<clientes_vetor[i]->CPF<<", "<<clientes_vetor[i]->nome<<", "<<clientes_vetor[i]->endereco<<", "<<std::endl;
	}

	return clientes_vetor;
}

Cliente* procurar_cliente(Cliente** clientes, int tamanho) {
	std::string cpf;
	// obtem string
	std::cout<<"CPF do Cliente:"<<std::endl; // 68573724615
	do {
		getline(std::cin, cpf);
	}
	while (cpf.length() != 11 ) ;

	// para cada cliente no vetor
	for (int i = 0; i < tamanho; i++) {
		// se o cliente possui o cpf passado, retorna o valor
		if (clientes[i]->CPF == cpf) {
			return clientes[i];
		}
	}

	return NULL;
}

int alterar_cliente(Cliente** clientes, int tamanho) {
	Cliente* cliente;
	std::string nome, cpf, endereco;

	// procura cliente
	do {
		cliente = procurar_cliente(clientes, tamanho);
	} while (clientes == NULL);

	// obtem valores do usuario
	do {
		std::cout<<"Novo Nome:"<<std::endl;
		getline(std::cin, nome);
	}
	while (nome.length() < 3);

	do {
		std::cout<<"Novo Endereço:"<<std::endl;
		getline(std::cin, endereco);
	}
	while (endereco.length() < 3);

	do {
		std::cout<<"Novo CPF:"<<std::endl;
		getline(std::cin, cpf);
	}
	while (cpf.length() != 11);

	// copia a string
	char* c_nome = new char[nome.size()+1];
	std::copy(nome.begin(), nome.end(), c_nome);
	c_nome[nome.size()] = '\0';
	cliente->nome = c_nome;
	// copia a string
	char* c_cpf = new char[cpf.size()+1];
	std::copy(cpf.begin(), cpf.end(), c_cpf);
	c_cpf[cpf.size()] = '\0';
	cliente->CPF = c_cpf;
	// copia a string
	char* c_endereco = new char[endereco.size()+1];
	std::copy(endereco.begin(), endereco.end(), c_endereco);
	c_endereco[endereco.size()] = '\0';
	cliente->endereco = c_endereco;

	// salva todos os clientes novamente
	std::ofstream f_clientes("./data/clientes.csv");
	for (int i = 0; i < tamanho; i++) {
		f_clientes << clientes[i]->CPF << ";" << clientes[i]->nome << ";" << clientes[i]->endereco << "\n";
	}
	// fecha arquivo
    f_clientes.close();
	return 1;
}

// funcao para cadastrar cliente
int cadastrar_cliente(Cliente** clientes, int tamanho) {
	std::string nome, cpf, endereco;

	// obtem valores do usuario
	do {
		std::cout<<"Nome:"<<std::endl;
		getline(std::cin, nome);
	}
	while (nome.length() < 3);

	do {
		std::cout<<"Endereço:"<<std::endl;
		getline(std::cin, endereco);
	}
	while (endereco.length() < 3);

	do {
		std::cout<<"CPF:"<<std::endl;
		getline(std::cin, cpf);
		// para cada cliente no vetor
		for (int i = 0; i < tamanho; i++) {
			// se o cliente possui o cpf passado, retorna o valor
			if (clientes[i]->CPF == cpf) {
				std::cout<<"CPF Ja Existe"<<std::endl;
				cpf = "";
			}
		}
	}
	while (cpf.length() != 11);


	// abre e adicionar os valores no arquivo
	std::ofstream fclientes;
	fclientes.open("./data/clientes.csv", std::ios::out | std::ios::app);
	fclientes << cpf << ";" << nome << ";" << endereco << "\n";
	// fecha arquivo
    fclientes.close();

	return 1;
}
