#include <stdio.h>
#include <stdlib.h>

// define our own custom struct for each node in the linked list
typedef struct node
{
    int number;
    struct node *next;
}
node;

void print_list(node *list);
create_node(value);
add_node(list, node);

int main(void)
{
    // create the list pointer variable, that will anticipate to be pointed to something of a "node" datatype, and initalize it to NULL
    node *list = NULL;
    // malloc() "node 2" in our memory + point out *n pointer to this node
    node *n = malloc(sizeof(node));

    // saftey check to ensure n is not pointing to a NULL value in our memory
    if (n != NULL)
    {
        n->number = 2;
        n->next = NULL;
    }

    // point our "*list" pointer to the same node our "*n" pointer is pointing to (at the start of this program list will be pointing to the head of the linked list)
    list = n;
    // create a temp pointer, that will anticipate to be poiinted to something of a "node" datatype, and point it to where *tmp is pointing to, drawing a link
    node *tmp = list;

    // malloc "node 4" in memory + point our "*n" pointer to this node
    n = malloc(sizeof(node));

    // saftey check to ensure n is not pointing to a NULL value in our memory
    if (n != NULL)
    {
        n->number = 4;
        n->next = NULL;
    }

    // while loop we use to find the last node that already exists in the established linked list
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    // then, set tmp->next field in node 2, to point to where *n is pointing to (node 4 in memory), drawing another link
    tmp->next = n;

    // malloc "node 5" in memory + point our "*n" pointer to this node
    n = malloc(sizeof(node));

    // saftey check to ensure n is not pointing to a NULL value in our memory
    if (n != NULL)
    {
        n->number = 5;
        n->next = NULL;
    }

    // however, by this point, our tmp pointer hasn't moved from node 2 yet, and the current tmp->next value is "4", which != NULL
    while (tmp->next != NULL)
    {
        // tmp->next on this example == 4, so we need to move our tmp pointer across to this "node 4"
        // this then loops again with the tmp pointer on node 4, this line wont execute a second time since node 4 -> next == NULL
        tmp = tmp->next;
    }

    // then, set tmp->next field in node 4, to point to where *n is pointing to (node 5 in memory), drawing another link
    // pass in the list pointer to a node into out function ot print out the .numbers in the linked list
    tmp->next = n;
    print_list(list);
    return 0;
}

// takes in paramater for the list pointer (that is anticipating to point to a node)
void print_list(node *list)
{
    printf("Numbers in linked list:\n");
    // make a temp pointer that will point to the head of the linked list
    node *tmp = list; 

    // if the list pointer variable pointing to the head of thelinked list is NULL
    if (list == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        // keep performing this while loop until temp is not longer pointing to a node after in the linked list
        while (tmp != NULL)
        {
            // print out the current nodes.number where tmp is pointing to, after this, update temp to point to the next node in the linked list to perform this action again
            printf("%d\n", tmp->number);
            tmp = tmp->next;
        }
    }
}
