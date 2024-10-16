#include <stdio.h>
#include <stdlib.h> 

/* STORING DATA */

/* espresso ingredients */
#define e_c 8
#define e_w 30
#define e_m 0
#define e_choc 0
float e_p = 3.5;

/* cappucino ingredients */
#define c_c 8
#define c_w 30
#define c_m 70
#define c_cho 0
float c_p = 4.5;

/* mocha ingredients */
#define m_c 8
#define m_w 39
#define m_m 160
#define m_cho 30
float m_p = 5.5;

/* admin password */
#define password 9671

/* minimum threshold of each item */
float min_cofbean = 8;
float min_water = 40;
float min_milk = 160;
float min_chocosyrup = 30;

/* initial available amount of each substance */
float available_coffee = 50;
float available_water = 100;
float available_milk = 400;
float available_chocosyrup = 100;
float sale_amount = 0;

/*initializing the funtions*/
int admin_menu();
void replenish_ad();
void change_price();
int coffeeOrder();
void sale_count();
void payment(float ouch);

/*MAIN MODE*/
int main() {
    int value;
    while (1) {
        printf("UOWD CAFE\nEnter 1: Order a coffee type\nEnter 2: Admin mode for the coffee maker operator\nEnter 3: End the application execution\n");
        scanf("%d", &value);
        if (value == 1) {
            coffeeOrder();
        } else if (value == 2) {
            admin_menu();
        } else if (value == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

/* ORDER COFFEE MODE */
int coffeeOrder() {
    int coffee_me;
    printf("COFFEE MENU\n");
    printf("1. Espresso %.2f\n", e_p);
    printf("2. Cappuccino %.2f\n", c_p);
    printf("3. Mocha %.2f\n", m_p);
    printf("0. Exit\n");
    printf("Select Your Order: ");
    scanf("%d", &coffee_me);

    if (coffee_me == 1) {
        printf("Espresso Coffee\n");
        printf("Ensuring all ingredients are available\n");
        if (e_c <= available_coffee && e_w <= available_water && e_m <= available_milk && e_choc <= available_chocosyrup) {
            payment(e_p);
            printf("Preparing coffee\nEnjoy your coffee\n\n");
            available_coffee -= e_c;
            available_milk -= e_m;
            available_chocosyrup -= e_choc;
            available_water -= e_w;
            sale_amount += e_p;
        } else {
            printf("Unavailable due to temporarily insufficient ingredients\n");
        }
    }
    else if (coffee_me == 2) {
        printf("Cappuccino Coffee\n");
        printf("Ensuring all ingredients are available\n");
        if (c_c <= available_coffee && c_w <= available_water && c_m <= available_milk && c_cho <= available_chocosyrup) {
            payment(c_p);
            printf("Preparing coffee\nEnjoy your coffee\n\n");
            available_coffee -= c_c;
            available_milk -= c_m;
            available_chocosyrup -= c_cho;
            available_water -= c_w;
            sale_amount += c_p;
        } else {
            printf("Unavailable due to temporarily insufficient ingredients\n");
        }
    }
    else if (coffee_me == 3) {
        printf("Mocha Coffee\n");
        printf("Ensuring all ingredients are available\n");
        if (m_c <= available_coffee && m_w <= available_water && m_m <= available_milk && m_cho <= available_chocosyrup) {
            payment(m_p);
            printf("Preparing coffee\nEnjoy your coffee\n\n");
            available_coffee -= m_c;
            available_milk -= m_m;
            available_chocosyrup -= m_cho;
            available_water -= m_w;
            sale_amount += m_p;
        } else {
            printf("Unavailable due to temporarily insufficient ingredients\n");
        }
    }
    else if (coffee_me == 0) {
        printf("Exiting\n");
    }
    else {
        printf("Invalid Choice\n");
    }
    return 0;
}

/* ADMIN MODE */
int admin_menu() {
    int m;
    printf("ADMIN MODE\n");
    printf("Enter Admin Password: ");
    scanf("%d", &m);
    if (m == password) {
        int j;
        printf("Enter 1: Display the quantity of each ingredient in the machine and the total sale amount\nEnter 2: Replenish ingredients in the machine\nEnter 3: Change coffee price\nEnter 0: Exit the Admin Mode function\n");
        scanf("%d", &j);
        if (j == 2){
        replenish_ad();
        }  
        if (j == 3){
        change_price();
        }      
        if (j == 0){
        printf("Exiting admin mode\n");
        }
        if (j == 1){
            printf("Available coffee beans: %.2f\nAvailable water: %.2f\nAvailable milk: %.2f\nAvailable choco syrup: %.2f\n", available_coffee, available_water, available_milk, available_chocosyrup);
            sale_count();
        }
    } else {
        printf("Wrong password\n\n");
    }
    return 0;
}

/*Replenish mode */
void replenish_ad(void) {
        if (available_coffee <= min_cofbean && available_water <= min_water && available_milk <= min_milk && available_chocosyrup <= min_chocosyrup){
            printf("The avaiable quantities are lower than the minimum threshold, Kindly refil the ingredients\n");
        }
        int k;
        printf("Type 1: To refill all ingredients\n");
        scanf("%d", &k);

        if (k == 1) {
            available_coffee = (rand() % (100 - 8 + 1)) + 8;
            available_water = (rand() % (300 - 40 + 1)) + 40;
            available_milk = (rand() % (400 - 160 + 1)) + 160;
            available_chocosyrup = (rand() % (100 - 30 + 1)) + 30;
            printf("Coffee beans refilled to: %.2f\n", available_coffee);
            printf("Water refilled to: %.2f\n", available_water);
            printf("Milk refilled to: %.2f\n", available_milk);
            printf("Chocolate syrup refilled to: %.2f\n", available_chocosyrup);
            printf("Ingredients have been refilled\n\n");
        }
    
}

/*Change price mode*/
void change_price(void) {
        int l;
        printf("Type 1: To change price of espresso\nType 2: To change price of cappuccino\nType 3: To change price of mocha\n");
        scanf("%d", &l);

        if (l == 1) {
            printf("Type the new price of espresso: ");
            scanf("%f", &e_p);  
            printf("Espresso Price has been changed\n\n");
        }
        if (l == 2) {
            printf("Type the new price of cappuccino: ");
            scanf("%f", &c_p); 
            printf("Cappuccino Price has been changed\n\n");
        }
        if (l == 3) {
            printf("Type the new price of mocha: ");
            scanf("%f", &m_p);  
            printf("Mocha Price has been changed\n\n");
        }
    
}

/*sale amount*/
void sale_count(void){
    printf("Total sale amount: $%.2f\n", sale_amount);
    int k;
    printf("Enter 1: If you would like to reset the total sale amount to zero?\n");
    scanf("%d", &k);
    if (k == 1){
        printf("Collect the sale amount: $%.2f\n\n", sale_amount);
        sale_amount = 0;
    }
}

/*payment mode*/
void payment(float ouch){
    float coin, totalInserted = 0;
    while (totalInserted < ouch) {
        printf("Enter 1: To insert 1$ coin\nEnter 0.5: To insert $0.5 coin\n");
        scanf("%f", &coin);
        if (coin == 1.0 || coin == 0.5) {
            totalInserted += coin;
        } else {
            printf("Invalid coin! Please insert 1$ or 0.5$.\n");
        }
        printf("Total inserted: %.2f, Remaining: %.2f\n", totalInserted, ouch - totalInserted);
    }
    
    float change = totalInserted - ouch;
    printf("Change owed: $%.2f\n", change);
    printf("Thank you for your purchase!\n");
}
