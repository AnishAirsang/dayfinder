# DayFinder

A simple C++ command-line program to find the day of the week for any given date. 

You could obviously just look at a calendar or ask AI, but I wanted to write this from scratch myself to practice C++, logic building, and how date calculations actually work..

## What it does
- Takes your name, date, month, and year as input.
- Handles leap years and validates invalid dates (e.g., February 30th or April 31st).
- Accepts months as numbers (1-12) or as names (e.g., "October" or "Oct").
- Calculates the exact day using month codes, year codes, and century codes.

## How to compile and run

```bash
g++ main.cpp -o dayfinder
./dayfinder
```

## Example Run

```text
Enter your full name: Anish
Enter the date (01-31): 15
Enter the month (01-12) or exact name (eg. January): October
Enter the year: 2026

=========================================
Date: 15 October 2026
Day : Thursday
=========================================
```
