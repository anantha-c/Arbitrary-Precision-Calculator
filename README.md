# Arbitrary Precision Calculator in C

## Overview

The Arbitrary Precision Calculator is a command-line application developed in **C** to perform arithmetic operations on numbers that are larger than the range supported by standard integer data types.

The project implements arithmetic operations from scratch using **doubly linked lists** to represent individual digits.

## Supported Operations

* Addition
* Subtraction
* Multiplication
* Division

## Implementation

Each large number is represented using a doubly linked list, where individual nodes store digits of the number.

The arithmetic operations are implemented manually rather than relying on built-in integer types. The implementation handles:

* Carry propagation
* Borrow propagation
* Positive and negative numbers
* Large numerical values

This approach allows the calculator to work with numbers beyond the limits of native integer data types.

## Project Structure

The application is organized into separate modules for:

* Linked-list operations
* Arithmetic operations
* Main application logic

A **Makefile** is used to automate the build process.

## Key Concepts

The project demonstrates practical usage of:

* Doubly linked lists
* Dynamic memory allocation
* Pointers
* Modular programming
* Arithmetic algorithms
* Command-line programming
* Build automation

## Technologies

* C
* Data Structures
* Doubly Linked Lists
* Dynamic Memory
* Pointers
* Makefile

## Objective

The main objective of the project is to understand how arbitrary precision arithmetic can be implemented without depending on the limitations of native integer data types, while gaining practical experience with linked-list-based data representation and modular C programming.
