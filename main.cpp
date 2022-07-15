#include <iostream>
#include "Player.h"
#include "GameBoard.h"
#include "RingList.h"
#include "Utility.h"

using namespace std;

const bool DEBUG = true;

void playerTurnTest()
{
    srand(2022); //Start Random Engine

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
        Player current = players.getNext();
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

    while (players.playerNumber() > 0 && turnNumber < 100)
    {
        Player current = players.getNext();

        int diceRoll = Utility::getRandom(6);
        int startField = current.getField();

        GameFields result = playBoard.getAfter(startField, diceRoll);
        int resultField = result.getIndex();
        current.setField(resultField); //TODO: Fix player position not updating in method (Probably due to absence of usage of pointers??)

        if (resultField < startField)
        {
            current.addMoney(200);
        }

        if (result.handler(current))
        {
            players.removePlayer(current);
        }

        turnNumber++;
    }
}

int main()
{
    play();
    return 0;
}