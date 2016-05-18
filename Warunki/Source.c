#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define WYDZIALOW 18
#define KOLUMN 7

char* tablica[500][KOLUMN];
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


void importCSV(char* csv_file, int kolumny)
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
			tablica[j][i] = malloc(strlen(xdd) + 1);
			strcpy(tablica[j][i], xdd);
			free(tmp);
		}

		j++;
		// NOTE strtok clobbers tmp
	}

}

int is_in_array(char val, char *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] == val)
			return 1;
	}
	return 0;
}

int main()
{
	char wybor, line[512];
	//(indeks+1) to IdWydzia³u, przechowywane maj¹ byæ Nazwy
	char przedmiot[3000][KOLUMN], wydzial[WYDZIALOW][1];

	printf("\t \t=================WARUNKOLICZNIK====================\n");
	printf("Witamy w naszym kalkulatorze do wyskosci warunkow za przedmioty nauczane na AGH,\
 zgodnie ze stawkami i programem studiow dla studentow zaczynajacych studia w 2015r.\n");
	printf("Przedmioty dotyczace j. obcych lub WF zostaly przeniesione odpowiednio pod nr 17 i 18. \n");
	printf("\t \t Wybierz wydzial z listy: \n");

	importCSV("wydzialy.csv", 1);
	int k, l;
	for (k = 0; k<WYDZIALOW; k++)  //for jest tylko do wypisywania tablicy
	{
		for (l = 0; l<1; l++)
		{
			printf("%s ", wydzial[k][l]);
		}
		printf("\n");
	}
	return 0;
}