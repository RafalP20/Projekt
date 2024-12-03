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
void edytujPlik(const char *nazwa_pliku) {
    FILE *plik;
    char tryb;
    char tekst[256];

    printf("Czy chcesz:\n");
    printf("1. Nadpisac plik (wpisz 'w')\n");
    printf("2. Dodac do pliku (wpisz 'a')\n");
    printf("Twoj wybor: ");
    scanf(" %c", &tryb);

    // Otwieranie pliku w wybranym trybie
    if (tryb == 'w') {
        plik = fopen(nazwa_pliku, "w");
    } else if (tryb == 'a') {
        plik = fopen(nazwa_pliku, "a");
    } else {
        printf("Nieprawidłowy wybór.\n");
        return;
    }

    if (plik == NULL) {
        perror("Nie można otworzyc pliku");
        return;
    }

    printf("Wprowadz tekst do zapisania (maks. 256 znakow):\n");
    getchar(); // Czyszczenie bufora wejściowego
    fgets(tekst, sizeof(tekst), stdin);

    // Zapis do pliku
    fprintf(plik, "%s", tekst);

    printf("Dane zostaly zapisane do pliku.\n");

    fclose(plik);
}
long long silnia(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * silnia(n - 1);
    }
}
const char *RED = "\033[1;31m";  // Czerwony
    const char *WHITE = "\033[1;37m"; // Biały
int main() {
    char name[MAX_NAME];
    char dane[MAX_DANE];
    int wybor;

    do {
        menu:
        printf("\n Menu:\n");
        printf("1. Kalkulator\n");
        printf("2. Zapisz dane do pliku\n");
        printf("3. Odczytaj dane z pliku\n");
        printf("4. Edycja pliku\n");
        printf("5. Usun plik\n");
        printf("6. Wyswietl liste plikow\n");
        printf("7. Dane tworcow\n");
        printf("8. Niespodzianka\n");
        printf("9. Wyjscie\n");
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
    printf("5. Silnia\n");
    printf("6. Wyjscie\n");
    printf("Wybierz opcje: ");
        }

{
    int opcja;
    int n;
    double liczba1, liczba2, wynik;

    while (1) {
        
        scanf("%d", &opcja);

        if (opcja == 6) {
            printf("Zamykanie kalkulatora. Do widzenia!\n");
            goto menu;
        }
    
        if (opcja == 5)
           {
             {
            printf("Podaj liczbe: ");
            scanf("%d", &n);
        if (n < 0) {
            printf("Silnia nie jest zdefiniowana dla liczb ujemnych.\n");
    } else {
            printf("Silnia z %d wynosi %lld\n", n, silnia(n));
    } 
            }
            return 0;}
           
            if (opcja < 1 || opcja > 4) {
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
                if (wynik == 5){
                printf("5 Dziekujemy za ta ocene");
                }else {
                 printf("Wynik dodawania: %.2f\n", wynik);
                }
                break;
                
            case 2:
                wynik = liczba1 - liczba2;
                 if (wynik == 5){
                printf("5 Dziekujemy za ta ocene");
                }else {
                printf("Wynik odejmowania: %.2f\n", wynik);
                }
                break;
                
            case 3:
                wynik = liczba1 * liczba2;
                 if (wynik == 5){
                printf("5 Dziekujemy za ta ocene");
                }else {
                printf("Wynik mnozenia: %.2f\n", wynik);
                }
                break;
               
            case 4:
                if (liczba2 != 0) {
                    wynik = liczba1 / liczba2;
                     if (wynik == 5){
                printf("5 Dziekujemy za ta ocene");
                }else {
                    printf("Wynik dzielenia: %.2f\n", wynik);
                    }
                } else {
                    printf("Błąd: Dzielenie przez zero!\n");
                }
                break;

           
            
   
            default:
                printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
        }
    }
}
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
            {
            char nazwa_pliku[256];
                printf("Podaj nazwe pliku do edycji: ");
                scanf("%s", nazwa_pliku);
                edytujPlik(nazwa_pliku);
            }
                break;
            case 5:
                printf("Podaj nazwe pliku do usuniecia: ");
                scanf("%s", name);
                usun(name);
                break;
            case 6:
                wyswietlanie();
                break;
            case 7:
                printf("Projekt zrobiony przez Rafala Plute i Jakuba Piskorza 2024. Dziekujemy za skorzystanie z naszych uslug\n");
                break;
            case 8:
    printf("Wesolych swiat\n\n");
    printf("%s       *    \n",RED);
    printf("      ***    \n");
    printf("     *****    \n");
    printf("    *******   \n");
    printf("   *********  \n");
    printf("%s     *****     \n",WHITE);
    printf("   *       *   \n");
    printf("  *   o o   *  \n");
    printf("  *    ^    *  \n");
    printf("  *   '-'   *  \n");
    printf("   *       *   \n");
    printf("     *****     \n");
    printf("    *******    \n");
    printf("   *       *   \n");
    printf("  *         *  \n");
    printf("  *         *  \n");
    printf("   *       *   \n");
    printf("    *******    \n");
    printf("   *********   \n");
    printf("  *          * \n");
    printf(" *            *\n");
    printf("  *          * \n");
    printf("   *********   \n");
    return 0;
            case 9:
                printf("Wyjscie z programu.\n");
                exit(0);
            default:
                printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
        }
    } while (wybor != 10);
/* wybor opcji */
    return 0;
}