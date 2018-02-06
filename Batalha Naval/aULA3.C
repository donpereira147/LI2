#include <stdio.h>

typedef struct estado {
	float soma v;
	int num;
	float minimo;
	float maximo;
	float calores [100000];
} ESTADO;

ESTADO E;
 e -> somav = 0;
 e -> num = 0;

void inserir (ESTADO *e, float v){
	e -> soma v += v; e . valores[e -> num] = v;
	e -> num ++;
	if (e -> minimo > v)
		e -> minimo = v;
	...
	return e;
}

void interpretador (ESTADO *e, char *linha){
	.....
	inserir (e , v);
}

... ESTADO ...

int main () {
	char linha [1024];
	ESTADO e;
	e . soma v = e.num = e.minimo = e.maximo = 0;
	while (fgets (linha, 1024, stdin)) interpretador  (&&, linha);
	return 0;
}