#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KOLUMNY_A 7
#define WIERSZE_A 18
#define KIERUNKOW 60
#define MAX_CSV 95
char* przedmioty[MAX_CSV][KOLUMNY_A];
char* wydzialy[WIERSZE_A][2];
char* kierunki[KIERUNKOW][3];

char* getfield(char* line, int num)
{
	char* tok;
	for (tok = strtok(line, ";");
		tok && *tok;
		tok = strtok(NULL, ";\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}

void importPrzedm(char* csv_file, int kolumny)
{
	FILE* stream = fopen(csv_file, "r");
	char line[1024];
	int j = 0;
	while (fgets(line, 1024, stream))
	{

		int i;

		for (i = 0; i < kolumny; i++)
		{
			char* tmp = strdup(line);
			char* xdd = getfield(tmp, i + 1);
			przedmioty[j][i] = malloc(strlen(xdd) + 1);
			strcpy(przedmioty[j][i], xdd);
			free(tmp);
		}

		j = j + 1;
		// NOTE strtok clobbers tmp
	}

}

void importKier(char* csv_file, int kolumny)
{
	FILE* stream = fopen(csv_file, "r");
	char line[1024];
	int j = 0;
	while (fgets(line, 1024, stream))
	{

		int i;

		for (i = 0; i < kolumny; i++)
		{
			char* tmp = strdup(line);
			char* xdd = getfield(tmp, i + 1);
			kierunki[j][i] = malloc(strlen(xdd) + 1);
			strcpy(kierunki[j][i], xdd);
			free(tmp);
		}

		j = j + 1;
		// NOTE strtok clobbers tmp
	}

}

void importWydz(char* csv_file, int kolumny)
{
	FILE* stream = fopen(csv_file, "r");
	char line[1024];
	int j = 0;
	while (fgets(line, 1024, stream))
	{

		int i;

		for (i = 0; i < kolumny; i++)
		{
			char* tmp = strdup(line);
			char* xdd = getfield(tmp, i + 1);
			wydzialy[j][i] = malloc(strlen(xdd) + 1);
			strcpy(wydzialy[j][i], xdd);
			free(tmp);
		}

		j = j + 1;
		// NOTE strtok clobbers tmp
	}

}


int main(int argc, char *argv[])
{
	importWydz("wydzialy.csv", 2);
	importKier("kierunki.csv", 3);
	//importPrzedm("przedmiotytest.csv", KOLUMNY_A);

	printf("\t \t=================WARUNKOLICZNIK====================\n");
	printf("Witamy w naszym kalkulatorze do wyskosci warunkow za przedmioty nauczane na AGH,\
 zgodnie ze stawkami i programem studiow dla studentow zaczynajacych studia w 2015r.\n");
	printf("Przedmioty dotyczace j. obcych lub WF zostaly przeniesione odpowiednio pod nr 17 i 18. \n");
	printf("\t \t Wybierz wydzial z listy: \n");
	int k, l, wyborW;
	char wyborW_char;
	for (k = 0; k < WIERSZE_A; k++)  //for jest tylko do wypisywania tablicy
	{
		for (l = 0; l < 2; l++)
		{
			printf("%s ", wydzialy[k][l]);
		}
		printf("\n");
	}
	//printf("Nr: ");
	//scanf("%c", &wyborW_char);
	//wyborW = (int)wyborW_char;

	//if (wyborW < 19) {
	for (k = 0; k < KIERUNKOW; k++)  //for jest tylko do wypisywania tablicy
	{
		//	if (kierunki[k][0] == wyborW) {
		for (l = 1; l < 3; l++)
		{
			printf("%s ", kierunki[k][l]);
		}
		//	}
		printf("\n");
	}
	//}

	system("Pause");
	return 0;
}