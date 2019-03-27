#include "global.h"
#include "library.h"

//Example of use

/*



*/

void _drawSprite(void)
{
		
}

struct OamData _createSpriteOamData(void)
{
	static const struct OamData spriteNameOamData =
	{
		.y = 0,
		.affineMode = 0,
		.objMode = 0,
		.mosaic = 0,
		.bpp = 0,
		.shape = 0,
		.x = 0,
		.matrixNum = 0,
		.size = 1,
		.tileNum = 0,
		.priority = 0,
		.paletteNum = 0,
		.affineParam = 0,
	};
	return spriteNameOamData;
}


struct SpriteSheet _createSpriteSheet(u8 *spriteName, u8 size, u8 tag)
{
	struct SpriteSheet spriteSheet =
	{
		.data = spriteName,
		.size = size, //512 recommended
		.tag = tag, //Este es lugar en que el sistema dibujará el sprite en la OAM
	};
}

struct SpritePalette _createSpritePalette(u8 *paletteName, u8 tag2)
{
	struct SpritePalette spritePalette =
	{
		.data = paletteName,
		.tag = tag2, //Este es lugar en que el sistema dibujará el sprite en la OAM
	};
}

struct SpriteTemplate _createSpriteTemplate(u8 oamDataName, u8 tag3, union AnimCmd nameSpriteAnimTablee)
{
	struct SpriteTemplate spriteTemplate =
	{
		.tileTag = tag3, //Este es lugar en que el sistema dibujará el sprite en la OAM
		.paletteTag = tag3, //Este es lugar en que el sistema dibujará el sprite en la OAM
		.oam = &oamDataName,
		.anims = nameSpriteAnimTablee,
		.images = NULL, //Lo dejaremos siempre como NULL
		.affineAnims = gDummySpriteAffineAnimTable, //Esto es para las animaciones afines, de nuevo, si no las usamos, dejaremos esto por defecto
		.callback = SpriteCallbackDummy, //Esto es para las animaciones, si no las usaremos, también se quedará así
	};
}

/*union AnimCmd _createEmptyAnim(void)
{
	static const union AnimCmd nameSpriteAnimSeq0[] =
	{
		ANIMCMD_FRAME(0, 5),
		ANIMCMD_END,
	};

	static const union AnimCmd *const nameSpriteAnimTable = nameSpriteAnimSeq0;
	return *nameSpriteAnimTable;
}

union AnimCmd _createEmptyAnim(void)
{
	union AnimCmd nameSpriteAnimSeq0[] =
	{
		ANIMCMD_FRAME(0, 5),
		ANIMCMD_END,
	};
	return *nameSpriteAnimSeq0;
}*/