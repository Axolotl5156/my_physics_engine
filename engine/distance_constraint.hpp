#pragma once

#include "constraint.hpp"
#include "body.hpp"

class DistanceConstraint : public Constraint
{
    
    private : 
        Body *m_body_a;
        Body *m_body_b;
        float m_lenght;

    public :

        DistanceConstraint(Body *body_a, Body *body_b);

        void solve();

};