#include "insertion_sort.h"
#include<stdlib.h>

node* isort(node* list) {

// Hvis listen er tom (list == NULL) eller kun har ét element (list->next == NULL),
// er den allerede sorteret, så vi returnerer listen, som den er.
    if (list == NULL || list->next == NULL) 
    {
        return list;
    }
    
    node* sorted_list = list;
    node* current = list->next;

    while (current != NULL)
    {
        node *next_node = current->next;
        

        if (current->data < sorted_list->data)
        {
            current->next = sorted_list;
            sorted_list = current;
        }
        else
        {
            node *temp  = sorted_list;
            while (temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            
            current->next = temp->next;
            temp->next = current;
        }
        
        


        current = next_node;
    }
    



    return sorted_list;


}



//



/* 
node* isort(node* list){

    
    
    node* head = list; // head starter med at pege på starten af listen
    node* current = head->next; // current starter med at pege på den anden node i listen, da den første betragtes som sorteret
    node *next_node; // Pointer til at gemme referencen til den næste node.

    
    
    // Itererer så leange der er en node. Stop hvis NULL(Ikke flere noder)
    while (current != NULL)
    {
        node *temp = head; // Midlertidig pointer der starter fra starten af listen hver gang.
      

        if (current->data < head->data)
        {
            next_node = current->next; // Gem en reference til den næste node i listen

            head = current; //Opdater head til at pege på current, som nu bliver den nye første node i listen
            current->next = temp; //Opdater current->next til at pege på temp, som repræsenterer den tidligere første node (den gamle head)
            current = next_node; // Opdater current til nu at pege på den næste node i listen
        }
        else
        {
            // Gå gennem den sorterede del af listen for at finde den korrekte indsættelsesposition for current.
            // Fortsæt, så længe vi ikke er nået til slutningen af listen (temp->next != NULL)
            // og værdien i den næste node (temp->next->data) er mindre end værdien af current.
            // Stop når vi finder en node med en værdi større eller lig med current, hvor current skal indsættes.
            while (temp->next != NULL && temp->next->data < current->data) 
            {
                temp = temp->next; // Flyt temp til næste node for at finde den rette indsættelsesposition.
            }

            next_node = current->next; // Gem reference til den næste node, der skal behandles, inden vi opdaterer current
            current->next = temp->next; // Indsæt current mellem temp og temp->next
            temp->next = current; // Opdater temp->next til at pege på current, så current er korrekt indsat
            current = next_node; // Gå videre til den næste node, der skal sorteres
        }
        
    
        

    }
    
    return head;

}



 */