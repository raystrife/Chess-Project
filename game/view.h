#ifndef VIEW_H
#define VIEW_H
#include <iostream>

class View {
	public:
		virtual ~View() {}
		virtual void notify(int, int, char) = 0;
		virtual void print(std::ostream&, char) const = 0;
};

#endif
