#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//start

struct node
{
    char data;
    struct node *next;
};
typedef struct node nodeptr;
/*struct treenode
{
    char *data;
    struct treenode *left;
    struct treenode *right;
};
typedef struct treenode nodeptrtree;
*/
//required globle variables
//nodeptrtree *treehead, *treefirst;

//linked list add node
nodeptr *newnode(char c)
{
    nodeptr *np;
    np= (nodeptr *)malloc(sizeof(nodeptr));
    np->data=c;
    return np;
}
//funtion for printing linked list
void printlinkedlist(nodeptr *head)
{
    while(head->data!= EOF)
    {
        printf("%c",head->data);
        head=head->next;
    }
}
//function for tree new node froms node and store data with "empty"
/*nodeptrtree *newtreenode()
{
    nodeptrtree *np;
    np=(nodeptrtree *)malloc(sizeof(nodeptrtree));
    np->data="empty";
    return np;
}*/

//FUNCTION  for cheacking the character is an alphabet or a character
/*int ccheck(char c)
{
    
    if(strcmp(c,".") && strcmp(c,"-") && strcmp(c," "))
        return 1;
    else
        return 0;
}
char searchtree(char a[],nodeptrtree *treefirst)
{
    int i=0;
    nodeptrtree *head;
    head=treefirst;
    while(a[i]!="\0")
    {
        if(a[i]==".")
        {
            head=head->left;
        }
        else if(a[i]=="-")
        {
            head=head->right;
        }
    }
    return head->data;
 }
 */

int main()
{
    //variables required
    nodeptr *head ,*first,*temp=0;
   // nodeptrtree *treehead, *treefirst;
    char c,*a,*ct;
    //taking info from file name morseinf.txt
    FILE *morse;
    morse=fopen("morseinf.txt", "r");//opening file
    if (morse == NULL )//checking file status
        {
            printf("Error! Could not open file\n");
            exit(-1);
        }
    while((c=fgetc(morse))!=EOF)//reading one by one character to linked list
        {
            if(first==NULL)
            {
                first=newnode(c);
                head=first;
            }
            else
            {
                head->next=newnode(c);
                head=head->next;
            }
        }
    head->next=newnode(EOF);
          printlinkedlist(first);
    //linked list stored with morseinf.txt file
    //start storing characters in a tree in a spaefied location
   /*treefirst=newtreenode();
    treehead=treefirst;
    head=first;
    
    while(head->data!=EOF)
    {
        if(ccheck(head->data))
            c=head->data;
        else
        {
            if(head->data==".")//"."==left side node forms "-"=right node forms if " "=give the the data to head->data and reset to head to first
            {
                if(treehead->left==NULL)
                {
                    treehead->left=newtreenode();
                    treehead->left->data="not a morse code";
                }
                treehead=treehead->left;
            }
            else if(!strcmp(head->data,"-"))
            {
                if(treehead->right==NULL)
                {
                    treehead->right=newtreenode();
                }
                treehead=treehead->right;
            }
            else if(!strcmp(head->data," "))
            {
                treehead->data=ct;
                treehead=treefirst;
            }
        }
        head->next=head;
    }
    //cheaking working
    gets(a);
    printf("%c",searchtree(a,treefirst));*/
}
    

