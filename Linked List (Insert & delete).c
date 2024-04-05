/* Not a LeetCode question. This code, just helps to practice linked lists (Inserton and deletion) */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
int data;
struct node * link;
};

int menu(){
    int in=0;

    printf("Press 0 to exit\n");
    printf("Press 2 to count the number of nodes in the linked list\n");
    printf("Press 3 to print the data at each node in the linked list\n");
    printf("Press 4 to inset a number at the beginning of list\n");
    printf("Press 5 to inset a number at the end of list\n");
    printf("Press 6 to inset a number at the nth position of list\n");
    printf("Press 7 to delete number at the beginning of list\n");
    printf("Press 8 to delete number at the end of list\n");
    printf("Press 9 to delete a number at the nth position of list\n");
    printf("Press 10 to delete the whole list\n");

    scanf("%d",&in);

    return in;
}

int count_nodes(struct node *head){
    int count=0;

    struct node *current=NULL;
    current = head;
    if(current==NULL){
        printf("Linked list is empty");
    }
    while(current!=NULL){
       count++;
       current = current->link;
    }

    return count;
}

void print_data_at_nodes(struct node* head){
    struct node *ptr =NULL;
    ptr=head;

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
    printf("\n");
}

struct node* insert_beginning(int in, struct node* head){
    struct node *ptr=NULL;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=in;
    ptr->link=NULL;

    ptr->link=head;
    head=ptr;
    printf("New linked list is:\n");

    print_data_at_nodes(head);
    return head;
}

struct node* insert_end(int in, struct node* head){
    struct node *ptr = NULL;
    struct node *temp = NULL;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data=in;
    temp->link=NULL;

    ptr=head;
    if(head==NULL){
        head = insert_beginning(in, head);
        ptr=NULL;
    }
    else{
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=temp;
    }

    printf("New linked list is:\n");
    print_data_at_nodes(head);
    return head;
}

struct node* insert_nth_position(int pos, int in, struct node* head){
    if((count_nodes(head)+1)<pos){
        printf("List is not that long! Wrong entry!");
    }
    else if(pos==1){
        head = insert_beginning(in, head);
    }
    else{
        struct node* ptr=NULL;
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=in;
        ptr->link=NULL;

        struct node* temp=NULL;
        temp=head;

        for(int i=1;i<(pos-1);i++){
            temp=temp->link;
        }

        ptr->link=temp->link;
        temp->link=ptr;
    }

    printf("New linked list is:\n");
    print_data_at_nodes(head);
    return head;
}

struct node* delete_begining(struct node* head){
    struct node * temp;
    temp=head;

    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        head=head->link;
        free(temp);
        temp=NULL;
    }
    printf("New linked list is:\n");
    print_data_at_nodes(head);
    return head;
}

struct node* delete_last_node(struct node* head){
    struct node * temp;
    temp=head;

    if(head==NULL){
        printf("List is empty\n");
    }
    else if(temp->link==NULL){
        free(temp);
        temp=NULL;
        head=NULL;
    }
    else{
        while(temp->link->link!=NULL){
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
    }
    printf("New linked list is:\n");
    print_data_at_nodes(head);
    return head;
}

struct node* delete_nth_node(int pos, struct node* head){
    struct node* temp=NULL;
    struct node* temp2 =NULL;
    temp=head;

    if (pos>count_nodes(head)){
        printf("Wrong entry! List is not that long\n");
    }
    else if(pos==1){
        head = delete_begining(head);
    }
    else if(pos==count_nodes(head)){
        head = delete_last_node(head);
    }
    else{
        for(int i=1;i<pos-1; i++){
            temp=temp->link;
        }
        temp2=temp->link;
        temp->link=temp2->link;
        free(temp2);
        temp2=NULL;
    }
    printf("New linked list is:\n");
    print_data_at_nodes(head);
    return head;
}

struct node* delete_entire_linkedlist(struct node * head){
    struct node * temp= NULL;
    temp=head;

    if(head==NULL){
        printf("Linked list is empty!!\n\n");
    }
    else{
        while(temp->link!=NULL){
            temp=temp->link;
            free(head);
            head=temp;
        }
        free(head);
        head=NULL;
        temp=NULL;

        printf("Linked list is deleted!!\n\n");
    }

    return (head);
}

int main(){
    int in=0, count=0, num=0, pos=0;
    int pressed_menu_option=0;
    bool exit_requested = false;

    printf("Enter the first number to create a linked list\n");
    scanf("%d",&in);

    struct node *head=NULL;
    head = (struct node*) malloc(sizeof(struct node));

    head->data=in;
    head->link=NULL;
    printf("\n");

    while(!exit_requested){
        pressed_menu_option = menu();

        switch(pressed_menu_option){
        case 0:
            exit_requested = true;
            break;

        case 2:
            count=count_nodes(head);
            printf("Number of nodes present: %d\n", count);
            printf("\n");
            break;

        case 3:
            print_data_at_nodes(head);
            break;

        case 4:
            scanf ("%d", &num);
            head = insert_beginning(num, head);
            break;

        case 5:
            scanf ("%d", &num);
            head = insert_end(num,head);
            break;

        case 6:
            printf("Insert at what position?\n");
            scanf ("%d", &pos);
            printf("What number to insert?\n");
            scanf ("%d", &num);
            head = insert_nth_position(pos, num, head);
            break;

        case 7:
            head = delete_begining(head);
            break;

        case 8:
            head = delete_last_node(head);
            break;

        case 9:
            printf("Delete at what position?\n");
            scanf ("%d", &num);
            head = delete_nth_node(num, head);
            break;

        case 10:
            head = delete_entire_linkedlist(head);
            break;

        default:
            printf("Wrong entry! Enter again.\n\n");
            menu();
            break;
        }
    }

    return 0;
}
