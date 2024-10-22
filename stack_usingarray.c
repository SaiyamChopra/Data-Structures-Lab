#include <stdio.h>
int stack[20];
int top=-1;
void push()
{   int x;
printf("enter the value \n");
scanf("%d",&x);
    if(top==19){
        printf("overflow");
    }
    else{
     
        top++;
        stack[top]=x;
        printf("Pushed %d",x);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("underflow");
    }
    else{
        printf("Element removed %d",stack[top]);
        top--;
    }
}
void peek()
{ if(top==-1)
    {
        printf("underflow");
    }
    else{
        printf("Element is %d",stack[top]);
    }
}
void display()
{
     if(top==-1)
    {
        printf("underflow");
    }
    for(int i=top;i>0;i--)
    {
        printf(" \n%d",stack[i]);
    }
}
int main(){
    int choice;
    do{
        printf("------------------\n");
        printf("ENter the operation \n");
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Peek \n");
        printf("4.Display \n");
        printf("5.Exit \n");
        scanf("%d" ,&choice);
switch(choice)
{
    case 1:
    push();
    break;
    
    case 2:
    pop();
    break;

    case 3:
    peek();
    break;
    case 4:
    display();
    break;
    case 5:
     printf("Exiting...");
    break;
    default:
    printf("invakid no");
    break;
}
    }while(choice!=5);
return 0;
}

