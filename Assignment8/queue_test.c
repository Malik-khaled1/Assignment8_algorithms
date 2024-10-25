#include "queue.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main(void){

    queue q; // Deklarer og definer køen q

    initialize(&q); // Initialiser køen ved at sende adressen til q som parameter
    assert(q.front == NULL && q.rear == NULL); // Assert at køen er tom efter initialisering

    int x = 5;
    enqueue(&q, x); // Tilføj en node til køen med værdien 5

    int y = dequeue(&q); // Tildel y værdien i den node som fjernes fra køen
    assert(y == x); // Assert at værdien i den node der blev tilføjet i køen er lig med den værdi i noden der blev fjernet fra køen


    int x_0 = 4;
    int x_1 = 3;
    int y_0;
    int y_1;

    enqueue(&q, x_0);
    enqueue(&q, x_1);

    y_0 = dequeue(&q);
    y_1 = dequeue(&q);

    assert(y_0 == x_0);
    assert(y_1 == x_1);

    printf("Koeen er korrekt initialiseret.\n");
    printf("Dequeued vaerdi: %d\n", y);

    return 0;
}