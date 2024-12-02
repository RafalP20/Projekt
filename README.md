#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_DANE 60
#define MAX_NAME 20


void zapis(const char *name, const char *dane) {
    FILE *plik = fopen(name, "w");
    if (plik == NULL) {
        perror("Blad");
        return;
    }
    fprintf(plik, "%s", dane);
    fclose(plik);
    printf("Dane zostaly zapisane w %s.\n", name);
}

/* zapisywanie danych */

char* odczyt(const char *name) {
    FILE *plik = fopen(name, "r");
    if (plik == NULL) {
        perror("Blad");
        return NULL;
    }

    char *dane = (char *)malloc(MAX_DANE);
    if (dane == NULL) {
        perror("Blad");
        fclose(plik);
        return NULL;
    }

    size_t n = fread(dane, 1, MAX_DANE - 1, plik);
    dane[n] = '\0'; 

    fclose(plik);
    return dane;
}
/* odczytywanie danych */
void usun(const char *name) {
    if (remove(name) == 0) {
        printf("Plik %s usunieto .\n", name);
    } else {
        perror("Blad");
    }
}
/* usuwanie plików */
void wyswietlanie() {
    DIR *katalog;
    struct dirent *pozycja;
    int licznik = 1;

    katalog = opendir(".");
    if (katalog == NULL) {
        perror("Blad");
        return;
    }

    printf("Lista zapisanych plikow:\n\n");
    while ((pozycja = readdir(katalog)) != NULL) {
        printf("%d.   %s\n",licznik, pozycja->d_name);
        licznik++;
    }

    closedir(katalog);
}
/* wyswietlanie plików */
int main() {
    char name[MAX_NAME];
    char dane[MAX_DANE];
    int wybor;

    do {
        printf("\n Menu:\n");
        printf("1. Kalkulator\n");
        printf("2. Zapisz dane do pliku\n");
        printf("3. Odczytaj dane z pliku\n");
        printf("4. Usun plik\n");
        printf("5. Wyswietl liste plikow\n");
        printf("6. Dane tworcow\n");
        printf("7. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);
/* opcje wyboru */

 switch (wybor) {
            case 1:{
            printf("\nKalkulator:\n");
    printf("1. Dodawanie\n");
    printf("2. Odejmowanie\n");
    printf("3. Mnozenie\n");
    printf("4. Dzielenie\n");
    printf("5. Wyjscie\n");
    printf("Wybierz opcje: ");
        }

{
    int opcja;
    double liczba1, liczba2, wynik;

    while (1) {
        
        scanf("%d", &opcja);

        if (opcja == 5) {
            printf("Zamykanie kalkulatora. Do widzenia!\n");
            break;
        }

        if (opcja < 1 || opcja > 5) {
            printf("Nieprawidlowy wybor, sprobuj ponownie.\n");
            continue;
        }

        printf("Podaj pierwsza liczbe: ");
        scanf("%lf", &liczba1);
        printf("Podaj druga liczbe: ");
        scanf("%lf", &liczba2);

        switch (opcja) {
            case 1:
                wynik = liczba1 + liczba2;
                printf("Wynik dodawania: %.2f\n", wynik);
                break;
            case 2:
                wynik = liczba1 - liczba2;
                printf("Wynik odejmowania: %.2f\n", wynik);
                break;
            case 3:
                wynik = liczba1 * liczba2;
                printf("Wynik mnozenia: %.2f\n", wynik);
                break;
            case 4:
                if (liczba2 != 0) {
                    wynik = liczba1 / liczba2;
                    printf("Wynik dzielenia: %.2f\n", wynik);
                } else {
                    printf("Błąd: Dzielenie przez zero!\n");
                }
                break;
            default:
                printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
        }
    }
}


        break;
            case 2:
                printf("Podaj nazwe pliku: ");
                scanf("%s", name);
                printf("Podaj dane do zapisania: ");
                getchar();
                fgets(dane, MAX_DANE, stdin);
                size_t len = strlen(dane);
                if (len > 0 && dane[len - 1] == '\n') {
                    dane[len - 1] = '\0';
                }
                zapis(name, dane);
                break;
            case 3:
                printf("Podaj nazwe pliku: ");
                scanf("%s", name);
                {
                    char *odczytane_dane = odczyt(name);
                    if (odczyt != NULL) {
                        printf("Odczytane dane: %s\n", odczytane_dane);
                        free(odczytane_dane);
                    }
                }
                break;
            case 4:
                printf("Podaj nazwe pliku do usuniecia: ");
                scanf("%s", name);
                usun(name);
                break;
            case 5:
                wyswietlanie();
                break;
            case 6:
                printf("Projekt zrobiony przez Rafala Plute i Jakuba Piskorza 2024. Dziekujemy za skorzystanie z naszych uslug\n");
                break;
            case 7:
                printf("Wyjscie z programu.\n");
                break;
            default:
                printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
        }
    } while (wybor != 7);
/* wybor opcji */
    return 0;
}
