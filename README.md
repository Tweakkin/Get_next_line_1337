# 📜 get_next_line

> A custom implementation of the `get_next_line()` function in C, for reading a file line by line — part of the 1337/42 core curriculum.

---

## 📘 Description

The `get_next_line()` function reads from a file descriptor and returns a line, one call at a time. This project trains you to manage memory dynamically, handle buffers, and maintain reading state between function calls.

> Think of it like `fgets()`, but lower-level, controlled by you.

---

## 🧠 Key Concepts

- Efficient file I/O using `read()`
- Managing static buffers
- Handling multiple file descriptors
- Memory allocation and cleanup

---

## ⚙️ Usage

### 🔧 Function Prototype

```c
char *get_next_line(int fd);
