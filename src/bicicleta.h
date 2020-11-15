#include <string>

#ifndef _BICICLETA_H_
#define _BICICLETA_H_

typedef struct {
	int codigo;
	const char* marca;
	const char* modelo;
	double valor;
} Bicicleta;

int cadastrar_bicicleta(Bicicleta** bicicletas, int tamanho);

int quantidade_bicicletas_registradas();

Bicicleta** bicicletas_registradas(int);

int cpf_valido(std::string);

Bicicleta* procurar_bicicleta(Bicicleta**, int);

int alterar_bicicleta(Bicicleta**, int);

#endif
