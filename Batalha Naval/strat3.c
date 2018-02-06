int barcosL(TAB t, int c)
{	
	int acc = 0;
	for(int x = 0; x < t.lin; x++)
		if ((t.m[x][c] != '~') && (t.m[x][c] != '.')) acc++;
	return acc;
}

int barcosC(TAB t, int l)
{
	int acc = 0;
	for(int x = 0; x < t.col; x++)
		if ((t.m[l][x] != '~') && (t.m[l][x] != '.')) acc++;
	return acc;
}


int auxi(TAB t, int l, int c)
{
	if (t.m[l][c] == '<') if ((t.m[l+1][c] != '~') && (t.m[l+1][c+1] != '~')) return 0;
		else if (t.m[l][c] == '^') if ((t.m[l][c+1] != '~') && (t.m[l+1][c+1] != '~')) return 0;
			else if (t.m[l][c] == 'O') if ((t.m[l][c+1] != '~') && ((t.m[l+1][c] != '~')) && (t.m[l+1][c+1] != '~')) return 0;
	return 1;
}


int posicao(TAB t)
{
	int l, c;
	for(l = 0; l < t.lin; l++)
		for(c = 0; c < t.col; c++)
			if ((l == 0) && (c == 0)) if (auxi(t, l, c) == 0) return 0;
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


void validacao(Tab t)
{
	if ((posicao(t) == 1) && (somas(t) == 1)  printf("%s\n", "SIM");
		else printf("%s\n", "NAO");
}






TAB strat3(TAB t)
{
	int l, c, acc = 0;





	for(l = 0; l < t.lin; l++)
		for(c = 0; c < t.col; c++)
			estadoC(t,c);
	return t;
}