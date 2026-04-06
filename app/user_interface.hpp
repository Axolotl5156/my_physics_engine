#pragma once
#include <unordered_map>
#include <memory>
#include <functional>

#include "simulation.hpp"
#include "bouncing_ball.hpp"
#include "floating_balls.hpp"
#include "pendulum.hpp"
#include "test_sim.hpp"

#include "app_config.hpp"

/**
 * @brief the front line of the programm
 * 
 * this class handle all user input
 */
class UserInterface
{

    private :

        AppContext m_context;
        std::unordered_map<std::string, std::function<std::unique_ptr<ISimulation>()>> m_simulations;
        bool m_is_running = true;

        void handle_command(const std::string &input);
        
        void cmd_list();
        void cmd_record(const std::vector<std::string> &args);
        void cmd_run(const std::vector<std::string> &args);
        void cmd_help();
        void cmd_quit();
        void cmd_testsim();

    public :

        UserInterface();

        /**
         * @brief the starting point of the program
         */
        void run();
        
};