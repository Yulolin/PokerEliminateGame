#include "GameController.h"

void GameController::startGame(int levelID) {
    // 加载关卡数据
    LevelConfigLoader levelConfigLoader = LevelConfigLoader();
    // 读取文件并加载卡牌
    std::vector<CardModel> cardModels = levelConfigLoader.loadLevelJson("../Classes/configs/LevelConfig.json");
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // 创建场景
    GameView* gameView = GameView::createScene();
    Director::getInstance()->runWithScene(gameView);

    // 卡牌管理
    GlobalCardController* globalCardController = new GlobalCardController(visibleSize.height / 6,
        visibleSize.width * 0 / 6, visibleSize.width * 2.5 / 6, visibleSize.width * 4 / 6, 
        gameView->playerField->getPosition().y);
    // 初始化卡牌
    globalCardController->cardsInit(cardModels, gameView);
    //设置撤销按钮
    gameView->setUndoButton(globalCardController);

}
