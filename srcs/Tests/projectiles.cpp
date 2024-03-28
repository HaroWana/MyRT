#include "../../includes/tests.hpp"

Projectile    tick(Environment env, Projectile proj)
{
    Point pos = proj.pos + proj.vel;
    Vector  vel = proj.vel + env.grav + env.wind;
    Projectile ret;
    ret.pos = pos;
    ret.vel = vel;
    return (ret);
}

void    shoot_up()
{
    Projectile  proj;
    proj.vel = Vector(1, 1.8, 0);
    proj.vel.normalize();
    proj.vel * 11.25f;
    Environment env;
    for (int i = 0; proj.pos.getCoor('y') > 0; i++)
    {
        proj = tick(env, proj);
        std::string frame = "Frame: " + std::to_string(i);
        std::string position = "Position = " + std::to_string(proj.pos.getCoor('x')) + ", " + std::to_string(proj.pos.getCoor('y')) + ", " + std::to_string(proj.pos.getCoor('z'));
        print(LEFT, frame, LINELENGTH, FCYAN, NOC, BOLD);
        print(RIGHT, position, LINELENGTH - frame.length(), FWHITE, NOC, BOLD);
        std::cout << std::endl;
    }
}