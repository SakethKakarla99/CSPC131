#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Song{
  private:
    std::string title;
    std::string artist;
  public:
  //constructor for Song
  Song(std::string title, std::string artist){
    this->title = title;
    this->artist = artist;
  }
  std::string getTitle() const{
    return title;
  }
  std::string getArtist() const{
    return artist;
  }
};

class DLLNode{
  private:
    std::unique_ptr<Song> song;
    std::shared_ptr<DLLNode> prev;
    std::shared_ptr<DLLNode> next;
  public:
    DLLNode(std::unique_ptr<Song> song_):song(std::move(song_)){
    }
  void setPrev(std::shared_ptr<DLLNode> prev_){
    this->prev = prev_;
  }
  void setNext(std::shared_ptr<DLLNode> next_){
    this->next = next_;

  }
  std::shared_ptr<DLLNode> getPrev() const{
    return prev;
  }
  std::shared_ptr<DLLNode> getNext() const{
    return next;
  }
  Song* getSong() const{
    return song.get();
  }
    
};

class musicPlayer{
  private:
  std::shared_ptr<DLLNode> head;
  std::shared_ptr<DLLNode> tail;
  std::shared_ptr<DLLNode> current;
  public:
  //constructor 
  musicPlayer(){
    this->head = make_shared<DLLNode>(make_unique<Song>("null","null"));
    this->tail = make_shared<DLLNode>(make_unique<Song>("null","null"));
    this->head->setPrev(nullptr);
    this->head->setNext(tail);
    this->tail->setPrev(head);
    this->tail->setNext(nullptr);
    this->current = head;
   
  }

  void addSong(std::unique_ptr<Song> song_){
    //std::share_ptr<Song> songtemp;
    //songtemp = std::move(song_);
    if(head->getPrev() == tail){
      std::shared_ptr<DLLNode> temp = make_shared<DLLNode>(std::move(song_));
      temp->setNext(tail);
      temp->setPrev(tail->getPrev());
      tail->setPrev(temp);
      temp->getPrev()->setNext(temp);
      current = temp;
    }
    else{
      std::shared_ptr<DLLNode> temp = make_shared<DLLNode>(std::move(song_));
      temp->setNext(tail);
      temp->setPrev(tail->getPrev());
      tail->getPrev()->setNext(temp);
      tail->setPrev(temp);
      current = temp;
    }
    
  }

  void playSong(){
    std::cout << "Song: " << current->getSong()->getTitle() << " Artist: " << 
      current->getSong()->getArtist() << std::endl;
  }
  void playNext(){
    if(current->getNext() == tail){
      std::cout << "No more song to play! " << std::endl;
    }
    else{
      current = current->getNext();
      playSong();
    }
  }
  void playPrev(){
    if(current->getPrev() == head){
      std::cout << "No more songs to play! " << std::endl;
    }
    else{
      current = current->getPrev();
      playSong();
    }
  }
  void displayPlaylist(){
    
    std::shared_ptr<DLLNode> tempPlay;
    tempPlay = tail;
    while(tempPlay->getPrev() != head){
      tempPlay = tempPlay->getPrev();
      std::cout << "Song: " <<tempPlay->getSong()->getTitle();
      std::cout << " " << "Artist: " << tempPlay->getSong()->getArtist() << std::endl;
      
    }
    
    
  }



};

int main() {
  musicPlayer mp;
  char choice;
  std::string title;
  std::string artist;

  do{
    std::cout << "\nMusic Player Menu: " << std::endl;
    std::cout << "1. Add a Song" << std::endl;
    std::cout << "2. Play Current Song" << std::endl;
    std::cout << "3. Play Next Song" << std::endl;
    std::cout << "4. Play Previous Song" << std::endl;
    std::cout << "5. Display Playlist" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cin >> choice;

    switch(choice){
      case '1':
          std::cout << "Enter song title: ";
          std::cin.ignore();

          getline(std::cin,title);
          std::cout << "Enter artist name: ";
          getline(std::cin,artist);
          mp.addSong(std::make_unique<Song>(title,artist));
          std::cout << "Song added successfully!" << std::endl;
          break;
      case '2':
          std::cout << "Current Song: " << std::endl;
          mp.playSong();
          break;
      case '3':
          mp.playNext();
          break;
      case '4':
          mp.playPrev();
          break;
      case '5':
          std::cout<< "Current Playlist: " << std::endl;
          mp.displayPlaylist();
          break;
      case '6':
          std::cout << "Exiting..." << std::endl;
          break;
      default:
          std::cout <<"Invalid choice. Please enter a valid option." << std::endl;
    }
    
  } while(choice != '6');

  return 0;
  


}