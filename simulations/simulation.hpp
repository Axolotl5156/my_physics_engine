#pragma once

#include "app_config.hpp"

/**
 * @brief abstract class for all simulations
 */
class ISimulation
{

    public :

        ISimulation() = default;
        virtual ~ISimulation() = default;

        /**
         * @brief will run whatever simulation it is
         */
        virtual void run(AppContext config) = 0;

};