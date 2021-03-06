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
struct treenode
 {
 char data;
 struct treenode *left;
 struct treenode *right;
 };
 typedef struct treenode nodeptrtree;

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
nodeptrtree* newtreenode(char data)
 {
     nodeptrtree *np;
     np=(nodeptrtree *)malloc(sizeof(nodeptrtree));
     np->data=data;
     np->left=np->right=NULL;
     return np;
 }
//funtion to read the array and store in tre
nodeptrtree* treeorder(char arr[], nodeptrtree* root,int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        nodeptrtree* temp = newtreenode(arr[i]);
        root = temp;
        
        // insert left child
        root->left = treeorder(arr,
                                      root->left, 2 * i + 1, n);
        
        // insert right child
        root->right = treeorder(arr,
                                       root->right, 2 * i + 2, n);
    }
    return root;
}




//FUNCTION  for cheacking the character is an alphabet or a character
/*int ccheck(char c)
 {
 
 if(strcmp(c,".") && strcmp(c,"-") && strcmp(c," "))
 return 1;
 else
 return 0;
 }*/
//function for searching the tree
char searchtree(char *ai,nodeptrtree* root)
{
    nodeptrtree *temp;
    temp=root;
    int i=0;
    while(ai[i]=='.' || ai[i]=='-')
    {
        if(ai[i]=='.')
        {
            root=root->left;
        }
        else if(ai[i]=='-')
        {
            root=root->right;
        }
        i++;
    }
    return root->data;
    
}
//function used to converet moprse to char
nodeptrtree* morsetravel(char c,nodeptrtree* root)
{
    if(c=='.')
    {
        root=root->left;
        return root;
    }
    else
    {
        root=root->right;
        return root;
    }
}

int main(int argc, char *argv[])
{
    //variables required
    nodeptr *head ,*first,*temp;
    nodeptrtree *treehead, *treefirst;
    char c,*a,*ct,order1[60];
    //taking info from file name morseinf.txt
    FILE *morse,*order,*arg,*argout;
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
    int j=0;
    order=fopen("morsearray.txt","r");
    while((c=fgetc(order))!=EOF)
    {
        order1[j]=c;
        printf("%c",order1[j]);
        j++;
    }
    int n=sizeof(order1)/sizeof(order1[0]);
    nodeptrtree* root = treeorder(order1,root,0,n);
    treefirst=root;
    printf("\n\n%c\n\n",root->left->data);
    char ai[6];
    scanf("%s",ai);
    puts(ai);
    int i=0;
    //char ap;
    /*while(ai[i]=='.' || ai[i]=='-')
    {
        if(ai[i]=='.')
        {
            root=root->left;
        }
        else if(ai[i]=='-')
        {
            root=root->right;
        }
        i++;
    }
    printf("\n\n\n%c\n\n\n",root->data);*/
   // ap=searchtree(ai,treefirst);
    // treehead=treefirst;
    //printf("%c\n",ap);
   /* if(strcmp(argv[1],"-f"))
    {
        j=0;
        arg=fopen(argv[2],"r");
        argout=fopen(argv[3],"w");
        while((c=fgetc(arg))!=EOF)//reading one by one character to linked list
        {
            if(c=='.')
            {
                treehead=treehead->left;
            }
            else if(c=='-')
            {
                treehead=treehead->right;
            }
            else if(c==' ')
            {
                fprintf(argout,"%c",treehead->data);
                treehead=treefirst;
                
            }
            else if(c=='/')
            {
                fprintf(argout,"%c ",treehead->data);
                treehead=treefirst;
            }
            
        }
        
    }*/
    
}
