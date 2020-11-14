#ifndef _VBSYS_H_
#define _VBSYS_H_

#include "bicicleta.h"
#include "cliente.h"
#include "venda.h"

typedef struct {
	Cliente** clientes;
	int n_clientes;

	Venda** vendas;
	int n_vendas; 

	Bicicleta** bicicletas;
	int n_bicicletas;
} VBSys;

#endif 

