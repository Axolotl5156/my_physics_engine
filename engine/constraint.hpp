#pragma once

class Constraint
{
    public:
        Constraint() = default;
        virtual ~Constraint() = default;

        virtual void solve() = 0;
};