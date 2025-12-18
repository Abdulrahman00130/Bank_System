# 🏦 Bank System – Console-Based Management Application (C++)

A modular, console-based **Bank Management System** implemented in **C++**, designed with clear separation of concerns, role-based access, and file-based persistence.
The project demonstrates solid fundamentals in **OOP**, **clean architecture**, and **basic data management**, making it suitable for academic use and entry-level backend/embedded portfolios.

---

## 📌 Overview

The **Bank System** is a command-line application that simulates core banking operations for different user roles:

* **Admin**
* **Employee**
* **Client**

Each role has specific permissions and workflows, enforced through dedicated managers and validation layers.
Data is persisted using file-based storage, abstracted through interfaces to allow future extensibility.

---

## ✨ Key Features

### 🔐 Role-Based Access Control

* **Admin**: Full system control (users & data)
* **Employee**: Manage clients and banking operations
* **Client**: View balance and perform allowed transactions

### 🧱 Object-Oriented Design

* Encapsulation via classes such as `Person`, `Client`, `Employee`, `Admin`
* Inheritance to reuse and extend common behavior
* Polymorphism through interfaces (e.g., data source abstraction)

### 🗂 File-Based Persistence

* Data stored and retrieved from files
* Centralized file handling through helper and manager classes

### 🛡 Input Validation & Safety

* Central validation layer for user input
* Prevents invalid operations and corrupted data

### 📺 Console UI Screens

* Screen navigation and display logic separated from business logic
* Clear and user-friendly CLI flow

---

## 🏗 Project Structure

```
Bank_System/
│
├── include/                # Header files (interfaces & declarations)
│   ├── Person.h
│   ├── Client.h
│   ├── Employee.h
│   ├── Admin.h
│   ├── ClientManager.h
│   ├── EmployeeManager.h
│   ├── AdminManager.h
│   ├── DataSourceInterface.h
│   ├── FileManager.h
│   ├── FilesHelper.h
│   ├── Parser.h
│   ├── Validation.h
│   └── Screens.h
│
├── src/
│   └── Globals.cpp         # Global shared resources
│
├── main.cpp                # Application entry point
│
├── bin/                    # Compiled binaries (Debug/Release)
├── obj/                    # Object files
└── Bank_System.cbp         # Code::Blocks project file
```

---

## 🛠 Technologies Used

* **Language:** C++
* **Compiler:** GCC
* **IDE:** Code::Blocks
* **Paradigms:** Object-Oriented Programming (OOP)
* **Storage:** File System

---

## ▶️ How to Build & Run

### Using Code::Blocks

1. Open `Bank_System.cbp`
2. Choose **Debug** or **Release**
3. Build & Run

---

## 📈 Possible Enhancements

* Replace file storage with a database (SQLite / MySQL)
* Add password hashing & authentication
* Improve error handling & logging
* Implement unit testing
* Add transaction history & reporting

---

## 🎯 Educational Value

This project is ideal for demonstrating:

* Strong C++ fundamentals
* OOP design principles
* Clean separation of concerns
* Real-world problem modeling

---

Just tell me what you want next.
