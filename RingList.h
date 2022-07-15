//
// Created by Geoffrey on 14.07.2022.
//

#ifndef MONOPOLY_RINGLIST_H
#define MONOPOLY_RINGLIST_H

#include <vector>
#include "Player.h"

class RingList {
private:
    vector<Player*> playerList;
    int index = 0;

    /*
     * Helper method to get Index of a given Player. Outputs either the value in interval [0, vector.size()] or if
     * not found the value -1.
     */
    int getIndex(Player& toFind);

public:

    /*
     * Ability to parse a first player in constructor.
     */
    RingList(Player& first);

    //TODO: Add new constructor to add ability to pass entire Player List/Array/Vector

    /*
     * Base constructor to reset the player Ringlist.
     */
    RingList();

    /*
     * Adds player to Ringlist. Returns true if there was no issue encountered.
     */
    bool addPlayer(Player& toAdd);

    /*
     * Tries to remove given Player from Ring list (for instance once the player has been disqualified).
     * If the removal is successful, the method returns true, in opposite case, false is returned.
     *
     * Also includes computation of index to ensure, that no players are skipped because of the removal of a player.
     */
    bool removePlayer(Player& toRemove);

    /*
     * Returns next Player that should play. Ring list work around by using a vector and a currentIndex variable, that is used modulo the playerCount.
     */
    Player& getNext();

    /*
     * Returns amount of active players in match.
     */
    int playerNumber();
};


#endif //MONOPOLY_RINGLIST_H
