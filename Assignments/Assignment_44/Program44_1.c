////////////////////////////////////////////////////////////////////////
//
//  Required Header Files
//
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

/*------------------------------------------------------------------------------
        Old Name                    New Name
--------------------------------------------------------------------------------
        struct Node                 NODE
        struct Node *               PNODE
        struct Node **              PPNODE
--------------------------------------------------------------------------------*/

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  int no        → Data to be inserted in the node
//  Output        : Modifies linked list by adding new node at first position
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;
    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = (*first);
        *first = newn;
    }
}



void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |-->", first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Search
//  Description     :   Used to Find the element in list
//  Input           :   Head, value to find
//  Output          :   (BOOLEAN)
//  Author          :   Aditya Mali
//  Date            :   30/12/2025
//
////////////////////////////////////////////////////////////////////////

bool Search(PNODE first, int no)
{
    bool bFlag = false;

    while(first != NULL)
    {
        if(first -> data == no)
        {
            bFlag = true;
            break;
        }
        first = first -> next;
    }
    return bFlag;
}

////////////////////////////////////////////////////////////////////////
//
//  Entry point function : Main
//
////////////////////////////////////////////////////////////////////////

int main()
{
    bool bRet = false;
    PNODE head  = NULL;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    bRet = Search(head, 111);
    if(bRet == true)
    {
        printf("It is present in Linked list");
    }
    else
    {
        printf("It is not present in Linked list");
    }

    return 0;
}
