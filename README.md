本作品基于龙芯 2K1000LA 开发板构建网关显示与控制终端，以龙芯 1C102 开发板作为传感节点主控芯片。传感节点通过 Wi-Fi 协议实时采集温度、湿度、光照等环境数据，经无线传输至显示与控制终端，终端再将数据传输至华为云云服务器，终端运行 Qt代码显示系统界面 ，实现数据实时显示，同时还接入了deepseek大模型，实现通过AI节点状态监测和数据分析。针对工业场景多节点供电布线难、造价高、扩展性差等痛点，系统依托无线连接技术实现分布式多点环境信息实时采集，并集成数据分析功能，可触发超数值阈值报警，支持历史数据查询与远程数据查看。该系统适用于低温冷库、食品生产、防尘车间等工业环境，有效解决传统有线传感系统弊端，提升工业环境监测的智能化与便捷化水平。



loongdisp是在linux上运行的qt代码，
节点代码直接烧录到1c102上即可
