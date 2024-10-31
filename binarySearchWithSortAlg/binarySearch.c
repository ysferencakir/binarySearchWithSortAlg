#include <stdio.h>







void menu() {
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

    int secim,i;
    double sayilar[25];
    do {
        menu();
        scanf_s("%d", &secim);
        if (secim == 1) {

            printf("Sayilari giriniz. Ayni sayi 2 kere girilmemelidir.\n\n");
            for (i = 0; i < 25; i++) {
                printf("\t\t%d. sayiyi giriniz.\n",i+1);
                scanf_s("%lf", &sayilar[i]);
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