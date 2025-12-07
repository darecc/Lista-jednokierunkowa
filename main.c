#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include "list.h"

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001); // Dla wejścia też
    setlocale(LC_ALL, ".UTF-8");
    ListElement_type *head;
    head = (ListElement_type *)malloc(sizeof(ListElement_type));
    head = NULL;
    int opcja = -1;
    int liczba = -1;
    int index = -1;

    while(opcja!=0)
    {
    system("cls");
    printf("\nAktualny stan listy: ");
    show(head); //wyświetlenie zawartości listy

    printf("\n\nDrogi użytkowniku! Co chcesz zrobić?\n");
    printf("0. Zakończyć program.\n");
    printf("1. Dodać element na początek listy.\n");
    printf("2. Dodać element na koniec listy.\n");
    printf("3. Dodać element zgodnie z wybranym indeksem.\n");
    printf("4. Usunąć element z początku listy.\n");
    printf("5. Usunąć element z końca listy.\n");
    printf("6. Usunąć element o wybranym indeksie.\n");
    printf("7. Odwrócenie listy.\n");
    scanf("%i", &opcja);

    switch (opcja)
    {
    case 0:
    	return 0;
    	break;

    case 1:
        printf("Wpisz liczbę jaką chcesz dodać: ");
        scanf("%i", &liczba);
        push_front(&head, liczba);
        break;
     case 2:
        printf("Wpisz liczbę jaką chcesz dodać: ");
        scanf("%i", &liczba);
        push_back(&head, liczba);
        break;
    case 3:
        printf("Wpisz liczbę jaką chcesz dodać: ");
        scanf("%i", &liczba);
        printf("Wpisz indeks: ");
        scanf("%i", &index);
        push_by_index(&head, index, liczba);
        break;
    case 4:
        pop_front(&head);
        break;
	case 5:
        pop_back(&head);
        break;

	case 6:
        printf("Wpisz indeks elementu, który chcesz usunąć: ");
        scanf("%i", &index);
        pop_by_index(&head, index);
        break;
    case 7:
        reverse_list(&head);
        break;
    default:
        printf("Podaj właściwą opcję.\n");
        break;
    }
    }

    return 0;
}
