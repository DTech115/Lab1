#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


int main(int argc, char** argv) {

	//dimension variables
	int width = 800;
	int height = 600;

	ALLEGRO_DISPLAY* display = NULL;

	//check for allegro/display
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(width, height);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	//use primitives
	al_init_primitives_addon();

	//set background to black & flip renders
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	//fish body made of circles & a triangle [line for eye]
	al_draw_filled_circle(400, 300, 100, al_map_rgb(255, 255, 255));
	al_draw_triangle(300, 300, 200, 400, 200, 200, al_map_rgb(255, 255, 255), 10);
	al_draw_circle(450, 350, 50, al_map_rgb(0, 0, 0), 5);
	al_draw_line(400, 275, 450, 275, al_map_rgb(255, 165, 0), 5);

	//some bubbles made of empty circles at various positions
	al_draw_circle(510, 200, 20, al_map_rgb(0, 0, 255), 5);
	al_draw_circle(570, 160, 30, al_map_rgb(0, 255, 255), 5);
	al_draw_circle(510, 100, 40, al_map_rgb(0, 100, 255), 5);


	al_flip_display();


	al_rest(10.0);

	al_destroy_display(display);

	return 0;
}