#include <iostream>
#include <memory>

#include "bouncing_ball.hpp"

int main()
{

    std::cout << std::endl;
    std::cout << "Select simulation" << std::endl << std::endl;
    std::cout << "1 : Bouncing Ball" << std::endl;
    std::cout << std::endl;
    std::cout << "> ";

    int choice;
    std::cin >> choice;

    std::unique_ptr<ISimulation>simulation;

    switch(choice)
    {
        case 1:
            simulation = std::make_unique<BouncingBallSimulation>();
            break;
        default:
            std::cout << "invalid choice" << std::endl;
    }

    simulation->run();

    return 0;
}