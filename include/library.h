#ifndef GUARD_LIBRARY_H
#define GUARD_LIBRARY_H

void _drawSprite(void);
void _createSpriteData(struct SpriteSheet spriteSheet, struct SpritePalette spritePalette, struct SpriteTemplate spriteTemplate, u8 *spriteName, u16 *paletteName, struct OamData oamDataName, const union AnimCmd *const nameSpriteAnimTable[], u16 spriteSize, u16 spriteTag);
struct OamData _createSpriteOamData(void);
struct SpriteSheet _createSpriteSheet(u8 *spriteName, u16 spriteSize, u16 spriteTag);
struct SpritePalette _createSpritePalette(u16 *paletteName, u16 paletteTag);
struct SpriteTemplate _createSpriteTemplate(struct OamData oamDataName, u16 spritepaletteTileTag, const union AnimCmd *const nameSpriteAnimTable[]);

#define ANIMCMD_EMPTY { ANIMCMD_FRAME(0, 5), ANIMCMD_END, }

//#define _createEmptyAnim(_name) static const union AnimCmd _name[] = { ANIMCMD_FRAME(0, 5), ANIMCMD_END, };


#endif // GUARD_LIBRARY_H