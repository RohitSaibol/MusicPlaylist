#include <iostream>
#include<string>

using namespace std;

class Song{
    public:
        string name;
        float duration;
        string artist;

        Song* next;
        Song* prev;

    public:
        Song(string na,string art,float du){
            name=na;
            artist=art;
            duration=du;

            next=NULL;
            prev=NULL;
        }
};


class Playlist{
    private:
        Song* head;
        Song* current;
        Song* last;

    public:

        Playlist() {
            head = NULL;
            last = NULL;
            current = NULL;
        }


        // ---------------- ADD SONG ----------------
        void addSong(string name , string artist , float duration){

            if(head==NULL){

                Song* newSong= new Song(name , artist , duration );

                head=newSong;
                last=newSong;
                current=newSong;

                head->next=newSong;
                head->prev=newSong;
            }

            else{

                Song* newSong= new Song(name , artist , duration );

                head->prev=newSong;
                last->next=newSong;

                newSong->next=head;
                newSong->prev=last;

                last=newSong;
                current=newSong;
            }
        }


        // ---------------- DELETE SONG ----------------
        void delSong(string name){

            Song* mover=head;

            if(mover==NULL){
                cout<<"No song in Playlist ^_^ \n";
                return;
            }

            while(true){

                if(mover->name==name){

                    cout<<"Song found and deleted :-<3\n";

                    if(head==last){

                        delete mover;

                        head=NULL;
                        last=NULL;
                        current=NULL;

                        return;
                    }


                    Song* previous = mover->prev;
                    Song* nextSong = mover->next;

                    if(mover==head){

                        head=nextSong;

                        head->prev=last;
                        last->next=head;
                    }

                    else if(mover==last){

                        last=previous;

                        last->next=head;
                        head->prev=last;
                    }

                    else{

                        previous->next=nextSong;
                        nextSong->prev=previous;
                    }

                    if(current==mover){
                        current=head;
                    }


                    mover->next=NULL;
                    mover->prev=NULL;

                    delete mover;

                    return;
                }


                mover=mover->next;


                if(mover==head){
                    break;
                }
            }

            cout<<"song NOT found !!! (Write correct Spelling or other song ^_^)\n";
        }


        // ---------------- PLAY CURRENT ----------------
        void playCurrent(){

            if (current == NULL) {
                cout << "Playlist is empty!" << endl;
                return;
            }

            cout << "\nNow Playing:" << endl;
            cout << "Song: " << current->name << endl;
            cout << "Artist: " << current->artist << endl;
            cout << "Duration: " << current->duration << " minutes" << endl;
        }


        // ---------------- NEXT SONG ----------------
        void playNextSong(){

            if(current==NULL){
                cout<<"Playlist is EMPTY : ^_^\n";
                return;
            }

            current=current->next;

            playCurrent();
        }


        // ---------------- PREVIOUS SONG ----------------
        void playPrevious(){

            if(current==NULL){
                cout<<"Playlist is EMPTY : ^_^\n";
                return;
            }

            current=current->prev;

            playCurrent();
        }


        // ---------------- PLAY SONG BY NAME ----------------
        void playSong(string name){

            Song* mover = head;

            if(mover==NULL){
                cout<<"Empty PlayList || Add Songs <3 \n";
                return;
            }

            while(true){

                if(mover->name==name){

                    current=mover;

                    playCurrent();

                    return;
                }

                mover=mover->next;

                if(mover==head){
                    break;
                }
            }

            cout<<"Song NOT found || REtry with correct spelling : ^_^ \n";
        }


        // ---------------- DISPLAY PLAYLIST ----------------
        void displayPlaylist(){

            if(head==NULL){

                cout<<"Empty PlayList || Add Songs <3 \n";

                return;
            }

            Song* mover = head;

            while(true){

                cout << "Song: " << mover->name << endl;
                cout << "Artist: " << mover->artist << endl;
                cout << "Duration: " << mover->duration << " minutes" << endl;

                mover = mover->next;

                if (mover == head) {
                    break;
                }
            }
        }

};


int main(){

    Playlist RohitPlayList;


    RohitPlayList.addSong("brand new day", "rohit", 5.00);
    RohitPlayList.addSong("tokyo drift", "F&F", 4.16);


    int choice = 0;

    string name;
    string artist;
    float duration;


    while(choice != 8){

        cout << "\n========== PLAYLIST ==========\n";

        cout << "1. Add Song" << endl;
        cout << "2. Delete Song" << endl;
        cout << "3. Next Song" << endl;
        cout << "4. Previous Song" << endl;
        cout << "5. Play Current Song" << endl;
        cout << "6. Play Song By Name" << endl;
        cout << "7. Display Playlist" << endl;
        cout << "8. Exit" << endl;


        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice){

            // ADD SONG
            case 1:

                cin.ignore();

                cout << "Enter song name: ";
                getline(cin, name);

                cout << "Enter artist name: ";
                getline(cin, artist);

                cout << "Enter duration: ";
                cin >> duration;

                RohitPlayList.addSong(name, artist, duration);
                cout<<endl;

                break;


            // DELETE SONG
            case 2:

                cin.ignore();
                RohitPlayList.displayPlaylist();
                cout<<endl;

                cout << "Enter song name to delete: ";
                getline(cin, name);

                RohitPlayList.delSong(name);
                cout<<endl;

                break;


            // NEXT SONG
            case 3:

                RohitPlayList.playNextSong();
                cout<<endl;

                break;


            // PREVIOUS SONG
            case 4:

                RohitPlayList.playPrevious();
                cout<<endl;

                break;


            // CURRENT SONG
            case 5:

                RohitPlayList.playCurrent();
                cout<<endl;

                break;


            // PLAY SONG BY NAME
            case 6:

                cin.ignore();

                cout << "Enter song name: ";
                getline(cin, name);

                RohitPlayList.playSong(name);
                cout<<endl;

                break;


            // DISPLAY PLAYLIST
            case 7:

                RohitPlayList.displayPlaylist();
                cout<<endl;

                break;


            // EXIT
            case 8:

                cout << "Exiting playlist..." << endl;
                cout<<endl;

                break;


            default:

                cout << "Invalid choice!" << endl;
                cout<<"\n"<<endl;
        }
    }
    return 0;
}
