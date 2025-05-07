#include "GameController.h"

void GameController::startGame(int levelID) {
    // ���عؿ�����
    LevelConfigLoader levelConfigLoader = LevelConfigLoader();
    // ��ȡ�ļ������ؿ���
    std::vector<CardModel> cardModels = levelConfigLoader.loadLevelJson("../Classes/configs/LevelConfig.json");
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // ��������
    GameView* gameView = GameView::createScene();
    Director::getInstance()->runWithScene(gameView);

    // ���ƹ���
    GlobalCardController* globalCardController = new GlobalCardController(visibleSize.height / 6,
        visibleSize.width * 0 / 6, visibleSize.width * 2.5 / 6, visibleSize.width * 4 / 6, 
        gameView->playerField->getPosition().y);
    // ��ʼ������
    globalCardController->cardsInit(cardModels, gameView);
    //���ó�����ť
    gameView->setUndoButton(globalCardController);

}
