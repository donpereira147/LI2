#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*A função mostrar imprime o tabuleiro e a soma do número de constituintes dos barcos no fim de cada linha/coluna que 
existem nessa linha/coluna.
*/

void mostrar(FILE *fp2, TAB t)
{
	int l, c;
	for (l = 0; l < t.lin; l++)
		for(c = 0; c <= t.col; c++)
			if (c == t.col) fprintf(fp2," %d\n", t.somal[l]);
			else fprintf(fp2, "%c", t.m[l][c]);
	for(l = 0; l < t.col; l++)
		fprintf(fp2, "%d", t.somac[l]);
	fprintf(fp2,"\n");
}


TAB strat1(TAB t)
{
	int l, c;
	for(l = 0; l < t.lin; l++)
	  for(c = 0; c < t.col; c++)
		switch (t.m[l][c])
		{
			case '<':
				if (((l-1) >= 0) && ((c-1) >= 0)) t.m[l-1][c-1] = '~';
				if ((l-1) >= 0) t.m[l-1][c] = '~';
				if ((c-1) >= 0) t.m[l][c-1] = '~';
				if (((l+1) < t.lin) && ((c+1) < t.col)) t.m[l+1][c+1] = '~'; 
				if ((l+1) < t.lin) t.m[l+1][c] = '~';
				if (((l-1) >= 0) && ((c+1) < t.col)) t.m[l-1][c+1] = '~';
				if (((l+1) < t.lin) && ((c-1) >= 0)) t.m[l+1][c-1] = '~';
			break;
			case '>':
				if (((l-1) >= 0) && ((c-1) >= 0)) t.m[l-1][c-1] = '~';
				if ((l-1) >= 0) t.m[l-1][c] = '~';
				if (((l+1) < t.lin) && ((c+1) < t.col))  t.m[l+1][c+1] = '~';
				if ((l+1) < t.lin) t.m[l+1][c] = '~';
				if ((c+1) >= 0) t.m[l][c+1] = '~';
				if (((l-1) >= 0) && ((c+1) <t.col)) t.m[l-1][c+1] = '~'; 
				if (((l+1) < t.lin) && ((c-1) >= 0)) t.m[l+1][c-1] = '~';
			break;
			case '^':
				if (((l-1) >= 0) && ((c-1) >= 0)) t.m[l-1][c-1] = '~';
				if ((l-1) >= 0) t.m[l-1][c] = '~';
				if ((c-1) >= 0) t.m[l][c-1] = '~';
				if (((l+1) < t.lin) && ((c+1) < t.col)) t.m[l+1][c+1] = '~';
				if ((c+1) >= 0) t.m[l][c+1] = '~';
				if (((l-1) >= 0) && ((c+1) <t.col)) t.m[l-1][c+1] = '~';
				if (((l+1) < t.lin) && ((c-1) >= 0)) t.m[l+1][c-1] = '~';
			break;
			case 'v':
				if (((l-1) >= 0) && ((c-1) >= 0)) t.m[l-1][c-1] = '~';
				if ((c-1) >= 0) t.m[l][c-1] = '~';
				if (((l+1) < t.lin) && ((c+1) < t.col)) t.m[l+1][c+1] = '~';
				if ((l+1) < t.lin) t.m[l+1][c] = '~';
				if ((c+1) >= 0) t.m[l][c+1] = '~';
				if (((l-1) >= 0) && ((c+1) <t.col)) t.m[l-1][c+1] = '~';
				if (((l+1) < t.lin) && ((c-1) >= 0)) t.m[l+1][c-1] = '~';
			break;
			case 'O':
				if (((l-1) >= 0) && ((c-1) >= 0)) t.m[l-1][c-1] = '~';
				if ((l-1) >= 0) t.m[l-1][c] = '~';
				if ((c-1) >= 0) t.m[l][c-1] = '~';
				if (((l+1) < t.lin) && ((c+1) < t.col)) t.m[l+1][c+1] = '~';
				if ((l+1) < t.lin) t.m[l+1][c] = '~';
				if ((c+1) >= 0) t.m[l][c+1] = '~';
				if (((l-1) >= 0) && ((c+1) <t.col)) t.m[l-1][c+1] = '~';
				if (((l+1) < t.lin) && ((c-1) >= 0)) t.m[l+1][c-1] = '~';
			break;
			case '#':
				if (((l-1) >= 0) && ((c-1) >= 0)) t.m[l-1][c-1] = '~';
				if (((l+1) < t.lin) && ((c+1) < t.col)) t.m[l+1][c+1] = '~';
				if (((l-1) >= 0) && ((c+1) <t.col)) t.m[l-1][c+1] = '~';
				if (((l+1) < t.lin) && ((c-1) >= 0)) t.m[l+1][c-1] = '~';
			break;
	}
	return t;
}


/*A função strat2 representa uma das estratégias para resolver o puzzle da batalha naval. Esta função consiste em 
colocar água nas linhas/colunas em que os segmentos de barco já estão todos colocados.
*/

TAB strat2(TAB t)
{
	int l, c, accum, x;
	for(l = 0; l < t.lin; l++)
	{
		accum = 0;
		for(c = 0; c < t.col; c++)
			if ((t.m[l][c] != '.') && (t.m[l][c] != '~')) accum++;
		if (accum == t.somal[l])
		{
			for(x = 0; x < t.col; x++)
				if (t.m[l][x] == '.') t.m[l][x] = '~';
		}
	}
	for(c = 0; c < t.col; c++)
	{
		accum = 0;
		for(l = 0; l < t.lin; l++)
			if ((t.m[l][c] != '.') && (t.m[l][c] != '~')) accum++;
		if (accum == t.somac[c])
		{
			for(x = 0; x < t.lin; x++)
				if (t.m[x][c] == '.') t.m[x][c] = '~';	
		}
	}
	return t;
}


int barcosL(TAB t, int c)
{	
	int x, acc = 0;
	for(x = 0; x < t.lin; x++)
		if ((t.m[x][c] != '~') && (t.m[x][c] != '.')) acc++;
	return acc;
}

int barcosC(TAB t, int l)
{
	int x, acc = 0;
	for(x = 0; x < t.col; x++)
		if ((t.m[l][x] != '~') && (t.m[l][x] != '.')) acc++;
	return acc;
}

int verifica(TAB t, int l, int c)
{
	if (t.m[l][c] != '~') return 0;
		else return 1; 
}

int posicao(TAB t)
{
	int l, c;
	for(l = 0; l < t.lin;  l++)
	  for(c = 0; c < t.col; c++)
		switch (t.m[l][c])
		{
			case '<':
				if (((l-1) >= 0) && ((c-1) >= 0)) if (verifica(t, l-1, c-1) == 0) return 0;
				if ((l-1) >= 0) if (verifica(t, l-1, c) == 0) return 0;
				if ((c-1) >= 0) if (verifica(t, l, c-1) == 0) return 0;
				if (((l+1) < t.lin) && ((c+1) < t.col)) if (verifica(t, l+1, c+1) == 0) return 0;
				if ((l+1) < t.lin) if (verifica(t, l+1, c) == 0) return 0;
				if (((l-1) >= 0) && ((c+1) < t.col)) if (verifica(t, l-1, c+1) == 0) return 0;
				if (((l+1) < t.lin) && ((c-1) >= 0)) if (verifica(t, l+1, c-1) == 0) return 0;
			break;
			case '>':
				if (((l-1) >= 0) && ((c-1) >= 0)) if (verifica(t, l-1, c-1) == 0) return 0;
				if ((l-1) >= 0) if (verifica(t, l-1, c) == 0) return 0;
				if (((l+1) < t.lin) && ((c+1) < t.col)) if (verifica(t, l+1, c+1) == 0) return 0;
				if ((l+1) < t.lin) if (verifica(t, l+1, c) == 0) return 0;
				if (((c+1) < t.col)) if (verifica(t, l, c+1) == 0) return 0;
				if (((l-1) >= 0) && ((c+1) < t.col)) if (verifica(t, l-1, c+1) == 0) return 0;
				if (((l+1) < t.lin) && ((c-1) >= 0)) if (verifica(t, l+1, c-1) == 0) return 0;
			break;
			case 'v':
				if (((l-1) >= 0) && ((c-1) >= 0)) if (verifica(t, l-1, c-1) == 0) return 0;
				if ((c-1) >= 0) if (verifica(t, l, c-1) == 0) return 0;
				if (((l+1) < t.lin) && ((c+1) < t.col)) if (verifica(t, l+1, c+1) == 0) return 0;
				if ((l+1) < t.lin) if (verifica(t, l+1, c) == 0) return 0;
				if (((c+1) < t.col)) if (verifica(t, l, c+1) == 0) return 0;
				if (((l-1) >= 0) && ((c+1) < t.col)) if (verifica(t, l-1, c+1) == 0) return 0;
				if (((l+1) < t.lin) && ((c-1) >= 0)) if (verifica(t, l+1, c-1) == 0) return 0;
			break;
			case '^':
				if (((l-1) >= 0) && ((c-1) >= 0)) if (verifica(t, l-1, c-1) == 0) return 0;
				if ((l-1) >= 0) if (verifica(t, l-1, c) == 0) return 0;
				if ((c-1) >= 0) if (verifica(t, l, c-1) == 0) return 0;
				if (((l+1) < t.lin) && ((c+1) < t.col)) if (verifica(t, l+1, c+1) == 0) return 0;
				if (((c+1) < t.col)) if (verifica(t, l, c+1) == 0) return 0;
				if (((l-1) >= 0) && ((c+1) < t.col)) if (verifica(t, l-1, c+1) == 0) return 0;
				if (((l+1) < t.lin) && ((c-1) >= 0)) if (verifica(t, l+1, c-1) == 0) return 0;
			break;
			case '0':
				if (((l-1) >= 0) && ((c-1) >= 0)) if (verifica(t, l-1, c-1) == 0) return 0;
				if ((l-1) >= 0) if (verifica(t, l-1, c) == 0) return 0;
				if ((c-1) >= 0) if (verifica(t, l, c-1) == 0) return 0;
				if (((l+1) < t.lin) && ((c+1) < t.col)) if (verifica(t, l+1, c+1) == 0) return 0;
				if ((l+1) < t.lin) if (verifica(t, l+1, c) == 0) return 0;
				if (((c+1) < t.col)) if (verifica(t, l, c+1) == 0) return 0;
				if (((l-1) >= 0) && ((c+1) <t.col)) if (verifica(t, l-1, c+1) == 0) return 0;
				if (((l+1) < t.lin) && ((c-1) >= 0)) if (verifica(t, l+1, c-1) == 0) return 0;
			break;
		}
	return 1;
}


int somas(TAB t)
{
	int l, c, r = 1;
	for(l = 0; l < t.lin; l++)
			if 	(barcosC(t, l) != t.somal[l]) return 0;
	for(c = 0; c < t.col; c++)
			if (barcosL(t, c) != t.somac[c]) return 0;
	return 1;
} 


void validacao(TAB t)
{
	if ((posicao(t) == 1) && (somas(t) == 1))  printf("%s\n", "SIM");
		else printf("%s\n", "NAO");
}



/* A função main lê o que foi escrito pelo utilizador e decide qual o comando que irá ser utilizado (escolhendo a 
função correta). Deste modo, o tabuleiro irá ser atualizado de cada vez que uma função modificadora altere o estado do tabuleiro.
*/

int main(){
	int l, c;
	char car[MAXL], com[MAXL];
	TAB tabuleiro;
	FILE *fp, *fp2;
	fp = stdin;
	fp2 = stdout;
	printf("Insira o comando: \n");
	if (fgets(com, MAXL, fp) != NULL)
		sscanf(com, "%s %d %d", car, &l, &c);
	while ( car[0] != 'q')
	{
		switch (car[0])
		{
			case 'm':
				mostrar(fp2, tabuleiro); 
			break;
		    case 'c':
		    	tabuleiro = interp(fp, tabuleiro);
		    break;
		    case 'h': 
		     	tabuleiro = estadoL(tabuleiro, l);
		    break;    
		    case 'v':
		     	tabuleiro = estadoC(tabuleiro, l);
		    break;    
		    case 'p':
		     	tabuleiro = coloca(tabuleiro, car[1], l, c);
		    break;
		    case 'l' :
		    	fp = fopen("tab.txt","r");
		    	tabuleiro = interp(fp, tabuleiro);
		    break;
		    case 'e':
		    	fp2 = fopen("tab.txt","w");
		    break;
		    case 'E':
		    	if (car[1] == '1') tabuleiro = strat1(tabuleiro);
		    		else if (car[1] == '2') tabuleiro = strat2(tabuleiro);
		    break;
		    case 'V':
		    	validacao(tabuleiro);
		    break;
		}
		printf("Insira o comando: \n");
		if (fgets(com, MAXL, fp) != NULL)	
			sscanf(com, "%s %d %d", car, &l, &c);
	}
	if (car[0] == 'q') exit(0);
	return 0;
}




