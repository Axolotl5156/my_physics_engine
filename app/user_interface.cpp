#include "user_interface.hpp"

#include <iostream>
#include <sstream>

UserInterface::UserInterface()
{
    m_simulations["bouncing_ball"] = []()
    {
        return std::make_unique<BouncingBallSimulation>();
    };
    m_simulations["floating_balls"] = []()
    {
        return std::make_unique<FloatingBalls>();
    };
}

void UserInterface::run()
{
    std::string input;

    std::cout << std::endl;
    std::cout << "Type 'help' for commands" << std::endl;
    
    while(m_is_running)
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        std::cout << std::endl;
        handle_command(input);
        std::cout << std::endl;
    }

}

void UserInterface::handle_command(const std::string &input)
{
    std::istringstream iss(input);
    std::string cmd;
    iss >> cmd;

    if(cmd.compare("list") == 0)
        cmd_list();
    else if(cmd.compare("run") == 0)
    {
        std::string name;
        iss >> name;
        cmd_run(name);
    }
    else if(cmd.compare("record") == 0)
    {
        std::string arg;
        iss >> arg;
        cmd_record(arg);
    }
    else if(cmd.compare("help") == 0)
        cmd_help();
    else if(cmd.compare("quit") == 0)
        cmd_quit();
    else if(cmd.compare("testsim") == 0)
        cmd_testsim();
    else
    {
        std::cout << "Unknown command" << std::endl;
    }
}

void UserInterface::cmd_list()
{
    std::cout << "list of available simulations:" << std::endl;
    for(const auto [name, _] : m_simulations)
    {
        std::cout << " - " << name << std::endl;
    }
}

void UserInterface::cmd_record(const std::string &arg)
{
    if (arg.compare("enable") == 0)
    {
        m_context.record_enable = true;
        std::cout << "Recording enabled\n";
    }
    else if (arg.compare("disable") == 0)
    {
        m_context.record_enable = false;
        std::cout << "Recording disabled\n";
    }
    else
    {
        std::cout << "Usage: record enable|disable\n";
    }
}

void UserInterface::cmd_help()
{
    std::cout << "Commands :" << std::endl;
    std::cout << " list : list all simulations available" << std::endl;
    std::cout << " run <simulation> : run the simulation" << std::endl;
    std::cout << " record [enable|disable] : enable or disable the record" << std::endl;
    std::cout << " help : show all commands" << std::endl;
    std::cout << " quit : exit the program" << std::endl;
}

void UserInterface::cmd_quit()
{
    std::cout << "Exiting program" << std::endl;
    m_is_running = false;
}

void UserInterface::cmd_run(const std::string &sim_name)
{
    auto it = m_simulations.find(sim_name);
    if(it == m_simulations.end())
    {
        std::cout << "Simulation " << sim_name << " not found" <<std::endl;
        return;
    }

    auto sim = it->second();
    sim->run(m_context);
}

void UserInterface::cmd_testsim()
{
    std::unique_ptr sim = std::make_unique<TestSim>();
    sim->run(m_context);
}