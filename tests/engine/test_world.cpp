#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "world.hpp"
#include "circleShape.hpp"
#include <memory>

TEST_CASE("Test World setters and getters", "[world]")
{
    World world(800.f, 600.f, 50.f, 1.f);

    REQUIRE(world.get_width() == Catch::Approx(800.f));
    REQUIRE(world.get_height() == Catch::Approx(600.f));
    REQUIRE(world.get_gravity() == Catch::Approx(50.f));
    REQUIRE(world.get_restitution() == Catch::Approx(1.f));

    world.set_gravity(60.f);
    world.set_restition(2.f);

    REQUIRE(world.get_gravity() == Catch::Approx(60.f));
    REQUIRE(world.get_restitution() == Catch::Approx(2.f));

}

TEST_CASE("Body falls due to gravity", "[world]")
{
    World world(800.f, 600.f);

    std::unique_ptr<Body> body = std::make_unique<Body>(
        100.f, 100.f, 1.f,
        std::make_unique<CircleShape>(10.f), BodyType::Dynamic
    );

    Body* ptr = body.get();
    world.add_body(std::move(body));

    world.update_world(1.0f);

    REQUIRE(ptr->get_pos_y() > 100.f); // doit descendre
}

TEST_CASE("Body bounces on ground", "[world]")
{
    World world(800.f, 600.f);

    std::unique_ptr<Body> body = std::make_unique<Body>(
        100.f, 590.f, 1.f,
        std::make_unique<CircleShape>(10.f), BodyType::Dynamic
    );

    body->set_vel_x(0.f);
    body->set_vel_y(100.f);

    Body* ptr = body.get();
    world.add_body(std::move(body));

    world.update_world(0.1f);

    REQUIRE(ptr->get_vel_y() < 0.f); // doit rebondir
}