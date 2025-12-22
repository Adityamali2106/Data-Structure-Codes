#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLL
{
    public:
        PNODE first;
        int iCount;

        SinglyLL()
        {
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if (first == NULL)
            {
                first = newn;
            }
            else 
            {
                newn -> next = first;
                first = newn;
            }

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if (first == NULL)
            {
                first = newn;
            }
            else 
            {
                temp = first;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }

                temp -> next = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;
            if (first == NULL)
            {
                return;
            }
            else if (first -> next == NULL)
            {
                delete(first);
                first = NULL;
            }
            else
            {
                temp = first;

                first = temp -> next;
                delete(temp);
            }
            iCount--;
        }
 
        void DeleteLast()
        {
            PNODE temp = NULL;
            if (first == NULL)
            {
                return;
            }
            else if (first -> next == NULL)
            {
                delete(first);
                first = NULL;
            }
            else
            {
                temp = first;
                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }
                delete(temp -> next);
                temp -> next = NULL;
            }
            iCount--;
        }
 

        void Display()
        {
            PNODE temp = NULL;

            temp = first;
            if (temp == NULL)
            {
                cout<<"List is Empty\n";
                return;
            }

            while(temp != NULL)
            {
                cout<<"| "<<temp -> data<<" | -> ";
                temp = temp -> next;
            }
            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no,int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            int iCnt = 0;

            if(pos < 1 || pos > iCount + 1)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if (pos == 1)
            {
                InsertFirst(no);
            }
            else if (pos == iCount +1)
            {
                InsertLast(no);
            }
            else
            {
                temp = first;

                newn = new NODE;

                newn -> data = no;
                newn -> next = NULL;

                for (iCnt = 1; iCnt < pos - 1;iCnt++)
                {
                    temp = temp -> next;
                }

                newn -> next = temp -> next;
                temp -> next = newn;
                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE Target = NULL;
            int iCnt = 0;

            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if (pos == 1)
            {
                DeleteFirst();
            }
            else if (pos == iCount + 1)
            {
                DeleteLast();
            }
            else
            {
                temp = first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }

                Target = temp -> next;
                temp -> next = Target -> next;
                delete(Target);
                iCount--;
            }
        }
};

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(105,3);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}