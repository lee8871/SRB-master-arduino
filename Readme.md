# SRB Master Arduino
`李阳` `lee8871@126.com`
## 简单机器人总线（Simple Robotic Bus，SRB）
相信你已经看过[SRB简介](https://github.com/lee8871/SRB-Introduction)了。
这里将介绍如何使用Arduino连接SRB。这个使用Leonardo连接SRB。</br>
Arduino UNO的陶瓦振荡器精度比较低，连接SRB不太稳定，如果能手工将UNO的振荡器换成晶体振荡器，连接SRB也不错。</br>

## 编程概览
Arduino目前只支持访问数据，配置需要使用SRBConfig软件。</br>
你没有看明白SRB总线协议也没有关系，使用SRB非常简单，你只需要理解这里的内容就够了。

## 数据模型
在这个例子里，总线上只有一个双电机节点。双电机节点内有一个交互储存区内容如下：[(这是这个数据结构的定义)](readonly\SRB-app-dmotor-share.h)
* 电机A低位   1Byte
* 电机A高位   1Byte
* 电机B低位   1Byte
* 电机B高位   1Byte

我们再Arduino中也声明一个相同的数据块:
```c++
	Du_Motor::sDataRs motor_data; //定义一个双电机模块的数据空间
  ```
motor_data只是一个结构体，对他的修改还不能影响到节点。
需要定义一个通信节点，负责将motor_data的数据变化传给节点，或者将节点数据的变化传回
motor_data（当然双电机没有需要回传的数据）。

```c++
	SrbTinyNode node_motor; //定义一个节点
  ```
然后需要将节点进行初始化配置
```c++
	void nodeInit(){
	    node_motor.address = 4;//设置节点地址
	    node_motor.datas = (uint8*)(&motor_data);//设置节点数据空间
  ```
motor_data中有些数据要传给节点，有些数据要从节点读出，Du_Motor::mappingX决定了哪些数据是读出，哪些数据是读入。下面需要将这些数据的访问规则告诉node_motor：
```c++
	    node_motor.mapping[0] = (sStaticMapping*)(Du_Motor::mapping0);//设置节点访问映射表
	    node_motor.mapping[1] = (sStaticMapping*)(Du_Motor::mapping1);
	    node_motor.mapping[2] = (sStaticMapping*)(Du_Motor::mapping2);
	    node_motor.mapping[3] = (sStaticMapping*)(Du_Motor::mapping3);
	}
```
节点有四个数据端口，每个端口传输的数据有可能不同。（在这个例子中，四个端口传输的数据是相同的，只是顺序不同）这里可能不太好理解，如果不理解，只需要记住这样写就好，这段代码没有任何变数。</br></br>

在运行过程中，可以这样是对motor_data进行修改:

```c++
	motor_data.ma.speed = 620;//速度是620，ma表示 motorA
  motor_data.ma.dir = MOTOR_DIR_REVERSE;//反转
	motor_data.mb.speed = 1000;//mb表示MotorB
  motor_data.mb.dir = MOTOR_DIR_BRAKE;//刹车
  motor_data.mb.u16 = motor_data.ma.u16//u16是speed和dir的组合，相当于将电机A的状态复制给B
  ```
修改数据后还要使用access(0)将数据写入电机节点。access函数的参数是访问的端口，范围是0到3。</br>
```c++
	node_motor.access(0);//将刚刚写好的数据发往电机.
```
数据访问将按照端口说明将motor_data的数据发给节点，对于带有传感器的节点，也会从中读取传感器数据。放入motor_data。在进行一次</br>
