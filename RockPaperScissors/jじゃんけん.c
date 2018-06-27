/**インクルード******************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/**************************/
int judge(int player, int enemy) {
  int result_map[][3] =
    {{0,1,2},
     {2,0,1},
     {1,2,0}};
  return result_map[player][enemy];
}

char get_one_char() {
  char buf = getchar();
  while (getchar() != '\n');
  return buf;
}

int check_valid_hand(int hand) {
  return hand == 0 || hand == 1 || hand == 2;
}

int main(void){
  srand(time(NULL));
  /**表紙*******************************/
  printf("\n            Game Start!!\n\n");
  int win = 0;
  int drow = 0;
  int loose = 0;
  int count = 0;
  while(1){
    printf(" *ゲームスタート >>1\n *スコア >>2\n *やめる >>3:");
    char option = get_one_char();
    /***ゲーム*************************/
    while(option=='1'){
      printf("   グーは>>1   チョキは>>2   パーは>>3\n");
      printf("    あなたの手を選んでください:");
      int player = get_one_char() - '1';
      int enemy = rand() % 3;
      if(check_valid_hand(player)){
        if(judge(player,enemy) == 0){
          printf("   あいこです\n");
          drow ++;
        }
        else if(judge(player,enemy) == 1){
          printf("   あなたの勝ちです\n");
          win ++;
        }
        else if(judge(player,enemy) == 2){
          printf("   あなたの負けです\n");
          loose ++;
        }
        printf("     続ける>>1\n     やめる>>2:");
        count ++;
        if(get_one_char() =='2'){
          break;
        }
      }
      printf(" もう一度\n");
    }
    /**スコア*********************************/
    while(option=='2'){
      if(count == 0){
        printf(" まだじゃんけんしてないよ\n");
      }
      else if(count != 0){
        double score[3];
        score[0] = (double) win/(double)count;
        score[1] = (double) drow/(double)count;
        score[2] = (double) loose/(double)count; 
        printf(" 勝率は%f％です\n",score[0]*100);
        printf(" あいこ率は%f％です\n",score[1]*100);
        printf(" 敗率は%f％です\n",score[2]*100);
        if(score[0]==0){printf("  あなたは勝利したことがありません\n");}
        if(!score[2]){printf("  あなたは敗北を知りません\n");}
      }
      printf("               1で戻る：");
      char a = get_one_char();
      if(a == '1')break;
    }
    /*************************/
    if(option =='3')break;
  }
  return 0;
}
