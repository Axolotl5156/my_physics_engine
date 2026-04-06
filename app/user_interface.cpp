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
        return std::make_unique<FloatingBallsSimulation>();
    };
    m_simulations["pendulum"] = []()
    {
        return std::make_unique<PendulumSimulation>();
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
    std::vector<std::string> args;
    std::string token;

    while(iss >> token)
    {
        args.push_back(token);
    }

    if(args.empty())
        return;

    const std::string &cmd = args[0];

    if(cmd.compare("list") == 0)
        cmd_list();
    else if(cmd.compare("run") == 0)
        cmd_run(args);
    else if(cmd.compare("record") == 0)
        cmd_record(args);
    else if(cmd.compare("help") == 0)
        cmd_help();
    else if(cmd.compare("quit") == 0)
        cmd_quit();
    else if(cmd.compare("test") == 0)
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

void UserInterface::cmd_record(const std::vector<std::string> &args)
{
    if(args.size() < 2 || args.size() > 3)
    {
        std::cout << "Usage: record enable <path (default=\"video.mp4\")>|disable" << std::endl;
        return;
    }

    const std::string &action = args[1];

    if (action.compare("enable") == 0)
    {
        m_context.record_enable = true;
        std::cout << "record enabled" << std::endl;

        if(args.size() == 3)
        {
            m_context.output_file = args[2];
            std::cout << "output file = " << args[2] << std::endl;
        }
        else
        {
            std::cout << "no specified output file, set to default : \"video.mp4\"" << std::endl;
            m_context.output_file = "video.mp4";
        }
        // m_context.record_enable = true;
        // std::cout << "Recording enabled" << std::endl;
    }
    else if (action.compare("disable") == 0)
    {
        m_context.record_enable = false;
        std::cout << "Recording disabled" << std::endl;
    }
    else
    {
        std::cout << "Usage: record enable|disable" << std::endl;
    }
}

void UserInterface::cmd_help()
{
    std::cout << "Commands :" << std::endl;
    std::cout << " list : list all simulations available" << std::endl;
    std::cout << " run <simulation> : run the simulation" << std::endl;
    std::cout << " record [record enable [output_path] : enable record. Default path is \"video.mp4\" " << std::endl;
    std::cout << " record disable : disabled record" << std::endl;
    std::cout << " help : show all commands" << std::endl;
    std::cout << " quit : exit the program" << std::endl;
}

void UserInterface::cmd_quit()
{
    std::cout << "Exiting program" << std::endl;
    m_is_running = false;
}

void UserInterface::cmd_run(const std::vector<std::string> &args)
{
    // auto it = m_simulations.find(sim_name);
    // if(it == m_simulations.end())
    // {
    //     std::cout << "Simulation " << sim_name << " not found" <<std::endl;
    //     return;
    // }

    // auto sim = it->second();
    // sim->run(m_context);
    if(args.size() < 2)
    {
        std::cout << "usage run <simulation>" << std::endl;
        return;
    }

    const std::string &name = args[1];
    auto it = m_simulations.find(name);
    
    if(it == m_simulations.end())
    {
        std::cout << "Simulation " << name << " not found" <<std::endl;
        return;
    }

    std::unique_ptr<ISimulation> sim = it->second();
    sim->run(m_context);

}

void UserInterface::cmd_testsim()
{
    std::unique_ptr sim = std::make_unique<TestSim>();
    sim->run(m_context);
}