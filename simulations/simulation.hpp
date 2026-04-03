#pragma once

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
        virtual void run() = 0;

};