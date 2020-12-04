#include <iostream>
#include <bangtal>
#include <ctime>

using namespace bangtal;
using namespace std;

extern void one_main();
extern void two_main();
extern void three_main();
ScenePtr lobbyScene;
SoundPtr lobbySound;

int level = 1;

void lobby_main() {
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	lobbyScene = Scene::create("", "Images/대기실.png");
	lobbySound = Sound::create("music/lobby.mp3");

	lobbySound->play();

	auto ob = Object::create("Images/pan.png", lobbyScene, 0, 0);

	ob->setOnMouseCallback([&](ObjectPtr, int x, int y, MouseAction) -> bool {
		// cout << x << " " << y << endl;
		if (x > 380 && x < 800 && y > 475 && y < 575) {
			lobbySound->stop();
			one_main();
		}
		else if (x > 815 && x < 1235 && y > 475 && y < 575) {
			if (level < 3) {
				showMessage("2단계를 깨야만 PLAY할 수 있습니다.");
				return true;
			}
			lobbySound->stop();
			three_main();
		}
		else if (x > 380 && x < 800 && y > 370 && y < 470) {
			
			if (level < 2) {
				showMessage("1단계를 깨야만 PLAY할 수 있습니다.");
				return true;
			}
			lobbySound->stop();
			two_main();
		} 
		return true;
	});

	enterScene(lobbyScene->ID());
}