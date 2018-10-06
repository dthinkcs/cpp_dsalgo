#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class dnode{
    int data=0;
    dnode *prev;
    dnode *next;
    public:
    dnode(dnode*,dnode*){
    prev = NULL;
    next = NULL;
    }
    dnode(){}
    dnode* createnode(dnode*);
    void display(dnode *);
    dnode* ins_be(dnode *);
    dnode* ins_af(dnode *);
    dnode* del_sp(dnode *);
};
dnode* dnode::del_sp(dnode *header){
    int x;
    dnode* cur=header -> next;
    cout<<"enter node to delete:";
    cin>>x;

    while(cur!=NULL){
        if(cur->data == x){
            cur->prev->next=cur->next;
            cur->next->prev=cur->prev;
            delete(cur);
        }
            cur = cur->next;

    }
    return header;
}
dnode* dnode::ins_be(dnode *header){
    int x,y;
    dnode *cur;
    cout<<"enter node to be inserted before:";
    cin>>x;
    cout<<"enter node:";
    cin>>y;
    dnode *temp = new dnode();
    temp->data = y;
    cur=header->next;
    while(cur!=NULL){
    if(cur->data == x)
    {temp->prev = cur->prev;
     temp ->next = cur;
     cur->prev->next = temp;
     cur->prev = temp;
     }
     cur = cur->next;
    }
    return header;
}
dnode* dnode::createnode(dnode *header){
    int x;
    do{
        cout<<"enter the node(-1 to exit):";
        cin>>x;
        if(x==-1)
            return header;
        dnode *temp = new dnode();
        temp->data = x;
        temp->next = NULL;
        temp->prev = NULL;
        if(header->next == NULL){
            header->next = temp;
            temp->prev = header;
        }
        else{
            temp->next = header->next;
            temp->prev = header;
            header->next->prev=temp;
            header->next = temp;

        }
    }while(1);
    return header;
}
void dnode::display(dnode *header){

    for(dnode *i = header->next; i!=NULL; i= i->next)
        cout<<i->data<<"->";
    cout<<"\n";
}

main(){
    int x;
    dnode k;
    dnode* header = new dnode(NULL,NULL);

    header = k.createnode(header);

    do{

        cout<<"1.Ins_be 2.Display 3.delete 4.ins_ele 5.exit";
        cin>>x;
        switch (x){
        case 1:k.ins_be(header);
                break;
        case 2:k.display(header);
                break;
        case 3:k.del_sp(header);
                break;
        case 4:
                break;
        case 5:exit(0);
        default:cout<<"Invalid input";
        }
    }while (1);
}
