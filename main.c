#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>


typedef struct ListElement {
    int data;
    struct ListElement * next;
} ListElement_type;


void show(ListElement_type *head);
int list_size(ListElement_type *head);
void push_front(ListElement_type **head, int number);
void push_back(ListElement_type **head, int number);
void push_by_index(ListElement_type **head, int number, int position);
void pop_front(ListElement_type **head);
void pop_back(ListElement_type **head);
void pop_by_index(ListElement_type **head, int position);
void reverse_list(ListElement_type **head);

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

void push_front(ListElement_type **head, int number)
{
    ListElement_type *current;
    current=(ListElement_type *)malloc(sizeof(ListElement_type));
    current->data=number;
    current->next=(*head);
    *head=current;
}

void push_back(ListElement_type **head, int number)
{
	if(*head==NULL)
	{
		*head = (ListElement_type *)malloc(sizeof(ListElement_type));
   		(*head)->data = number;
    	(*head)->next = NULL;
	}else
	{
		ListElement_type *current=*head;
	    while (current->next != NULL) {
	        current = current->next;
	    }
	    current->next = (ListElement_type *)malloc(sizeof(ListElement_type));
	    current->next->data = number;
	    current->next->next = NULL;
	}
}

void push_by_back(ListElement_type **head, int number, int position)
{
	if(position==0) push_front(head, number);
	else
	{
		if(position==list_size(*head)) push_back(head, number);
		else
		{
			ListElement_type *current=*head;
   			ListElement_type *tmp;

			int i=0;
  			while (current->next != NULL && i < position - 1) {
            	current = current->next;
      			i++;
    		}
            tmp=current->next;
            current->next=(ListElement_type *)malloc(sizeof(ListElement_type));
            current->next->data=number;
            current->next->next=tmp;
        }
	}
}

void pop_front(ListElement_type **head)
{
    ListElement_type * tmp=NULL;
    if (*head!=NULL) {
   	 tmp=(*head)->next;
   	 free(*head);
   	 *head=tmp;
	}
}

void pop_back(ListElement_type **head)
{

	if((*head)->next==NULL)
	{
		*head=NULL;
	}else
	{
		ListElement_type *current=*head;
		while (current->next->next!= NULL) {
        current = current->next;
    	}
   		 free(current->next);
   		 current->next=NULL;
	}
}


void pop_by_index(ListElement_type **head, int position)
{
	if(position==0) pop_front(head);
	else
	{
		ListElement_type *current=*head;
	    ListElement_type *tmp;

		int i=0;
		while (current->next != NULL && i < position-1) {
	        current=current->next;
			i++;
		}
		tmp = current->next;
	    current->next = tmp->next;
	    free(tmp);
	}
}

void push_by_index(ListElement_type **head, int position, int value) {
    // 1. Utwórz nowy element
    ListElement_type *new_element = (ListElement_type*)malloc(sizeof(ListElement_type));
    if (new_element == NULL) {
        printf("Błąd alokacji pamięci!\n");
        return;
    }
    new_element->data = value;
    new_element->next = NULL;

    // 2. Obsługa wstawiania na początek (pozycja 0) lub do pustej listy
    if (position == 0 || *head == NULL) {
        new_element->next = *head;
        *head = new_element;
        return;
    }

    // 3. Znajdź odpowiednie miejsce w liście
    ListElement_type *current = *head;
    ListElement_type *previous = NULL;
    int current_index = 0;

    // Przejdź do żądanej pozycji lub końca listy
    while (current != NULL && current_index < position) {
        previous = current;
        current = current->next;
        current_index++;
    }

    // 4. Wstaw element w znalezione miejsce
    previous->next = new_element;
    new_element->next = current;
}

void show(ListElement_type *head)
{
    printf("\n");
    if(head==NULL) printf("Lista jest pusta");
    else
    {
        ListElement_type *current=head;
            do {
            printf("%i", current->data);
            printf("\n");
            current = current->next;
            }
            while (current != NULL);
    }
}

int list_size(ListElement_type *head)
{
    int counter=0;
    if(head==NULL) return counter;
    else
    {
        ListElement_type *current=head;
            do {
            counter++;
            current = current->next;
            }while (current != NULL);
    }
    return counter;
}

// procedura odwracania (iteracyjnego listy)
void reverse_list(ListElement_type **head) {
    ListElement_type *prev = NULL;
    ListElement_type *current = *head;
    ListElement_type *next = NULL;

    while (current != NULL) {
        // Zapamiętaj następny element
        next = current->next;

        // Odwróć wskaźnik
        current->next = prev;

        // Przesuń wskaźniki do przodu
        prev = current;
        current = next;
    }

    // Ustaw nową głowę listy
    *head = prev;
}
