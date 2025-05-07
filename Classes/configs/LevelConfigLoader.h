#pragma once
#include <fstream>
#include <utils/json/json.h>
#include <cocos2d.h>
#include <models/CardModel.h>
#include <vector>

// 关卡信息加载器，加载json关卡文件
class LevelConfigLoader
{
public:
	std::vector<CardModel> loadLevelJson(const char* path);
};

