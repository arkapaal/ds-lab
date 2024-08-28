#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int exponent;
    int coefficient;
    struct node * next;
}node;
void CreatePolynomial(node ** h){
    int n;
    printf("Enter the highest degree of polynomial: ");
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        node * newnode=(node*)malloc(sizeof(node));
        newnode->exponent=i;
        printf("Enter the coefficient of x^%d: ",i);
        scanf("%d",&newnode->coefficient);
        newnode->next=NULL;
        if(i==n){
            *h=newnode;
        }
        else{
            node * temp;
            for(temp=*h;temp->next!=NULL;temp=temp->next);
            temp->next=newnode;
        }
    }
}
void DisplayPoly(node *h){
    node * temp;
    for(temp=h;temp!=NULL;temp=temp->next){
        printf(" %dx^%d ",temp->coefficient,temp->exponent);
        if(temp->next!=NULL)printf("+");
    }
    return;
}
void MultiplyPolynomial(node*h1,node*h2,node ** h3){
    node *temp1,*temp2;
    for(temp1=h1;temp1!=NULL;temp1=temp1->next){
        for(temp2=h2;temp2!=NULL;temp2=temp2->next){
            node * newnode=(node*)malloc(sizeof(node));
            newnode->exponent=temp1->exponent+temp2->exponent;
            newnode->coefficient=temp1->coefficient*temp2->coefficient;
            if(*h3==NULL){
                *h3=newnode;
            }
            else{
                node * temp;
                for(temp=*h3;temp->next!=NULL;temp=temp->next);
                temp->next=newnode;
            }
        }
    }
    printf("Resultant Polynomial: ");
    DisplayPoly(*h3);
    return;

}



void AddPolynomial(node ** h1,node**h2){
    node * temp1,*temp2,*result=NULL;
    temp1=*h1;
    temp2=*h2;
    while(temp1!=NULL&&temp2!=NULL){
        node * newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        if(temp1->exponent>temp2->exponent){
            newnode->exponent=temp1->exponent;
            newnode->coefficient=temp1->coefficient;
            if(result==NULL){
                result=newnode;
            }
            else{
                node * temp;
                for(temp=result;temp->next!=NULL;temp=temp->next);
                temp->next=newnode;
            }
            temp1=temp1->next;
        }
        else if(temp1->exponent<temp2->exponent){
            newnode->exponent=temp2->exponent;
            newnode->coefficient=temp2->coefficient;
            if(result==NULL){
                result=newnode;
            }
            else{
                node * temp;
                for(temp=result;temp->next!=NULL;temp=temp->next);
                temp->next=newnode;
            }
            temp2=temp2->next;
        }
        else{
            newnode->exponent=temp1->exponent;
            newnode->coefficient=temp1->coefficient+temp2->coefficient;
            if(result==NULL){
                result=newnode;
            }
            else{
                node * temp;
                for(temp=result;temp->next!=NULL;temp=temp->next);
                temp->next=newnode;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        node * newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->coefficient=temp1->coefficient;
        newnode->exponent=temp1->exponent;
        if(result==NULL){
            result=newnode;
        }
        else{
            node * temp;
            for(temp=result;temp->next!=NULL;temp=temp->next);
            temp->next=newnode;
        }

    }
    while(temp2!=NULL){
        node * newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->coefficient=temp2->coefficient;
        newnode->exponent=temp2->exponent;
        if(result==NULL){
            result=newnode;
        }
        else{
            node * temp;
            for(temp=result;temp->next!=NULL;temp=temp->next);
            temp->next=newnode;
        }

    }
    printf("Resultant polynomial: ");
    DisplayPoly(result);
    return;
}



int main(){
    int ch;
    node *head1=NULL;
    node * head2=NULL;
    node*head3=NULL;
    printf("Enter polynomial 1\n");
    CreatePolynomial(&head1);
    printf("Enter polynomial 2\n");
    CreatePolynomial(&head2);
    do{
        printf("\n1.Add\n2.Multiply\n3.Display both polynomials\n4.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            AddPolynomial(&head1,&head2);
            break;
            case 2:
            MultiplyPolynomial(head1,head2,&head3);
            break;
            case 3:
            DisplayPoly(head1);
            printf("\n");
            DisplayPoly(head2);
            break;

            case 4:
            printf("Exiting the program...");
            break;
            
            default:
            printf("Invalid choice");
            break;
        }

    }while(ch!=4);


    return 0;
}