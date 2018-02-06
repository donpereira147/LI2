#include <stdio.h>
#include <string.h>

void imprimir_palavras (char *linha) {
	char *separador = "\t\n\r";
	char *pal =NULL;

	pal = strtok (linha, separador);
	printf("%s\n", pal);

	while ((pal = strtok(NULL, separador)) != NULL) { 
	printf("%s\n", pal);
	}
}

int main () {
	char c [20] = "lel";
	imprimir_palavras (c);
	return 0;
}
