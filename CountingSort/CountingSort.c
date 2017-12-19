#include<stdio.h>

void counting(int tab[], int rozmiar, int zakres){

	//zliczanie elementów
	int zlicz[zakres+1];

	//zerowanie tablicy pomocniczej
	for(int i=0; i<=zakres; i++){
		zlicz[i]=0;
	}
	
	//zliczanie elementów
	for(int i=0; i<rozmiar; i++){
		zlicz[tab[i]]++;
	}
	
	//dodanie zliczonych elementów
	for(int i=1; i<=zakres; i++){
		zlicz[i]=zlicz[i]+zlicz[i-1];
	}

	//wypisywanie tablicy zlicz
	printf("Tablica pomocnicza:\n");
	for(int i=0; i<=zakres; i++){
		printf("%d, ", zlicz[i]);
	}
	printf("\n");

	//ostateczne sortowanie
	int wynik[rozmiar];
	for(int i=rozmiar-1;i>=0;i--){
		zlicz[tab[i]]--;
		wynik[zlicz[tab[i]]]=tab[i];
	}
	
	//wypisanie po sortowaniu
	printf("Tablica po sortowaniu:\n");
	for (int i=0; i<rozmiar;i++){
		printf("%d, ", wynik[i]);
	}

	printf("\n");

}


int main(){
	int A[] = {5,1,4,5,0,1,1,3,4,1};
	int rozmiar = 10;
	int i=0;

	printf("Tablica\n");
	for (i=0; i<rozmiar;i++){
		printf("%d, ", A[i]);
	}

	printf("\n");

	counting(A, rozmiar, 8);

	return 0;
}