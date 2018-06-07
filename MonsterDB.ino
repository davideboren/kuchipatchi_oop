MonsterDB::MonsterDB(){
  unsigned int lifespanBaby =  100;
  unsigned int lifespanAdult = 150;
  monsterRepo[Kurotsubutchi] = MonsterRef(kurotsubutchi1,kurotsubutchi2,Mover,lifespanBaby,Kuchipatchi,Kuchipatchi);
  monsterRepo[Kuchipatchi] = MonsterRef(kuchipatchi1,kuchipatchi2,Mover,lifespanAdult,Kurotsubutchi,Kurotsubutchi);

}

const uint8_t * MonsterDB::getSprite1(MonsterName name){
  return monsterRepo[name].sprite1;
}

const uint8_t * MonsterDB::getSprite2(MonsterName name){
  return monsterRepo[name].sprite2;
}

MonsterType MonsterDB::getMonsterType(MonsterName name){
  return monsterRepo[name].monsterType;
}

unsigned int MonsterDB::getMonsterLifespan(MonsterName name){
  return monsterRepo[name].monsterLifespan;
}

MonsterName MonsterDB::getNextMonster(MonsterName name){
  return random(2)?monsterRepo[name].nextMonster[0]:monsterRepo[name].nextMonster[1];
}
