#include <catch2/catch_test_macros.hpp>

#include "rendererSFML.hpp"
#include "world.hpp"
#include "body.hpp"
#include "circleShape.hpp"

TEST_CASE("Renderer SFML can be constructed", "[renderer]")
{
    RendererSFML renderer1(800, 600, "Test");
    RendererSFML renderer2(800, 600, "Test", sf::Color(20,20,20,255));
    RendererSFML renderer3(800, 600, "Test", 60);
    RendererSFML renderer4(800, 600, "Test", 60, sf::Color(20,20,20,255));

    REQUIRE(renderer1.is_open() == true);
    REQUIRE(renderer2.is_open() == true);
    REQUIRE(renderer3.is_open() == true);
    REQUIRE(renderer4.is_open() == true);
}

TEST_CASE("RendererSFML display and clear doe's not crash", "[renderer]")
{
    RendererSFML renderer(800, 600, "Test");

    renderer.clear();
    renderer.display();

    REQUIRE(renderer.is_open() == true);
}

TEST_CASE("RendererSFML handles empty world", "[renderer]")
{
    World world(800, 600);
    RendererSFML renderer(800, 600, "Test");

    renderer.clear();
    renderer.draw_frame(world);
    renderer.display();

    REQUIRE(renderer.is_open() == true);
}

TEST_CASE("RendererSFML draws a simple body", "[renderer]")
{
    World world(800, 600);

    auto shape = std::make_unique<CircleShape>(10.f);
    auto body = std::make_unique<Body>(100.f, 100.f, 1.f, std::move(shape), BodyType::Dynamic);

    world.add_body(std::move(body));

    RendererSFML renderer(800, 600, "Test");

    renderer.clear();
    renderer.draw_frame(world);
    renderer.display();

    REQUIRE(renderer.is_open() == true);
}

TEST_CASE("RendererSFML handles multiple bodies", "[renderer]")
{
    World world(800, 600);

    for (int i = 0; i < 10; ++i)
    {
        auto shape = std::make_unique<CircleShape>(10.f);
        auto body = std::make_unique<Body>(i * 20.f, i * 20.f, 1.f, std::move(shape), BodyType::Dynamic);

        world.add_body(std::move(body));
    }

    RendererSFML renderer(800, 600, "Test");

    renderer.clear();
    renderer.draw_frame(world);
    renderer.display();

    REQUIRE(renderer.is_open() == true);
}

TEST_CASE("RendererSFML handles event polling without crash", "[renderer]")
{
    RendererSFML renderer(800, 600, "Test");

    renderer.handle_events();

    REQUIRE(renderer.is_open() == true);
}