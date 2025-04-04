#ifndef GAME_STATE_LOGGER_H
#define GAME_STATE_LOGGER_H

#include "Updatable.h"

class JSONGenerator;
/*
 * The GameStateLogger logs the current state of the game to a log file.
 * It does this every X seconds.
 * This logged data can be used to analyze the game afterwards.
 *
 * The resulting log contains 2 types of records:
 * 1) Periodic game data, update of all the objects in the game with all states.
 * 2) Events fired by certain actions. Missile firing, beams firing, damage, destruction of certain objects.
 */
class GameStateLogger : public Updatable
{
public:
    GameStateLogger();
    virtual ~GameStateLogger();

    void start();
    void stop();

    virtual void update(float delta) override;

private:
    FILE* log_file;
    float logging_interval;
    float logging_delay;
    float start_time;
    std::map<int, glm::vec2> static_objects;

    void logGameState();
};

#endif//GAME_STATE_LOGGER_H
