char *headings[40][6];

struct data {
	int obsnum;
	char lastname[50];
	char firstnames[60];
	char city[30];
	int empid;
	int salary;
};

struct data mydata[4];


int main() {

	int i;

	headings[40][0] = "Obs";


	FILE *fp = fopen("data.csv", "r");

	if (fp != NULL)
	{
		fscanf(fp, "%15s, %15s, %8s, %10s, %10s \n",
			headings[40][1], headings[40][2], headings[40][3],
			headings[40][4], headings[40][5]);

		for (i = 0; i<5; i++)
		{
			mydata[i].obsnum = i;
			fscanf(fp, "%49s, %59s, %29s, %d, %d \n",
				mydata[i].firstnames, mydata[i].lastname, mydata[i].city,
				&mydata[i].empid, &mydata[i].salary);
			/* i++; */
		}  /* EOF */

		fclose(fp);

	}  /* File exists */


	   /*  Print the file */

	printf("%s, %s, %s, %s, %s, %s \n", headings[40][0],
		headings[40][1], headings[40][2], headings[40][3],
		headings[40][4], headings[40][5]);

	int j;

	for (j = 0; j<5; j++)
	{
		printf("%d %s %s %s %d %d \n",
			mydata[j].obsnum, mydata[j].firstnames,
			mydata[j].lastname, mydata[j].city,
			mydata[j].empid, mydata[j].salary);
		/* j++; */
	}

	return 0;

}