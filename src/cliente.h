#include <string>

#ifndef _CLIENTE_H_
#define _CLIENTE_H_

typedef struct {
	const char* nome;
	const char* CPF; // 123.456.789-01
	const char* endereco;
} Cliente;

int cadastrar_cliente(Cliente**, int);

int quantidade_clientes_registrados();

Cliente** clintes_registrados(int);

Cliente* procurar_cliente(Cliente**, int);

int alterar_cliente(Cliente**, int);



#endif
