//
// Created by imry on 9/29/24.
//

#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H
#include "../../model/Components/Player.h"

class Player;
//Abstract class command for commands processing
class AbstractCommand {
protected:
    Player* _player;
public:
    AbstractCommand(Player* player = nullptr): _player(player) {}
    virtual ~AbstractCommand() = default;
    // The `execute` method that all concrete commands must implement
    virtual void execute() = 0;

    Player* getPlayer() const {
        return _player;
    }
};



#endif //ABSTRACTCOMMAND_H
