void enqueue(int n)
{
if(rear=max-1)
{
    printf("full");
}
else{
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=n;
    printf("inserted %D",n);

}
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Empty");
    }
    else{
        printf("element dequed %d",queue[front]);
        front++;
        if(front>rear)
        {
            front=-1;
            rear=-1;

        }
    }
}
void display()
{
     if(front==-1 || front>rear)
    {
        printf("Empty");
    }
    else{
        for(int i=front;i<rear;i++)
        {
            printf("%d",queue[i]);
        }
        printf("\n");
    }
}

void peek()
{
   if(front==-1 || front>rear)
    {
        printf("Empty");
    }
    else
    {
        printf("element is %D",queue[front]);
    } 
}