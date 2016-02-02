/* simulate normal dice (1 - 6)
 * construct Dice with top, front, right value.
 * rotating with rot function.
 * rot directions: N is back, S is forward, E is right, W is left.
 */

struct Dice {
  int top, bottom, right, left, front, back;

  Dice(int top_, int front, int_right) {
    top   = top_;    bottom = 7 - top;
    right = right_;  left   = 7 - left;
    front = front_;  back   = 7 - front;
  }
  void rot(char d) {
    if (d == 'N') {
      int tmp = front; front = bottom;
      bottom = back; back = top; top = tmp;
    }
    if (d == 'S') {
      int tmp = back; back = bottom;
      bottom = front; front = top; top = tmp;
    }
    if (d == 'E') {
      int tmp = left; left = bottom;
      bottom = right; right = top; top = tmp;
    }
    if (d == 'W') {
      int tmp = right; right = bottom;
      bottom = left; left = top; top = tmp;
    }
  }
};
