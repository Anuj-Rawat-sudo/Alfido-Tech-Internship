#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Base Class
class Product
{
protected:
    int id;
    string name;
    double price;

public:
    Product(int i, string n, double p)
    {
        id = i;
        name = n;
        price = p;
    }

    virtual void display()
    {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Price: " << price << endl;
    }

    virtual string saveData()
    {
        return to_string(id) + "," + name + "," + to_string(price);
    }
};

// Derived Class
class Electronics : public Product
{
private:
    int warranty;

public:
    Electronics(int i, string n, double p, int w)
        : Product(i, n, p)
    {
        warranty = w;
    }

    void display() override
    {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Price: " << price
             << " | Warranty: " << warranty << " Months"
             << endl;
    }

    string saveData() override
    {
        return to_string(id) + "," + name + "," +
               to_string(price) + "," +
               to_string(warranty);
    }
};

int main()
{
    vector<Product*> products;

    int choice;

    do
    {
        cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Normal Product\n";
        cout << "2. Add Electronic Product\n";
        cout << "3. View Products\n";
        cout << "4. Save Products To File\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name;
            double price;

            cout << "Enter Product ID: ";
            cin >> id;

            cout << "Enter Product Name: ";
            cin >> name;

            cout << "Enter Product Price: ";
            cin >> price;

            products.push_back(
                new Product(id, name, price));

            cout << "Product Added Successfully!\n";
        }

        else if (choice == 2)
        {
            int id, warranty;
            string name;
            double price;

            cout << "Enter Product ID: ";
            cin >> id;

            cout << "Enter Product Name: ";
            cin >> name;

            cout << "Enter Product Price: ";
            cin >> price;

            cout << "Enter Warranty (Months): ";
            cin >> warranty;

            products.push_back(
                new Electronics(
                    id,
                    name,
                    price,
                    warranty));

            cout << "Electronic Product Added Successfully!\n";
        }

        else if (choice == 3)
        {
            if (products.empty())
            {
                cout << "No Products Available!\n";
            }
            else
            {
                cout << "\n----- Product List -----\n";

                for (auto p : products)
                {
                    p->display();
                }
            }
        }

        else if (choice == 4)
        {
            ofstream file("products.txt");

            for (auto p : products)
            {
                file << p->saveData() << endl;
            }

            file.close();

            cout << "Data Saved To products.txt Successfully!\n";
        }

    } while (choice != 5);

    cout << "\nThank You!\n";

    return 0;
}
