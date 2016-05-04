#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define WYDZIALOW 18
#define KOLUMN 7


const char* getfield(char* line, int num)
//metoda pobieraj¹ca treœæ pola w CSV o wskazanym numerze  
{
	const char* tok;
	for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n"))
	{
		if (!--num)
			return tok;
	}
}

void read_csv(FILE* file) {
//metoda wypisuj¹ca zawartoœæ pierwszego i drugiego pola z skazanego pliku csv
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
	char wybor, line[512];
	 //(indeks+1) to IdWydzia³u, przechowywane maj¹ byæ Nazwy
	char przedmiot[3000][KOLUMN], wydzial[WYDZIALOW];
	
	/*Nie mam pomys³u jak inaczej, ale mo¿e takimi tablicami warto. 
	Ogó³em chodzi ¿eby to co zczytywane jest z ka¿dej csv, np z wydzia³y, by³o zapisywane,
	¿eby siê potem da³o robiæ coœ pokroju wielopoziomowego wybierania:
		if(strtoi(wybor) < _WYDZIALY_)
			>>tu wstawiæ dalsze dzia³ania, które bêd¹ wyœwietlaæ dalsze poziomy w oparciu o podane IdWydzia³u<<
	*/
	int lines = 0;
	FILE* wydzialy = fopen("wydzialy.csv", "r");
	
	FILE* przedmioty = fopen("Przedmioty.csv", "r");

	printf("\t \t=================WARUNKOLICZNIK====================\n");
	printf("Witamy w naszym kalkulatorze do wyskosci warunkow za przedmioty nauczane na AGH,\
 zgodnie ze stawkami i programem studiow dla studentow zaczynajacych studia w 2015r.\n");
	printf("Przedmioty dotyczace j. obcych lub WF zostaly przeniesione odpowiednio pod nr 17 i 18. \n");
	printf("\t \t Wybierz wydzial z listy: \n");

	while (fgets(line, 512, wydzialy))
	{
		char* tmp = strdup(line);
		const char* field1 = getfield(tmp, 1);
		free(tmp);
		tmp = strdup(line);
		const char* field2 = getfield(tmp, 2);
		printf("%s: %s \n", field1, field2 );
		tmp = strdup(line);
		field2 = getfield(tmp, 2);
		wydzial[lines] = field2;
		lines++;
		
	}
	
	//read_csv(wydzialy);

	//printf("Nr: ");
	//scanf("%c", &wybor);

	system("pause");
	return 0;
}