#include "global.h"
#include "library.h"

//Example of use

/*

_createEmptyAnim(AnimSprite);

*/

u16 nombrePaleta[] = INCBIN_U16("graphics/library_test/bag.gbapal");
u8 nombreSprite[] = INCBIN_U8("graphics/library_test/bag.4bpp");
static EWRAM_DATA u8 iconNameEWRAM = 0;

struct SpriteSheet bagSpriteSheet;
struct SpritePalette bagSpritePalette;
struct SpriteTemplate bagSpriteTemplate;

void _drawSprite(void)
{
	static const union AnimCmd bagAnimSpriteAnimCmd[] = ANIMCMD_EMPTY;
	static const union AnimCmd *const bagAnimSprite[] = {bagAnimSpriteAnimCmd,};
	
	struct OamData bagOamData = _createSpriteOamData();
	//_createEmptyAnim(bagAnimSprite);
	_createSpriteData(bagSpriteSheet, bagSpritePalette, bagSpriteTemplate, nombreSprite, nombrePaleta, bagOamData, bagAnimSprite, 512, 12);
}

void _createSpriteData(struct SpriteSheet spriteSheet, struct SpritePalette spritePalette, struct SpriteTemplate spriteTemplate, u8 *spriteName, u16 *paletteName, struct OamData oamDataName, const union AnimCmd *const nameSpriteAnimTable[], u16 spriteSize, u16 spriteTag)
{
	spriteSheet = _createSpriteSheet(spriteName, spriteSize, spriteTag);
	spritePalette = _createSpritePalette(paletteName, spriteTag);
	spriteTemplate = _createSpriteTemplate(oamDataName, spriteTag, nameSpriteAnimTable);
}

struct OamData _createSpriteOamData(void)
{
	struct OamData spriteNameOamData =
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

struct SpriteSheet _createSpriteSheet(u8 *spriteName, u16 spriteSize, u16 spriteTag)
{
	struct SpriteSheet spriteSheet =
	{
		.data = spriteName,
		.size = spriteSize,
		.tag = spriteTag,
	};
	return spriteSheet;
}


struct SpritePalette _createSpritePalette(u16 *paletteName, u16 paletteTag)
{
	struct SpritePalette spritePalette =
	{
		.data = paletteName,
		.tag = paletteTag,
	};
	return spritePalette;
}

struct SpriteTemplate _createSpriteTemplate(struct OamData oamDataName, u16 spritepaletteTileTag, const union AnimCmd *const nameSpriteAnimTable[])
{
	struct SpriteTemplate spriteTemplate =
	{
		.tileTag = spritepaletteTileTag,
		.paletteTag = spritepaletteTileTag,
		.oam = &oamDataName,
		.anims = nameSpriteAnimTable,
		.images = NULL,
		.affineAnims = gDummySpriteAffineAnimTable,
		.callback = SpriteCallbackDummy,
	};
	return spriteTemplate;
}