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
    /*ファイル操作*/
  FILE *fp;
  if((fp = fopen("history.txt","r")) == NULL){
    fp = fopen("history.txt","a+");
    fprintf(fp,"win_%d\n",0);
    fprintf(fp,"draw_%d\n",0);
    fprintf(fp,"lose_%d\n",0);
  }
  char s[256];
  int push;
  int i = 0;
  char a[10],b[10],c[10];
  while((push = fgetc(fp)) != '\n'){
    if(push >= 48 && push <= 57){
      a[i] = push;
      i++;
    }
  }
  i = 0;
  while((push = fgetc(fp)) != '\n'){
    if(push >= 48 && push <= 57){
      b[i] = push;
      i++;
    }
  }
  i = 0;
  while((push = fgetc(fp)) != '\n'){
    if(push >= 48 && push <= 57){
      c[i] = push;
      i++;
    }
  }
  int win = atoi(a);
  int draw = atoi(b);
  int lose = atoi(c);
  /*
  win = atoi(a);
  draw = atoi(b);
  lose = atoi(c);
  */
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
          draw ++;
        }
        else if(judge(player,enemy) == 1){
          printf("   あなたの勝ちです\n");
          win ++;
        }
        else if(judge(player,enemy) == 2){
          printf("   あなたの負けです\n");
          lose ++;
        }
        printf("     続ける>>1\n     やめる>>2:");
        if(get_one_char() =='2'){
          break;
        }
      }
      printf(" もう一度\n");
    }
    /**スコア*********************************/
    while(option=='2'){
      int count = win + draw + lose;
      if(count == 0){
        printf(" まだじゃんけんしてないよ\n");
      }
      else if(count != 0){
        double score[3];
        score[0] = (double) win/(double)count;
        score[1] = (double) draw/(double)count;
        score[2] = (double) lose/(double)count; 
        printf(" 勝率は%.1f％です\n",score[0]*100);
        printf(" あいこ率は%.1f％です\n",score[1]*100);
        printf(" 敗率は%.1f％です\n",score[2]*100);
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
