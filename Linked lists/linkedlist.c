#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node  // custom struct for each node in the linked list
{
    int number;  // int of the node
    struct node *next;  // pointer to next node
}
node;

node* create_node(int);  // function prototypes
void add_node(node *list, node *n);
void print_list(node *list);
node* delete_node(node *list);
node* insert_node(node *list);
void free_memory(node *list);

int main(void)
{
    int input = get_int("Please enter how many nodes you would like to create in the linked list? \n");
    node *list = NULL;  // list pointer variable, anticipating to be pointed at something of "node" datatype, initalize it to NULL so its not pointing to anything

    if (input != 0)
    {
        node *n = malloc(sizeof(node));  // malloc() "node 0" in memory + point our *n pointer to it
        if (n != NULL)  // saftey check to ensure n is not pointing to a NULL value in memory to avoid a seg fault
        {
            n->number = 0;  // set the number field of the node our "*n" is currently pointing to: 2
            n->next = NULL;   // set the next field of the node our "*n" is currently pointing to: NULL
        }
        list = n; // point our "*list" pointer to the same node our "*n" pointer is pointing to (at the start of this program, "list" will be pointing to the "head" of the linked list)

        for (int i = 1; i < input; i++) // start counting i at 1, since we statically declared the first node as "0"
        {
            n = create_node(i);  // use create_node to create a new node + also take the pointer to a node this function returns & assign it back to n
            add_node(list, n);  // connect the "nth" node created() above, to the existing linked list
        }

        print_list(list);
        list = delete_node(list);
        print_list(list);
        list = insert_node(list);
        print_list(list);
        free_memory(list);
        return 0;
    }
}

node* create_node(int i)  // our function to generate a node with the number we got from "i' in main()" "node 0", then "node 1" , then "node 2" etc
{
    node *n = malloc(sizeof(node)); // a new n pointer that will malloc "node i" in memory + point our "*n" pointer to this node
    if (n != NULL)  // saftey check to ensure n is not pointing to a NULL value in our memory
    {
        n->number = i;  // set the number field of the node our "*n_2" is currently pointing to: whatever "i" is (this draws a line in our linked list)
        n->next = NULL;  // set the next field of the node our "*n" is currently pointing to: NULL
    }
    return n;
}

void add_node(node *list, node *n)  // takes in paramaters for the 1. "list" pointer (that is anticipating to point to a node) and the "n" pointer (to point to the "n" node itself)
{
    node *tmp = list; // create a temp pointer, that will anticipate to be poiinted to something of a "node" datatype, and point it to where *tmp is pointing to, drawing a link
    while (tmp->next != NULL) // every time when looping through the linked list, if the current node tmp is  sitting on isn't NULL
    {
        tmp = tmp->next; // then migrate the temp pointer to the next node in the linked list
    }
    tmp->next = n; // then, set tmp->next field in this current node to = n, to point to where *n is pointing to, drawing another link between the temp node and node n after it.
}

void print_list(node *list) // takes in paramater for the list pointer (that is anticipating to point to a node)
{
    printf("Numbers in linked list:\n");
    node *tmp = list; // make a temp pointer that will point to the head of the linked list

    if (list == NULL)  // if the list pointer variable pointing to the head of thelinked list is NULL
    {
        printf("The linked list is empty\n");
    }
    else
    {
        while (tmp != NULL)  // keep performing this while loop until temp is not longer pointing to a node after in the linked list
        {
            printf("%d\n", tmp->number);  // print out the current nodes.number where tmp is pointing to
            tmp = tmp->next;  // then after this, update temp to point to the next node in the linked list to perform this action again
        }
    }
    printf("\n");
}

node* delete_node(node *list)
{
    int input = get_int("Please enter the number of a node you would like to delete from the linked list?\n");
    node *tmp_before = list;  // make a temp pointer that will point to the head of the linked list

    if (list == NULL)  // if the list pointer variable pointing to the head of the linked list is NULL
    {
        printf("Invalid linked list");
    }
    else
    {
        bool bool_var = true;
        while (bool_var == true)
        {
            if (tmp_before == NULL)
            {
                printf("Your linked list does not have any nodes to delete, goodbye:\n");
                bool_var = false;
            }

            if (input == 0)  // handle the deleation of the first node in the linked list
            {
                if (tmp_before->next != NULL)
                {
                    list = tmp_before->next;  // set the list pointer to point to where tmp_before->next is pointing to
                    free(tmp_before);  // free the node tmp_before is currently sitting on
                    bool_var = false;
                    break;
                }
                else // tmp_before->next == NULL)
                {
                    free(tmp_before); // just free the node tmp_before is currently sitting on if we know there are no nodes after we will end up orphaning by mistake
                    bool_var = false;
                    break;
                }
            }

            for (int i = 0; i < input - 1; i++)  // keep looping until we hit the value of the users input -1
            {
                if (tmp_before->next == NULL) // if the nth node we are trying to delete doesn't exist
                {
                    printf("The node you are trying to delete doesn't exist in the linked list, goodbye.\n");
                    bool_var = false;
                }

                tmp_before = tmp_before->next;  // set tmp_before on thisiteration of this loop to == tmp_before->next of the previous loop.
            }

            node *tmp = tmp_before->next;  // create a second tempoary pointer variable to sit on the "nth" node

            if (tmp->next != NULL)  // if the node after temp actually points to another node afterwards
            {
                tmp_before->next = tmp->next;  // point the pointer 1. from "temp_before.next" to 2. the node after temp, where "temp.next" is pointing to
                free(tmp);  // free the node after it is safe to do so without orphaning the rest of the linked list
                bool_var = false;
                break;
            }
            else  // https://www.tutorialspoint.com/c_standard_library/c_function_free.htm
            {
                tmp_before->next = NULL;  // set the last node of the linked ist to NULL before we free it(). if we dont do this, after we free() it tmp_before->next will point to the "0" free() leaves in this block of memory tmp used to occupy
                free(tmp);
                bool_var = false;
                break;
            }
        }
    }
    return list;
    printf("\n");
}

node* insert_node(node *list)
{
    int input = get_int("Please enter the place of a node# you would like to insert a node into after? \n");
    node *tmp_before = list;

    node *yeet = malloc(sizeof(node)); // a new n pointer that will malloc "node i" in memory + point our "*n" pointer to this node
    if (yeet != NULL)  // saftey check to ensure n is not pointing to a NULL value in our memory
    {
        yeet->number = 420;
        yeet->next = NULL;
    }

    if (list == NULL)
    {
        printf("Invalid linked list to insert into");
    }
    else
    {
        bool bool_var = true;
        while (bool_var == true)
        {
            if (tmp_before == NULL)
            {
                printf("Your linked list does not have any nodes to insert into, goodbye");
                bool_var = false;
                break;
            }

            for (int i = 0; i < input; i++)
            {
                if (tmp_before->next == NULL)
                {
                    printf("The node after the one you are trying to insert after doesn't exist in the linked list, goodbye.\n");
                    bool_var = false;
                    break;
                }

                tmp_before = tmp_before->next;  // set tmp_before on thisiteration of this loop to == tmp_before->next of the previous loop.
            }

            node *tmp = tmp_before->next;  // create a second tempoary pointer variable to sit on the "nth" node

            if (tmp != NULL)  // if the node after temp actually points to another node afterwards
            {
                yeet->next = tmp;
                tmp_before->next = yeet;
                bool_var = false;
                break;
            }
            else
            {
                tmp_before->next = yeet;
                bool_var = false;
                break;
            }
        }
    }
    return list;
    printf("\n");
}

void free_memory(node *list)
{
    node* tmp = list;

    while (list != NULL)  // check if list is currently NULL, if so, the list is empty and we just return
    {
        tmp = list;  // save list into a tmp variable
        list = list->next;  // save list into a tmp variable
        free(tmp);  // safely free the node where the (tmp) variable is currently sitting at 1 nod ebehind the new head now, repeat step 1
    }
}
