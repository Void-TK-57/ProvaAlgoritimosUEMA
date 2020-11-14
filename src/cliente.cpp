
#include <iostream>
#include <string>
#include <fstream>
#include "cliente.h"

// retorna 1 se o cpf e valido 
int cpf_valido(std::string) {
	// a se implementar 
	return 1;
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
	std::cout<<"Valor: "<<cpf<<std::endl;

	// abre e adicionar os valores no arquivo
	std::ofstream clientes("./data/clientes.csv");
	clientes << cpf << ";" << nome << ";" << endereco << "\n";
	// fecha arquivo
    clientes.close();

	return 1;
}