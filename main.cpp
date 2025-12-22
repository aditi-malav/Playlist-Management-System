#include<iostream>
#include<stack>
#include "playlist.h"
using namespace std;
stack<Node*> history;
void insertOperations(Node* & playlist){
    int ch;
    string song,ref;
    while(true){
        cout << "Insert / Delete\n";
        cout << "1 Add at head\n";
        cout << "2 Add at end\n";
        cout << "3 Add after song\n";
        cout << "4 Add before song\n";
        cout << "5 Delete song\n";
        cout << "0 Back\n";

        cin>>ch;
        cin.ignore(1000, '\n');

        if(ch==0) break;
        
        else if(ch==1){
            cout<<"Enter song name: ";
            getline(cin, song);
            playlist=addSongAtHead(playlist,song);
        }
        else if(ch==2){
            cout<<"Enter song name: ";
            getline(cin, song);
            playlist=addSongAtEnd(playlist, song);
        }
        else if(ch==3){
            cout<<"Enter song after which you want to insert: ";
            getline(cin, ref);
            cout << "Enter new song name: ";
            getline(cin, song);
            playlist = addSongAfter(playlist,ref, song);
        }
        else if(ch==4){
            cout<<"Enter song before which you want to insert: ";
            getline(cin, ref);
            cout << "Enter new song name: ";
            getline(cin, song);
            playlist = addSongBefore(playlist, ref, song);
        }
        else if(ch==5){
            cout << "Enter song name to delete: ";
            getline(cin, song);
            playlist = deleteSong(playlist, song);
        }
        
        else{
            cout<<"Invalid Operation"<<endl;
        }
        

    }
}
void transformOperations(Node*& playlist){
    int ch;
    while(true){
        cout << "Transform\n";
        cout << "1 Shuffle\n";
        cout << "2 Reverse\n";
        cout << "3 Remove duplicates\n";
        cout << "4 Undo\n";
        cout << "0 Back\n";

        cin>>ch;

        if(ch==0) break;

        else if(ch==1){
            history.push(clonePlaylist(playlist)); 
            playlist = shufflePlaylist(playlist);
            cout << "Playlist shuffled\n";
        }
        else if(ch==2){
            history.push(clonePlaylist(playlist));
            playlist = reversePlaylist(playlist);
            cout << "Playlist reversed\n";
        }
        else if(ch==3){
            history.push(clonePlaylist(playlist));
            playlist = removeDuplicates(playlist);
             cout << "Duplicates removed\n";
        }
        else if(ch==4){
            if(history.empty()){
                cout<<"Nothing to undo\n";
            }
            else{
                freePlaylist(playlist);
                playlist=history.top();
                history.pop();
                cout <<"Undo successful\n";
            }
        }
        else{
            cout<<"Invalid Operation"<<endl;
        }
    }
}
void analyzeOperations(Node* playlist){
    int ch;
    while(true){
        cout << "Analyze\n";
        cout << "1 Size\n";
        cout << "2 Check loop\n";
        cout << "3 Loop length\n";
        cout << "4 Loop start\n";
        cout << "0 Back\n";
        cin>>ch;
        if(ch==0) break;
        else if(ch==1){
            cout<<"Size:" << playlistSize(playlist) << endl;
        }
        else if(ch==2){
            if(hasloop(playlist)) cout << "Loop exists\n";
            else cout << "No loop\n";
        }
        else if(ch==3){
            cout << loopLength(playlist) << endl;
        }
        else if(ch==4){
            Node* st = findLoopStart(playlist);
            if(st) cout << "Loop starts at: " << st->songName << endl;
            else cout << "No loop\n";
        }
        else{
            cout<<"Invalid Operation"<<endl;
        }

    }
}
int main(){
    Node* playlist=NULL;
    int choice;
    

    while(true){
    cout<<"Operations you can perform"<<endl;
    cout<<"1.Insert / Delete"<<endl;
    cout<<"2.Transform"<<endl;
    cout<<"3.Analyse"<<endl;
    cout<<"4.Print playlist"<<endl;
    cout<<"0. Exit"<<endl;
    
    cin>>choice;
    if(choice==0){
         freePlaylist(playlist);
         while(!history.empty()){
            freePlaylist(history.top());
            history.pop();
         }
        break;
    } 
    if(choice==1){
        insertOperations(playlist);
    }
    else if(choice==2){
        transformOperations(playlist);
    }
    else if(choice==3){
        analyzeOperations(playlist);
    }
    else if(choice==4){
        printPlaylist(playlist);
    }
    else{
        
        cout<<"Invalid Operation"<<endl;
    }
    }
    return 0;
}