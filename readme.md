# 備忘録

2025/03/03阪木
・Lチカができるようにapp_process.cに変更を行いました。<br><br>
　-----slcpからGPIO Initをインストールし、新しいインスタンスを追加します。追加したインスタンスを設定でpin modeをopen_drain outputとします。SL_EMLIB_GPIO_INIT_インスタンス名　にはピンの設定を行ってください。<br><br>
  -----app_process.cについてはapp_process_action関数がありこの関数がmain.cでwhileループしているのでapp_process.cにLチカができるように書き込みます。<br><br>
  -----"em_gpio.h""sl_udelay.h"はLED点灯用の.hファイルです。sl_udelay.hはslcpからMicrosecond delayをインストールしてください。<br><br>
  
・今はIADCを使ってCPUの電圧を表示しようとしています。


