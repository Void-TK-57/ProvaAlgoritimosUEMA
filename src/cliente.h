#include <string>

#ifndef _CLIENTE_H_
#define _CLIENTE_H_

typedef struct {
	const char* nome;
	const char* CPF;
	const char* endereco;
} Cliente;

int cadastrar_cliente();

int cpf_valido(std::string);

#endif 
