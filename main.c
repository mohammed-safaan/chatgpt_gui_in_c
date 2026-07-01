#include "raygui/raygui.h"
#include <raylib.h>
#include <stdio.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define BACKGROUND_COLOR (Color){69, 69, 69, 255}
#define SIDEBAR_COLOR (Color){50, 50, 50, 255}
#define SIDEBAR_WIDTH .3 * SCREEN_WIDTH
#define MESSAGE_MAX_LENGTH 2048

void DrawsideBar() {
  DrawRectangle(0, 0, SIDEBAR_WIDTH, GetRenderHeight(), SIDEBAR_COLOR);
}

void DrawMessageInputBox(char *message) {
  Rectangle bounds = {SIDEBAR_WIDTH + 10, GetRenderHeight() - 50,
                      GetRenderWidth() - SIDEBAR_WIDTH - 20, 40};
  GuiTextBox(bounds, message, MESSAGE_MAX_LENGTH, true);
}

int main(void) {
  int currentMonitor = GetCurrentMonitor();
  if (currentMonitor < 0) {
    currentMonitor = 0;
  }
  int screenWidth = GetMonitorWidth(currentMonitor);
  int screenHeight = GetMonitorHeight(currentMonitor);

  if (screenWidth <= 0 || screenHeight <= 0) {
    screenWidth = SCREEN_WIDTH;
    screenHeight = SCREEN_HEIGHT;
  }

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth - 100, screenHeight - 100, "AI Chatbot");

  printf("==================> Screen Width: %d, Screen Height: %d\n",
         screenWidth, screenHeight);
  SetTargetFPS(60);

  char message[MESSAGE_MAX_LENGTH] = {0};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BACKGROUND_COLOR);
    DrawsideBar();
    DrawMessageInputBox(message);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
