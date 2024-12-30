#include "classes.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Dictionary dictionary;
	dictionary.add("human", "������");
	dictionary.add("dog", "������");
	dictionary.add("cat", "��");
	dictionary.add("feelings", "�������");
	dictionary.add("love", "�����");
	dictionary.add("hatred", "���������");
	dictionary.printWord("human");
	dictionary.printWord("dog");
	dictionary.printWord("cat");
	dictionary.changeTranslation("hatred", "�����");
	dictionary.printWord("hatred");
	dictionary.topThree();
	dictionary.bottomThree();
	dictionary.removeWord("dog");
	dictionary.printWord("dog");
	return 0;
}