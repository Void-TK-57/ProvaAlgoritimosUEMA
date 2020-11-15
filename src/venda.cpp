#include "venda.h"
#include "bicicleta.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "cliente.h"
#include <string.h>
#include <map>

int realizar_venda(Bicicleta** bicicletas, int n_bicicletas, Cliente** clientes, int n_clientes) {
    // procura cliente e bicicleta da venda
    Cliente* cliente;
    do {
        cliente = procurar_cliente(clientes, n_clientes);
    } while (cliente == NULL);

    // mostra bicicletas
    std::cout<<"Bicicletas Disponiveis:"<<std::endl;
    for (int i = 0; i < n_bicicletas; i++) {
        std::cout<<"Codigo: "<< bicicletas[i]->codigo<<"; Marca: "<<bicicletas[i]->marca<<"; Modelo: "<<bicicletas[i]->modelo<<"; Valor: "<<bicicletas[i]->valor<<std::endl;
    }
    // requer bicicleta
    Bicicleta* bicicleta;
    do {
        bicicleta = procurar_bicicleta(bicicletas, n_bicicletas);
    } while (bicicleta == NULL);

	// remove do estoque
	std::ofstream f_bicicletas("./data/bicicletas.csv");
	for (int i = 0; i < n_bicicletas; i++) {
		if (bicicletas[i]->codigo != bicicleta->codigo) {
			f_bicicletas << bicicletas[i]->codigo << ";" << bicicletas[i]->modelo << ";" << bicicletas[i]->marca << ";" << bicicletas[i]->valor << "\n";
		}
	}
	// fecha arquivo
    f_bicicletas.close();

    // abre e adicionar os valores no arquivo
	std::ofstream vendas;
	vendas.open("./data/vendas.csv", std::ios::out | std::ios::app);
	vendas << cliente->CPF << ";" << bicicleta->codigo << ";" << bicicleta->marca << ";" << bicicleta->modelo<< ";" << bicicleta->valor << "\n";
	// fecha arquivo
    vendas.close();

	return 1;

}

void mais_vendida() {
	//contador
	std::map<std::string, int> quantidade;
	std::string linha, codigo, cpf, valor, modelo, marca;
	// le arquivo
	std::ifstream vendas("./data/vendas.csv");
	while (getline(vendas, linha)) {
		// cria um stream baseado na linha
        std::stringstream ss(linha);
        std::getline(ss, cpf, ';');
        std::getline(ss, codigo, ';');
		std::getline(ss, marca, ';');
        std::getline(ss, modelo, ';');
		std::getline(ss, valor, ';');
        // cria cliente e adiciona valores
		quantidade[modelo] = 0;
    }
	vendas.close();

	// le arquivo
	std::ifstream vendas2("./data/vendas.csv");
	while (getline(vendas2, linha)) {
		// cria um stream baseado na linha
        std::stringstream ss(linha);
        std::getline(ss, cpf, ';');
        std::getline(ss, codigo, ';');
		std::getline(ss, marca, ';');
        std::getline(ss, modelo, ';');
		std::getline(ss, valor, ';');
        // cria cliente e adiciona valores
		quantidade[modelo] += 1;
    }
	vendas2.close();

	std::string bicicleta_mais_vendida = "Nenhuma";
	int total_vendas = -1;
	// obtem modelo de maior venda
	for (std::map<std::string,int>::iterator it = quantidade.begin(); it!=quantidade.end(); ++it) {
		if (it->second > total_vendas) {
			total_vendas = it->second;
			bicicleta_mais_vendida = it->first;
		}
	}

    std::cout<<"Modelo da Bicicleta Mais Vendida: "<<bicicleta_mais_vendida<<", Total de Vendas: "<<total_vendas<<std::endl;
}


void historico_cliente(Cliente** clientes, int n_cliente) {
	// obtem cliente
	Cliente* cliente;
	std::string linha, codigo, cpf, valor, modelo, marca;
	do {
		cliente = procurar_cliente(clientes, n_cliente);
	} while (cliente == NULL);
	// le arquivo
	std::ifstream vendas("./data/vendas.csv");
	std::cout<<"Bicicletas Compradas por "<<cliente->nome<<": "<<std::endl;
	while (getline(vendas, linha)) {
		// cria um stream baseado na linha
        std::stringstream ss(linha);
        std::getline(ss, cpf, ';');
        std::getline(ss, codigo, ';');
		std::getline(ss, marca, ';');
        std::getline(ss, modelo, ';');
		std::getline(ss, valor, ';');
		if (cpf == cliente->CPF) {
			std::cout<<"Marca: "<<marca<<", Modelo: "<<modelo<<", Valor: "<<valor<<", Codigo: "<<codigo<<std::endl;
		}
    }
	vendas.close();

}
