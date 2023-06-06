ALLEGRO_LIBRARIES := allegro-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_dialog-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5 allegro_video-5
ALLEGRO_FLAGS := $(shell pkg-config --cflags --libs "$(ALLEGRO_LIBRARIES) <= 5.2.8") -lallegro

CC := gcc
OUT:= game
# MAIN:= mac_main.o GameWindow.o scene.o global.o charater.o
MAIN:= mac_main.c GameWindow.c game_scene.c menu_scene.c global.c character.c bfs.c utility.c

all: $(MAIN)
	$gcc -o $(OUT) $(MAIN) $(ALLEGRO_FLAGS)

clean:
	rm $(OUT)