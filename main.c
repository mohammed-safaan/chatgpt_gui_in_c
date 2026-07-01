#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello, World!");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Hello, World!", 190, 200, 20, WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
