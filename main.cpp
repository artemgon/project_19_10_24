#include "classes.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Dictionary dictionary;
	dictionary.add("human", "людина");
	dictionary.add("dog", "собака");
	dictionary.add("cat", "кіт");
	dictionary.add("feelings", "почуття");
	dictionary.add("love", "любов");
	dictionary.add("hatred", "ненависть");
	dictionary.printWord("human");
	dictionary.printWord("dog");
	dictionary.printWord("cat");
	dictionary.changeTranslation("hatred", "огида");
	dictionary.printWord("hatred");
	dictionary.topThree();
	dictionary.bottomThree();
	dictionary.removeWord("dog");
	dictionary.printWord("dog");
	return 0;
}