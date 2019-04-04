# SRB总线连接与配置
`李阳` `lee8871@126.com`</br>
本文将指导您使用Arduino控制SRB设备。</br>

## 准备
你需要准备这些东西</br>
- **Arduino Leonardo**  //主程序在里面运行。
- **SRB转UART**  //用来将Arduino连接到SRB，形成SRB主机
- **USB转Uart** 或 **SRB转USB**   //用来连接PC端，这里只详细介绍USB转Uart。
- **SRB双电机模块**  //一个SRB节点。
- 一个机器人底盘，包括：
  - **两个电机** //SRB双电机模块即将控制的两个电机。
  - **电源** //机器人上的电池供电，你的电源可以采用4节AA电池（6V）或者2节锂电池（8V）
- **排线**、**导线** 与 **IDC接头** //用于接线

<img src="Image\Robot.jpg"  height="330" width="495"></br>
这是我用的机器人底盘。里面有四个电机，我把同一边的两个电机连在一起，这样可以看做两个电机的底盘。</br></br>
<img src="Image\Devices.jpg"  height="330" width="495"></br>
这是要用到的电路板。其中右上模块为小型Leonardo。左下模块为SRB转USB模块，此模块可以不用。</br></br>

## 接线
1. IDC的压线方法请参考[这里](https://github.com/lee8871/SRB-Introduction/blob/master/IDC%E5%8E%8B%E7%BA%BF%E6%96%B9%E6%B3%95.md)。在灰色排线上压接两个IDC接头，根据机器人中你安装模块的位置，确定排线的长度和接头的位置。</br>
<img src="Image\Bus-2-IDCs.jpg"  height="330" width="495"></br>
接头的朝向没有关系，只要IDC的Pin1标记和排线对应。
2. 给排线供电。Pin3-->Gnd Pin4-->Vcc。</br>
<img src="Image\connect-to-power.jpg"  height="330" width="495"></br>
这个时候打开开关，就能看到指示灯点亮了。</br>
3. 连接双电机模块的电机和动力电源。电机如果没有接好的PH2.0mm接头，也可以直接将导线焊接在电路板上。
<img src="Image\connect-motors.jpg"  height="330" width="495"></br>

4. 连接SRB转Uart到Leonardo。接法如下：</br>

引脚 | SRB端 | Leonardo
---|---|---
1  |VCC | 连接5V
2  |GND   | 连接GND
3  |SRB2UNO |连接0 Rx。
4  |UNO2SRB |连接1 Tx。
5  |DE  |连接2。
6  |nRE |连接3。

照片中的接线使用老版本的 SRB转Uart，接线顺序与新版不同，请按照接线表格进行连接。</br>
5. 最后，连接**USB转UART**。只有[leonardo_bridge](https://github.com/lee8871/SRB-master-arduino/blob/master/examples/leonardo_bridge/leonardo_bridge.ino)使用Uart转Usb。例程中标明了串口使用的管脚。</br>
6. 全部接好后，是这个样子的：</br>
<img src="Image\finish.jpg"  height="330" width="495"></br>
<img src="http://assets.processon.com/chart_image/5b3755e8e4b045a5a30d6a3a.png"></br>

## 使用PC进行配置
1. 首先使用ArduinoIDE烧写[leonardo_bridge](https://github.com/lee8871/SRB-master-arduino/blob/master/examples/leonardo_bridge/leonardo_bridge.ino)。
2. 打开SRB-Config选择**端口配置**->**uart**在出现的工具栏中选择对应的串口，例如我这里选择COM5。</br>
<img src="Image\open-port.png"></br>
3. 点击扫描节点按钮，然后点击扫描得到的节点。</br>
<img src="Image\search-node.png"></br>
4. 下面我们已经迫不及待的想让电机转动了。在上一步中打开的窗口中，打开功能测试栏，鼠标四处拖动，电机就会转动。</br>
<img src="Image\control.png"></br>
5. 配置节点。最常用的配置是节点的地址。如果总线上有多个节点，你需要一个一个接入总线，将地址配置成每个不同。你也可以对电机模块的一些参数进行配置。</br>
<img src="Image\config.png"></br>
6. 顺带一提，主窗口中的另外两个按钮分别是运行SRB程序，和地址显示。运行SRB程序在这个例子中没有用，如果你希望用电脑控制机器人运动，则需要使用这个功能。
