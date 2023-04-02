#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


#define X 9

struct pole {
    int wartosc;
    int liczba_mozliwosci;
    int mozliwosci[X];
};

bool sprawdz(struct pole tab[X][X], int i, int j, int liczba) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (tab[x + (i - (i % 3))][y + (j - (j % 3))].wartosc == liczba) {
                if (x + (i - (i % 3)) == i && (y + (j - (j % 3)) == j))
                    continue;
                return 1;
            }
        }
    }

    for (int x = 0; x < i; x++) {
        if (tab[i][x].wartosc == liczba) {
            if (x == j) continue;
            return 1;
        }
    }
    for (int y = 0; y < 9; y++) {
        if (tab[y][j].wartosc == liczba) {
            if (y == i) continue;
            return 1;
        }
    }
    return 0;
}

void swap(int t[X], int i, int j) {
    int tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
}

void losowe_9(int tab[X]) {
    int wek[X] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ostatnia = 9, tmp, wylosowana;
    for (int i = 0; i < X; ++i) {
        wylosowana = rand() % ostatnia;
        tab[i] = wek[wylosowana];
        swap(wek, wylosowana, ostatnia - 1);
        ostatnia--;
    }
}

int rozwiaz(struct pole tab[X][X], int i, int j) {
    if (i == X) return 0;
    for (int k = 0; k < tab[i][j].liczba_mozliwosci; ++k) {
        int w = tab[i][j].mozliwosci[k];
        tab[i][j].wartosc = w;

        for (int l = 0; l < X; ++l) {
            for (int m = 0; m < X; ++m) {
                if (l == i && m == j)continue;
                if (l == i || m == j || (l / 3 == i / 3 && m / 3 == j / 3)) {
                    for (int n = 0; n < tab[l][m].liczba_mozliwosci; ++n) {
                        if (tab[l][m].mozliwosci[n] == w) {
                            swap(tab[l][m].mozliwosci, tab[l][m].liczba_mozliwosci - 1, n);
                            tab[l][m].liczba_mozliwosci--;
                        }
                    }
                }
            }
        }


        int rozw = rozwiaz(tab, i + (j == X - 1 ? 1 : 0), (j + 1) % X);
        if (rozw == 0) return 0;
        tab[i][j].wartosc = 0;

        for (int l = 0; l < X; ++l) {
            for (int m = 0; m < X; ++m) {
                if (l == i && m == j)continue;
                if (l == i || m == j || (l / 3 == i / 3 && m / 3 == j / 3)) {
                    if (tab[l][m].liczba_mozliwosci < X && tab[l][m].mozliwosci[tab[l][m].liczba_mozliwosci] == w) {
                        tab[l][m].liczba_mozliwosci++;
                    }
                }
            }
        }
    }
    return 1;
}

void wypelnij(struct pole tab[X][X]) {
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < X; ++j) {
            if (tab[i][j].wartosc != 0) {
                for (int k = 0; k < X; ++k) {
                    tab[i][j].mozliwosci[k] = tab[i][j].wartosc;
                }
                tab[i][j].liczba_mozliwosci = 1;
            } else {
                losowe_9(tab[i][j].mozliwosci);
                tab[i][j].liczba_mozliwosci = 9;
            }
        }
    }

    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < X; ++j) {
            if (tab[i][j].liczba_mozliwosci > 1) {
                for (int k = 0; k < tab[i][j].liczba_mozliwosci; ++k) {
                    int tmp = sprawdz(tab, i, j, tab[i][j].mozliwosci[k]);
                    if (tmp == 1) {
                        swap(tab[i][j].mozliwosci, k, tab[i][j].liczba_mozliwosci - 1);
                        k--;
                        tab[i][j].liczba_mozliwosci--;
                    }
                }
            }
        }
    }
    rozwiaz(tab, 0, 0);
}

void wypisz(struct pole tab[X][X]) {
    for (int i = 0; i < X; i++) {
        if (i % 3 == 0) printf("-------------------------------\n");
        for (int j = 0; j < X; j++) {
            if (j % 3 == 0) printf("|");
            if (tab[i][j].wartosc == 0) printf(" . ");
            else printf(" %d ", tab[i][j].wartosc);
            if (j == X - 1) printf("|");
        }
        printf("\n");
        if (i == X - 1) printf("-------------------------------");
    }
}

void wczytaj(struct pole tab[X][X], char *f) {
    int wek[X], tmp;

    if (f == NULL) {
        perror("Nie udalo sie otworzyc pliku do odczytu");
    }

    fscanf(f, "%d%d%d%d%d%d%d%d%d", &wek[0], &wek[1], &wek[2], &wek[3], &wek[4], &wek[5], &wek[6],
           &wek[7], &wek[8]);
    fclose(f);

    for (int i = 0; i < X; i++) {
        for (int j = 0; j < X; j++) {
            tmp = wek[i] % 10;
            wek[i] = (wek[i] - tmp) / 10;
            tab[i][8 - j].wartosc = tmp;
        }
    }
}

int zapisz(struct pole tab[X][X], char *f) {
    if (f == NULL) {
        perror("Nie udalo sie otworzyc pliku do zapisu");
        return 1;
    }
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < X; j++) {
            fprintf(f, "%d", tab[i][j].wartosc);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    return 0;
}

void usuwanie(struct pole tab[X][X], int poziom) {
    int x, y;
    srand(time);
    for (int i = 0; i < poziom; i++) {
        x = rand() % 9;
        y = rand() % 9;
        if (tab[x][y].wartosc == 0) {
            i = i - 1;
            continue;
        } else {
            tab[x][y].wartosc = 0;
        }
    }
}

int generuj(struct pole tab[X][X], int poziom) {
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < X; ++j) {
            tab[i][j].wartosc = 0;
        }
    }
    wypelnij(tab);
    usuwanie(tab, poziom);
}



int main(int argc, char *argv[]) {
    srand(time(NULL));
    int akcja;
    struct pole tab[X][X];
    FILE *f;
    f = fopen(argv[1], "rw+");
    int poziom;



        printf("1: Generowanie sudoku\n");
        printf("2: Rozwiazywanie sudoku\n");
        printf("3: Sprawdzanie sudoku\n");
        printf("4: Wypisz sudoku\n");

        scanf("%d", &akcja);

        switch (akcja) {

            case 1: {
                printf("Podaj poziom trudnosci 1: trudny, 2: sredni, 3: latwy\n");
                scanf("%d", &poziom);
                if (poziom == 1) poziom = 60;
                else if (poziom == 2) poziom = 45;
                else poziom = 30;
                generuj(tab, poziom);
                zapisz(tab, f);
                wypisz(tab);
                break;
            }

            case 2: {
                wczytaj(tab, f);
                wypelnij(tab);
                wypisz(tab);
                zapisz(tab, f);
                break;
            }

            case 3: {
                wczytaj(tab, f);
                bool tmp = 0;
                for (int i = 0; i < X; i++) {
                    for (int j = 0; j < X; j++) {
                        int liczba = tab[i][j].wartosc;
                        if (liczba == 0){

                        }
                        else if (sprawdz(tab, i, j, liczba) == 1) {
                            printf("Nie da sie rozwiazac\n");
                            tmp = 1;
                            break;
                        }
                        if (i == X - 1 && j == X - 1) printf("Da sie rozwiazac\n");
                        if (tmp == 1) break;
                    }
                    if (tmp == 1) break;
                }
                break;
            }

            case 4: {
                wczytaj(tab, f);
                wypisz(tab);
                break;
            }

            default: {
                printf("Niepoprawne polecenie\n");
                break;
            }
        }


    return 0;
}