#include<stido.h>
int main()
{
	char screen[500];/*가로:30*세로:15*/

	int i = 0;
	while(i<500)
	{
		
		screen[i]='0';
		i=i+1;
	}
	screen[464]='\0';
	screen[30]='\n';
	screen[61]='\n';
	screen[92]='\n';
	screen[120]='\n';
	screen[154]='\n';
	screen[185]='\n';
	screen[216]='\n';
	screen[247]='\n';
	screen[278]='\n';
	screen[309]='\n';
	screen[340]='\n';		
	screen[371]='\n';
	screen[402]='\n';
	screen[433]='\n';
		
	printf("%s\ndone.",screen);
	

	return 0;
}
