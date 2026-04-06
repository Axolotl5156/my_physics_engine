#pragma once

#include "simulation.hpp"

/**
 * @brief a simulation of multiple boncing balls
 */
class FloatingBallsSimulation : public ISimulation
{

    public :

        /**
         * @brief run the bouncing ball simulation
         */
        void run(AppContext config);

};

