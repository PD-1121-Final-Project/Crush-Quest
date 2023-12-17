
// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include "Admirer.h"
#include "Character.h"
#include "Crush.h"
#include "Personality.h"
#include "../Item/Item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Enemy : public Character {
  private:
    double impression;
    vector <string> attackEvents = {"你的情敵精心策劃了一次約會，邀請了暗戀對象去新北耶誕城。\n他們漫步在璀璨的燈飾下，享受著節日的歡樂氛圍。\n他們一起去逛耶誕市集，你的情敵買了熱可可給暗戀對象，讓整個晚上顯得格外浪漫。\n",
                                    "你的情敵邀請了暗戀對象一起去看一部最新上映的喜劇電影。\n他們一起分享了爆米花，並在電影中不時交換笑容。\n電影結束後，他們還一起討論了劇情，這次約會讓他們的關係更加親密。\n",
                                    "在一次聚會上，你的情敵為暗戀對象唱了一首情歌。\n他的聲音溫暖而動聽，讓聽眾為之著迷。\n暗戀對象看上去非常欣賞這次表演，臉上露出了陶醉的笑容，顯然被深深打動了。\n",
                                    "你的情敵在社交媒體上發布了一個與暗戀對象的自拍限時動態。\n照片中兩人有些親密，似乎在享受一個美好的時刻。\n這個動態吸引了一些朋友的點讚和評論，顯示他們之間良好的互動。\n",
                                    "你的暗戀對象特地去觀看了你的情敵的之夜表演。\n情敵在舞台上表現出色，吸引了所有觀眾的目光，包括你的暗戀對象。表演結束後，暗戀對象對情敵的才華讚不絕口，顯然對這次表演印象深刻。\n",
                                    "你的情敵在學術上取得了顯著的成就，成功發了一篇paper。\n這一成就在朋友間引起了轟動，也讓暗戀對象對他刮目相看。\n情敵的學術成就不僅提升了他的聲譽，也加深了暗戀對象對他的敬佩。\n",
                                    "你的情敵開始在暗戀對象下課後主動前去接她。\n他們一起走出教室，聊著天，一同前往下一個目的地。\n這種貼心的舉動讓暗戀對象感到驚喜和愉快，也逐漸增進了他們之間的感情。\n"};

  public:
    Enemy(const std::string& name, Personality attributes);
    ~Enemy();
    void attack(Crush& crush, Admirer& admirer, vector<Item*> items, int itemCnt);
    void update(Personality a, double impressionIncre);
    void printImpre();
    double getImpression();
  friend class Admirer;
  friend class Crush;
};

#endif // ENEMY_H
