from PIL import Image
import os
import re

spriteList = []
spriteEnumList = []
spriteEnumString = "enum monsterID {\n"

stageDec = []
varDec = []

#These sprites don't need stage declarations or enums
banlist = ["blank", "bubble", "degg", "evolve", "flusher", "hatch", \
			"poop", "tegg"]

for r, d, f in os.walk("sprite"):
	for file in f:
		if "bmp" in file:
			spriteList.append(file)

for sprite in sorted(spriteList):
	spritePath = "sprite/" + sprite
	spriteName = sprite.split('.')[0]
	spriteNameNoDigits = re.sub(r'\d+','', spriteName)
	spriteEnum = "id" + re.sub(r'\d+','', spriteName).capitalize()
	
	#Add monster to enums and stage case list
	if spriteNameNoDigits not in banlist:
		if spriteEnum not in spriteEnumList:
			#New sprite, so cap off previous stage declaration
			if len(stageDec) != 0:
				stageDec[-1] = stageDec[-1] + "16,lifespanSave,lifespan);\n      " + \
									"EEPROM.put(0,stager());\n      break;"
			
			#add to enums and start stage declaration
			spriteEnumList.append(spriteEnum)
			spriteEnumString = spriteEnumString + "  " + spriteEnum + ",\n"
			stageDec.append("    case " + spriteEnum + ":\n" + \
							"      tamaStageMover(" + spriteName + ",")
		elif spriteEnum in spriteEnumList:
			stageDec[-1] = stageDec[-1] + spriteName + ","
		
		
	print("Processing: " +spritePath)

	bitArray = []
	spr = Image.open(spritePath)
	sprW, sprH = spr.size
	
	numBytesInSprite = int((sprW*sprH)/8)

	for h in range(0,sprH):
		for w in range(0,sprW):
			if type(spr.getpixel((w,h))) == tuple:
				pixVal = spr.getpixel((w,h))[0] 
			else:
				pixVal = spr.getpixel((w,h))
			if pixVal == 0:
				bitArray.append(0b1)
			else:
				bitArray.append(0b0)
	
	bytes = []
	
	byteString = ""
	for b in range(0,numBytesInSprite):
		bytes.append(0x00)
		for i in range(0,8):
			bytes[b] = bytes[b] << 1 | bitArray[8*b + i]
		byteString = byteString + hex(bytes[b]) + ", "

	varDec.append("\nstatic const unsigned char PROGMEM " + spriteName + " [] = {\n" + byteString + "\n};")
	
spriteEnumString = spriteEnumString + "idEgg,\n"
spriteEnumString = spriteEnumString + "};\n"

spriteFile = open("../sprites.h","w")
spriteFile.write(spriteEnumString)
spriteFile.write("\n".join(varDec))

stageFile = open("../stagetemplates.h","w")
stageFile.write("\n".join(stageDec))