#include "insertion_sort.h" // Inkluderer headerfilen, der definerer strukturen for "node"
#include <stdlib.h>         // Til brug af standardbibliotekfunktioner som malloc og free

node* isort(node* list) {

// Hvis listen er tom (list == NULL) eller kun har ét element (list->next == NULL),
// er den allerede sorteret, så vi returnerer listen som den er.
    if (list == NULL || list->next == NULL) 
    {
        return list; // Returnerer listen, hvis den er tom eller kun har ét element
    }
    
    // Initialiserer sorted_list som NULL, da vi skal opbygge den sorterede liste fra bunden
    node* sorted_list = NULL;

    // current starter med at pege på det første element i den usorterede liste
    node* current = list;

    // Gennemgår den oprindelige liste, så længe current ikke er NULL (dvs. indtil vi har gennemgået alle elementer)
    while (current != NULL)
    {
        // Gemmer next_node, da current vil blive flyttet til sorted_list, og vi ellers ville miste pegepinden til det næste element
        node *next_node = current->next;
        
        // Hvis sorted_list er tom (første gang) eller hvis current's data er mindre end det første element i sorted_list,
        // skal current indsættes forrest i sorted_list
        if (!sorted_list || current->data < sorted_list->data)
        {
            // Sætter current ind som det nye første element i sorted_list
            current->next = sorted_list;
            sorted_list = current;
        }
        else
        {
            // Hvis current ikke skal indsættes forrest, skal vi finde den rette position i den sorterede liste
            node *temp  = sorted_list;  // temp bruges til at iterere over den sorterede liste
            
            // Finder det sted i sorted_list, hvor current skal indsættes.
            // Så længe vi ikke når slutningen af sorted_list, og temp's næste elements data er mindre end current's data,
            // fortsætter vi med at rykke fremad i listen.
            while (temp->next && temp->next->data < current->data)
            {
                temp = temp->next;  // Ryk temp til det næste element
            }
            
            // Indsætter current efter temp, da vi har fundet det rigtige sted i sorted_list
            current->next = temp->next;  // current skal pege på det næste element efter temp
            temp->next = current;        // temp's næste element skal nu være current
        }
        
        // Gå videre til det næste element i den oprindelige usorterede liste
        current = next_node;
    }

    // Når alle elementer er gennemgået og sat i sorted_list, returnerer vi den sorterede liste
    return sorted_list;
}






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