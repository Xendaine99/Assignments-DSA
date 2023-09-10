#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
   
};
void insertathead(node* &head,node* &tail,int d)
{   if(head==NULL)
    {
    node*temp=new node(d);
    head=temp;
    tail=temp;
    }
    else{
    node*temp=new node(d);
    temp ->next=head;
    head->prev=temp;
    head=temp;}
}
void insertattail(node* &head,node* &tail,int d)
{   if(tail==NULL)
   {
    node*temp=new node(d);
    tail=temp;
    head=temp;
   }
   else{
    node*temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;}
}
void print(node* &head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertatposition(node*&head,node*&tail,int position,int d)
{
    if(position==1)
    {
        insertathead(head,tail,d);
        return;
    }
    node*temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertattail(head,tail,d);
        return;
    }
    //creating a node for d
    node*nodetoinsert=new node(d);
    temp->next->prev=nodetoinsert;
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}
void deletenode(int position,node*&head)
{
   if(position==1)
   {
       node*temp=head;
       temp->next->prev=NULL;
       head=temp->next;
       temp->next=NULL;
       delete temp;
   }
   else
   {
    node* curr=head;
    node* prev=NULL;
    int cnt=1;
    while(cnt<position)
    {
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    curr->prev=NULL;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
   }
}

int main()
{
    node*node1=new node(10);
    node*head=NULL;
    node*tail=NULL;
    print(head);
    insertattail(head,tail,13);
    print(head);
    cout<<"Inserting at tail"<<endl;
    insertattail(head,tail,14);
    print(head);
    insertattail(head,tail,15);
    print(head);
    cout<<"Inserting at head"<<endl;
    insertathead(head,tail,12);
    print(head);
    insertathead(head,tail,11);
    print(head);
    insertathead(head,tail,10);
    print(head);
    cout<<"Inserting at specific position"<<endl;
    insertatposition(head,tail,7,56);
    print(head);
    cout<<"Deleting a node"<<endl;
    deletenode(3,head);
    print(head);
    return 0;
}