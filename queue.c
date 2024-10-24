#include "queue.h"
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#include "queue.h"

void initialize(queue *q) {

    q->front = NULL; // Sæt front til at pege på NULL da der ikke er nogen noder i køen endnu
    q->rear = NULL; // Sæt rear til at pege på NULL da der ikke er nogen noder i køen endnu

    q->size = 0; // Initialiser størrelsen på køen til 0, da der den ikke indeholder nogen elementer endnu

}

bool empty(const queue *q) {

    return q->size == 0; // Retuner true hvis størrelsen på køen er 0, ellers false
}

bool full(const queue *q) {

    node* new_node = malloc(sizeof(node)); // Opret en ny node og allokker hukommelse i heapen.

    if (new_node == NULL) // Hvis malloc retunerer en NULL pointer
    {
        printf("The queue is FULL!");
        return true;
    }
    
    return false;
}

void enqueue(queue *q, int x) {

    node *new_node = malloc(sizeof(node)); // Opret en ny node og alloker hukommelse til den
    new_node->data = x; // Indsæt dataen i den nye node

    if (q->front == NULL && q->rear == NULL) // Hvis både fronten og bagenden af køen er NULL, så må køen være tom
    {
        q->front = new_node; // Fronten skal pege på den nye node
        q->rear = new_node; // Bagenden skal pege på den nye node

    } else
    {
        q->rear->next = new_node; // Bagendens next skal pege på den nye node. DVS. den nye node indsættes bagerst i køen
        q->rear = new_node; // Bagenden skal nu pege på den nye node. dvs at den nye bagende i køen nu er den nye node
  
    }
    new_node->next = NULL; // Den nye nodes next skal pege på NULL
    
    q->size++; // Øg størrelsen af køen med én
}

int dequeue(queue *q) {

    if (empty(q)) // Tjek om køen er tom
    {
        printf("The queue is empty, nothing to dequeue");
        
        return -1; // Retuner en -1, indikation på en fejl
    }
    
    node* temp = q->front; // Midlertidig variabel, som reference til køens front
    q->front = q->front->next; // Fjern den første node i køen og lad front pege på den næste node som nu er den første
    
    if (q->front == NULL) // Tjek hvis fronten nu peger på NULL efter fjernelse?
    {
        q->rear = NULL; // Hvis JA, opdater bagenden til også at pege på NULL. Nu er køen tom
    }
    
    int value = temp->data; // Gem værdien i den fjernede node
    free(temp); // Frigør hukommelsen

    return value; // Retuner værdien i den fjernede node

}