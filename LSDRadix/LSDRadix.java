//Juliusz Korczakowski
//Implementation of LSD Radix Sort on strings and QuickSort on strings
//To correct: String shoud be available by pointers/idexes, create table with strings lenghts
//Points: 4/7


import java.io.*;

public class LSDRadix {


    //QuickSort

    private static int Partition(String arr[], int low, int high)	{
        String pivot = arr[high];
        int i = (low-1); // index of smaller element
        for (int j=low; j<high; j++)	{
            if (arr[j].compareTo(pivot) <= 0)	{
                i++;
                String temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        String temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        return i+1;
    }

    private static void quickSort(String arr[], int low, int high)	{
        if (low < high)	{
            int pi = Partition(arr, low, high);
            // Recursively sort elements before
            // partition and after partition
            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }



    private LSDRadix() {
    }

    // find longest length string in string[] a.
    public static int findLongestLength(String[] a) {
        int longest = 0;
        for (int i = 0; i < a.length; ++i) {
            if (a[i].length() > longest) {
                longest = a[i].length();
            }
        }
        return longest;
    }

    // if d >= 0 && d < a[i].length(), return a[i].charAt(d);
    // else , return 0, which means least value to sort.
    public static int findCharAtInString(int i, int d, String[] a) {
        if (d < 0 || d >= a[i].length()) {
            return 0;
        }
        return a[i].charAt(d);
    }

    // Rearranges the array of variable-length strings.
    public static void sort(String[] a) {
        int n = a.length;
        int R = 256;
        String[] aux = new String[n];
        int w = findLongestLength(a);  // w is the length of longest string in a.
        for (int d = w - 1; d >= 0; d--) {
            // sort by key-indexed counting on dth character

            // compute frequency counts
            int[] count = new int[R + 1];
            for (int i = 0; i < n; ++i) {
                int c = findCharAtInString(i, d, a);
                count[c + 1]++;
            }

            // compute cumulates
            for (int r = 0; r < R; ++r) {
                count[r + 1] += count[r];
            }

            // move data
            for (int i = 0; i < n; ++i) {
                int c = findCharAtInString(i, d, a);
                aux[count[c]++] = a[i];
            }

            // copy back
            for (int i = 0; i < n; ++i) {
                a[i] = aux[i];
            }
        }
    }


    public static void main(String[] args) throws IOException {


        try (BufferedReader br = new BufferedReader(new FileReader("/home/jkorczakowski/AIDS/data.txt"));
             BufferedReader br1 = new BufferedReader(new FileReader("/home/jkorczakowski/AIDS/data.txt"));
             BufferedWriter bw = new BufferedWriter(new FileWriter("/home/jkorczakowski/AIDS/result.txt"))) {
            String line1;


            String[] radix;
            String[] quick;
            int count = 0;
            int i = 0;

            while ((line1 = br1.readLine()) != null) {
                count++;
            }

            System.out.println("Liczba nazwisk: " + count);
            radix = new String[count];
            quick = new String[count];



            while ((line1 = br.readLine()) != null) {
                String[] values = line1.split(" ");
                if (values.length >= 2)
                    quick[i] = (values[1]);
                radix[i] = (values[1]);
                i++;
            }

         /*       for (int k=0; k<5; k++)
                {
                    System.out.println("QUICK: " + quick[k]);
                    System.out.println("RADIX: " + radix[k]);

            }
         */



            long start1 = System.currentTimeMillis();
            sort(radix);
            long end1 = System.currentTimeMillis()-start1;

            long start2 = System.currentTimeMillis();
            quickSort(quick,0,i-1);
            long end2 = System.currentTimeMillis()-start2;

            System.out.println("RADIX: \t\t" + end1 + " ns");
            System.out.println("QUICKSORT:  " + end2 + " ns");

            for (int j = 0; j < count; j++) {
                bw.write(radix[j] + '\n');
            }
        }
    }
}





