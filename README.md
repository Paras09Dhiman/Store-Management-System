# 🏪 Store Management System

A console-based Store Management System built with **C++** to manage products, track inventory, handle customer purchases, and generate bills. This project applies core programming concepts to a practical store-management scenario.

## 📌 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Technologies](#-technologies)
- [Getting Started](#-getting-started)
- [How to Use](#-how-to-use)
- [Concepts Practiced](#-concepts-practiced)
- [Limitations](#-current-limitations)
- [Future Improvements](#-future-improvements)
- [Author](#-author)

## 📖 Overview

The Store Management System provides a menu-driven interface for managing a store's products and inventory. Users can add and maintain product records, search and sort inventory, process sales, restock products, and simulate customer purchases with a shopping cart and a formatted bill.

The project was developed to strengthen my C++ fundamentals through practical implementation, logical problem-solving, and input validation.

## ✨ Features

### 📦 Product Management
- Add new products with names, categories, prices, and quantities.
- Display all available products with their IDs.
- Update product details.
- Delete products with a confirmation step.
- Search for products by name or ID.

### 📊 Inventory Management
- Restock existing products.
- Sell products while checking stock availability.
- Sort products by name, price, or quantity using Bubble Sort.
- Calculate total product types, stock units, and inventory value.
- Identify low-stock products.
- Find the most expensive product and the product with the highest stock.
- View category-wise inventory and search inventory by product name.

### 🛒 Customer Purchase and Billing
- Browse available products.
- Add multiple products to a shopping cart.
- Calculate item subtotals and the final purchase total.
- Confirm or cancel a purchase.
- Update inventory after a confirmed purchase.
- Generate a formatted customer bill.

### 🛡️ Basic Input Validation
- Validate product prices and quantities.
- Handle several invalid numeric inputs.
- Check product IDs and stock availability.
- Prevent adding more than the supported inventory capacity.

## 🛠️ Technologies

- **Language:** C++
- **Standard Library:** `iostream`, `string`, `iomanip`, `limits`
- **Application Type:** Console-based
- **Data Storage:** In-memory arrays

## 🚀 Getting Started

### Prerequisites

You need:
- A C++ compiler, such as GCC/G++.
- A terminal or command prompt.

### 1. Clone the Repository

Replace `YOUR_USERNAME` and `YOUR_REPOSITORY` with your GitHub details.

```bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPOSITORY.git
cd YOUR_REPOSITORY
```

### 2. Compile the Program

Make sure your source file is named `main.cpp`, or replace the filename in the command with your actual filename.

**Windows (G++):**

```bash
g++ main.cpp -o store.exe
```

**Linux / macOS (G++):**

```bash
g++ main.cpp -o store
```

### 3. Run the Program

**Windows:**

```powershell
.\store.exe
```

**Linux / macOS:**

```bash
./store
```

## 🎮 How to Use

After launching the program, select an option from the main menu:

| Option | Operation |
|---|---|
| 1 | Add Products |
| 2 | Display All Products |
| 3 | Search Products |
| 4 | Sort Products |
| 5 | Sell Products |
| 6 | Restock Products |
| 7 | Update Products |
| 8 | Delete Products |
| 9 | Customer Purchase |
| 10 | Store Statistics |
| 11 | Exit |

Follow the prompts to complete each operation. Start by adding products, then explore inventory management, customer purchases, billing, and store statistics.

## 🧠 Concepts Practiced

This project helped me practice:

- C++ structures (`struct`) and arrays
- Loops and conditional statements
- String handling and `getline()`
- Input validation using `cin`, `clear()`, and `ignore()`
- Searching and sorting algorithms
- Bubble Sort and early termination optimization
- Basic calculations and inventory updates
- Formatted output using `setw()`, `fixed`, and `setprecision()`
- Menu-driven program design and problem-solving

## ⚠️ Current Limitations

- The system supports a maximum of **100 product records**.
- Product data is stored in memory and is lost when the program exits.
- The application uses a console interface rather than a graphical user interface.
- It is an educational project, not a production-ready retail system.

## 🔮 Future Improvements

- Save and load inventory using file handling.
- Introduce a database for persistent storage.
- Improve input validation across all menu operations.
- Add sales history and daily revenue reports.
- Introduce unique product identifiers and more robust inventory handling.
- Build a graphical or web-based interface.

## 👨‍💻 Author

**Paras Dhiman**

Computer Science and Engineering student learning C++ through hands-on projects.

I'm focused on strengthening my programming fundamentals, improving problem-solving skills, and building more practical projects as I progress.

---

⭐ If you find this project useful for learning C++, feel free to explore the code and share suggestions for improvement.
