#include<iostream>

using namespace std;

struct node {
    int data;
    node *next=nullptr,*prev=nullptr;
};

class c_list{
    node *start=nullptr,*prev=nullptr;
    unsigned int size=0;
    public:
        void add_start(int val){
            if(start==nullptr){
                node *temp=new node;
                temp->data=val;
                start=temp;
                prev=temp;
                temp->next=start;
                temp->prev=start;
                size=1;
            }
            else{
                node *temp=new node;
                start->prev=temp;
                temp->data=val;
                temp->next=start;
                temp->prev=prev;
                start=temp;
                size++;
            }
        }

    void traverse_for(){
        node *temp=start;
        int curr=1;
        cout<<endl;
        while(curr<=size){
            cout<<temp->data<<" ";
            curr++;
            temp=temp->next;
        }
            cout<<endl;
    }

    void traverse_back(){
        node *temp=prev;
        int curr=1;
        cout<<endl;
        while(curr<=size){
            cout<<temp->data<<" ";
            curr++;
            temp=temp->prev;
        }
            cout<<endl;
    }

    void get_info(){
        cout<<start<<" "<<prev<<" "<<size;
    }

    void split(c_list &l1,c_list &l2){
            //cout<<"here1";
        if(start==prev){
            cout<<"not possible\n";
        }

        else{
            int curr=1;
            l1.start=start;
            l2.prev=prev;
            l1.size=size/2;
            l2.size=size-(size/2);
            //cout<<l1.size<<" "<<l2.size<<"\n";
            node *temp1,*temp2;
            temp1=start;

            while(curr<=size){
                temp2=temp1;
                temp1=temp1->next;

                if(curr==size/2){
                    l1.prev=temp2;
                    temp2->next=start;
                    l1.start->prev=temp2;
                }

                else if(curr==(size/2)+1){
                    l2.start=temp2;
                    temp2->prev=prev;
                }

                else if(curr==size){
                    temp2->next=l2.start;
                    l2.start->prev=temp2;


                }

             curr++;

            }
        }
               // cout<<"here2";
    }
    // end of definition of spilt
};

int main(){
    c_list *c1=new c_list;
    c_list c2,c3;

    c1->add_start(10);
    c1->add_start(20);
    c1->add_start(30);
    c1->add_start(40);
    c1->add_start(50);
    c1->add_start(60);
    c1->add_start(70);
    c1->add_start(80);
    c1->traverse_for();
    c1->traverse_back();
    c1->split(c2,c3);
    delete c1;
    cout<<"c2\n";
    c2.add_start(90);
    c2.traverse_for();
    c2.traverse_back();
    cout<<"c3\n";
    c3.add_start(100);
    c3.traverse_for();
    c3.traverse_back();
}
