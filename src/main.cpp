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

/*

//Vender bicicleta
//Bicicletas no estoque
//Bicicletas mais vendida
//Histórico de um cliente
//Cadastrar Cliente
//Cadastrar Bicicleta
//Alterar Bicicleta
//Alterar Cliente
//Sair

*/



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
	// inicialmente, carrega cliente e bicicletas
	int n_clientes = quantidade_clientes_registrados();
	Cliente** clientes = clintes_registrados(n_clientes);

	int n_bicicletas = quantidade_bicicletas_registradas();
	Bicicleta** bicicletas = bicicletas_registradas(n_bicicletas);

	// opcao escolhida pelo usuario
	int opcao = -1;
	// enquanto opcao nao for 9 (sair) continua a execucao
	while (obter_opcao(&opcao) != 9) {
		switch (opcao) {
			case 1:
				if (realizar_venda(bicicletas, n_bicicletas, clientes, n_clientes) == 1) {
					std::cout<<"Venda Realizada Com Sucesso!"<<std::endl;
				}
				n_clientes = quantidade_clientes_registrados();
				clientes = clintes_registrados(n_clientes);

				n_bicicletas = quantidade_bicicletas_registradas();
				bicicletas = bicicletas_registradas(n_bicicletas);
				break;
			case 2:
				std::cout<<"Bicicletas Disponiveis:"<<std::endl;
				for (int i = 0; i < n_bicicletas; i++) {
					std::cout<<"Codigo: "<< bicicletas[i]->codigo<<"; Marca: "<<bicicletas[i]->marca<<"; Modelo: "<<bicicletas[i]->modelo<<"; Valor: "<<bicicletas[i]->valor<<std::endl;
				}
				break;
			case 3:
				mais_vendida();
				break;
			case 4:
				historico_cliente(clientes, n_clientes);
				break;
			case 5:
				if (cadastrar_cliente(clientes, n_clientes) == 1) {
					std::cout<<"Cadastro Realizado Com Sucesso!"<<std::endl;
				}
				n_clientes = quantidade_clientes_registrados();
				clientes = clintes_registrados(n_clientes);

				n_bicicletas = quantidade_bicicletas_registradas();
				bicicletas = bicicletas_registradas(n_bicicletas);
				break;
			case 6:
				if (cadastrar_bicicleta(bicicletas, n_bicicletas) == 1) {
					std::cout<<"Cadastro Realizado Com Sucesso!"<<std::endl;
				}
				n_clientes = quantidade_clientes_registrados();
				clientes = clintes_registrados(n_clientes);

				n_bicicletas = quantidade_bicicletas_registradas();
				bicicletas = bicicletas_registradas(n_bicicletas);
				break;
			case 7:
				if (alterar_bicicleta(bicicletas, n_bicicletas) == 1) {
					std::cout<<"Alteração Realizada Com Sucesso!"<<std::endl;
				}
				n_clientes = quantidade_clientes_registrados();
				clientes = clintes_registrados(n_clientes);

				n_bicicletas = quantidade_bicicletas_registradas();
				bicicletas = bicicletas_registradas(n_bicicletas);
				break;
			case 8:
				if (alterar_cliente(clientes, n_clientes) == 1) {
					std::cout<<"Alteração Realizada Com Sucesso!"<<std::endl;
				}
				n_clientes = quantidade_clientes_registrados();
				clientes = clintes_registrados(n_clientes);

				n_bicicletas = quantidade_bicicletas_registradas();
				bicicletas = bicicletas_registradas(n_bicicletas);
				break;
		}
	}
	std::cout << "Finalizando..." << std::endl;

	// deleta vetor de clientes
	for (int i = 0; i < n_clientes; i++) {
		delete[] clientes[i]->nome;
		delete[] clientes[i]->CPF;
		delete[] clientes[i]->endereco;
		delete clientes[i];
	}
	delete[] clientes;

	// deleta vetor de bicicletas
	for (int i = 0; i < n_bicicletas; i++) {
		delete[] bicicletas[i]->marca;
		delete[] bicicletas[i]->modelo;
		delete bicicletas[i];
	}
	delete[] bicicletas;

	return 0;
}
