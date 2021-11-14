#include "Keyboard.h"

Keyboard::Keyboard(Window *win) {
  window = win;
}

void Keyboard::poll() {
  Keyboard::window->poll();
}

bool Keyboard::isButtonPressed(unsigned int key) {
  int state = window->getButtonState(key);
  return state == GLFW_PRESS;
}