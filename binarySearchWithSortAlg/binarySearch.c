#include <stdio.h>
#include<stdlib.h>


static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1); // Smaller element index
    int j;
    for (j = low; j < high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap the pivot element to its correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


static void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

static int binsrch(int a[], int x, int low, int high)
{
    int mid;

    if (low > high)
        return (-1);
    mid = (low + high) / 2;
    if (x == a[mid])
        return (mid);
    if (x < a[mid])
        return (binsrch(a, x, low, mid - 1));
    else
        return (binsrch(a, x, mid + 1, high));
}




static void menu() {
    printf("\n");
    printf("***********************************************************\n");
    printf("*           Girilen sayilari arayan program.              *\n");
    printf("*    Lutfen bir set(25 adet) sayi girisi yap veya cik.    *\n");
    printf("***********************************************************\n");
    printf("*                  1.Yeni sayi girisi                     *\n");
    printf("*                  2.Cikis                                *\n");
    printf("***********************************************************\n");
    printf("Secimin nedir:\n");
}

int main() {

    int secim=1,i=0,x=0;
    int sayilar[5] = { 0 }, arr[5] = {0};

    do {
        menu();
        scanf_s("%d", &secim);
        if (secim == 1) {

            printf("Sayilari giriniz. Ayni sayi 2 kere girilmemelidir.\n\n");
            for (i = 0; i < 5; i++) {
                printf("\t\t%d. sayiyi giriniz.\n",i+1);
                scanf_s("%d", &sayilar[i]);
                arr[i] = sayilar[i];
            }
            
            
            int n = sizeof(arr) / sizeof(arr[0]);

            printf("Original array: ");
            
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");

            // Perform recursive QuickSort
            quickSort(arr, 0, n - 1);
            for (i = 0; i < 5; i++) {
                if (arr[i] == sayilar[i]) {
                    printf("Siralamaniz dogru ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                else {
                    printf("Siralamaniz yanlis ");
                    printf("Sorted array: ");

                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }

            }
            printf("Sayiyi giriniz.\n\n");
            scanf_s("%d", &x);
            i = binsrch(arr, x, 0, n - 1); // ilk n elemanda arama yapacak.

            if (i != -1) {
                printf("Girdiginiz sayi %d. indekste bulundu.\n", i);
            }
            else {
                printf("Girdiginiz sayi dizide bulunamadi.\n");
            }







        }
        else if (secim == 2) {
            printf("Cikis yapiliyor...\n");
            break;
        }
        else {
            printf("Gecersiz secim. Lutfen tekrar deneyin.\n");

        }
    } while (secim == 1);
    return 0;
}