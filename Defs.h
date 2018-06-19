/*
 * Defs.h
 *
 * A bunch of definitions
 */
#ifndef DEFS_H
#define DEFS_H

enum MonsterType {
  MOVER,
  SITTER,
  FLOATER
};

enum MonsterStage {
  EGG_STAGE,
  BABY_STAGE,
  TODDLER_STAGE,
  TEEN_STAGE,
  ADULT_STAGE,
  POOP_STAGE,
  SHIP_STAGE,
  LAST_STAGE
};

enum Events {
  IDLE_EVENT,
  POOP_EVENT,
  VISITOR_EVENT,
  LAST_EVENT
};

enum ActiveMonsterSlot {
  PRIMARY,
  VISITOR,
  POOP,
  BUBBLES,
  LAST_MON_SLOT
};

enum MoveQueueAction {
  MOVE_X_SPRITE_1,
  MOVE_X_SPRITE_2,
  WAIT_SPRITE_1,
  WAIT_SPRITE_2,
  LAST_MOVE_QUEUE_ACTION
};

enum MonsterName {
  Mimitchi,
  Kurotsubutchi,
  Kuchipatchi,
  Poop,
  LAST_MON_NAME
};

enum MonsterTask {
  IDLE,
  GOTO
};

//Mimitchi
static const unsigned char PROGMEM mimitchi1 [] = {
0x00, 0x00, 0x0C, 0x18, 0x1E, 0x3C, 0x1E, 0x3C, 0x0F, 0x78, 0x0F, 0xF8, 0x08, 0x08, 0x14, 0x14,
0x11, 0xC4, 0x38, 0x06, 0x38, 0x06, 0x10, 0x04, 0x08, 0x18, 0x07, 0xF8, 0x0F, 0x08, 0x00, 0x00
};

//Kuchipatchi
int idKuchipatchi = 0;
static const unsigned char PROGMEM kuchipatchi1 [] = {
0x00, 0x00, 0x07, 0xE0, 0x08, 0x10, 0x14, 0x08, 0x70, 0x44, 0x80, 0x04, 0xF0, 0x04, 0x80, 0x04,
0x60, 0x04, 0x10, 0x02, 0x10, 0x52, 0x10, 0x52, 0x10, 0x22, 0x08, 0x04, 0x04, 0xC8, 0x03, 0x30
};
static const unsigned char PROGMEM kuchipatchi2 [] = {
0x00, 0x00, 0x07, 0xE0, 0xC8, 0x10, 0xB4, 0x08, 0x80, 0x44, 0x70, 0x04, 0x80, 0x04, 0xA0, 0x04,
0xD0, 0x04, 0x10, 0x02, 0x10, 0x12, 0x10, 0x4A, 0x10, 0x32, 0x08, 0x04, 0x09, 0x38, 0x06, 0xC0
};

//Kurotsubutchi
int idKurotsubutchi = 1;
static const unsigned char PROGMEM kurotsubutchi1 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x80, 0x03, 0xC0, 0x07, 0xE0, 0x0D, 0xF0, 0x0F, 0xB0, 0x0C, 0xF0, 0x0F, 0xF0, 0x07, 0xE0
};
static const unsigned char PROGMEM kurotsubutchi2 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x80, 0x03, 0xC0, 0x07, 0xE0, 0x0D, 0xB0, 0x0F, 0xF0, 0x0E, 0x70, 0x07, 0xE0
};

//Poop
static const unsigned char PROGMEM poop1 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x10, 0x04, 0x20, 0x08, 0x10, 0x05, 0x00, 0x01, 0x80, 0x03, 0x40, 0x07, 0xA0, 0x07, 0xE0
};
static const unsigned char PROGMEM poop2 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x04, 0x20, 0x08, 0x10, 0x01, 0x20, 0x01, 0x80, 0x03, 0x40, 0x05, 0xE0, 0x07, 0xE0
};

#endif
