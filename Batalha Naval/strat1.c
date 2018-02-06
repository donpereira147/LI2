
TAB strat1 (TAB t){
	int l, c;
	for(l = 0; l <= t.lin; l++)
	{
		for(c = 0; c < t.lin; c++)
		{
			if ((l == 0) && (c == 0)) aux1(t,l,c);
				else if ((l == 0) && ((c < t.col) && (c > t.col))) aux2(t,l,c);
					else if ((l == 0) && (c == t.col)) aux3(t,l,c);
						else if (((l < t.lin) && ( l > t.lin)) && (c == 0)) aux4(t,l,c);
							else if (((l < t.lin) && ( l > t.lin)) && (c < t.col) && (c > t.col)) aux5(t,l,c);
								else if (((l < t.lin) && ( l > t.lin)) && (c == t.col)) aux6(t,l,c);
									else if ((l == t.lin) && (c == 0)) aux7(t,l,c);
										else if ((l == t.lin) && ((c < t.col) && (c > t.col))) aux8(t,l,c);
											else aux8(t,l,c);
		}
	}
return t;
}

TAB aux1(TAB t, int l, int c)
{
	if (t.m[l][c] == '<') {t.m[l+1][c] = '~'; t.m[l+1][c+1] ='~';}
		else if (t.m[l][c] == '^') {t.m[l][c+1] ='~'; t.m[l+1][c+1] ='~';} 
			else if (t.m[l][c] == 'O') {t.m[l+1][c] = '~'; t.m[l][c+1] ='~'; t.m[l+1][c+1] ='~';}
	return t;
}

TAB aux2(TAB t, int l, int c)
{
	if (t.m[l][c] == '<')  {t.m[l+1][c] = '~'; t.m[l+1][c+1] ='~'; t.m[l][c-1] = '~'; t.m[l+1][c-1] = '~';}
		else if (t.m[l][c] == '>') {t.m[l+1][c] = '~'; t.m[l+1][c+1] ='~'; t.m[l][c+1] = '~';t.m[l+1][c-1] = '~';}
			else if (t.m[l][c] == '^') {t.m[l+1][c+1] ='~'; t.m[l][c-1] = '~'; t.m[l][c+1] = '~';t.m[l+1][c-1] = '~';}
				else if (t.m[l][c] == '#') {t.m[l+1][c] = '~'; t.m[l+1][c+1] ='~'; t.m[l+1][c-1] = '~';} 
					else if (t.m[l][c] == 'O') {t.m[l+1][c] = '~'; t.m[l+1][c+1] ='~'; t.m[l][c-1] = '~'; t.m[l][c+1] = '~';t.m[l+1][c-1] = '~';}
	return t;
}

TAB aux3(TAB t, int l, int c)
{
	if (t.m[l][c] == '>') {t.m[l][c-1] = '~';t.m[l+1][c-1] = '~';}
		else if (t.m[l][c] == '^') {t.m[l+1][c] = '~';t.m[l+1][c-1] = '~';} 	
			else if (t.m[l][c] == 'O') {t.m[l+1][c] = '~';t.m[l][c-1] = '~';t.m[l+1][c-1] = '~';}
	return t;
}

TAB aux4(TAB t, int l, int c)
{
	if (t.m[l][c] == '<') {t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~'; t.m[l+1][c+1] = '~'; t.m[l+1][c] = '~';}
		else if (t.m[l][c] == '^') {t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~'; t.m[l][c+1] = '~'; t.m[l+1][c+1] = '~';}
			else if (t.m[l][c] == '#') {t.m[l-1][c+1] = '~'; t.m[l][c+1] = '~'; t.m[l+1][c+1] = '~';}
				else if if (t.m[l][c] == 'v') {t.m[l-1][c+1] = '~'; t.m[l][c+1] = '~'; t.m[l+1][c+1] = '~'; t.m[l+1][c] = '~';}
					else if (t.m[l][c] == 'O') {t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~'; t.m[l][c+1] = '~'; t.m[l+1][c+1] = '~'; t.m[l+1][c] = '~';}
	return t;
}

TAB aux5(TAB t, int l, int c)
{
	if (t.m[l][c] == '<') {t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~'; t.m[l+1][c] = '~'; t.m[l+1][c+1] = '~'; t.m[l+1][c-1] = '~'; t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~';}
		else if (t.m[l][c] == '>') {t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~'; t.m[l+1][c] = '~'; t.m[l+1][c+1] = '~'; t.m[l+1][c-1] = '~'; t.m[l-1][c-1] = '~'; t.m[l][c+1] = '~';}
			else if (t.m[l][c] == '^') {t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~'; t.m[l+1][c+1] = '~'; t.m[l+1][c-1] = '~'; t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~'; t.m[l][c+1] = '~';}
				else if (t.m[l][c] == '#') {t.m[l-1][c+1] = '~'; t.m[l+1][c+1] = '~'; t.m[l+1][c-1] = '~'; t.m[l-1][c-1] = '~';} 
					else if if (t.m[l][c] == 'v') {t.m[l-1][c+1] = '~'; t.m[l+1][c] = '~'; t.m[l+1][c+1] = '~'; t.m[l+1][c-1] = '~'; t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~'; t.m[l][c+1] = '~';} 
						else if (t.m[l][c] == 'O') {t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~'; t.m[l+1][c] = '~'; t.m[l+1][c+1] = '~'; t.m[l+1][c-1] = '~'; t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~'; t.m[l][c+1] = '~';}
	return t;
}

TAB aux6(TAB t, int l, int c)
{
	if (t.m[l][c] == '>') {t.m[l-1][c] = '~'; t.m[l+1][c] = '~'; t.m[l+1][c-1] = '~'; t.m[l-1][c-1] = '~';}
		else if (t.m[l][c] == '^') {t.m[l-1][c] = '~'; t.m[l+1][c-1] = '~';t.m[l][c-1] = '~';t.m[l-1][c-1] = '~';}
			else if (t.m[l][c] == '#') {t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~'; t.m[l+1][c-1] = '~';}
				else if if (t.m[l][c] == 'v') {t.m[l+1][c-1] = '~';t.m[l][c-1] = '~';t.m[l-1][c-1] = '~'; t.m[l+1][c] = '~';}				
					else if (t.m[l][c] == 'O') {t.m[l-1][c] = '~'; t.m[l+1][c] = '~';t.m[l+1][c-1] = '~';t.m[l][c-1] = '~';t.m[l-1][c-1] = '~';}
	return t;	
}


TAB aux7(TAB t, int l, int c)
{
	if (t.m[l][c] == '<') {t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~';}
		else if (t.m[l][c] == 'v') {t.m[l][c+1] = '~'; t.m[l-1][c+1] = '~';}
			if (t.m[l][c] == '0') {t.m[l][c+1] = '~'; t.m[l-1][c+1] = '~'; t.m[l-1][c] = '~';}
	return t;
}

TAB aux8(TAB t, int l, int c)
{
	if if (t.m[l][c] == '<') {t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~'; t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~';}	
		else if (t.m[l][c] == '>') {t.m[l-1][c-1] = '~'; t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~'; t.m[l][c+1] = '~';}
			else if (t.m[l][c] == 'v') {t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~'; t.m[l-1][c+1] = '~'; t.m[l][c+1] = '~';}
				else if (t.m[l][c] == '#') {t.m[l-1][c-1] = '~'; t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~';}	
					else if (t.m[l][c] == 'O') {t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~'; t.m[l-1][c] = '~'; t.m[l-1][c+1] = '~'; t.m[l][c+1] = '~';}
	return t;
}

TAB aux9(TAB t, int l, int c)
{
	if (t.m[l][c] == '>') {t.m[l-1][c] = '~'; t.m[l-1][c-1] = '~';}
		else if (t.m[l][c] == 'v') {t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~';}
			if (t.m[l][c] == '0') {t.m[l][c-1] = '~'; t.m[l-1][c-1] = '~'; t.m[l-1][c] = '~';}
	return t;
}