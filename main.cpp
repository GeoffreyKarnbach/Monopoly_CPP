#include <iostream>
#include "Player.h"
#include "GameBoard.h"
#include "RingList.h"
#include "Utility.h"

using namespace std;

const bool DEBUG = false;


void playerTurnTest()
{
    srand(time(0)); //Start Random Engine

    Player player1(1000, "Player1");
    Player player2(1000, "Player2");
    Player player3(1000,"Player3");
    Player player4(1000, "Player4");

    RingList players(player1);
    players.addPlayer(player2);
    players.addPlayer(player3);
    players.addPlayer(player4);

    cout << "A total of " << to_string(players.playerNumber()) << " players have been added to the game." << endl << endl;
    int currentTurn = 1;

    while (players.playerNumber() > 0 && currentTurn < 100)
    {
        Player& current = players.getNext();
        cout << "(TURN "+ to_string(currentTurn)+") Current player is: " << current.toString() << endl;

        int odd = rand()%10+1;

        if (odd == 8)
        {
            cout << "Current player has been eliminated. Game will go on without him." << endl << endl;
            players.removePlayer(current);
        }
        else
        {
            cout << "Current player finished his turn. Next turn." << endl << endl;
        }

        currentTurn++;
    }
}

//TODO: Create CSV File with all Luck and Community cards available

void play()
{
    srand(time(0));
    GameBoard playBoard;
    playBoard.generate();

    Player player1(1000, "Player1");
    Player player2(1000, "Player2");
    Player player3(1000,"Player3");
    Player player4(1000, "Player4");

    RingList players(player1);
    players.addPlayer(player2);
    players.addPlayer(player3);
    players.addPlayer(player4);

    if (DEBUG)
    {
        playBoard.outputComplexBoard();
    }

    int turnNumber = 0;
    bool replay = false;
    int repeated = 0;

    Player* current =  &(players.getNext());

    while (players.playerNumber() > 0 && turnNumber < 1000)
    {
        if (repeated == 3) //If the player has diced three times in a row two identical diced, the player goes to jail
        {
            cout << "Player goes to jail" << endl;
            current->goToJail();
            repeated = 0;
            replay = false;
            continue;
        }

        if (!replay) //If there is a new turn where the last player didn't roll identical dices, set the current player to the next in the ringlist
        {
            cout << endl;
            current = &(players.getNext());

            if (current->jailLength() != 0)
            {
                if (current->jailLength() == 3)
                {
                    current->leaveJail();
                    cout << current->toString() << endl << "HAS LEFT JAIL." << endl;
                    int x;
                    cin >> x;
                }
                else
                {
                    //TODO: Implement more jail features as paying or having an out of jail card
                    cout << current->toString() << " is still in jail since " << current->jailLength() << " turns." << endl;
                    current->stayInJail();
                    continue;
                }
            }
        }

        int diceRoll1 = Utility::getRandom(6);
        int diceRoll2 = Utility::getRandom(6);

        int diceRoll = diceRoll1 + diceRoll2;

        int startField = current->getField();

        GameFields result = playBoard.getAfter(startField, diceRoll); //Compute new field where player arrives depending on
        int resultField = result.getIndex();

        current->setField(resultField);

        if (resultField < startField) //Take into account if player crosses the start field to receive +200
        {
            current->addMoney(200);
        }

        if (result.handler(*current))
        {
            players.removePlayer(*current);
        }

        cout << current->toString() << " after rolling a " << diceRoll << " (" << diceRoll1 << " + " << diceRoll2 << ")." << endl;

        if (diceRoll1 == diceRoll2)
        {
            replay = true;
            repeated++;
        }
        else
        {
            replay = false;
            repeated = 0;
        }

        turnNumber++;
    }
}

int main()
{
    play();
    return 0;
}