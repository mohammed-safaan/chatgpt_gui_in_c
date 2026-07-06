#include <raylib.h>
#include <stdio.h>
#include <string.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define BACKGROUND_COLOR (Color){69, 69, 69, 255}
#define SIDEBAR_COLOR (Color){50, 50, 50, 255}
#define SIDEBAR_WIDTH (GetRenderWidth() * 0.3f)
#define MESSAGE_MAX_LENGTH 2048
#define MAX_MESSAGES 100
#define FONT_NAME "assets/fonts/Roboto-VariableFont_wdth,wght.ttf"
#define MSG_INPUT_BACKGROUND_COLOR (Color){255, 255, 255, 50}

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
  DrawRectangleRounded(bgMsgBoxBounds, 0.2f, 4, MSG_INPUT_BACKGROUND_COLOR);

  int textPad = 10;
  Rectangle textBounds = {bgX + textPad, bgY + textPad, bgWidth - 2 * textPad,
                          bgHeight - 2 * textPad};
  GuiTextBox(textBounds, message, MESSAGE_MAX_LENGTH, true);
}

void addToMsgHistory(char messageHistory[MAX_MESSAGES][MESSAGE_MAX_LENGTH],
                     int *messageCount, char *message) {
  if (*messageCount < MAX_MESSAGES) {
    strncpy(messageHistory[*messageCount], message, MESSAGE_MAX_LENGTH - 1);
    messageHistory[*messageCount][MESSAGE_MAX_LENGTH - 1] = '\0';
    (*messageCount)++;
    strcpy(message, "\0");
  }
}

void DrawMessageHistory(char messageHistory[MAX_MESSAGES][MESSAGE_MAX_LENGTH],
                        int messageCount, Font font) {
  int margin = 20;
  int msgBoxHeight = 50;
  int msgBoxSpacing = 10;
  int msgFontSize = 23;

  int startX = SIDEBAR_WIDTH + margin;
  int startY = margin;

  for (int i = 0; i < messageCount; i++) {
    char *message = messageHistory[i];
    Vector2 position = (Vector2){startX, startY};
    Vector2 textHeight =
        MeasureTextEx(GetFontDefault(), message, msgFontSize, 0);

    DrawTextEx(font, message, position, msgFontSize, 0, WHITE);
    startY += textHeight.y + margin;
  }
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
  char messageHistory[MAX_MESSAGES][MESSAGE_MAX_LENGTH] = {0};
  int messageCount = 0;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BACKGROUND_COLOR);
    DrawsideBar();
    DrawMessageInputBox(message);
    DrawMessageHistory(messageHistory, messageCount, font);

    if (IsKeyPressed(KEY_ENTER) && *message != '\0') {
      if (messageCount < MAX_MESSAGES) {
        addToMsgHistory(messageHistory, &messageCount, message);
      }
      message[0] = '\0';
    }
    EndDrawing();
  }

  UnloadFont(font);
  CloseWindow();
  return 0;
}
