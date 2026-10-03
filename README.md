# Music Playlist

A simple C++ console application that manages a music playlist using a circular doubly linked list.

## Features

- Add a song with a name, artist, and duration
- Delete a song by name
- Play the current song
- Move to the next and previous songs
- Play a song by its name
- Display the entire playlist
- Exit the application

## Project Overview

This project demonstrates core data structure concepts in C++:

- Circular doubly linked list implementation
- Dynamic memory management
- Menu-driven console interface
- Basic playlist operations

## How it works

The `Playlist` class stores songs in a circular doubly linked list, where each `Song` node contains:

- song name
- artist
- duration
- pointers to the previous and next song

This allows seamless navigation across the playlist in both directions.

## Run the project

1. Open a terminal in the project directory.
2. Compile the program:

```bash
g++ musicplaylist.cpp -o musicplaylist
```

3. Run the compiled program:

```bash
./musicplaylist
```

## Example menu

```text
========== PLAYLIST ==========
1. Add Song
2. Delete Song
3. Next Song
4. Previous Song
5. Play Current Song
6. Play Song By Name
7. Display Playlist
8. Exit
```

## File structure

- `musicplaylist.cpp` - main program containing the playlist logic and interactive menu

## License

This project is a simple educational C++ program and is intended for learning and personal use.
