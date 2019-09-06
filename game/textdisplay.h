#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "view.h"

class TextDisplay : public View {
	char **display;
	public:
		TextDisplay();
		~TextDisplay();
		virtual void notify(int, int, char);
		virtual void print(std::ostream&, char) const;
};

#endif
