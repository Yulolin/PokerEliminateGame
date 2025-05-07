#include "LevelConfigLoader.h"

std::vector<CardModel> LevelConfigLoader::loadLevelJson(const char* path) {
	// 使用输入输出流读取json文件以二进制的形式读取
	std::fstream ifs;
	ifs.open(path, std::ios::binary | std::ios::in);
	if (!ifs.is_open()) {
		printf("Error  loading: %s\n", path);
		return std::vector<CardModel>();
	}
	// 读取到的二进制文件 调用jsoncpp读取其中的数据
	Json::Reader reader;
	Json::Value root;

	std::vector<CardModel> cardModels;
	if (ifs.is_open())
	{
		if (reader.parse(ifs, root))
		{
			// 已经将读取到文本文档存入到Json::Value root对象中了
			// Json::Value 类型的对象进行
			for each (auto var in root["Playfield"])
			{
				int cardSuit = var["CardSuit"].asInt();
				int cardFace = var["CardFace"].asInt();
				cocos2d::Vec2 position = cocos2d::Vec2(var["Position"]["x"].asFloat(), var["Position"]["y"].asFloat());
				CardFieldType cardField = CFT_PLAYERFIELD;
				cardModels.push_back(CardModel(cardFace, cardSuit, position, cardField));
			}
			for each (auto var in root["Stack"])
			{
				int cardSuit = var["CardSuit"].asInt();
				int cardFace = var["CardFace"].asInt();
				cocos2d::Vec2 position = cocos2d::Vec2(var["Position"]["x"].asFloat(), var["Position"]["y"].asFloat());
				CardFieldType cardField = CFT_HAND;
				cardModels.push_back(CardModel(cardFace, cardSuit, position, cardField));
			}
		}
	}
	return cardModels;
}
