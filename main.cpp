// Store Management System

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct product{
    string name;
    string category;
    float price;
    int quantity;
};

int main(){
    int user;
    int count = 0;
    product products[100];

    while(1){
    // Homepage-
        cout << "===========================================\n";
        cout << "========= Store Management System =========\n";
        cout << "===========================================\n";
        cout << "1. Add Products\n2. Display All Products\n3. Search Products\n4. Sort Products\n5. Sell Products\n6. Restock Products\n7. Update Products\n8. Delete Products\n9. Customer Purchase\n10. Store Statistics\n11. Exit\n";
        
        cout << "Enter Your Choice: ";

        if(!(cin >> user)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if(user < 1 || user > 11){
            cout << "Invalid Choice! Please select 1-11.\n";
            continue;
        }

    // Add Products
        if(user == 1){
            if(count >= 100) {
                cout << "\n==== Inventory is full! Cannot add more products ====\n";
            }
            else {
                cout << "\n------------------------------------\n";
                cout << "======== Add Products ========\n";
                cin.ignore();   // clear leftover '\n'

                cout << "Name of Product: ";
                getline(cin, products[count].name);
                while(products[count].name.empty()){
                    cout << "Product name cannot be empty!\n";
                    cout << "Enter Name of Product: ";
                    getline(cin, products[count].name);
                }
                cout << "Category of Product: ";
                getline(cin, products[count].category);
                while(products[count].category.empty()){
                    cout << "Product category cannot be empty!\n";
                    cout << "Enter Category of Product: ";
                    getline(cin, products[count].category);
                }
                cout << "Price of Product: ";
                while(!(cin >> products[count].price) ||
                    products[count].price <= 0){

                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Please enter a number.\n";
                    }
                    else{
                        cout << "Invalid price! Price must be greater than 0.\n";
                    }
                    cout << "Enter Price Again: ";
                }
                
                cout << "Quantity of Product: ";

                while(!(cin >> products[count].quantity) ||
                    products[count].quantity < 0){

                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Please enter a whole number.\n";
                    }
                    else{
                        cout << "Invalid quantity! Quantity cannot be negative.\n";
                    }
                    cout << "Enter Quantity Again: ";
                }

                count++;
                cout << "Product Added Successfully!\n";
                cout << "------------------------------------\n\n";
            }
        }

    // Display All Products
        else if(user == 2){
            cout << "\n------------------------------------\n";
            cout << "======== Display All Products ========\n";
            int i = 0;
            if(count == 0){
                cout << "No Products Available!\n";
            }
            else{
                while(i < count){
                    cout << "Product ID = " << i + 1 << "\n";
                    cout << "Product = " << products[i].name << "\n";
                    cout << "Category = " << products[i].category << "\n";
                    cout << "Price = " << products[i].price << "\n";
                    cout << "Quantity = " << products[i].quantity << "\n";
                    cout << "------------------------------------\n";
                    i++;
                }
                cout << "\n";
            }
        }

    // Search Products
        else if(user == 3){
            cout << "\n------------------------------------\n\n";
            cout << "======== Search Products ========\n";
            
            cout << "1. Search by Name\n2. Search by ID\n3. Back\n";

            int searchChoice = 0;
            cout << "Enter Your Choice: ";
            cin >> searchChoice;

            if(searchChoice == 1){ // By Name
                bool found = false;
                int flag = 0;
                string name;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                
                for(int i = 0; i < count; i++){
                    if(products[i].name.find(name) != string::npos){
                        found = true;
                        flag = i;
                        break;
                    }
                }

                if(found){
                    cout << "\n========== Product Found ==========\n";
                    cout << "Product = " << products[flag].name << "\n";
                    cout << "Category = " << products[flag].category << "\n";
                    cout << "Price = " << products[flag].price << "\n";
                    cout << "Quantity = " << products[flag].quantity << "\n";
                    cout << "-----------------------------------\n\n";
                }
                else{
                    cout << "--------------------\n";
                    cout << " Product Not Found!\n";
                    cout << "--------------------\n\n";
                }
            }
            else if(searchChoice == 2){ // By ID
                int id;
                cout << "Enter ID: ";
                cin >> id;

                if(id >= 1 && id <= count){
                    cout << "\n========== Product Found ==========\n";
                    cout << "Product = " << products[id - 1].name << "\n";
                    cout << "Category = " << products[id - 1].category << "\n";
                    cout << "Price = " << products[id - 1].price << "\n";
                    cout << "Quantity = " << products[id - 1].quantity << "\n";
                }
                else{
                    cout << "--------------------\n";
                    cout << " Product Not Found!\n";
                    cout << "--------------------\n\n";
                }
            }
            else if(searchChoice == 3){ // Back
                cout << "Thank You!\n";
            }
            else{
                cout << "Invalid Choice!\n";
            }
            cout << "------------------------------------\n\n";
        }

    // Sort Products
        else if(user == 4){
            cout << "\n------------------------------------\n\n";
            cout << "======== Sort Products ========\n";

            cout << "1. Sort by Price\n2. Sort by Quantity\n3. Sort by Name\n4. Back\n";

            int choice4;
            cout << "Enter Your Choice: ";
            cin >> choice4;

            if(choice4 == 1){
                for(int i = 0; i < count; i++){
                    bool isSwaped = false;
                    for(int j = 0; j < count - i - 1; j++){
                        if(products[j].price > products[j + 1].price){
                            // Bubble Sort
                            product temp = products[j];
                            products[j] = products[j + 1];
                            products[j + 1] = temp;
                            isSwaped = true;
                        }
                    }
                    if(!isSwaped){
                        break;
                    }
                }
                cout << "All Products is Sorted by Price!\n";
            }
            else if(choice4 == 2){
                for(int i = 0; i < count; i++){
                    bool isSwaped = false;
                    for(int j = 0; j < count - i - 1; j++){
                        if(products[j].quantity > products[j + 1].quantity){
                            // Bubble Sort
                            product temp = products[j];
                            products[j] = products[j + 1];
                            products[j + 1] = temp;
                            isSwaped = true;
                        }
                    }
                    if(!isSwaped){
                        break;
                    }
                }
                cout << "All Products is Sorted by Quantity!\n";
            }
            else if(choice4 == 3){
                for(int i = 0; i < count; i++){
                    bool isSwaped = false;
                    for(int j = 0; j < count - i - 1; j++){
                        if(products[j].name > products[j + 1].name){
                            // Bubble Sort
                            product temp = products[j];
                            products[j] = products[j + 1];
                            products[j + 1] = temp;
                            isSwaped = true;
                        }
                    }
                    if(!isSwaped){
                        break;
                    }
                }
                cout << "All Products is Sorted by Name!\n";
            }
            else if(choice4 == 4){
                cout << "Thank You!\n";
            }
            else{
                cout << "Invalid Choice! Please select 1-4.\n";
            }
            cout << "------------------------------------\n\n";
        }

    // Sell Products
        else if(user == 5){
            cout << "\n------------------------------------\n\n";
            cout << "======== Sell Products ========\n";
            int productID, units;
            cout << "Enter the ID of Product: ";
            while(!(cin >> productID)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Invalid input! Please enter a Numeric Product ID: ";
            }

            if(productID > 0 && productID <= count){
                cout << "----- Product Details -----\n";
                cout << "Product = " << products[productID - 1].name << "\n";
                cout << "Category = " << products[productID - 1].category << "\n";
                cout << "Price = " << products[productID - 1].price << "\n";
                cout << "Quantity = " << products[productID - 1].quantity << "\n";
                cout << "-----------------------\n";
                cout << "Enter Quantity to Sell: ";

                while(!(cin >> units) || units <= 0){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Please enter a whole number.\n";
                    }
                    else{
                        cout << "Invalid quantity! Quantity must be greater than 0.\n";
                    }

                    cout << "Enter Quantity to Sell Again: ";
                }

                if(units > products[productID - 1].quantity){
                    cout << "--- Not Enough Stock! ---\n";
                }
                else{
                    products[productID - 1].quantity -= units;
                    cout << "--- Sale Successful! ---\n";
                    cout << "Remaining Quantity: "
                         << products[productID - 1].quantity << "\n";
                }
            }
            else{
                cout << "--- Invalid Product ID! ---\n";
            }

            cout << "------------------------------------\n\n";
        }

    // Restock Products
        else if(user == 6){
            cout << "\n------------------------------------\n\n";
            cout << "======== Restock Products ========\n";
            int productID, units;
            cout << "Enter the ID of Product: ";
            while(!(cin >> productID)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a numeric Product ID: ";
            }

            if(productID > 0 && productID <= count){
                cout << "----- Product Details -----\n";
                cout << "Product = " << products[productID - 1].name << "\n";
                cout << "Category = " << products[productID - 1].category << "\n";
                cout << "Price = " << products[productID - 1].price << "\n";
                cout << "Quantity = " << products[productID - 1].quantity << "\n";
                cout << "-----------------------\n";
                cout << "Enter Quantity to Restock: ";
                while(!(cin >> units) || units <= 0){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Enter a whole number.\n";
                    }
                    else{
                        cout << "Invalid quantity! Must be greater than 0.\n";
                    }
                    cout << "Enter Quantity to Restock Again: ";
                }
    
                if(units > 0){
                    products[productID - 1].quantity += units;
                    cout << "--- Restock Successful! ---\n";
                    cout << "New Quantity: " << products[productID - 1].quantity << "\n";
                }
                else{
                    cout << "--- Invalid Quantity! ---\n";
                }
            }
            else{
                cout << "----- Product Not Found! -----\n";
            }
            cout << "------------------------------------\n\n";
        }

    // Update Products
        else if(user == 7){
            cout << "\n------------------------------------\n\n";
            cout << "======== Update Products ========\n";
            int p_id, choice;
            cout << "Enter ID of Product: ";
            while(!(cin >> p_id)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a numeric Product ID: ";
            }

            if(p_id >= 1 && p_id <= count){
                    cout << "\n========== Product Found ==========\n";
                    cout << "Product = " << products[p_id - 1].name << "\n";
                    cout << "Category = " << products[p_id - 1].category << "\n";
                    cout << "Price = " << products[p_id - 1].price << "\n";
                    cout << "Quantity = " << products[p_id - 1].quantity << "\n";
                    cout << "-----------------------------------\n\n";
                    cout << "\nWhat do you want to Update:- \n";
                    cout << "1. Name\n2. Category\n3. Price\n4. Quantity\n";
                    cout << "Choice: ";
                    while(!(cin >> choice)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Enter a numeric choice: ";
                    }
        
                    if(choice == 1){
                        cout << "Enter Name: ";
                        cin.ignore();
                        getline(cin, products[p_id - 1].name);
                        cout << "Product Updated Successfully!\n";
                    }
                    else if(choice == 2){
                        cout << "Enter Category: ";
                        cin.ignore();
                        getline(cin, products[p_id - 1].category);
                        cout << "Product Updated Successfully!\n";
                    }
                    else if(choice == 3){
                        cout << "Enter Price: ";

                        while(!(cin >> products[p_id - 1].price) ||
                            products[p_id - 1].price <= 0){
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input! Enter a numeric price.\n";
                            }
                            else{
                                cout << "Invalid price! Price must be greater than 0.\n";
                            }

                            cout << "Enter Price Again: ";
                        }
                        cout << "Product Updated Successfully!\n";
                    }
                    else if(choice == 4){
                        cout << "Enter Quantity: ";

                        while(!(cin >> products[p_id - 1].quantity) ||
                            products[p_id - 1].quantity < 0){
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input! Enter a whole number.\n";
                            }
                            else{
                                cout << "Invalid quantity! Quantity cannot be negative.\n";
                            }

                            cout << "Enter Quantity Again: ";
                        }
                    }
                    else{
                        cout << "Invalid Choice!\n";
                    }
                }
                else{
                    cout << "--------------------\n";
                    cout << " Product Not Found!\n";
                    cout << "--------------------\n\n";
                }

            cout << "------------------------------------\n\n";
        }

    // Delete Products
        else if(user == 8){
            cout << "\n------------------------------------\n\n";
            cout << "======== Delete Products ========\n";
            int userid;
            cout << "Enter ID of Product: ";
            while(!(cin >> userid)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a numeric Product ID: ";
            }

            if(userid >= 1 && userid <= count){
                cout << "\n========== Product Found ==========\n";
                cout << "Product = " << products[userid - 1].name << "\n";
                cout << "Category = " << products[userid - 1].category << "\n";
                cout << "Price = " << products[userid - 1].price << "\n";
                cout << "Quantity = " << products[userid - 1].quantity << "\n";
                cout << "-----------------------------------\n\n";
                
                int check;
                cout << "Do you want to Delete this Product!\n";
                cout << "1. YES\n2. NO\n";
                cout << "Enter: ";
                while(!(cin >> check) || (check != 1 && check != 2)){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cout << "Invalid choice! Enter 1 to delete or 2 to cancel: ";
                }

                if(check == 1){
                    for(int i = userid - 1; i < count - 1; i++){
                        products[i] = products[i + 1];
                    }
                    cout << "---- Product Deleted Successfully! ----\n";
                    count--;
                }
                else if(check == 2){
                    cout << "No Product is Deleted!\n";
                }
                else{
                    cout << "Enter Valid Choice!\n";
                }
            }
            else{
                cout << "--------------------\n";
                cout << " Product Not Found!\n";
                cout << "--------------------\n\n";
            }
            cout << "------------------------------------\n\n";
        }

    // Customer Purchase
        else if(user == 9){
            cout << "\n------------------------------------\n\n";
            cout << "======== Customer Purchase ========\n";
            if(count == 0){
                cout << "No Products Available! Please add products first.\n";
            }
            else{
                int productid, unit;
                int cartid[100], cartUnits[100], cartCount = 0;
                int ch = 1, CHOICE;
                float total = 0;
    
                for(int i =  0; i < count; i++){
                    cout << "Product ID = " << i + 1 << "\n";
                    cout << "Product = " << products[i].name << "\n";
                    cout << "Category = " << products[i].category << "\n";
                    cout << "Price = " << products[i].price << "\n";
                    cout << "Quantity = " << products[i].quantity << "\n";
                    cout << "--------------------------------------\n";
                }
                do{
                    cout << "Enter Product ID: ";
                    while(!(cin >> productid)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Enter a numeric Product ID: ";
                    }

                    if(productid >= 1 && productid <= count){
                        cout << "Enter Quantity: ";
                        while(!(cin >> unit)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input! Enter a numeric quantity: ";
                        }
                        
                        int alreadyInCart = 0;
    
                        for(int i = 0; i < cartCount; i++){ 
                            if(cartid[i] == productid){
                                alreadyInCart += cartUnits[i];
                            }
                        }
                        
                        if(unit >= 1 && alreadyInCart + unit <= products[productid - 1].quantity){
                            if(cartCount < 100){
                                cartid[cartCount] = productid;
                                cartUnits[cartCount] = unit;
                                cout << "Product Added in Cart!\n";
                                total += products[productid - 1].price * unit;
                                cartCount++;
                            }
                            else{
                                cout << "Cart is Full! Cannot add more products.\n";
                                ch = 2;
                            }
                            
                            if(cartCount < 100){
                                cout << "Add More Products in Cart:-\n";
        
                                cout << "1. Yes\n2. No\n";
                                cout << "Enter Choice: ";
                                cin >> ch;
                            }

            
                            if(ch == 2){
                                cout << "Thank You!\n";
                                break;
                            }
                            else if(ch != 1 && ch != 2){
                                cout << "Invalid Choice! Please enter 1 or 2.\n";
                                ch = 1;
                            }
                        }
                        else if(alreadyInCart + unit > products[productid - 1].quantity){
                            cout << "Out Of Quantity!\n";
                        }
                        else{
                            cout << "Invalid Quantity!\n";
                        }
                    }
                    else{
                        cout << "Invalid ID!\n";
                    }
                }while(ch == 1);
    
                if(cartCount == 0){
                   cout << "Cart is Empty!\n";
                }
                else{
                    for(int i =  0; i < cartCount; i++){
                        cout << "Name = " << products[cartid[i] - 1].name << "\n";
                        cout << "Quantity = " << cartUnits[i] << "\n";
                        cout << "Price = " << products[cartid[i] - 1].price << "\n";
                        cout << "SubTotal = " << cartUnits[i] * products[cartid[i] - 1].price << "\n";
                        cout << "----------------------------\n";
                    }
                    cout << "Final Total = " << total << "\n";
                    cout << "1. Confirm Purchase\n2. Cancel Purchase\n";
                    cout << "Enter Choice: ";
                    while(!(cin >> CHOICE) || (CHOICE != 1 && CHOICE != 2)){
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Invalid Choice! Enter 1 to confirm or 2 to cancel: ";
                    }
    
                    if(CHOICE == 1){
                        for(int i =  0; i < cartCount; i++){
                            products[cartid[i] - 1].quantity -= cartUnits[i];
                        }
    
                        cout << "\n============================================================\n";
                        cout << "                       MY STORE\n";
                        cout << "                     CUSTOMER BILL\n";
                        cout << "============================================================\n";
    
                        cout << left
                             << setw(22) << "Product"
                             << setw(12) << "Quantity"
                             << setw(12) << "Price"
                             << setw(12) << "Subtotal" << "\n";
    
                        cout << "------------------------------------------------------------\n";
    
                        for(int i = 0; i < cartCount; i++){
                            cout << left
                                 << setw(22) << products[cartid[i] - 1].name
                                 << setw(12) << cartUnits[i]
                                 << setw(12) << fixed << setprecision(2)
                                 << products[cartid[i] - 1].price
                                 << setw(12)
                                 << cartUnits[i] * products[cartid[i] - 1].price
                                 << "\n";
                        }
    
                        cout << "------------------------------------------------------------\n";
                        cout << right << setw(46) << "Final Total: "
                             << fixed << setprecision(2) << total << "\n";
                        cout << "============================================================\n";
                        cout << "                Thank you for shopping!\n";
                        cout << "============================================================\n\n";
    
                    }
                    else if(CHOICE == 2){
                        cout << "Purchase Cancelled!\n";
                    }
                    else{
                        cout << "Invalid Choice!\n";
                    }
    
                }
                
            }
            
            cout << "------------------------------------\n\n";
        }

    // Store Statistics
        else if(user == 10){
            cout << "\n------------------------------------\n\n";
            cout << "======== Store Statistics ========\n";
            int totalStock = 0;
            float totalValue = 0;
            int lowStockCount = 0;
            int expensiveProduct = 0, highestStockProduct = 0;
            cout << "1. Total Product Types: " << count << "\n";
            for(int i = 0; i < count; i++){
                totalStock += products[i].quantity; 
                totalValue += products[i].quantity * products[i].price;
                if(products[i].quantity < 5){
                    lowStockCount++;
                }
            }
            
            cout << "2. Total Stock Units: " << totalStock << "\n";
            cout << "3. Total Stock Value: " << totalValue << "\n";
            cout << "4. Low Stock Products: " << lowStockCount << "\n";
            if(count > 0){
                for(int i = 1; i < count; i++){
                    if(products[i].price > products[expensiveProduct].price){
                        expensiveProduct = i;
                    }
                    if(products[i].quantity > products[highestStockProduct].quantity){
                        highestStockProduct = i;
                    }
                }
                cout << "5. Most Expensive Product: " << products[expensiveProduct].name << " - " << products[expensiveProduct].price << "\n";
                cout << "6. Product with the Highest Stock: "<< products[highestStockProduct].name << " - " << products[highestStockProduct].quantity << "\n";
            }

            cout << "7. Category-wise Inventory\n";
            cout << "8. Inventory Search\n";
            int n;
            cout << "Enter Choice: ";
            cin >> n;
            if(n == 7){
                cout << "======== Category-wise Inventory ========\n";
                for(int i = 0; i < count; i++){
                    bool alreadyProcessed = false;
                    for(int j = 0; j < i; j++){
                        if(products[j].category == products[i].category){
                            alreadyProcessed = true;
                            break;
                        }
                    }
                    if(alreadyProcessed){
                        continue;
                    }
                    int categoryStock = 0;
                    for(int k = 0; k < count; k++){
                        if(products[k].category == products[i].category){
                            categoryStock += products[k].quantity;
                        }
                    }
                    cout << products[i].category << " - " << categoryStock << "\n";
                }
            }
            else if(n == 8){
                cout << "======== Inventory Search ========\n";
                bool found = false;
                string searchName;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, searchName);
                for(int i = 0; i < count; i++){
                    if(searchName == products[i].name){
                        found = true;
                        cout << "\n========== Product Found ==========\n";
                        cout << "Product = " << products[i].name << "\n";
                        cout << "Category = " << products[i].category << "\n";
                        cout << "Price = " << products[i].price << "\n";
                        cout << "Quantity = " << products[i].quantity << "\n";
                    }
                }
                if(!found){
                    cout << "--------------------\n";
                    cout << " Product Not Found!\n";
                    cout << "--------------------\n";
                }
            }
            else{
                cout << "Invalid Choice! Please select 7 or 8.\n";
            }
            
            cout << "------------------------------------\n\n";
        }

    // Exit
        else if(user == 11){
            cout << "------------------------------\n";
            cout << " ======== Thank You! ========\n";
            cout << "------------------------------\n";
            break;
        }

    // Invalid
        else{
            cout << "---------------------------------\n";
            cout << " ======= Invalid Choice! =======\n";
            cout << "---------------------------------\n";
        }
    }

    return 0;
}