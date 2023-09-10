#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    ~node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data : "<<value<<endl;
    }
};
void insertathead(node* &head,int d)
{
    node*temp=new node(d);
    temp ->next=head;
    head=temp;
}
void insertattail(node* &tail,int d)
{
    node*temp=new node(d);
    tail ->next=temp;
    tail=temp;
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
void insertatposition(node*&tail,node*&head,int position,int d)
{   
    if(position==1)
    {
        insertathead(head,d);
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
        insertattail(tail,d);
        return;
    }
    node* nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}
void deletenode(int position,node*&head)
{
   if(position==1)
   {
       node*temp=head;
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
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
   }
}
int main()
{
     node*node1=new node(10);
    node*head=node1;
     node*tail=node1;
     print(head);
     cout<<"Adding at head"<<endl;
     insertathead(head,9);
     print(head);
      insertathead(head,8);
     print(head);
    insertathead(head,7);
     print(head);
      insertathead(head,6);
     print(head);
      insertathead(head,5);
     print(head);
     cout<<"Adding at tail"<<endl;
     insertattail(tail,11);
      print(head);
     insertattail(tail,12);
     print(head);
      insertattail(tail,13);
     print(head);
     cout<<"Adding at specific position"<<endl;
     insertatposition(tail,head,10,14);
     print(head);
      cout<<"deletin a node"<<endl;
     deletenode(3,head);
     print(head);
     return 0;
}