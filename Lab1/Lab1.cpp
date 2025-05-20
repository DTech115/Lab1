#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


int main(int argc, char** argv) {

	int width = 800;
	int height = 600;

	ALLEGRO_DISPLAY* display = NULL;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(width, height);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	al_init_primitives_addon();

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	al_draw_line(0, 0, 100, 100, al_map_rgb(255, 255, 255), 10);
	al_flip_display();

	al_rest(5.0);

	al_destroy_display(display);

	return 0;
}