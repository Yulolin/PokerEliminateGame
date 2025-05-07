# PokerEliminateGame
## 演示视频
[![video](https://github.com/Yulolin/PokerEliminateGame/blob/main/Video.mp4)](https://github.com/user-attachments/assets/a0784d4c-2be9-4d48-91de-f1ec90aa756d)
## 程序运行流程
程序从main进入，使用AppDelegate生成Application应用，并调用GameController开始游戏。
GameController创建卡牌管理类GlobalCardController和游戏场景GameView，并进行初始化。
在GameView中创建游戏的场景背景及撤销、关闭等按钮。
创建完后使用LevelConfigLoader类来读取关卡json文件中的数据，并将数据传递给GlobalCardController::init()函数进行卡牌的初始化加载。
## 卡牌模块
使用CardController作为卡牌类进行实现，其中包含卡牌数据CardModel和卡牌显示CardView。
其作为卡牌原子供程序其他部分使用。
### 卡牌数据
CardModel作为卡牌数据变量，拥有四个关键变量
![image](https://github.com/user-attachments/assets/024a75bb-1a2b-44ba-b246-cf25a1595800)
### 卡牌显示
CardView作为卡牌显示类，继承自ImageView，包含一系列显示层面的函数实现。
通过传入的CardModel数据来对卡牌的位置显示进行更改。
![image](https://github.com/user-attachments/assets/ab816316-6b62-42e5-8da2-08336ccedc07)
## 卡牌管理
使用GlobalCardController进行卡牌管理。
### 全局卡牌数据
GlobalCardController持有GameModel游戏卡牌数据
其中包括三个区域，手牌区、手牌栈区、桌面区
![image](https://github.com/user-attachments/assets/f6ed681a-73ec-431a-807c-4af1b4598fb0)
### 卡牌移动逻辑
GlobalCardController实现多个函数来对卡牌进行移动操作，通过传入CardController*变量来对卡牌进行操作，包括：
handToStack：手牌区域卡牌移动到栈区
addToStack：桌面区域卡牌移动到栈区
### 撤销逻辑
GlobalCardController包含UndoManager变量。
UndoManager中使用栈来存储玩家操作的Operation数据，内容包括玩家点击的CardController*，点击前的位置，点击前卡牌所属的区域。
并实现撤销的逻辑供GlobalCardController使用。
## 未来展望
### 新卡牌添加
新的卡牌可以通过直接在关卡配置json文件中添加词条实现
若是新类型的卡牌，可以通过增加新的CardModel数据类来对卡牌信息进行保存，同时新增加CardView类对其进行显示，并在LevelConfigLoader类和GlobalCardController类中增加对应的逻辑处理。
### 新撤销功能
比如说添加一个回退上上步的功能，在UndoManager中对撤销逻辑进行增加，取出栈的第二个元素，回退相应操作，再将原来的第一个放回。
