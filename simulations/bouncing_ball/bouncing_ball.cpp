
#include "bouncing_ball.hpp"

#include "world.hpp"
#include "body.hpp"
#include "circleShape.hpp"
#include "rendererSFML.hpp"

void BouncingBallSimulation::run()
{
    World world(800, 600);
    world.set_gravity(981.f);
    world.set_restition(0.8f);

    std::unique_ptr<Shape> shape = std::make_unique<CircleShape>(10.f);
    std::unique_ptr<Body> ball = std::make_unique<Body>(400.f, 100.f, 0.f, 0.f, 1.f, std::move(shape));

    world.add_body(std::move(ball));

    RendererSFML renderer(world.get_width(), world.get_height(), "Bouncing ball", sf::Color(20,20,20,255));
    renderer.enable_recording("video.mp4");

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

    if(renderer.is_recording())
        renderer.finalize_recording();

}