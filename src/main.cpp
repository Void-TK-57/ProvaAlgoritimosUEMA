#include <iostream>

#include "bicicleta.h"
#include "cliente.h"
#include "venda.h"
#include "vbsys.h"

/*
Cadastrar
Consultar Estoque
Vender
Consultar a bicileta que mais for vendida 
Consultar Historico
*/

// funcao para mostrar opcoes 
void mostrar_opcoes() {
	// mostra as opcoes
	std::cout<<"Digite 1 a 9 para escolher uma das opções a seguir:"<<std::endl;
	std::cout<<"\t[1] - Vender bicicleta"<<std::endl;
	std::cout<<"\t[2] - Bicicletas no estoque"<<std::endl;
	std::cout<<"\t[3] - Bicicletas mais vendida"<<std::endl;
	std::cout<<"\t[4] - Histórico de um cliente"<<std::endl;
	std::cout<<"\t[5] - Cadastrar Cliente"<<std::endl;
	std::cout<<"\t[6] - Cadastrar Bicicleta"<<std::endl;
	std::cout<<"\t[7] - Alterar Bicicleta"<<std::endl;
	std::cout<<"\t[8] - Alterar Cliente"<<std::endl;
	std::cout<<"\t[9] - Sair "<<std::endl;
}


// funcao para obter argumento do usuario 
int obter_opcao(int* opcao) {
	// mostra as opcoes 
	mostrar_opcoes();
	std::cout<<"--> ";
	// obtem opcao 
	std::cin >> *opcao;
	// se a opcao nao for entre 1 e 9 tentar obter-la de novo
	if ( ( *opcao < 1 ) || (*opcao > 9) ) obter_opcao(opcao);
	// por fim, retorna o valor opcao
	return *opcao;
}


int main() {
	std::cout << "Bem Vindo." << std::endl;
	// inicialmente, carrega cliente 
	int n_clientes = quantidade_clientes_registrados();
	Cliente** clientes = clintes_registrados(n_clientes);
	// opcao escolhida pelo usuario 
	int opcao = -1;
	// enquanto opcao nao for 9 (sair) continua a execucao
	while (obter_opcao(&opcao) != 9) {
		switch (opcao) {
			case 1:
				std::cout<<1<<std::endl;
				break;
			case 2:
				std::cout<<2<<std::endl;
				break;
			case 3:
				std::cout<<3<<std::endl;
				break;
			case 4:
				std::cout<<4<<std::endl;
				break;
			case 5:
				if (cadastrar_cliente() == 1) {
					std::cout<<"Cadastro Realizado Com Sucesso!"<<std::endl;
				}
				break;
			case 6:
				std::cout<<6<<std::endl;
				break;
			case 7:
				std::cout<<7<<std::endl;
				break;
			case 8:
				std::cout<<8<<std::endl;
				break;
		}
	}
	std::cout << "Finalizando..." << std::endl;

	// deleta vetor de clientes 
	for (int i = 0; i < n_clientes; i++) {
		delete clientes[i];
	}
	delete[] clientes;

	return 0;
}


