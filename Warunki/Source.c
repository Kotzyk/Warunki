#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define _WYDZIALY_ 18
#define MAX_KIERUNKI 7
#define MAX_PRZEDMIOTY 22
#define _SEMESTRY_ 7

const char* getfield(char* line, int num)
//metoda pobieraj�ca tre�� pola w CSV o wskazanym numerze  
{
	const char* tok;
	for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n"))
	{
		if (!--num)
			return tok;
	}
}

void read_csv(FILE* file) {
//metoda wypisuj�ca zawarto�� pierwszego i drugiego pola z skazanego pliku csv
	char line[512];
	while (fgets(line, 512, file))
	{
		char* tmp = strdup(line);
		printf("%s : %s \n", getfield(tmp, 1), getfield(tmp, 2));
		free(tmp);
		
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
	char wybor;
	char wydzial[_WYDZIALY_]; //(indeks+1) to IdWydzia�u, przechowywane maj� by� Nazwy
	char przedmiot[_WYDZIALY_][MAX_KIERUNKI][_SEMESTRY_][MAX_PRZEDMIOTY]; 
	/*Nie mam pomys�u jak inaczej, ale mo�e takimi tablicami warto. 
	Og�em chodzi �eby to co zczytywane jest z ka�dej csv, np z wydzia�y, by�o zapisywane,
	�eby si� potem da�o robi� co� pokroju wielopoziomowego wybierania:
		if(strtoi(wybor) < _WYDZIALY_)
			>>tu wstawi� dalsze dzia�ania, kt�re b�d� wy�wietla� dalsze poziomy w oparciu o podane IdWydzia�u<<
	*/

	
	FILE* wydzialy = fopen("wydzialy.csv", "r");
	FILE* przedmioty = fopen("Przedmioty.csv", "r");

	printf("\t \t=================WARUNKOLICZNIK====================\n");
	printf("Witamy w naszym kalkulatorze do wyskosci warunkow za przedmioty nauczane na AGH,\
 zgodnie ze stawkami i programem studiow dla studentow zaczynajacych studia w 2015r.\n");
	printf("Przedmioty dotyczace j. obcych lub WF zostaly przeniesione odpowiednio pod nr 17 i 18. \n");
	printf("\t \t Wybierz wydzial z listy: \n");

	read_csv(wydzialy);
	printf("Nr: ");
	scanf("%c", &wybor);

	system("pause");
	return 0;
}