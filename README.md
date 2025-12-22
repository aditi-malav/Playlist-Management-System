# Playlist-Management-System
*(Linked List Validation & Undo — C++)*

---

## Overview
- Implemented a playlist management system using a **singly linked list** in C++
- Focused on **data structure correctness, memory safety, and state recovery**
- Designed as a **system-oriented project**, emphasizing internal integrity over UI complexity

---

## Core Idea
- Model a playlist as a linked structure that undergoes multiple transformations
- Ensure the structure remains valid and recoverable after changes
- Distinguish clearly between:
  - **User-level operations** (playlist manipulation)
  - **System-level logic** (structural validation and safety)

---

## Loop Detection (System-Level Validation)
- Implemented **Floyd’s Cycle Detection Algorithm**
- Added utilities to:
  - detect a loop in the playlist
  - find the starting node of the loop
  - compute loop length
- Loops are **not created through user input**
- Treated as a **system-level safety feature** to detect structural corruption
- Aligned with how linked list cycle problems are modeled on platforms like **LeetCode**

---

## Undo Mechanism (State Recovery)
- Implemented undo using **state restoration**, not inverse operations
- Before each transformation:
  - a **deep copy snapshot** of the playlist is stored
- Snapshots managed using a **stack**
- Undo restores the most recent valid state
- All unused states are explicitly freed to avoid memory leaks

---

## Playlist Operations
- Add song:
  - at head
  - at end
  - before a given song
  - after a given song
- Delete song from any position
- Print playlist
- Supports song names with spaces (`getline`)

---

## Transformations
- Shuffle playlist
- Reverse playlist
- Remove duplicate songs

---

## Memory Management
- All nodes are dynamically allocated and explicitly deallocated
- `freePlaylist()` ensures safe cleanup
- Undo history is fully cleared on program exit
- Designed to avoid memory leaks and infinite traversal

---

## Project Structure

```text
.
├── playlist.h      // Node structure and function declarations
├── playlist.cpp    // Linked list logic, validation, undo support
├── main.cpp        // Menu-driven interface and user interaction
├── Makefile        // Build configuration
└── README.md
```
---

## ⏱️ Time & Space Complexity

| Operation | Time Complexity | Space Complexity |
|---------|-----------------|------------------|
| Add / Delete Song | O(n) | O(1) |
| Shuffle Playlist | O(n) | O(1) |
| Reverse Playlist | O(n) | O(1) |
| Remove Duplicates | O(n) | O(n) |
| Undo (State Restore) | O(n) | O(n) |
| Loop Detection (Floyd’s Algorithm) | O(n) | O(1) |
| Loop Start Detection | O(n) | O(1) |
| Loop Length Calculation | O(n) | O(1) |

---

## Key Learnings

- Practical understanding of **singly linked list internals**
- Safe pointer manipulation and traversal techniques
- Difference between **user-visible data** and **structural correctness**
- Designing **system-level validation** independent of user input
- Implementing undo using **state snapshots** instead of inverse operations
- Memory-safe programming with explicit allocation and deallocation
- Applying classical algorithms (Floyd’s cycle detection) in real systems
- Structuring medium-sized C++ projects with headers, source files, and build scripts

---

## Conclusion

This project demonstrates a system-oriented approach to linked list design in C++.  
Rather than focusing only on functionality, it emphasizes **correctness, safety, and recoverability**.

By separating user operations from system-level validation and using state-based undo,
the project reflects real-world engineering practices used in low-level systems.

It serves as a strong foundation for understanding data structure integrity,
memory management, and defensive programming.



