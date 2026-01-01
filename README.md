# Clinic Patient Management System (CLI)

A lightweight, console-based application designed to demonstrate **CRUD concepts** (Create, Read, Search) and **manual data manipulation** using the C programming language.

This project intentionally avoids databases and external libraries to highlight how **structured data** can be managed directly in memory using **Structs** and **Arrays**, along with explicit control over input handling and program flow.

---

## 🌟 Key Features (CRUD Logic)

This application focuses on fundamental data-management mechanics rather than production robustness.

### 1. Create (Insert Data)

* **Auto-Increment Logic**
  Each new patient is assigned an ID using a sequential rule:

  `ID = previousID + 1`

* **Array Slot Validation**
  Ensures insertion occurs only if a free slot exists in the pre-allocated array.

* **Safe Input Handling**
  Uses `fgets()` combined with manual string sanitization to handle:

  * multi-word names
  * multi-word disease descriptions

  This avoids common `scanf` pitfalls and buffer overflow risks.

---

### 2. Read (View Data)

* **Tabular Output Rendering**
  Displays patient records in a structured table layout within the terminal.

* **Dynamic Spacing Logic**
  Adjusts column spacing based on string length:

  * name length > 13
  * name length < 5

  This keeps table borders visually aligned despite variable-length input.

---

### 3. Search (Query Data)

Implements a **linear search algorithm** with two query modes:

* **Search by ID**
  Direct integer comparison against stored IDs.

* **Search by Name (First-Name Matching)**

  * Iterates character-by-character over the full name string
  * Extracts characters until a space (`' '`) or null terminator (`'\0'`) is encountered
  * Compares the extracted substring against user input

  Example:

  > Searching `"Budi"` will match `"Budi Susanto"`

**Complexity:**

* Time: `O(n)`
* Space: `O(1)` (in-place scanning)

---

## ⚙️ Technical Implementation

* **Language:** C (C99 Standard)
* **Paradigm:** Procedural Programming
* **Data Structure:** Array of Structures (`struct pasienKlinik`)
* **Platform:** Windows

> ⚠️ `windows.h` is used for `system("cls")` and `Sleep()` to control basic UI behavior.

---

## 🧱 Core Data Structure

The entire system is centered around a manually defined structure:

```c
struct pasienKlinik {
    int ID;
    char nama[20];
    int umur;
    char penyakit[20];
};
```

**Design Trade-off:**

* ✔️ Predictable memory layout
* ✔️ Easy iteration
* ❌ Fixed-size fields
* ❌ Not suitable for large-scale or variable-length data

---

## 🚀 How to Compile & Run

> **Note:** This application is intended for **Windows** due to its dependency on `windows.h`.

### 1. Clone the Repository

```bash
git clone https://github.com/nugrahsdhka/simple-crud-cli.git
cd simple-crud-cli
```

### 2. Compile (GCC / MinGW)

```bash
gcc main.c -o clinic_app
```

### 3. Run

```bash
./clinic_app
```

---

## 🔮 Future Roadmap

Implemented:

* [x] Create — Insert new patient records
* [x] Read — Display all patient data
* [x] Search — Query by ID or first name

Planned Enhancements:

* [ ] Update — Modify existing records
* [ ] Delete — Remove records with array shifting
* [ ] Persistence — Save/load data to `.txt` or `.csv`
* [ ] Modularization — Separate logic into multiple source files

---

## 🧠 Engineering Notes

This project prioritizes **explicit control and clarity** over abstraction.

The goal is not feature richness, but demonstrating:

* understanding of memory-backed data structures
* careful input handling
* conscious design trade-offs in low-level programming

---

**Created by:** Dhika Setia Nugraha
