#include "Characters.h"

uint8_t buf[8] = { 0 };
byte bufferSize = 8;

void releaseKey() {
  for (int i = 0; i < bufferSize + 1; i++) {
      buf[i] = 0;
  }
  Serial.write(buf, 8);
}

void key(int keyIndex, bool shortPress) {
  buf[2] = keyIndex;
  Serial.write(buf, 8);

  if (shortPress) {
    releaseKey();
  }
}

void keyList(char providedKeys[], int arrayLength) {
  for (int i = 0; i < arrayLength ; i++) {
    key(providedKeys[i], true);
  }
}

void shiftKey() {
  for (int i = 3; i < bufferSize + 1; i++) {
    if (!buf[i]) {
        buf[i] = LSHIFT;
        break;
    }
  }
  Serial.write(buf, 8);
}

void ctrlKey() {
  for (int i = 3; i < bufferSize + 1; i++) {
    if (!buf[i]) {
        buf[i] = LCTRL;
        break;
    }
  }
  Serial.write(buf, 8);
}

void winKey() {
  for (int i = 3; i < bufferSize + 1; i++) {
    if (!buf[i]) {
        buf[i] = LWIN;
        break;
    }
  }
  Serial.write(buf, 8);
}

void keyString(char stringReference[]) {
  for(int i = 0; i < strlen(stringReference); i++ ) {
    switch(stringReference[i]) {
      case 'q':
        key(Q, true);
        break;
      case 'w':
        key(W, true);
        break;
      case 'e':
        key(E, true);
        break;
      case 'r':
        key(R, true);
        break;
      case 't':
        key(T, true);
        break;
      case 'y':
        key(Y, true);
        break;
      case 'u':
        key(U, true);
        break;
      case 'i':
        key(I, true);
        break;
      case 'o':
        key(O, true);
        break;
      case 'p':
        key(P, true);
        break;
      case 'a':
        key(A, true);
        break;
      case 's':
        key(S, true);
        break;
      case 'd':
        key(D, true);
        break;
      case 'f':
        key(F, true);
        break;
      case 'g':
        key(G, true);
        break;
      case 'h':
        key(H, true);
        break;
      case 'j':
        key(J, true);
        break;
      case 'k':
        key(K, true);
        break;
      case 'l':
        key(L, true);
        break;
      case 'z':
        key(Z, true);
        break;
      case 'x':
        key(X, true);
        break;
      case 'c':
        key(C, true);
        break;
      case 'v':
        key(V, true);
        break;
      case 'b':
        key(B, true);
        break;
      case 'n':
        key(N, true);
        break;
      case 'm':
        key(M, true);
        break;

      case 'Q':
        shiftKey();
        key(Q, true);
        break;
      case 'W':
        shiftKey();
        key(W, true);
        break;
      case 'E':
        shiftKey();
        key(E, true);
        break;
      case 'R':
        shiftKey();
        key(R, true);
        break;
      case 'T':
        shiftKey();
        key(T, true);
        break;
      case 'Y':
        shiftKey();
        key(Y, true);
        break;
      case 'U':
        shiftKey();
        key(U, true);
        break;
      case 'I':
        shiftKey();
        key(I, true);
        break;
      case 'O':
        shiftKey();
        key(O, true);
        break;
      case 'P':
        shiftKey();
        key(P, true);
        break;
      case 'A':
        shiftKey();
        key(A, true);
        break;
      case 'S':
        shiftKey();
        key(S, true);
        break;
      case 'D':
        shiftKey();
        key(D, true);
        break;
      case 'F':
        shiftKey();
        key(F, true);
        break;
      case 'G':
        shiftKey();
        key(G, true);
        break;
      case 'H':
        shiftKey();
        key(H, true);
        break;
      case 'J':
        shiftKey();
        key(J, true);
        break;
      case 'K':
        shiftKey();
        key(K, true);
        break;
      case 'L':
        shiftKey();
        key(L, true);
        break;
      case 'Z':
        shiftKey();
        key(Z, true);
        break;
      case 'X':
        shiftKey();
        key(X, true);
        break;
      case 'C':
        shiftKey();
        key(C, true);
        break;
      case 'V':
        shiftKey();
        key(V, true);
        break;
      case 'B':
        shiftKey();
        key(B, true);
        break;
      case 'N':
        shiftKey();
        key(N, true);
        break;
      case 'M':
        shiftKey();
        key(M, true);
        break;

      case ' ':
        key(SPACE, true);
        break;

      case '1':
        key(ONE, true);
        break;
      case '2':
        key(TWO, true);
        break;
      case '3':
        key(THREE, true);
        break;
      case '4':
        key(FOUR, true);
        break;
      case '5':
        key(FIVE, true);
        break;
      case '6':
        key(SIX, true);
        break;
      case '7':
        key(SEVEN, true);
        break;
      case '8':
        key(EIGHT, true);
        break;
      case '9':
        key(NINE, true);
        break;
      case '0':
        key(ZERO, true);
        break;

      case '!':
        shiftKey();
        key(ONE, true);
        break;
      case '@':
        shiftKey();
        key(TWO, true);
        break;
      case '#':
        shiftKey();
        key(THREE, true);
        break;
      case '$':
        shiftKey();
        key(FOUR, true);
        break;
      case '%':
        shiftKey();
        key(FIVE, true);
        break;
      case '^':
        shiftKey();
        key(SIX, true);
        break;
      case '&':
        shiftKey();
        key(SEVEN, true);
        break;
      case '*':
        shiftKey();
        key(EIGHT, true);
        break;
      case '(':
        shiftKey();
        key(NINE, true);
        break;
      case ')':
        shiftKey();
        key(ZERO, true);
        break;

      case '`':
        key(ACCENT, true);
        break;
      case '-':
        key(MINUS, true);
        break;
      case '=':
        key(EQUALSIGN, true);
        break;
      case '[':
        key(SQUAREBRACKETLEFT, true);
        break;
      case ']':
        key(SQUAREBRACKETRIGHT, true);
        break;
      case ';':
        key(SEMICOLON, true);
        break;
      case ',':
        key(COMMA, true);
        break;
      case '.':
        key(DOT, true);
        break;
      case '/':
        key(RIGHTSLASH, true);
        break;

      case '~':
        shiftKey();
        key(ACCENT, true);
        break;
      case '_':
        shiftKey();
        key(MINUS, true);
        break;
      case '+':
        shiftKey();
        key(EQUALSIGN, true);
        break;
      case '{':
        shiftKey();
        key(SQUAREBRACKETLEFT, true);
        break;
      case '}':
        shiftKey();
        key(SQUAREBRACKETRIGHT, true);
        break;
      case ':':
        shiftKey();
        key(SEMICOLON, true);
        break;
      case '"':
        shiftKey();
        key(APOSTROPHE, true);
        break;
      case '<':
        shiftKey();
        key(COMMA, true);
        break;
      case '>':
        shiftKey();
        key(DOT, true);
        break;
      case '?':
        shiftKey();
        key(RIGHTSLASH, true);
        break;
      case '|':
        shiftKey();
        key(LEFTSLASH, true);
        break;
    }

    if (stringReference[i] == "'") {
      key(APOSTROPHE, true);
    }
  }
}