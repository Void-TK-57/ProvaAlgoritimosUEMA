#include "bicicleta.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "cliente.h"
#include <string.h>

#ifndef _VENDA_H_
#define _VENDA_H_

typedef struct {
	int codigo;
	const char* CPF;
	double total;
} Venda;

int realizar_venda(Bicicleta**, int, Cliente** , int);

Venda** historico_cliente(Cliente* );

void mais_vendida();

void historico_cliente(Cliente**, int n_cliente);

#endif
