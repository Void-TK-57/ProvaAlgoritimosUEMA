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
	// opcao escolhida pelo usuario 
	int opcao = -1;
	// enquanto opcao nao for 9 (sair) continua a execucao
	while (obter_opcao(&opcao) != 9) {
		std::cout<<"Opcao escolhida: "<<opcao<<std::endl;
	}
	std::cout << "Finalizando..." << std::endl;
	return 0;
}


