#include "../../includes/tests.hpp"

void	ppm_content()
{
	{
		std::string title = "Writing to PPM buffer: ";
    	print(LEFT, title, LINELENGTH, FWHITE, NOC, RESET);
		std::cout << std::endl;
		Image	img = Image(5, 3);
		Color	c1 = Color(1.5, 0, 0);
		Color	c2 = Color(0, 0.5, 0);
		Color	c3 = Color(-0.5, 0, 1);
		img.writePixel(0, 0, c1);
		img.writePixel(2, 1, c2);
		img.writePixel(4, 2, c3);
		std::cout << img.canvas_to_ppm() << std::endl;
	}
	{
		std::string title = "PPM lines <= 70 characters: ";
    	print(LEFT, title, LINELENGTH, FWHITE, NOC, RESET);
		std::cout << std::endl;
		Image	img = Image(10, 2);
		for (int w = 0; w < img.width; w++)
		{
			for (int h = 0; h < img.height; h++)
			{
				img.writePixel(w, h, Color(1, 0.8, 0.6));
			}
		}
		std::string ppm = img.canvas_to_ppm();
		std::cout << ppm << std::endl;
		title = "PPM buffer ending with linebreak: ";
    	print(LEFT, title, LINELENGTH, FWHITE, NOC, RESET);
		if (*ppm.rbegin() == '\n')
        	print(RIGHT, "PASS", LINELENGTH - title.length(), FGREEN, NOC, BOLD);
    	else {
        	print(RIGHT, "FAIL", LINELENGTH - title.length(), FRED, NOC, BOLD);
		}
		std::cout << std::endl;
	}
	{
		Image	img(900, 550);
		std::string title = "Drawing projectile on PPM image (Projectile.ppm): ";
    	print(LEFT, title, LINELENGTH, FWHITE, NOC, RESET);
		Projectile  proj;
		proj.vel = Vector(1, 1.8, 0);
    	proj.vel.normalize();
    	proj.vel = proj.vel * 10;
		Environment env;
		for (int i = 0; proj.pos.getCoor('y') >= 0; i++)
		{
			if (proj.pos.getCoor('x') < img.width && proj.pos.getCoor('y') <= img.height)
				img.writePixel(proj.pos.getCoor('x'), img.height - proj.pos.getCoor('y'), Color(1, 0, 0));
			proj = tick(env, proj);
		}
		std::ofstream outfile ("Projectile.ppm");
		outfile << img.canvas_to_ppm() << std::endl;
		outfile.close();
		print(RIGHT, "DONE", LINELENGTH - title.length(), FGREEN, NOC, BOLD);
		std::cout << std::endl;
	}
}