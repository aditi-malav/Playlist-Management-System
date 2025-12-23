#include "playlist.h"
#include <iostream>
#include<unordered_set>
#include<string>

using namespace std;
Node::Node(string name){
    songName=name;
    next=NULL;
}
Node* addSongAtHead(Node* head,string name){
   
    Node* k=new Node(name);
    k->next=head;
    
    return k;
}
Node* addSongAtEnd(Node* head,string name){
    Node* newNode=new Node(name);
    if(head==NULL) return newNode;
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
  
    return head;
}

Node* addSongAfter(Node* head,string afterSong,string newSong){
    if(head==NULL) return head;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->songName==afterSong){
            Node* newNode=new Node(newSong);
            newNode->next=temp->next;
            temp->next=newNode;
            break;

        }
        temp=temp->next;
    }
    return head;
}
Node* addSongBefore(Node* head,string beforeSong,string newSong){
    if(head==NULL) return head;
    if(head->songName==beforeSong){
        return addSongAtHead(head,newSong);
    }
    Node* temp=head;

    while(temp->next!=NULL){
        if(temp->next->songName==beforeSong){
            Node* newNode=new Node(newSong);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
void printPlaylist(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->songName<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;



}
bool hasloop(Node* head){
    if(head==NULL || head->next==NULL) return false;
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
Node* findLoopStart(Node* head){
    if(head==NULL || head->next==NULL) return head;
     Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(slow!=fast) return NULL;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
Node* breakLoop(Node* head){
   if(!hasloop(head)) return head;
    Node* st=findLoopStart(head);
     
     Node* temp=st;
     while(temp->next!=st){
        
        temp=temp->next;
     }
    temp->next=NULL;
    return head;
     
}
int loopLength(Node* head){
    if(!hasloop(head)) return 0;
     Node* st=findLoopStart(head);
     int len=1;
     Node* temp=st;
     while(temp->next!=st){
        len++;
        temp=temp->next;
     }
     return len;
    
}

Node* findIntersection(Node* head1,Node* head2){
     Node* a=head1;
     Node*  b=head2;
    while(a!=b){
           
        a= (a==NULL) ? head2 : a->next;
        b= (b==NULL) ? head1 : b->next;
            
    }  
    return a;
}
Node* shufflePlaylist(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* t1=head;
    Node* t2=slow->next;
    slow->next=NULL;
    Node dummy("dummy");
    Node* temp=&dummy;
    while(t1 && t2){
        temp->next=t1;
        t1=t1->next;
        temp=temp->next;
        temp->next=t2;
        t2=t2->next;
    }
    while(t1){
        temp->next=t1;
        t1=t1->next;
        temp=temp->next;
    }
    while(t2){
        temp->next=t2;
        t2=t2->next;
        temp=temp->next;
    }
    return dummy.next;


}
Node* reversePlaylist(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
        }
    
    return prev;
}
Node *removeDuplicates(Node *head) {
        
    if(head==NULL || head->next==NULL) return head;
   
    unordered_set<string>s;
    Node* curr=head;
    Node* prev=NULL;
    while(curr){
        if(s.find(curr->songName)!=s.end()){
            Node* temp=curr;
            prev->next=curr->next;
            curr=curr->next;
            delete temp;
        }
        else{
            s.insert(curr->songName);
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
Node* deleteSong(Node* head,string song){
    if(head==NULL) return NULL;
    if(head->songName==song){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* prev=head;
    Node* curr=head->next;
    while(curr!=NULL){
        if(curr->songName==song){
            prev->next=curr->next;
            delete curr;
            return head;
            
        }
        
        prev=curr;
        
        curr=curr->next;
    }
    return head;
}
int playlistSize(Node* head){
   
    Node* curr=head;
    int len=0;
    while(curr){
        len++;
        curr=curr->next;
    }
    return len;
}
void freePlaylist(Node* head){
    while(head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
Node* clonePlaylist(Node* head){
    if(head == NULL) return NULL;

    Node* newHead = new Node(head->songName);
    Node* currOld = head->next;
    Node* currNew = newHead;

    while(currOld){
        currNew->next = new Node(currOld->songName);
        currNew = currNew->next;
        currOld = currOld->next;
    }
    return newHead;
}





