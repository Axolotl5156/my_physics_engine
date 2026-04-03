#include <iostream>
#include <memory>

#include "bouncing_ball.hpp"
#include "floating_balls.hpp"

int main()
{

    bool can_simulate = false;

    std::cout << std::endl;
    std::cout << "Select simulation" << std::endl << std::endl;
    std::cout << "1 : Bouncing Ball" << std::endl;
    std::cout << "2 : Floating Balls" << std::endl;
    std::cout << std::endl;
    std::cout << "> ";

    int choice;
    std::cin >> choice;

    std::unique_ptr<ISimulation>simulation;

    switch(choice)
    {
        case 1:
            simulation = std::make_unique<BouncingBallSimulation>();
            can_simulate = true;
            break;
        case 2:
            simulation = std::make_unique<FloatingBalls>();
            can_simulate = true;
            break;
        default:
            std::cout << "invalid choice" << std::endl;
            break;
    }

    if(can_simulate)
        simulation->run();

    return 0;
}