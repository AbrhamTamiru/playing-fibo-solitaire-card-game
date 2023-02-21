/*
    Name: Abrham Tamiru
    Date: 2/21/2023
    section: CECS 325 sec 02
    statement of integrity: Is done by Abrham Tamiru
*/
#include<iostream>
#include<random>
#include<ctime>
#include <cstdlib>
using namespace std;

const int numCard = 52;

class Card
{
    char suit;
    char rank;

public:
    Card(); // create a “default” card

    Card(char r, char s); // constructor to create a card, setting the rank and suit
    void setCard(char r, char s); //set existing card to new values
    int getValue();// return the point value of the card. Ace = 1, 2 thru 10, Jack = 10, Queen = 10,King = 10
    void show(); // show the card using 2 fields… Ace of Spade:AS, Ten of Diamond:10D, Queen of Heart : QH, Three of Club : 3C.
};

class Deck
{
private:
    Card deck[52];
    int numCard;
public:
    Deck();// constructor which creates a deck of 52 cards. Ace of Spades on top, followed by the rest of the spades in order, followed by Hearts, Diamondsand Clubs.

    void resetDeck();// reset the deck so it looks like a new deck.
    Card deal(); // deal a card from the top of the deck.

    void shuffle();//shuffle the card in the deck
    bool isEmpty();// true is deck is empty, false if the deck is not empty
    void show(); //show all the cards in the deck : 13 columns and 4 rows.
};

Deck::Deck() //create deck of 52 cards
{
    char ranks[] = { 'A','2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };// T hold for 10
    char suits[] = { 'S','H','C','D' };
    int index = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {

            deck[index] = Card(ranks[j], suits[i]);
            index++;

        }
    }
    numCard = 52;
}

void Deck::resetDeck() // create a new deck 
{
    char ranks[] = { 'A','2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
    char suits[] = { 'S','H','C','D' };
    int index = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {

            deck[index] = Card(ranks[j], suits[i]);
            index++;
        }
    }
    numCard = 52;
}

Card Deck::deal()
{
    Card top = deck[numCard - 1];// takes a card from the top
    numCard = numCard - 1;
    return top;
}

void Deck::shuffle()
{
    
    for (int i = 0; i < 52; i++)
    {
        int a = rand() % 52;
        int b = rand() % 52;
        Card temp = deck[a];// pick two random cards and swap them
        deck[a] = deck[b];
        deck[b] = temp;
    }
}

bool Deck::isEmpty()
{
    return(numCard == 0);//deck is empty if number of card is zero

}


void Deck::show() //display the deck in 4 *13
{
    for (int i = 0; i < 52; i++)
    {
        if (i % 13 == 0 && i != 0)
        {
            cout << endl;
            deck[i].show();
            cout << " ";
        }
        else {
            deck[i].show();
            cout << " ";
        }
    }
}
Card::Card()
{
    rank = suit = ' ';
}
Card::Card(char r, char s)
{
    rank = r;
    suit = s;
}

void Card::setCard(char r, char s)
{
    rank = r;
    suit = s;
}

int Card::getValue()
{
    if (rank == 'A')
    {
        return 1;
    }
    else if (rank == '2') {
        return 2;
    }
    else if (rank == '3') {
        return 3;
    }
    else if (rank == '4') {
        return 4;
    }
    else if (rank == '5') {
        return 5;
    }
    else if (rank == '6') {
        return 6;
    }
    else if (rank == '7') {
        return 7;
    }
    else if (rank == '8') {
        return 8;
    }
    else if (rank == '9')
    {
        return 9;
    }


    else if (rank == 'K' || rank == 'Q' || rank == 'J') // K,Q,J have a value of 10
    {
        return 10;
    }
    else  //used for T 
    {
        return 10;
    }

}

void Card::show()
{


    if (rank == 'T') //replace T by 10
    {
        cout << 10 << suit << ",";
    }
    else
        cout << rank << suit << ",";

}


bool isFibonacci(int val) // check for a given number is fibo
{
    int x = 0;
    int y = 1;
    int z = x + y;
    while (z < val)
    {
        x = y;
        y = z;
        z = x + y;
    }
    return z == val;
}

int main()
{
    Deck deck;
    int userChoice;
    bool isWinner = false;
    srand(time(0));

    while (true)
    {
        cout << "\nWelcome to Fibonacci Solitaire!" << endl;
        cout << "1. Create New Deck" << endl;
        cout << "2. Shuffle Deck" << endl;
        cout << "3. Display Deck" << endl;
        cout << "4. Play Fibo Solitaire" << endl;
        cout << "5. Win Fibo Solitaire" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        int sum = 0, piles = 0;
        int numAttempt = 0;

        switch (userChoice)
        {
        case 1:
            deck.resetDeck();
            cout << "\nA new deck is created.\n" << endl;
            break;
        case 2:
            cout << "\nThe card is shuffled:\n " << endl;
            deck.shuffle();
            break;
        case 3:

            cout << "\nThe deck is displayed below.\n " << endl;
            deck.show();
            cout << endl;
            break;

        case 4:
            deck.resetDeck();
            deck.shuffle();
            cout << "Playing Fibonacci Solitaire..." << endl;

            while (!deck.isEmpty())
            {
                Card top = deck.deal();
                sum += top.getValue();
                top.show();// show the deal cards
                cout << " ";

                if (isFibonacci(sum))
                {
                    cout << "Fibo:" << sum << endl;
                    piles++;
                    sum = 0; //if fibo deal other card and start adding from 0
                    
                    if (deck.isEmpty())
                    {
                        cout << "\nWinner in: " << piles << " piles" << endl;
                    }
                }
                else if (deck.isEmpty())
                {
                    if (sum != 0)
                    {
                        cout << "Fibo:" << sum << endl;
                    }
                    cout << "\nLosses in: " << piles + 1 << " piles" << endl;// piles+1 since it doesnt count the last pile
                }
            }

            break;
        case 5:
            numAttempt = 0;
           
            while (!isWinner) // play untill iswinner = true
            {
                deck.resetDeck();
                deck.shuffle();
                sum = 0;
                piles = 0;

                

                while (!deck.isEmpty())
                {
                    Card top = deck.deal();
                    sum += top.getValue();//sum the deal deck in the loop
                    top.show();
                    cout << " ";
                    if (isFibonacci(sum))
                    {
                        cout << "Fibo:" << sum << endl;
                        piles++;
                        sum = 0;

                        if (deck.isEmpty())
                        {
                            isWinner = true;
                            cout << "\nWinner in: " << piles << " piles" << endl;
                          
                            
                            break;
                        }
                    }
                }
                numAttempt++;
                cout << "\nnumber of played: " << numAttempt << "\n" << endl;
            }
            break;
        case 6:
            cout << "Exit" << endl;
            exit(0);
        break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
    return 0;
}
