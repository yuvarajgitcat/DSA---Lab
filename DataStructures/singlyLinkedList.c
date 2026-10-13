#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *newnode, *last, *delnode, *prev, *temp;

/* Function Prototypes */
void getnode();
void readnode();
void create();
void insertfirst();
void insertlast();
void insertmiddle();
void modify();
int delfirst();
int dellast();
int delmiddle();
void display();

int main()
{
    int choice;
    do
    {
        printf("\n=====================================");
        printf("\n     SINGLY LINKED LIST MENU");
        printf("\n=====================================");
        printf("\n1. Create Linked List");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at End");
        printf("\n4. Insert at Middle");
        printf("\n5. Modify a Node");
        printf("\n6. Delete First Node");
        printf("\n7. Delete Last Node");
        printf("\n8. Delete Middle Node");
        printf("\n9. Display");
        printf("\n10. Exit");
        printf("\n-------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                insertfirst();
                break;

            case 3:
                insertlast();
                break;

            case 4:
                insertmiddle();
                break;

            case 5:
                modify();
                break;

            case 6:
                delfirst();
                break;

            case 7:
                dellast();
                break;

            case 8:
                delmiddle();
                break;

            case 9:
                display();
                break;

            case 10:
                printf("\nProgram Terminated.\n");
                break;

            default:
                printf("\nInvalid Choice.");
        }

    } while(choice != 10);

    return 0;
}
  
create()
     {         
               int c;
                if(head!=NULL)
                {
                    printf("%s","Linked List is already created");
                    return(0);
                }
                else
                {
                    do
                    {
			getnode();
                    	readnode();
                    if(head==NULL)
                    {
			head=last=newnode;
                    }
else
                 {
		      last->link=newnode;
                        last=last->link or newnode;
                  }
                 print “Press 1 to add another node:";
                 read c;
                }while(c==1);
                }
                return(0);
     		}
insertlast()
{
    getnode();
    if(newnode==NULL)
    {
      print “Memory Insufficient";
      return(0);
    }
    readnode();
   if(head==NULL)
    {
       head=last=newnode;
       return(0);
    }
    last->link=newnode;
    last=last->link;
}
int insertfirst()
{
    getnode();
    if(newnode==NULL)
    {
         print “No Memory";
         return(0);
    }
    readnode();
if(head==NULL)
    {
        head=last=newnode;
        return(0);
    }
    newnode->link=head;
    head=newnode;
}
modify()
{ if(head==NULL)
    {      printf("\nSLL is Empty");
           return(0);           }
	     read x; //x is the item to be replaced
           temp=head;
           until(temp!=NULL)
           {
            if(temp->data==x)
		{read temp->data
		 exit(0) }   
	     else
           	 temp=temp->link;
            }
       }
insertmiddle()
{
    getnode();
    if(newnode==NULL)
    {
                     printf("\nNo Memory");
                     return(0);
    }
    readnode();
    if(head==NULL)
    {
                 head=last=newnode;
                 return(0);
    } 
    print ”Enter the node after which you want to insert the new node:";
    read x;
    temp=head;
while(temp!=NULL)
{
   if(temp->data==x)
   {
             newnode->link=temp->link;
             temp->link=newnode;
             return(0);
    }
    else
             temp=temp->link;
    }
    return(0);
}
delfirst()
{
    if(head==NULL)
    {
      print”SLL is empty:";
      return(0);
    }
    else if(head==last)
    {
    delnode=head;
    print”Deleted node is delnode->data;
    head=last=NULL;
    free(delnode);
    return(0);
}
else
 {
     delnode=head;
     print”Deleted node is delnode->data;
     head=head->link;
     free(delnode);
     return(0);
}
}
int dellast()
{
    if(head==NULL)
    {
                  printf("\nSLL is empty:");
                  return(0);
    }
    else if(head==last)
    {
         delnode=head;
         print”Deleted node is  delnode->data;
         head=last=NULL;
         free(delnode);
         return(0);
}
else
 {
     temp=head;
     while(temp->link!=NULL)
     {
      prev=temp;
      temp=temp->link;
      }
     delnode=temp;
     print "\nDeleted node is  delnode->data;
     last=prev;
     last->link=NULL;
     free(delnode);
     return(0);
}
}
delmiddle()
{
    int x;
    if(head==NULL)
    {
                  printf("\nSLL is empty:");
                  return(0);
    }
    else if(head==last)
    {
         delnode=head;
         print”Deleted node is delnode->data);
         head=last=NULL;
         free(delnode);
         return(0);
}
else
 {         temp=head;
         printf("\nEnter the element which has to be deleted");
         Read x;
         while(temp!=NULL)
         {           if(temp->data==x)
              {            delnode=temp;
                  print“Deleted node is delnode->data;
                   prev->link=temp->link;
                   free(delnode);
                   return(0);                  }
               else
               {     prev=temp;
                     temp=temp->link;                  }
         }}}

