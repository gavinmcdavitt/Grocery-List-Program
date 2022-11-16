#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;
const int SIZE =51;
void DisplayArray(double prices[], string items[]);
void ChangeArray(double prices[], string items[]);
string GetValidName();
void IsOptionInArray(double prices[], string items[]);
double GetValidPrice();
int ArrayElement(double prices[], string items[]);
void displayArrayAsc(double prices[], string items[]);
double getMax(double prices[], string items[]);
void countSort(double prices[], string items[], int exp);
void displayArrayBubble(double prices[], string items[]);
void searchPrices(double prices[], string items[]);

int main() {
    double prices[] = {3.99,4.99,2.99,3.50,4.50,6.00,9.00,1.25,1.25,4.50,3.25,
                       3.75,4.00,6.25,4.75,2.05,3.00,2.75,4.25,4.75,5.00,
                       3.75,4.65,5.25,6.00,2.00, 3.75,4.25,13.99,4.25,6.99,
                       7.99,4.55,3.75,6.99,4.99, 4.25,2.95,3.25,5.25,5.75,3.00,
                       3.25,4.75,5.15,5.35,6.30, 4.25,7.25,6.75,5.99};
    string items[] = {"apples", "pears", "bananas", "oranges", "berries","grapes", "melons", "lemon", "lime",
                      "milk", "butter", "eggs", "sour cream", "creamer", "cream cheese", "yogurt", "salt",
                      "taco seasoning", "toilet paper", "paper towels", "tissues","napkins", "aluminum foil",
                      "plastic wrap", "plastic bags", "soap","shampoo", "conditioner","razors", "shaving cream",
                      "deodorant", "lotion", "toothpaste", "floss", "pain reliever", "salad", "broccoli",
                      "carrots", "cucumbers", "garlic", "lettuce", "tomatoes", "mushrooms", "onions",
                      "peppers", "potatoes", "squash", "zucchini", "pizza","waffles", "ice cream"};
    const int ONE =1;
    int option;
    //cin >>option;
    while(ONE<2) {
        cout<<"Select these options below"<<endl;
        cout<<"1.) display the items and price"<<endl;
        cout <<"2.) change the price of an item"<<endl;
        cout <<"3.) Calculate the total amount of selected items"<<endl;
        cout<<"4.) Display prices in descending order"<<endl;
        cout <<"5.) Display prices in ascending order"<<endl;
        cout<< "6.) search using prices"<<endl;
        cin >>option;
        if(option ==1) {
            DisplayArray(prices, items);
            continue;
        }
        if (option ==2)
        {
            ChangeArray(prices, items);
            continue;
        }
        if(option==3)
        {
            IsOptionInArray(prices,items);
            continue;
        }
        if(option==4)
        {
           displayArrayAsc(prices, items);
           continue;
        }
        if(option ==5)
        {
            displayArrayBubble(prices,items);
        }
        if(option==6)
        {
            searchPrices(prices, items);
        }
        if(option ==99)
        {
            break;
        }
    }
    return 0;
}

/*
 * First function simply displays the array.
 */
    void DisplayArray(double prices[], string items[])
    {
        for(int i =0; i<SIZE; i++)
        {
            cout <<i+1 <<".) The price of "<<items[i]<< " is "<<setw(5)<<fixed << setprecision(2)<<prices[i]<<endl;
        }
    }
    /*
     * ChangeArray simply takes the price of a new item and new name that changes it.
     */
    void ChangeArray(double prices[], string items[])
    {
        double cost;
        string name;
        int num;
        cost = GetValidPrice();
        name = GetValidName();
        num = ArrayElement(prices,items);
        prices[num]= cost;
        items[num] = name;

    }
    double GetValidPrice()
    {
        cout <<"Please enter a valid price"<<endl;
        double price;
        cin >> price;
        while(price<=0)
        {
            cout<<"Please enter a valid price"<<endl;
            cin>>price;
        }
        return price;
    }
    string GetValidName()
    {
        string name;
        cout<<"What is the name of the new item?"<<endl;
        getline(cin>> ws,name);
        cout<<name <<endl;
        return name;
    }
    int ArrayElement(double prices[], string items[])
    {
        DisplayArray(prices, items);
        cout <<endl;
        cout<<"which number you would like to change."<<endl;
        cout<<endl;
        int num;
        cin >>num;
        num= num-1;
        return num;
    }

    void IsOptionInArray(double prices[], string items[])
    {
        double sum = 0;
        int i,j;
        string option;
        string newArray[SIZE];
        int num = 0;
        string shop=" ";
        cout << "How many items would you like to buy?" << endl;
        cin >> num;
        cout << "Please enter in your items" << endl;
        //first loop reads and second loop will be used to verify its in the
        for (i = 0; i < num; ++i)
        {
            cin >> newArray[i];
            transform(newArray[i].begin(), newArray[i].end(), newArray[i].begin(), ::tolower);
            for (j = 0; j <= SIZE; j++) {
                if (newArray[i] == items[j]) {
                    shop = newArray[i];
                    sum=sum + prices[j];
                }
            }
            if(shop==newArray[i])
            {
                cout << "Item is in array : " << newArray[i] << endl;
                cout<< "The sum is: " << sum<<endl;
            }
            else
            {
                cout << "Item is not in the array." << endl;
                continue;
            }
        }
    }
    /*
     * This will be a selection sort as it is faster than bubble sort.
     */
    void displayArrayAsc(double prices[], string items[])
    {


        int maxIndex;
        double maxValue;
        for(int i=0; i <(SIZE-1); i++ )
        {
            maxIndex =i;
            maxValue =prices[i];
            for(int index= i+1; index < SIZE; index++)
            {
                if(prices[index] > maxValue)
                {
                    maxValue= prices[i];
                    maxIndex = index;
                }
            }
            double temp =prices[maxIndex];
            prices[maxIndex] = prices[i];
            prices[i]=temp;
            string temporary = items[maxIndex];
            items[maxIndex]= items[i];
            items[i]=temporary;
        }
        DisplayArray(prices, items);
    }
    void displayArrayBubble(double prices[], string items[])
    {
        int index=0;
        for(int i=0; i <SIZE; i++)
        {
            int swapped =0;
            for(index=0; index <(SIZE - i-1); ++index)
            {
                if(prices[index] > prices[index+1])
                {
                    double temp =prices[index];
                    prices[index] = prices[index+1];
                    prices[index+1]=temp;
                    string temporary = items[index];
                    items[index]= items[index+1];
                    items[index+1]=temporary;

                    swapped =1;
                }
            }
            if(swapped ==0)
            {
                break;
            }
        }
        DisplayArray(prices, items);
    }
    void searchPrices(double prices[], string items[])
    {
        double number;
        cout<<"Please enter prices that you fit your budget"<<endl;
        cin >> number;
        cout<<"The amount of items less than or equal to " << number <<endl;

        for(int i=0; i<SIZE; i++)
        {
            if(prices[i]<=number)
            {
                cout<<i+1 <<".) The price of "<< items[i] << " is " <<fixed<<setprecision(2) <<prices[i]<<endl;
            }
        }
    }