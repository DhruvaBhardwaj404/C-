#include<iostream>
using namespace std;

struct node{
    int data;
    node *next=nullptr;
};

void insert_node_at_start(int val,node **start,unsigned int &s){
    node *temp=new node;
    temp->next=*start;
    temp->data=val;
    *start=temp;
    s++;
}

bool search_list( node **start,int val){
    node *temp=*start;
    unsigned int index=0;

    while(temp!=nullptr){
        if(temp->data == val){
            cout<<"Found at := "<<index<<"  Data->"<<temp->data<<endl;
            return true;
        }

        index++;
        temp=temp->next;
    }
    return false;
}

void get_middle(node **start,unsigned int size_list){
    unsigned int curr=1;
    node *temp=*start;

    if(size_list%2!=0)
        size_list++;

    while(curr<=size_list/2){
        if(curr==size_list/2){
            cout<<"Middle element = "<<temp->data<<endl;
        }
        curr++;
        temp=temp->next;
    }
}


int main(){
 node *start=nullptr;
 unsigned int size_list=0;
 insert_node_at_start(10,&start,size_list);
 insert_node_at_start(20,&start,size_list);
 insert_node_at_start(30,&start,size_list);
 insert_node_at_start(40,&start,size_list);
 insert_node_at_start(50,&start,size_list);
 insert_node_at_start(60,&start,size_list);
 insert_node_at_start(70,&start,size_list);

 search_list(&start,10);

 get_middle(&start,size_list);
}
