#include<stdio.h>
#include<malloc.h>
struct node
       {
         int n;
         int degree;
         struct node* parent;
         struct node* child;
         struct node* sibling;
       };

struct node* make_heap();
int new_link(struct node*,struct node*);
struct node* create(int);
struct node* unioun(struct node*,struct node*);
struct node* insert(struct node*,struct node*);
struct node* merge(struct node*,struct node*);
struct node* get_min(struct node*);
int reverse(struct node*);
int display(struct node*);
struct node* find(struct node*,int);
int decrease_key(struct node*,int,int);
int delete(struct node*,int);

int count=1;

struct node* make_heap()
  {
    struct node* np;
    np=NULL;
    return np;
  }

struct node * H=NULL;struct node *Hr=NULL;

int new_link(struct node* y,struct node* z)
  {
    y->parent=z;
    y->sibling=z->child;
    z->child=y;
    z->degree=z->degree+1;
  }

struct node* create(int k)
  {
   struct node* p;//new node;
   p=(struct node*)malloc(sizeof(struct node));
   p->n=k;
   return p;
 }

struct  node* unioun(struct node* H1,struct node* H2)
 {
   struct node* prev_x;
   struct node* next_x;
   struct node* x;
   struct   node* H=make_heap();
   H=merge(H1,H2);
   if(H==NULL)
    return H;
   prev_x=NULL;
   x=H;
   next_x=x->sibling;
   while(next_x!=NULL)
      {
        if((x->degree!=next_x->degree)||((next_x->sibling!=NULL)&&(next_x->sibling)->degree==x->degree))
        {
        prev_x=x;
        x=next_x;
        }
       else
        {
         if(x->n<=next_x->n)
         {
           x->sibling=next_x->sibling;
           new_link(next_x,x);
         }
         else
         {
          if(prev_x==NULL)
             H=next_x;
          else
             prev_x->sibling=next_x;
          new_link(x,next_x);
          x=next_x;
         }
     } 
    next_x=x->sibling;
   }
 return H;
}

struct node* insert(struct node* H,struct node* x)
{
   struct node* H1=make_heap();
   x->parent=NULL;
   x->child=NULL;
   x->sibling=NULL;
   x->degree=0;
   H1=x;
   H=unioun(H,H1);
   return H;
}

struct  node* merge(struct node* H1,struct node* H2)
{
  struct node* H=make_heap();
  struct  node* y;
  struct  node* z;
  struct  node* a;
  struct node* b;
  y=H1;
  z=H2;
  if(y!=NULL)
  {
    if(z!=NULL&&y->degree<=z->degree)
      H=y;
    else if(z!=NULL&&y->degree>z->degree)
      H=z;
  else
      H=y;
  }
 else
   H=z;
while(y!=NULL&&z!=NULL)
 {
   if(y->degree<z->degree)
   {
      y=y->sibling; 
   }
   else if(y->degree==z->degree)
      {
        a=y->sibling;
        y->sibling=z;
        y=a;
      }
   else
      {
        b=z->sibling;
        z->sibling=y;
        z=b;
      }
  }
  return H;
}

int display(struct node* H)
{
    struct node* p;
    if(H==NULL)
      {
      printf("\nHeap Empty");
      return 0;
      }
    printf("\nRoot node:-\n");
    p=H;
    while(p!=NULL)
    {
      printf("%d",p->n);
      if(p->sibling!=NULL)
      printf("-->");p=p->sibling;
    }
   printf("\n");
 }

struct  node* get_min(struct node* H1)
{
  int min;
  struct node* t=NULL;
  struct   node* x=H1;
  struct node *Hr;
  struct node* p;
  Hr=NULL;
  if(x==NULL)
  {
      printf("\nHeap is empty");
      return x;
   }
//    int min=x->n;
   p=x;
   while(p->sibling!=NULL)
   {
     if((p->sibling)->n<min)
     {
        min=(p->sibling)->n;
        t=p;
        x=p->sibling;
      }
    p=p->sibling;
   }
  if(t==NULL&&x->sibling==NULL)
      H1=NULL;
  else if(t==NULL)
      H1=x->sibling;
  else if(t->sibling==NULL)
      t=NULL;
  else
      t->sibling=x->sibling;
  if(x->child!=NULL)
  {
    reverse(x->child);
    (x->child)->sibling=NULL;
   }
   H=unioun(H1,Hr);
   return x;
}

int reverse(struct node* y)
{
  if(y->sibling!=NULL)
  {
    reverse(y->sibling);
    (y->sibling)->sibling=y;
   }
 else
   {
     Hr=y;
    }
}

struct  node* find(struct node* H,int k)
{
 struct node* x=H;
 struct  node* p=NULL;
 if(x->n==k)
  {
    p=x;
    return p;
   }
 if(x->child!=NULL&&p==NULL)
     {
       p=find(x->child,k);
     }

if(x->sibling!=NULL&&p==NULL)
      {
      p=find(x->sibling,k);
      }
  return p;
 }

int decrease_key(struct node* H,int i,int k)
 {
    int temp;
    struct     node* p;
    struct node* y;
    struct node* z;
    p=find(H,i);
    if(p==NULL)
      {
       printf("\nNo such entry found");
       return 0;
      }
 if(k>p->n)
 {
      printf("\nKey greater please enter valid entry");
      return 0;
  }
 p->n=k;
 y=p;
 z=p->parent;
 while(z!=NULL&&y->n<z->n)
  {
    temp=y->n;
    y->n=z->n;
    z->n=temp;
    y=z;
    z=z->parent;
  }
  printf("\nReduced successfully!");
}

int delete(struct node* H,int k)
{
  struct  node* np;
  if(H==NULL)
  {
      printf("\nEmpty");
      return 0;
   }

 decrease_key(H,k,-1000);
 np=get_min(H);
 if(np!=NULL)
 printf("\nDeleted successfully");
}

int main()
{
    int i,n,m,l;
    struct node* p;
    struct node* np;
    char ch;   
     printf("\nEnter number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=1;i<=n;i++)
    {
      scanf("%d",&m);
      np=create(m);
      H=insert(H,np);
    }
    display(H);
    do
     {
    printf("\nMENU:-\n");
    printf("\n1)Insert an element\n2)Extract min key\n3)decrease key\n4)delete\n5)Display\n6)Exit\n");
    scanf("%d",&l);
    switch(l)
      {
        case 1:do
            {
        printf("\nEnter THE element to be inserted:");
        scanf("%d",&m);
        p=create(m);
        H=insert(H,p);
        printf("\nHeap till Now:\n");
        display(H);
        printf("\nInsert more(y/Y)= \n");
        fflush(stdin);
        scanf("%c",&ch);
            }while(ch=='Y'||ch=='y');
         break;
        case 2:do
            {
        printf("\nExtract the minimum key");
        p=get_min(H);
        if(p!=NULL)
         printf("\nThe node extracted is %d",p->n);
        printf("\nHeap till now:\n");
        display(H);
        printf("\nExtract more(y/Y)\n");
        fflush(stdin);
        scanf("%c",&ch);
            }while(ch=='Y'||ch=='y');
        break;
        case 3:do
            {
        printf("\nEnter key to be decreased:");
        scanf("%d",&m);
        printf("\nEnter new key : ");
        scanf("%d",&l);
        decrease_key(H,m,l);
        printf("\nHeap till now:\n");
        display(H);
        printf("\nDecrease more(y/Y)\n");
        fflush(stdin);
        scanf("%c",&ch);
             }while(ch=='Y'||ch=='y');
        break;
        case 4:do
            {
        printf("\nEnter key to be deleted: ");
        scanf("%d",&m);
        delete(H,m);
        printf("\nDelete more(y/Y)\n");
        fflush(stdin);
        scanf("%c",&ch);
            }while(ch=='y'||ch=='Y');
        break;
        case 5:
          display(H);
          break;
        case 6:printf("\nExiting\n");break;
        default :printf("\nNo such option found\n");
      }
  }while(l!=6);
}
