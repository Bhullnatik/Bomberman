//
// bomberman.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Thu May 16 16:09:24 2013 leo chazal
// Last update Sun Jun  9 22:07:16 2013 leo chazal
//

#pragma			once

#define GAME_DELAY	0.02

#define TILE_SIZE	200
#define PLAYER_SIZE	140
#define BONUS_NUMBER	7
#define BONUS_CHANCE	2
#define BLOWUP_TICKS	125
#define FIRE_TICKS	50
#define	KEY_NUMBER	5
#define LEVEL_NUMBER	5
#define INVINC_TICKS	750

#define	NB_PLAYER_COLOR	2
#define	NB_IA_COLOR	6

#define	SAVE_EXTENSION	".bsave"
#define	MAP_EXTENSION	".bmap"
#define SAVE_PATH	"assets/saves/"
#define	SCORE_FILE	"score.bscore"

// FLOOR

#define TEXT_FLOOR_METAL	"/assets/textures/tiles/floor_metal.png"
#define TEXT_FLOOR_ICE		"/assets/textures/tiles/floor_snow.png"
#define TEXT_FLOOR_SAND		"/assets/textures/tiles/floor_sand.png"
#define TEXT_FLOOR_CURSED	"/assets/textures/tiles/floor_cursed.png"
#define TEXT_FLOOR_SKY		"/assets/textures/tiles/floor_sky.png"

// BLOCK

#define TEXT_FIRE		"/assets/textures/block/fire.png"
#define TEXT_BLOCK_METAL	"/assets/textures/block/box_metal.png"
#define TEXT_BLOCK_ICE		"/assets/textures/block/box_snow.png"
#define TEXT_BLOCK_SAND		"/assets/textures/block/box_sand.png"
#define TEXT_BLOCK_CURSED	"/assets/textures/block/box_cursed.png"
#define TEXT_BLOCK_SKY		"/assets/textures/block/box_sky.png"

// WALL

#define TEXT_WALL_METAL		"/assets/textures/wall/wall_metal.png"
#define TEXT_WALL_ICE		"/assets/textures/wall/wall_snow.png"
#define TEXT_WALL_SAND		"/assets/textures/wall/wall_sand.png"
#define TEXT_WALL_CURSED	"/assets/textures/wall/wall_cursed.png"
#define TEXT_WALL_SKY		"/assets/textures/wall/wall_sky.png"

// BONUS

#define	TEXT_B_BOMB		"/assets/textures/bonus/bomb_up.png"
#define TEXT_M_BOMB		"/assets/textures/bonus/bomb_down.png"
#define	TEXT_B_POWER		"/assets/textures/bonus/fire_up.png"
#define	TEXT_M_POWER		"/assets/textures/bonus/fire_down.png"
#define	TEXT_B_SPEED		"/assets/textures/bonus/speed_up.png"
#define	TEXT_M_SPEED		"/assets/textures/bonus/speed_down.png"
#define	TEXT_B_INVINC		"/assets/textures/bonus/invic_up.png"

// INTRO

#define	INTRO_BACKGROUND	"/assets/textures/intro/background.png"
#define	INTRO_TITLE		"/assets/textures/intro/title.png"
#define INTRO_BOMB		"/assets/textures/intro/bomb.png"
#define	INTRO_FIRE		"/assets/textures/intro/fire.png"

// TITLE

#define TITLE_BG		"/assets/textures/title/title.png"
#define TITLE_WORD		"/assets/textures/title/title_wording.png"

// BG

#define BG_LOAD			"/assets/textures/backgrounds/load_bg.png"
#define BG_LOBBY		"/assets/textures/backgrounds/lobby_bg.png"
#define BG_SKY                  "/assets/textures/backgrounds/sky_bg.png"
#define BG_METAL                "/assets/textures/backgrounds/metal_bg.png"
#define BG_ICE                  "/assets/textures/backgrounds/ice_bg.png"
#define BG_CURSE                "/assets/textures/backgrounds/curse_bg.png"
#define BG_SAND                 "/assets/textures/backgrounds/sand_bg.png"
#define BG_PRELOAD		"/assets/textures/backgrounds/preload_bg.png"
#define BG_CREDIT		"/assets/textures/backgrounds/credit_bg.png"
#define	BG_PAUSE		"/assets/textures/backgrounds/pause_bg.png"
#define	BG_ERROR		"/assets/textures/backgrounds/error_bg.png"

// ENDGAME

#define END_WINNER		"/assets/textures/endgame/winner.png"
#define END_LOSER		"/assets/textures/endgame/loser.png"
#define END_DRAW		"/assets/textures/endgame/draw.png"

// CREDITS

#define	CREDITS_MAYOUKJ		"/assets/textures/credits/mayouk_j.png"
#define CREDITS_CHAZALL		"/assets/textures/credits/chazal_l.png"
#define	CREDITS_MAGRINJ		"/assets/textures/credits/magrin_j.png"
#define CREDITS_HOARAUS		"/assets/textures/credits/hoarau_s.png"
#define CREDITS_KAPOUSC		"/assets/textures/credits/kapous_c.png"

// MODELS

#define	MODE_BOMBERMAN	"/assets/models/marvin.fbx"
#define MODE_BOMBS	"/assets/models/bomb.fbx"

#define SOUND_NUMBER	15
#define TRACK_MAIN	"assets/sounds/intro.mp3"
#define TRACK_MENU	"assets/sounds/menu.mp3"
#define TRACK_METAL	"assets/sounds/factory.mp3"
#define TRACK_ICE	"assets/sounds/ice.mp3"
#define TRACK_DEATH	"assets/sounds/cursed.mp3"
#define TRACK_SKY	"assets/sounds/rainbow.mp3"
#define TRACK_SAND	"assets/sounds/desert.mp3"
#define TRACK_CREDIT	"assets/sounds/credit.mp3"
#define FX_WIN		"assets/sounds/victory.mp3"
#define FX_LOSS		"assets/sounds/defeat.mp3"
#define FX_DEATH	"assets/sounds/death.mp3"
#define FX_BOMB		"assets/sounds/bomb.mp3"
#define FX_EXPLODE	"assets/sounds/explosion.mp3"
#define FX_BONUS	"assets/sounds/bonus.mp3"
#define FX_MALUS	"assets/sounds/malus.mp3"


namespace		Bomberman
{
  enum		Element
    {
      NELEM = 0,
      BLOCK,
      BONUS,
      BOMB,
      WALL,
      FIRE
    };

  enum	Dir
    {
      NONE = 0,
      UP = 180,
      DOWN = 360,
      LEFT = 270,
      RIGHT = 90
    };
}
