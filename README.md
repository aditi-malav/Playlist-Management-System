# Playlist-Management-System (C++)

## Overview
A menu-driven playlist management system implemented using a singly linked list.
The project emphasizes **structural correctness, controlled mutations, and safe state recovery**
rather than UI complexity.

Beyond basic playlist operations, the system includes **linked-list integrity validation**
and **self-healing mechanisms** to handle corrupted structures such as cycles.

---

## Code Organization & Responsibilities

### `playlist.h`
- Defines the `Node` structure
- Declares all playlist-related functions
- Acts as the interface between `main.cpp` and `playlist.cpp`

---

### `playlist.cpp` — Core Logic
Contains all linked list operations, validation utilities, and memory-management logic.

---

#### Playlist Construction & Modification
- `addSongAtHead`
- `addSongAtEnd`
- `addSongBefore`
- `addSongAfter`
- `deleteSong`

These functions mutate the linked list while maintaining pointer correctness.

---

#### Playlist Transformations
- `shufflePlaylist`
- `reversePlaylist`
- `removeDuplicates`

These are **destructive operations** that alter the playlist structure and are therefore
integrated with the **undo mechanism**.

---

#### Structural Validation Utilities
- `hasLoop`
- `findLoopStart`
- `loopLength`
- `breakLoop` 
- `findIntersection`

These functions are **system-level utilities**, independent of user input.
They are inspired by classical linked-list problems and are used to:

- Detect unintended cycles
- Analyze loop characteristics
- Restore the playlist to a valid linear state

Although a playlist is not expected to contain cycles during normal operation,
loop-handling utilities were intentionally added to handle **structural corruption scenarios**
such as accidental pointer misuse, faulty transformations, or future feature extensions.

In particular, `breakLoop` restores list integrity by identifying the loop start
(using Floyd’s cycle detection), traversing the cycle to locate the final node,
and breaking the loop **without deleting any nodes**, ensuring the playlist can
self-recover instead of crashing or entering infinite traversals.

---

#### Memory Management
- `freePlaylist`

Ensures:
- all dynamically allocated nodes are deleted
- no memory leaks occur during undo or program exit

---

## Undo Mechanism (State Restoration)

Undo is implemented using a **stack-based snapshot approach**.

- A global `stack<Node*> history` stores previous playlist states
- Before every destructive transformation:
  - a **deep copy** of the current playlist is created
  - the copy is pushed onto the stack
- Undo operation:
  - frees the current playlist
  - restores the most recent snapshot from history
- All stored snapshots are explicitly deleted on program exit

This design avoids complex inverse logic and guarantees correctness.

---


## `main.cpp` — Control Flow
- Implements a menu-driven interface
- Separates user interaction into:
  - Insert / Delete operations
  - Transform operations
  - Analysis operations
- Integrates undo and structural validation features
- Handles memory cleanup and program termination safely

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
| Loop Removal | O(n) | O(1) |

---

## Key Learnings

- Practical understanding of **singly linked list internals**
- Safe pointer manipulation and traversal techniques
- Difference between **user-visible data** and **structural correctness**
- Designing **self-healing data structures**
- Implementing undo using **state snapshots** instead of inverse operations
- Memory-safe programming with explicit allocation and deallocation
- Applying classical algorithms (Floyd’s cycle detection) in real systems

---







