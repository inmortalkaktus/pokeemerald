#ifndef GUARD_LIBRARY_H
#define GUARD_LIBRARY_H

void _drawSprite(void);
struct OamData _createSpriteOamData(void);

//#define ANIMCMD_EMPTY { ANIMCMD_FRAME(0, 5), ANIMCMD_END, }

#define _createEmptyAnim(name) static const union AnimCmd name[] = { ANIMCMD_FRAME(0, 5), ANIMCMD_END, };


#endif // GUARD_LIBRARY_H