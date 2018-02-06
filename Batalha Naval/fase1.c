#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*A função interp irá retirar a informação essencial para compreender 
o tabuleiro em causa, nomeadamente, o número de linhas, colunas, 
a soma dos objetos que se encontram em cada linha/coluna, bem como os elementos que estão em casa posição do tabuleiro.*/

TAB interp(FILE *fp, TAB t)
{
	int i,j,x,y;
	char linha[MAXL];
	char resto[MAXL];
	if (fgets(linha, MAXL, fp) != NULL)
		sscanf(linha, "%d %d", &t.lin, &t.col);
	if (fgets(linha, MAXL, fp) != NULL){
		for(i = 0; i<t.lin; i++)
		{

			sscanf(linha, "%d %[^\n]", &t.somal[i], resto);
			strcpy(linha, resto);
		}
	}
	if (fgets(linha, MAXL, fp) != NULL){
		for(j=0; j<t.col; j++)
		{
			sscanf(linha, "%d %[^\n]", &t.somac[j],resto);
			strcpy(linha, resto);
		}
	}
	for(x=0; x<t.lin; x++)
	{
		if (fgets(linha,MAXL,fp) != NULL){
			for(y=0; y<t.col; y++)
				t.m[x][y] = linha[y];
		}
	}

	return t;
}

/*A função estadoL recebe um inteiro correspondente à linha da matriz em que o estado não definido passará a
estar definido como água.
*/

TAB estadoL(TAB t, int l)
{
	int y; l--;
	for(y = 0; y<t.col; y++)
		if (t.m[l][y] == '.') t.m[l][y] = '~';
	return t;
}

/*A função estadoC recebe um inteiro correspondente à coluna da matriz em que o estado não definido passará a
estar definido como água.
*/

TAB estadoC(TAB t, int c)
{
	int x; c--;
	for(x = 0; x<t.lin; x++)
		if (t.m[x][c] == '.') t.m[x][c] = '~';	
	return t;
}

/*A função coloca recebe um caracter (char) e dois inteiros representantes da coluna e da linha da matriz em que
o caracter inserido substituirá o caracter existente. 
*/

TAB coloca(TAB t, char a, int l, int c)
{
	l--; c--;
	if ((l<t.lin) && (c<t.col)) t.m[l][c] = a;
	return t;
} 
