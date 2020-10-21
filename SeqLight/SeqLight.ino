//--------------------------------------------------------------------------------
// あらかじめ設定された点灯条件を再生するスケッチ
// [SeqLight.ino]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
//
// http://maison-dcc.sblo.jp/ http://dcc.client.jp/ http://ayabu.blog.shinobi.jp/
// https://twitter.com/masashi_214
//
// DCC電子工作連合のメンバーです
// https://desktopstation.net/tmi/ https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

#include "SeqLight.h"
  
unsigned long PreviosTime = 0;
unsigned long PreviosTime2 = 0;

// ArduinoNANOのデジタル出力 3,4,5,6,9,10,11 用のオブジェクトを生成
SeqLight LedA = SeqLight(3,7);
SeqLight LedB = SeqLight(5,8);
SeqLight LedC = SeqLight(6,9);
SeqLight LedD = SeqLight(9,10);
SeqLight LedE = SeqLight(10,11);
//SeqLight LedF = SeqLight(11,8);

void setup() {
  Serial.begin(115200);
    
  PreviosTime = millis();
  PreviosTime2 = PreviosTime;
  LedA.OnOff(ON);
  LedB.OnOff(ON);
  LedC.OnOff(ON);
  LedD.OnOff(ON);
  LedE.OnOff(ON);
//  LedF.OnOff(ON);
}

void loop() {
  static int sel = 0;
  if( (millis() - PreviosTime ) >= 10 ){  // 10:10msec 前回から10ms経過したかチェック
    PreviosTime = millis();
    LedA.stateCheck();
    LedB.stateCheck();
    LedC.stateCheck();
    LedD.stateCheck();
    LedE.stateCheck();
//    LedF.stateCheck();
  }
  if( (millis() - PreviosTime2 ) >= 5000 ){  // 5000:5000msec 前回から5000ms経過したかチェック
    PreviosTime2 = millis();
    switch(sel){
      case OFF:
              LedA.OnOff(OFF);
              LedB.OnOff(OFF);
              LedC.OnOff(OFF);
              LedD.OnOff(OFF);
              LedE.OnOff(OFF);
//              LedF.OnOff(OFF);
              sel = 1;
              break;
      case ON:
              LedA.OnOff(ON);
              LedB.OnOff(ON);
              LedC.OnOff(ON);
              LedD.OnOff(ON);
              LedE.OnOff(ON);
//              LedF.OnOff(ON);
              sel = 0;
              break;                            
      default:
              break;
    }
  }
}
