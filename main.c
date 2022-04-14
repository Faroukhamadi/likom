#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
};
typedef struct Node Node;

// IMPORTANT: Global Variable
Node* head;

void printLinkedList() {
  Node* current = head;

  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("NULL");
}


void lengthLinkedList() {
  Node* current = head;

  int length = 0;
  while (current != NULL) {
    length++; // length = length + 1
    current = current->next;
  }

  printf("\nThe length of the entered linked list is: %d", length);
}

void countOccurencesLinkedList(int valueToLookFor) {
  Node* current = head;

  int occurences = 0;
  while (current != NULL) {
    if (current->value == valueToLookFor) {
      occurences++; // occurences = occurences + 1
    }
    current = current->next;
  }

  printf("\nThe number of occurences of %d is: %d", valueToLookFor, occurences);
}



// head -> second -> third -> NULL
// head -> second -> third -> NULL
void createLinkedList(int n) {
  int x;

  head = malloc(sizeof(Node));

  printf("Enter value: \n");
  scanf("%d", &x);
  head->value = x;
  head->next = NULL;
  Node* current = head;


  for (int i = 1; i < n; i++) {
    Node* temp = malloc(sizeof(Node));
    current->next = temp;

    printf("Enter value: \n");
    scanf("%d", &x);

    temp->value = x;
    temp->next = NULL;
    current = temp;
  }
}


int getIndexOfNode(int value) {
  Node* current = head;

  int index = 0;

  while (current != NULL) {
    if (current->value == value) {
      return index;
    }
    index++;
    current = current->next;
  }
  return -1;
}





void deleteLinkedListElement(int valueToDelete) {
  Node* current = head;

  int deleteIndex = getIndexOfNode(valueToDelete);
  if (deleteIndex == -1) {
    return;
  } else if (deleteIndex == 0) {
    head = current->next;
    free(current);
    return;
  }

  for (int i = 0; i < deleteIndex - 1; i++) {
    current = current->next;
  }
  Node* current1 = current->next;
  current->next = current1->next;
  free(current1);

}

void sortLinkedList() {
  if (head == NULL || head->next == NULL) {
    return;
  }
  for (Node* i = head; i->next != NULL; i = i->next) {
    for (Node* j = head; j->next != NULL; j = j->next) {
      if (j->value > j->next->value) {
        int temp = j->value;
        j->value = j->next->value;
        j->next->value = temp;
      }
    }
  }
}



int main() {
  int n;
  printf("Enter linked list value\n");
  scanf("%d", &n);

  createLinkedList(n);
  printf("linked list before sort\n");
  printLinkedList();
  lengthLinkedList();
  countOccurencesLinkedList(70);
  printf("linked list after sort\n");
  sortLinkedList();
  printLinkedList();



  return 0;
}
