##
## Makefile for Bomberman in /home/mayouk_j/CPP/Bomberman
## 
## Made by jimmy mayoukou
## Login   <mayouk_j@epitech.net>
## 
## Started on  Wed May  8 02:08:07 2013 jimmy mayoukou
## Last update Sun Jun  9 20:28:55 2013 leo chazal
##

NAME=		bomberman

DEBUG	?=	false

OBJDIR=		./objs/
SRCDIR=		./srcs/
LIBDIR=		./libs/

INCLUDE=	-I ./includes/ -I ./includes/gdl/

VPATH=		$(SRCDIR)

CXXFLAGS=	-W -Wall -Wextra # -Werror

ifeq		($(DEBUG),true)
CXXFLAGS +=	-g3 -DDEBUG
endif

LDFLAGS=	-L libs/ -l fmodex64 -lgdl_gl -framework OpenGL

CXXFLAGS +=	$(INCLUDE)

SRC=		main.cpp			\
		Game.cpp			\
		Camera.cpp			\
		Engine.cpp			\
		Map.cpp				\
		MapView.cpp			\
		Block.cpp			\
		BlockView.cpp			\
		Tile.cpp			\
		TileView.cpp			\
		Wall.cpp			\
		WallView.cpp			\
		APlayer.cpp			\
		Player.cpp			\
		PlayerView.cpp			\
		Bonus.cpp			\
		BonusView.cpp			\
		Bomb.cpp			\
		BombView.cpp			\
		Fire.cpp			\
		FireView.cpp			\
		Warfare.cpp			\
		Sound.cpp			\
		MyText.cpp			\
		Save.cpp			\
		Intro.cpp			\
		IntroView.cpp			\
		Geometrics.cpp			\
		IA.cpp				\
		KeyHandler.cpp			\
		MainMenuHomeView.cpp		\
		MainMenuOptionsView.cpp		\
		MainMenuPlaySoloView.cpp	\
		MainMenuHome.cpp		\
		MainMenuOptions.cpp		\
		MainMenuPlaySolo.cpp		\
		MainMenuCredit.cpp		\
		MainMenuCreditView.cpp		\
		Img.cpp				\
		MainMenuLoadGame.cpp		\
		MainMenuLoadGameView.cpp	\
		Drawable.cpp			\
		TitleScreen.cpp			\
		EndGameScreen.cpp		\
		Utilities.cpp			\
		Error.cpp			\
		ErrorView.cpp			\

OBJ=		$(addprefix $(OBJDIR), $(SRC:.cpp=.o))


$(NAME):	$(OBJ)
		$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

$(OBJDIR)%.o:	%.cpp
		$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
