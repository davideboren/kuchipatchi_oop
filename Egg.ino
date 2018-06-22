Egg::Egg(MonsterName name, const uint8_t *bitmap1, const uint8_t *bitmap2, const uint8_t *bitmap3, unsigned int age, unsigned int lifespan, MonsterName next){

	myName = name;

	xPos = 48;
	yPos = 32;

	bmp1 = bitmap1;
	bmp2 = bitmap2;
	bmp3 = bitmap3;
	currentBmp = bmp1;

	xDir = -1;

	moveInstrQueuePos = 0;

	monsterAge = age;
	monsterLifespan = lifespan;

	nextMonster = next;
}

void Egg::queueHatch1(){
	moveInstrQueue[0].setMove(-2,0,0,0,2);
	moveInstrQueue[1].setMove(4,0,0,0,2);
	moveInstrQueue[2].setMove(-4,0,0,0,2);
	moveInstrQueue[3].setMove(4,0,0,0,2);

	moveInstrQueuePos = 0;
}

void Egg::queueHatch2(){
	moveInstrQueue[0].setMove(-2,0,0,0,3);
	moveInstrQueue[1].setMove(0,0,0,0,3);
	moveInstrQueue[2].setMove(0,0,0,0,3);
	moveInstrQueue[3].setMove(0,0,0,0,3);

	moveInstrQueuePos = 0;
}

void Egg::queueStand(){
	moveInstrQueue[0].setMove(0,0,0,0,1);
	moveInstrQueue[1].setMove(0,0,0,0,2);
	moveInstrQueue[2].setMove(0,0,0,0,1);
	moveInstrQueue[3].setMove(0,0,0,0,2);

	moveInstrQueuePos = 0;
}

void Egg::doMove(MoveInstruction move){

	if(move.xDir != 0){
		xDir = move.xDir;
	}

	if(move.yDir != 0){
		yDir = move.yDir;
	}

	xPos = xPos + xDir*move.xDist;
	yPos = yPos + yDir*move.yDist;

	switch(move.sprite){
		case 1:
			currentBmp = bmp1;
			break;
		case 2:
			currentBmp = bmp2;
			break;
		case 3:
			currentBmp = bmp3;
			break;
	}
}

void Egg::heartbeat(){
	updateAge();

	if (monsterLifespan - monsterAge == 40){
		queueHatch1();
	} else if (monsterLifespan - monsterAge == 20){
		queueHatch2();
	} else if (moveInstrQueuePos > 3){
		queueStand();
	}

	doMove(moveInstrQueue[moveInstrQueuePos]);
	moveInstrQueuePos++;
}
