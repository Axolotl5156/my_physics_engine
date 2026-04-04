
#include "floating_balls.hpp"

#include <iostream>

#include "world.hpp"
#include "body.hpp"
#include "circleShape.hpp"
#include "rendererSFML.hpp"

struct BodyInit
{
    float pos_x, pos_y;
    float vel_x, vel_y;
};

void FloatingBalls::run(AppContext config)
{

    World world(800, 600, 0.f, 1.f);

    std::vector<BodyInit> inits = {
        {200.f, 150.f, -150.f,  150.f},
        {400.f, 150.f,  150.f, -150.f},
        {600.f, 150.f,  150.f,  150.f},
        {200.f, 300.f, -150.f, -150.f},
        {400.f, 300.f,  200.f,    0.f},
        {600.f, 300.f,    0.f, -150.f},
        {200.f, 450.f,  150.f,    0.f},
        {400.f, 450.f,    0.f,  150.f},
        {600.f, 450.f, -150.f,    0.f}
    };

    for(BodyInit init : inits)
    {
        std::unique_ptr<Shape> shape = std::make_unique<CircleShape>(15.f);
        std::unique_ptr<Body> body = std::make_unique<Body>(
            init.pos_x, init.pos_y,
            init.vel_x, init.vel_y,
            1.f,
            std::move(shape)
        );
        world.add_body(std::move(body));
    }

    RendererSFML renderer(world.get_width(), world.get_height(), "floating balls");

    if(config.record_enable)
        renderer.enable_recording(config.output_file);

    sf::Clock clock;

    while(renderer.is_open())
    {

        float dt = clock.restart().asSeconds();
        renderer.handle_events();

        if(!renderer.is_paused())
        {
            world.update_world(dt);
        }

        renderer.clear();
        renderer.draw_frame(world);
        renderer.display();
    }

    if(config.record_enable)
        renderer.finalize_recording();
}