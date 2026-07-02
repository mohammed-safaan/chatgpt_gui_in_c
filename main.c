#include <raylib.h>
#include <stdio.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define BACKGROUND_COLOR (Color){69, 69, 69, 255}
#define SIDEBAR_COLOR (Color){50, 50, 50, 255}
#define SIDEBAR_WIDTH (GetRenderWidth() * 0.3f)
#define MESSAGE_MAX_LENGTH 2048
#define FONT_NAME "assets/fonts/Roboto-VariableFont_wdth,wght.ttf"
#define MSGBOX_BACKGROUND_COLOR (Color){255, 255, 255, 50}

void DrawsideBar() {
  DrawRectangle(0, 0, SIDEBAR_WIDTH, GetRenderHeight(), SIDEBAR_COLOR);
}

void DrawMessageInputBox(char *message) {
  int margin = 20;
  int bgHeight = 50;
  int bgX = SIDEBAR_WIDTH + margin;
  int bgY = GetRenderHeight() - margin - bgHeight;
  int bgWidth = GetRenderWidth() - SIDEBAR_WIDTH - 2 * margin;

  Rectangle bgMsgBoxBounds = {bgX, bgY, bgWidth, bgHeight};
  DrawRectangleRounded(bgMsgBoxBounds, 0.2f, 4, MSGBOX_BACKGROUND_COLOR);

  int textPad = 10;
  Rectangle textBounds = {bgX + textPad, bgY + textPad, bgWidth - 2 * textPad,
                          bgHeight - 2 * textPad};
  GuiTextBox(textBounds, message, MESSAGE_MAX_LENGTH, true);
}

int main(void) {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 100, "AI Chatbot");
  SetTargetFPS(60);

  MaximizeWindow();

  int fontSize = 24;

  Font font = LoadFontEx(FONT_NAME, fontSize, NULL, 0);
  GuiSetFont(font);
  GuiSetStyle(DEFAULT, TEXT_SIZE, fontSize);
  GuiSetStyle(DEFAULT, BORDER_WIDTH, 0);
  GuiSetStyle(DEFAULT, BASE_COLOR_PRESSED, 0X00000000);
  GuiSetStyle(DEFAULT, TEXT_COLOR_PRESSED, 0XFFFFFFFF);

  char message[MESSAGE_MAX_LENGTH] = {0};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BACKGROUND_COLOR);
    DrawsideBar();
    DrawMessageInputBox(message);
    EndDrawing();
  }

  UnloadFont(font);
  CloseWindow();
  return 0;
}
