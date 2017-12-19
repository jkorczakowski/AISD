// Juliusz Korczakowski, heapsort implementation in C
/* Manual:
 * compile with -lm flag and run with first argument as an input file and second argument as an output file
 * for example: "gcc -o heap HeapSort1.c -lm" then "./heap input.txt output.txt" 
 * arrays are indexed from 0 (changes in pseudocode from lectures)
 * warning: there is one global variable but it seems to be the best solution with this kind of code
 */
#include<stdio.h>
#include<math.h>

int heapSize;

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Heapify(int A[], int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;

	if(l <= heapSize && A[l]>A[i])
		largest = l;
	else
		largest = i;
	
	if(r <= heapSize && A[r]>A[largest])
		largest = r;
	
	if(largest != i)
	{
		swap(&A[i],&A[largest]);
		Heapify(A, largest);
	}
}

void BuildHeap(int A[])
{
	heapSize=heapSize-1;
	int i;
	for (i=floor(heapSize/2); i>=0; i--)
		Heapify(A,i);
}

void HeapSort(int A[])
{
	BuildHeap(A);
	int i;
	for (i=heapSize; i>0; i--)
	{
		swap(&A[heapSize],&A[0]);
			heapSize--;
			Heapify(A,0);
	}
}

// Function is checking numbers of lines in file

int linie(char *plik)
{
	int LNG = 0;
	int c;
	FILE *baza = fopen(plik,"r");
	while(fscanf(baza,"%d",&c)!=EOF)
	{
		LNG++;
	}

	fclose(baza);
	return LNG;
}

// Function is reading numbers from file

void wczytywanie (char *plik, int A[], int LNG)
{
	int i = 0;
	FILE *baza = fopen(plik,"r");
	while(i<LNG)
	{	
	fscanf(baza,"%d",&A[i]);
	i++;
	}
	fclose(baza);
}

// Function is writing down numbers to file

void wypisywanie(char *plik, int A[], int LNG)
{

	FILE *baza = fopen(plik,"w");
	for (int j=0; j<LNG; j++)
	fprintf(baza,"%d\n",A[j]);
	fclose(baza);

}


int main(int arg_num, char** arg)
{
	int LNG=linie(arg[1]);
	int A[LNG];
	wczytywanie(arg[1],A,LNG);
	heapSize = LNG;

//	printf("%d\n",LNG); // checking array length;
//	for (int i = 0; i<LNG; i++) // loop for checking reading from file (unsorted numbers)
//		printf("%d\n",A[i]);
//	printf("\n");


	HeapSort(A);


//	for (int i = 0; i<LNG; i++) //loop for checking heapsort algorithm (sorted numbers)
//	printf("%d\n",A[i]);

		
	wypisywanie(arg[2],A,LNG); 
	return 0;
}
