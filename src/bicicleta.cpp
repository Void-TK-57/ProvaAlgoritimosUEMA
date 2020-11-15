
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "bicicleta.h"

// funcao que diz a quantidade de bicicletas registrados
int quantidade_bicicletas_registradas() {
	int tamanho = 0;
	std::string linha;
	// le arquivo
	std::ifstream bicicletas("./data/bicicletas.csv");
	while (getline(bicicletas, linha)) {
		tamanho++;
	}
	return tamanho;
}

Bicicleta** bicicletas_registradas(int n_bicicletas) {
	// aloca memoria
	Bicicleta** bicicletas_vetor = new Bicicleta*[n_bicicletas];
	std::string linha, marca, modelo, codigo_str, valor_str;
	int codigo;
	double valor;
	// le arquivo
	std::ifstream bicicletas("./data/bicicletas.csv");
	for (int i = 0; i < n_bicicletas; i++) {
		// le o bicicleta
		getline(bicicletas, linha);
		// cria um stream baseado na linha
        std::stringstream ss(linha);
		std::getline(ss, codigo_str, ';');
        std::getline(ss, marca, ';');
        std::getline(ss, modelo, ';');
        std::getline(ss, valor_str, ';');
        // cria bicicleta e adiciona valores
        bicicletas_vetor[i] = new Bicicleta();

		std::stringstream codigo_ss(codigo_str);
		codigo_ss >> codigo;
		bicicletas_vetor[i]->codigo = codigo;

		char* c_marca = new char[marca.size()+1];
		std::copy(marca.begin(), marca.end(), c_marca);
		c_marca[marca.size()] = '\0';
        bicicletas_vetor[i]->marca = c_marca;

		char* c_modelo = new char[modelo.size()+1];
		std::copy(modelo.begin(), modelo.end(), c_modelo);
		c_modelo[modelo.size()] = '\0';
        bicicletas_vetor[i]->modelo = c_modelo;

		std::stringstream valor_ss(valor_str);
		valor_ss >> valor;
		bicicletas_vetor[i]->valor = valor;

    }

	return bicicletas_vetor;
}


Bicicleta* procurar_bicicleta(Bicicleta** bicicletas, int tamanho) {
	int codigo;
	// obtem string
	std::cout<<"Codigo da Bicicleta:"<<std::endl; // 68573724615
	do {
		std::cin>>codigo;
	}
	while ( codigo < 0 ) ;


	// para cada bicicleta no vetor
	for (int i = 0; i < tamanho; i++) {
		// se o bicicleta possui o cpf passado, retorna o valor
		if (bicicletas[i]->codigo == codigo) {
			return bicicletas[i];
		}
	}

	return NULL;
}


int alterar_bicicleta(Bicicleta** bicicletas, int tamanho) {
	Bicicleta* bicicleta;
	std::string marca, modelo;
	int codigo;
	double valor;

	// procura bicicleta
	do {
		bicicleta = procurar_bicicleta(bicicletas, tamanho);
	} while (bicicletas == NULL);

	// obtem valores do usuario
	std::cout<<"Novo Marca:"<<std::endl;
	do {
		getline(std::cin, marca);
	}
	while (marca.length() < 3);

	std::cout<<"Novo Modelo:"<<std::endl;
	do {
		getline(std::cin, modelo);
	}
	while (modelo.length() < 3);

	std::cout<<"Novo Codigo:"<<std::endl;
	do {
		std::cin>>codigo;
	}
	while (codigo < 0);

	std::cout<<"Novo Valor:"<<std::endl;
	do {
		std::cin>>valor;
	}
	while (codigo < 0.0);

	bicicleta->codigo = codigo;

	char* c_marca = new char[marca.size()+1];
	std::copy(marca.begin(), marca.end(), c_marca);
	c_marca[marca.size()] = '\0';
	bicicleta->marca = c_marca;

	char* c_modelo = new char[modelo.size()+1];
	std::copy(modelo.begin(), modelo.end(), c_modelo);
	c_modelo[modelo.size()] = '\0';
	bicicleta->modelo = c_modelo;

	bicicleta->valor = valor;

	// salva todos os bicicletas novamente
	std::ofstream f_bicicletas("./data/bicicletas.csv");
	for (int i = 0; i < tamanho; i++) {
		f_bicicletas << bicicletas[i]->codigo << ";" << bicicletas[i]->modelo << ";" << bicicletas[i]->marca << ";" << bicicletas[i]->valor << "\n";
	}
	// fecha arquivo
    f_bicicletas.close();
	return 1;
}


// funcao para cadastrar bicicleta
int cadastrar_bicicleta(Bicicleta** bicicletas, int tamanho) {
	std::string marca, modelo;
	int codigo;
	double valor;

	// obtem valores do usuario
	do {
		std::cout<<"Marca:"<<std::endl;
		getline(std::cin, marca);
	}
	while (marca.length() < 3);

	do {
		std::cout<<"Modelo:"<<std::endl;
		getline(std::cin, modelo);
	}
	while (modelo.length() < 3);

	do {
		std::cout<<"Codigo:"<<std::endl;
		std::cin>>codigo;
		// para cada cliente no vetor
		for (int i = 0; i < tamanho; i++) {
			// se o cliente possui o cpf passado, retorna o valor
			if (bicicletas[i]->codigo == codigo) {
				std::cout<<"codigo Ja Existe"<<std::endl;
				codigo = -1;
			}
		}
	}
	while (codigo < 0);

	do {
		std::cout<<"Valor:"<<std::endl;
		std::cin>>valor;
	}
	while (codigo < 0.0);

	// PARA IMPLEMENTAR: Checar se o valor do CPF Passsado ja nao existe na tabela

	// abre e adicionar os valores no arquivo
	std::ofstream fbicicletas;
	fbicicletas.open("./data/bicicletas.csv", std::ios::out | std::ios::app);
	fbicicletas << codigo << ";" << modelo << ";" << marca << ";" << valor << "\n";
	// fecha arquivo
    fbicicletas.close();

	return 1;
}
