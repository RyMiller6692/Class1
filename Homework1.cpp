#include <iostream>
using namespace std;
enum MembershipLevel
{
    NONE, BRONZE, SILVER, GOLD
};
struct Item
{
    string name;
    double price;
};
double applyDiscount(double totalPrice, MembershipLevel level)
{
    switch (level)
    {
    case BRONZE: return totalPrice * 0.95; 
    case SILVER: return totalPrice * 0.90; 
    case GOLD:   return totalPrice * 0.85; 
    default:     return totalPrice;        
    }
}
MembershipLevel getMembershipLevel()
{
    int membershipChoice;
    cout << "Enter your membership level (0 = NONE, 1 = BRONZE, 2 = SILVER, 3 = GOLD): ";
    cin >> membershipChoice;

    switch (membershipChoice)
    {
    case 1: return BRONZE;
    case 2: return SILVER;
    case 3: return GOLD;
    default: return NONE;
    }
}
void displayCart(Item cart[], int cartSize)
{
    cout << "\nYour cart items: " << endl;
    for (int i = 0; i < cartSize; i++)
    {
        cout << i + 1 << ". " << cart[i].name << " - $" << cart[i].price << endl;
    }
}
int main()
{
    const int MAX_ITEMS = 100; 
    Item cart[MAX_ITEMS];     
    int cartSize = 0;          
    double totalPrice = 0.0;
    char continueShopping;

    Item storeItems[5] = {
        {"Apple", 1.5},
        {"Banana", 0.75},
        {"Orange", 1.0},
        {"Milk", 2.5},
        {"Bread", 3.0}
    };
    cout << "Welcome to the Shopping Cart System!" << endl;
    do
    {
        cout << "\nItems available in the store:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << storeItems[i].name << " - $" << storeItems[i].price << endl;
        }

        int itemChoice;
        cout << "Select an item by entering the item number: ";
        cin >> itemChoice;

        if (itemChoice > 0 && itemChoice <= 5)
        {
            cart[cartSize] = storeItems[itemChoice - 1];
            totalPrice += storeItems[itemChoice - 1].price;
            cout << storeItems[itemChoice - 1].name << " has been added to your cart." << endl;
            cartSize++;
        }
        else
        {
            cout << "Invalid item selection!" << endl;
        }
        cout << "Do you want to add another item to your cart? (y/n): ";
        cin >> continueShopping;
    } while (continueShopping == 'y' || continueShopping == 'Y');
    displayCart(cart, cartSize);

    MembershipLevel level = getMembershipLevel();

    double finalPrice = applyDiscount(totalPrice, level);

    cout << "\nYour total price after discount is: $" << finalPrice << endl;

    return 0;
}
