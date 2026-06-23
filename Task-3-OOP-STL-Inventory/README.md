# Task 3 - Inventory Management System

## Description

This project is a simple Inventory Management System developed in C++. It demonstrates Object-Oriented Programming concepts such as classes, inheritance, STL containers, and file persistence.

## Features

* Add normal products
* Add electronic products
* View all products
* Save product information to a file
* Menu-driven console application

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* STL Vector
* File Handling (fstream)
* Visual Studio Code

## Class Design

### Product (Base Class)

Stores:

* Product ID
* Product Name
* Product Price

### Electronics (Derived Class)

Inherits from Product and adds:

* Warranty Period

## STL Usage

The project uses `vector<Product*>` to store product objects dynamically.

## File Persistence

Product data is saved in `products.txt` using file handling operations.

## Build Instructions

Compile:

```bash
g++ main.cpp -o inventory
```

Run:

```bash
inventory.exe
```

## Makefile Usage

Build:

```bash
make
```

Run:

```bash
make run
```

## Sample Input

```text
1
101
Book
250
2
102
Laptop
50000
24
3
4
5
```

## Sample Output

```text
ID: 101 | Name: Book | Price: 250
ID: 102 | Name: Laptop | Price: 50000 | Warranty: 24 Months
Data Saved To products.txt Successfully!
```

## Design Decisions

* Product is implemented as a base class.
* Electronics inherits from Product.
* STL vector is used to manage products efficiently.
* File persistence is implemented using products.txt.
* A menu-driven approach is used for simplicity and usability.

