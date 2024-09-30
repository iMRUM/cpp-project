//
// Created by imry on 9/29/24.
//

#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H


class Player;
//Concrete command for each operation
class AbstractCommand {
public:
    virtual ~AbstractCommand() = default;
    // The `execute` method that all concrete commands must implement
    virtual void execute(Player& player) = 0;
};



#endif //ABSTRACTCOMMAND_H
