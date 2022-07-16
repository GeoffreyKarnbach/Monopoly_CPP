#include <iostream>
#include "Player.h"
#include "GameBoard.h"
#include "RingList.h"
#include "Utility.h"

using namespace std;

const bool DEBUG = true;
const int JAIL_ID = 10;

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
    else
    {
        playBoard.outputBoard();
    }

    int turnNumber = 0;
    bool replay = false;
    int repeated = 0;

    Player temp(1000,"TEMP");
    Player& current =  temp;
    while (players.playerNumber() > 0 && turnNumber < 1000)
    {

        if (repeated == 3) //If the player has diced three times in a row two identical diced, the player goes to jail
        {
            cout << "Player goes to jail" << endl;
            repeated = 0;
            replay = false;

            //current.setField(JAIL_ID); // Sets the player to jail field //TODO:Implement special handling if current player is in jail (Maybe skip)

            int x; //TODO: Remove, temporary marker to show if player goes to jail (DEBUG)
            cin >> x;

            continue;
        }

        if (!replay) //If there is a new turn where the last player didn't roll identical dices, set the current player to the next in the ringlist
        {
            cout << endl;
            Player& current = players.getNext();
            cout << current.toString() << endl;
        }
        cout << current.toString() << endl;


        int diceRoll1 = Utility::getRandom(6);
        int diceRoll2 = Utility::getRandom(6);

        int diceRoll = diceRoll1 + diceRoll2;

        int startField = current.getField();

        GameFields result = playBoard.getAfter(startField, diceRoll); //Compute new field where player arrives depending on
        int resultField = result.getIndex();

        current.setField(resultField);

        if (resultField < startField) //Take into account if player crosses the start field to receive +200
        {
            current.addMoney(200);
        }

        if (result.handler(current))
        {
            players.removePlayer(current);
        }

        cout << current.toString() << " after rolling a " << diceRoll << " (" << diceRoll1 << " + " << diceRoll2 << ")." << endl;

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