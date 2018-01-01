#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 struct hash_data  {
	int amount;
	unsigned char *surname;
};


int line_count(char *filename);
int hash_func(unsigned long k, int m);
unsigned long to_int(unsigned char* str);


int main(int argc, char **argv)
{

if(argc!=2)
{
	printf("Wrong number of argument!\n");
		exit(1);
}

FILE *input = fopen(argv[1],"r");

if(input == NULL)
{
	printf("Wrong file!\n");
		exit(1);
}




int i;
int counter = line_count(argv[1]);
printf("%d\n",counter);
unsigned int key[counter];
unsigned long result;
char buffer[1024];

struct hash_data data[counter];

for(i=0;i<counter;i++)
{
fscanf(input,"%d",&data[i].amount);
fscanf(input,"%s",buffer);
data[i].surname = (unsigned char*)strdup(buffer);
result = to_int(data[i].surname);
key[i] = result;
result = 0;
printf("[%d] INT: %d  SUR: %s KEY: %u\n",i,data[i].amount,data[i].surname,key[i]);
free(data[i].surname);




}
fclose(input);






return 0;
}


int line_count(char *filename)
{
	FILE *input = fopen(filename,"r");
	
  	char c;
	int counter = 0;
	while((c=getc(input))!=EOF)
	{
		if(c == '\n')
		{
			counter++;
		}
	}
	fclose(input);
	return counter;
}


int hash_func(unsigned long k, int m)
{
	return k%m;
}

unsigned long  to_int(unsigned char *str)
{
	unsigned long num = 5381;
	int c;
	while((c = *str++))
		num = ((num << 5) + num) + c; /* num * 33 +c */
	return num;
}





