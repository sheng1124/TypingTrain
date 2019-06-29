#include <iostream>
#include <fstream>

using namespace std;

class Game
{
public:
	Game(const char *args);
	~Game();

	void loadText(const char *filename);

private:
	void closeTrainFile(){ trainFile.close(); }

	fstream trainFile;
};

Game::Game(const char *args)
{
	this->loadText(args);
}

Game::~Game()
{
	this->closeTrainFile();
}

void Game::loadText(const char *filename)
{
	trainFile.open(filename, ios::in);
	if(!trainFile.is_open())
	{
		cerr << "can't open file" << endl;
		exit(0);
	}
}

bool testArgs(int argc);

int main(int argc, char **argv)
{
	cout << argv[1] << endl;
	if(!testArgs(argc)) return 0;

	Game typingTrain(argv[1]);

}

bool testArgs(int argc)
{
	if(argc < 2)
	{
		cerr << "no file path" << endl;
		return false;
	}
	else if(argc > 2)
	{
		cerr << "too many files" << endl;
		return false;
	}

	return true;
}