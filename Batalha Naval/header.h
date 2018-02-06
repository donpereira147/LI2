#define MAXL 1024
#define MAXC 1024

typedef struct tabuleiro 
{
	int lin; /*número total de linhas do tabuleiro*/
	int col; /*número total de colunas do tabuleiro*/
	char m[MAXL][MAXC]; 
	int somal[MAXL]; /*linha que indica a soma de coisas numa linha*/
	int somac[MAXC]; /*linha que indica a soma de coisas numa coluna*/

}TAB;

TAB interp(FILE *fp, TAB t);

void mostrar(FILE *fp2, TAB t);

TAB estadoC(TAB t, int c);

TAB coloca(TAB t, char a, int l, int c);

TAB strat2(TAB t);

TAB estadoL(TAB t, int l);