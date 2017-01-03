#include "composite.h"


int main()
{
	MenuComponent* pancakeMenu = new Menu("PANCAKE MENU", "Breakfast");
	MenuComponent* lunchMenu = new Menu("LUNCH MENU", "Lunch");
	MenuComponent* dessertMenu = new Menu("DESSERT MENU","New Dessert!");

	MenuComponent* allMenus = new Menu("M&M house ", "enjoy your meal!");


	allMenus->add(pancakeMenu);
	pancakeMenu->add(new MenuItem("Banana pancake","pancake with banana ", 1.52));
	pancakeMenu->add(new MenuItem("Coffee pancake","pancake with coffee ", 2.22));


	allMenus->add(lunchMenu);
	lunchMenu->add(new MenuItem("Sweety Pasta","Spaheti with Sauce", 6.66));
	lunchMenu->add(new MenuItem("Curry rice","Curry with chicken ", 8.88));
	lunchMenu->add(new MenuItem("Beef noodle","Noodles with saulty beef ", 9.99));


	allMenus->add(dessertMenu);
	dessertMenu->add(new MenuItem("Apple Pie", "App pie with chocolate", 2.55));
	dessertMenu->add(new MenuItem("Pineapple Cake","egg plus pineapple ", 2.88));


	Waiter* waiter = new Waiter(allMenus);
	waiter->printMenu();
	return 0;
}
