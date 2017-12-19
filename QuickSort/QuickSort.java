//Juliusz Korczakowski AL.3.5
//To correct: data should be imported from file and result should be exported to file
//Wrong intepretation of subpoint 2.
//Better write it in C
//Points: 3/7

import java.time.Duration;
import java.time.Instant;
import java.util.Random;
import java.util.Scanner;


public class QuickSort {



  private static int partition(int A[], int p, int r) {
        int pivot = A[r];
        int i = (p - 1); // index of smaller element
        for (int j = p; j < r; j++) {

            if (A[j] <= pivot) {
                i++;
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }

       int temp = A[i + 1];
        A[i + 1] = A[r];
        A[r] = temp;

        return i + 1;
    }



   private static void sort(int A[], int p, int r) {
        if (p < r) {

            int pi = partition(A, p, r);


            sort(A, p, pi - 1);
            sort(A, pi + 1, r);
        }
    }



       private static void bubbleSort(int[] A) {
           int n = A.length;
           int temp = 0;
           for (int i = 0; i < n; i++) {
               for (int j = 1; j < (n - i); j++) {
                   if (A[j - 1] > A[j]) {
                       //swap elements
                       temp = A[j - 1];
                       A[j - 1] = A[j];
                       A[j] = temp;
                   }

               }
           }
       }

       private static void descOrder(int[] A)
       {
            for (int i=A.length-1, j=0; i>0; i--, j++)
            {
                A[j]=i;
       }
       }

       private static void random(int[] A)
       {
            Random rand = new Random();
            for (int i=0; i<A.length; i++)
                A[i] = rand.nextInt(100000)+1;

       }

       private static void sortVer(int []A)
       {
           Scanner qs = new Scanner(System.in);
           int c = qs.nextInt();

           random(A);
           if(A.length+1<c) {

               bubbleSort(A);
           }
           else {

               partition(A, 0, A.length-1);
               sort(A, 0, A.length-1);
           }
       }

    public static void main(String[] args) {
        //p low r high
        //String[] A = new String[10];
        //System.out.println(A.length);


        int[] A = new int[15000];
        //podpunkt 2

        //sortVer(A);

        //mod2

        random(A);
        Instant brs = Instant.now();
        bubbleSort(A);
        Instant bre = Instant.now();

        Instant qss = Instant.now();
        partition(A, 0, A.length-1);
        sort(A, 0, A.length-1);
        Instant qse = Instant.now();

        descOrder(A);
        Instant brs1 = Instant.now();
        bubbleSort(A);
        Instant bre1 = Instant.now();

        Instant qss1 = Instant.now();
        partition(A, 0, A.length-1);
        sort(A, 0, A.length-1);
        Instant qse1 = Instant.now();

        System.out.println("DANE LOSOWE");
        System.out.println("ROZMIAR TABLICY N \t\t\t\tQUICKSORT\t\tBUBBLESORT");
        System.out.println("\t15000\t\t\t\t\t\t" + Duration.between(qss, qse) + "\t\t" + Duration.between(brs, bre) + "\n\n");
        System.out.println("DANE NIEKORZYSTNE");
        System.out.println("ROZMIAR TABLICY N \t\t\t\tQUICKSORT\t\tBUBBLESORT");
        System.out.println("\t15000\t\t\t\t\t\t" + Duration.between(qss1, qse1) + "\t\t" + Duration.between(brs1, bre1));
    }


    }
