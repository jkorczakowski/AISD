//Juliusz Korczakowski
//29.12.2017

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define pr1 1543
#define pr2 1609
#define pr3 1621
#define pr4 1567

#define com1 1500
#define com2 1550
#define com3 1525
#define com4 1600

int word_length(char *filename);
float avg(int *tab, int length);
int max(int *tab, int length);
int count_zeros(int *tab, int length);
int line_count(char *filename);
int hash_func(unsigned long k, int m);
unsigned long to_int(unsigned char* str);

int main(int argc, char** argv)
{

if(argc!=2)
{
	printf("Wrong number of arguments or given argument is not a proper file!\n");
	exit(1);
}



unsigned char *word;
char buffer[1024];
int i;
int counter;
unsigned long result;
int index;
int maxPr1;
int maxPr2;
int maxPr3;
int maxPr4;
int maxCom1;
int maxCom2;
int maxCom3;
int maxCom4;
int zerosPr1;
int zerosPr2;
int zerosPr3;
int zerosPr4;
int zerosCom1;
int zerosCom2;
int zerosCom3;
int zerosCom4;
float avgPr1;
float avgPr2;
float avgPr3;
float avgPr4;
float avgCom1;
float avgCom2;
float avgCom3;
float avgCom4;
int tabPr1[pr1];
int tabPr2[pr2];
int tabPr3[pr3];
int tabPr4[pr4];
int tabCom1[com1];
int tabCom2[com2];
int tabCom3[com3];
int tabCom4[com4];

FILE *input = fopen(argv[1],"r");


if(input == NULL)
{
	printf("File does not exists!\n");
		exit(1);
}

counter = line_count(argv[1]);
unsigned long key[counter];

//djb2 algorithm

for (i=0; i<counter; i++)
{
	fscanf(input,"%s",buffer);
	word=strdup(buffer);
	result=to_int(word);
	key[i] = result;
	result = 0;
	free(word);
}

/*
//xor algorithm
for (int i=0; i<counter; i++)
{
	fscanf(input,"%s",word);
	for(int j=0, k=1; k<strlen(word);j+=2,k+=2)
	{
	 	result^=256*(word[j]+word[k]);
	}	
	key[i] = result;
	result = 0;
}
*/
fclose(input);


	//Zeroing primary number size arrays
for(i=0;i<pr1;i++)
	tabPr1[i]=0;

for(i=0;i<pr2;i++)
	tabPr2[i]=0;

for(i=0;i<pr3;i++)
	tabPr3[i]=0;

for(i=0;i<pr4;i++)
	tabPr4[i]=0;

printf("\t\t>PRIME NUMBERS<\n");
printf("M:\t%d\t%d\t%d\t%d \n",pr1,pr2,pr3,pr4);

	//Hashing primary number size arrays
for(i=0;i<counter;i++)
{
	index = hash_func(key[i],pr1);
	tabPr1[index]++;
	index = hash_func(key[i],pr2);
	tabPr2[index]++;
	index = hash_func(key[i],pr3);
	tabPr3[index]++;
	index = hash_func(key[i],pr4);
	tabPr4[index]++;
}
zerosPr1 = count_zeros(tabPr1,pr1);
zerosPr2 = count_zeros(tabPr2,pr2);
zerosPr3 = count_zeros(tabPr3,pr3);
zerosPr4 = count_zeros(tabPr4,pr4);
printf("ZERO:\t%d\t%d\t%d\t%d\n",zerosPr1,zerosPr2,zerosPr3,zerosPr4);

avgPr1 = avg(tabPr1,pr1);
avgPr2 = avg(tabPr2,pr2);
avgPr3 = avg(tabPr3,pr3);
avgPr4 = avg(tabPr4,pr4);
printf("AVG:\t%.2f\t%.2f\t%.2f\t%.2f\n",avgPr1,avgPr2,avgPr3,avgPr4);

maxPr1 = max(tabPr1,pr1);
maxPr2 = max(tabPr2,pr2);
maxPr3 = max(tabPr3,pr3);
maxPr4 = max(tabPr4,pr4);
printf("MAX:\t%d\t%d\t%d\t%d\n",maxPr1,maxPr2,maxPr3,maxPr4);


	//Zeroing compund numbers size arrays
for(i=0;i<com1;i++)
	tabCom1[i]=0;

for(i=0;i<com2;i++)
	tabCom2[i]=0;

for(i=0;i<com3;i++)
	tabCom3[i]=0;

for(i=0;i<com4;i++)
	tabCom4[i]=0;


printf("\t\t>COMPOUND NUMBERS<\n");
printf("M:\t%d\t%d\t%d\t%d \n",com1,com2,com3,com4);

	//Hashing compound number size arrays
for(i=0;i<counter;i++)
{
	index = hash_func(key[i],com1);
	tabCom1[index]++;
	index = hash_func(key[i],com2);
	tabCom2[index]++;
	index = hash_func(key[i],com3);
	tabCom3[index]++;
	index = hash_func(key[i],com4);
	tabCom4[index]++;
}
zerosCom1 = count_zeros(tabCom1,com1);
zerosCom2 = count_zeros(tabCom2,com2);
zerosCom3 = count_zeros(tabCom3,com3);
zerosCom4 = count_zeros(tabCom4,com4);
printf("ZERO:\t%d\t%d\t%d\t%d\n",zerosCom1,zerosCom2,zerosCom3,zerosCom4);

avgCom1 = avg(tabCom1,com1);
avgCom2 = avg(tabCom2,com2);
avgCom3 = avg(tabCom3,com3);
avgCom4 = avg(tabCom4,com4);
printf("AVG:\t%.2f\t%.2f\t%.2f\t%.2f\n",avgCom1,avgCom2,avgCom3,avgCom4);

maxCom1 = max(tabCom1,com1);
maxCom2 = max(tabCom2,com2);
maxCom3 = max(tabCom3,com3);
maxCom4 = max(tabCom4,com4);
printf("MAX:\t%d\t%d\t%d\t%d\n\n\n\n",maxCom1,maxCom2,maxCom3,maxCom4);


printf("Small test array\n");
int tabTest[5] = {0,0,0,0,0};
for(i=0 ;i<counter;i++)
{
	index = hash_func(key[i],5);
	tabTest[index]++;
}

int zeroTest = count_zeros(tabTest,5);
int maxTest = max(tabTest,5);
printf("MAX:%d\n",maxTest);
printf("ZEROS:%d\n",zeroTest);
for(i=0;i<5;i++)
printf("[%d] %d key: %lu\n",i,tabTest[i],key[i]%5);


return 0;
}


float avg(int *tab, int length)
{
	float sum=0;
	float count=0;
	float result;
	for(int i=0; i<length;i++)
	{
		if(tab[i]!=0)
		{
			sum+=tab[i];
			count++;
		}
	}
	result = sum/count;

return result;
}

int max(int *tab, int length)
{
	int max = tab[0];
 
  for (int i = 1; i < length; i++)
  {
    if (tab[i] > max)
    {
       max  = tab[i];
    }
  }
  return max;
}


int count_zeros(int *tab, int length)
{
	int counter = 0;
	for(int i=0;i<length;i++)
		if(tab[i]==0)
			counter++;
	return counter;
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

