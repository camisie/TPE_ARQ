#include <gameHandler.h>

void askYesNoQuit() {
  char ans;
  println("Are you sure you want to quit the game? [Y/n]");
  while ((ans = getChar()) != 'n' && ans != 'y' && ans != 'Y' && ans != 'N') {
      if (ans != 0) {
          println("Invalid option. Please enter 'Y' if you want to quit the game. If not, enter 'n'.");
      }
  }
  if (ans == 'n' || ans == 'N') {
      putChar('\n');
      println("Great! Let's keep playing :)");
  } else if (ans == 'Y' || ans == 'y') {
      returnToShell();
  }
  return ans;
}
