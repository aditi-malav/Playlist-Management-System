#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <unordered_set>
using namespace std;

struct Node{
    string songName;
    Node* next;
    Node(string name);
};

Node* addSongAtHead(Node* head,string name);
Node* addSongAtEnd(Node* head,string name);
Node* addSongAfter(Node* head,string afterSong,string newSong);
Node* addSongBefore(Node* head,string beforeSong,string newSong);
void printPlaylist(Node* head);

bool hasloop(Node* head);
Node* findLoopStart(Node* head);
Node* removeLoop(Node* head);
int loopLength(Node* head);
Node* findIntersection(Node* head1,Node* head2);

Node* shufflePlaylist(Node* head);
Node* reversePlaylist(Node* head);
Node* removeDuplicates(Node* head);
Node* deleteSong(Node* head,string song);
Node* clonePlaylist(Node* head);
int playlistSize(Node* head);
void freePlaylist(Node* head);
#endif


