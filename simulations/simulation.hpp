#pragma once

class ISimulation
{

    public :

        ISimulation() = default;
        virtual ~ISimulation() = default;

        virtual void run() = 0;

};