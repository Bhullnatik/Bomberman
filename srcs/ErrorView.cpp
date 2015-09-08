//
// ErrorView.cpp for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  9 15:44:56 2013 Jérémy Magrin
// Last update Sun Jun  9 21:57:45 2013 leo chazal
//

#include	"ErrorView.hh"
#include	"Error.hh"

Bomberman::ErrorView::ErrorView()
{

}

Bomberman::ErrorView::~ErrorView()
{

}

void			Bomberman::ErrorView::initialize(void)
{

}

void			Bomberman::ErrorView::draw(const AModel *inst)
{
  const Bomberman::Error		*error = dynamic_cast<const Bomberman::Error *>(inst);
  Bomberman::MyText                     text;
  std::list<std::string>		listTmp;
  std::string				tmp;
  float					posX;
  float					posY;
  int					i = 0;

  Bomberman::Drawable::getInstance()->drawBg(10);

  posX = (error->getWidth() / 2) - (5 * error->getErrorMsg().size());
  posY = (error->getHeight() / 2) - 10;
  text = error->getText();
  if (posX <= 0)
    {
      for (std::string::const_iterator it = error->getErrorMsg().begin();
	   it != error->getErrorMsg().end(); it++)
	{
	  if (tmp.size() == error->getWidth() / 25)
	    {
	      listTmp.push_back(tmp);
	      tmp.erase();
	    }
	  tmp += (*it);
	}
      for (std::list<std::string>::iterator it = listTmp.begin();
	   it != listTmp.end(); it++)
	{
	  posX = (error->getWidth() / 2) - (((listTmp.size() / 2) + 4) * tmp.size());
	  posY = (error->getHeight() / 2) - (15 * listTmp.size()) + 50;
	  text.draw((*it), posX, posY + i, 20);
	  i += 20;
	  if (posY + i + 40 >= error->getHeight())
	    break;
	}
    }
  else
    text.draw(error->getErrorMsg(), posX, posY, 20);
  text.draw("    Retour", 0, 20, 20);
}
