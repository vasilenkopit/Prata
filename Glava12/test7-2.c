#include <stdio.h>
/* פאיכ 2 */
extern int dais;
static int lily;
int rose;
int stem()
{
	int rose;
	printf("stem: int rose- &rose=%p, \t&dais=%p, \t&lily=%p\n", &rose,&dais,&lily);
	return 0;
}
void root()
{
	printf("root: \t\t&rose=%p, \t&dais=%p, \t&lily=%p\n", &rose,&dais,&lily);
	//return 0;
}