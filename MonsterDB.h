#ifndef MONSTERDB_H
#define MONSTERDB_H

#include "MonsterRef.h"
#include "Monster.h"
struct MonsterDB{
  MonsterRef monsterRepo[LAST_MON_NAME];
  MonsterDB();

  bool oceanTrue;
  bool oceanFalse;

  const uint8_t *   getSprite1(MonsterName name);
  const uint8_t *   getSprite2(MonsterName name);
  const uint8_t *   getSprite3(MonsterName name);
  MonsterType   getMonsterType(MonsterName name);
  MonsterStage getMonsterStage(MonsterName name);
  Biome getMonsterBiome(MonsterName name);
  bool isUnderwater(MonsterName name);
  Monster* newMonster(MonsterName name);
  ScreenFX* newFX(FXType fx);
  MonsterName getRandomMonster(MonsterName name);
};

#endif
