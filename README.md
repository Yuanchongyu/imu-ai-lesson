# IMU AI 课程：从倾斜滚球到动作分类

用 XIAO nRF52840 Sense 这块 IMU 芯片，带学生走完四个循序渐进的小项目：

```
01_tilt_ball → 02_see_the_data → 03_step_counter → 04_motion_ai
   (先玩)         (看懂数据)        (写规则)          (训练AI)
```

每一步都比上一步难一点点：先靠手感建立"这东西能感觉到动作"的直觉，再看懂动作变成了什么数字，再学会用一条简单规则处理这些数字，最后才真正训练一个 AI 模型去做规则写不出来的事。

**网页全部是英文的**（面向学生），教案和本文件是中文的（面向老师）。

---

## 直接用这些网址（已上线，换电脑也不用重新配置）

GitHub Pages 已开启，用 **Chrome 或 Edge** 打开即可：

| 步骤 | 网址 |
|---|---|
| 1 · Tilt Ball | https://yuanchongyu.github.io/imu-ai-lesson/01_tilt_ball/ |
| 2 · See The Data | https://yuanchongyu.github.io/imu-ai-lesson/02_see_the_data/ |
| 3 · Step Counter | https://yuanchongyu.github.io/imu-ai-lesson/03_step_counter/ |
| 4 · Motion AI | https://yuanchongyu.github.io/imu-ai-lesson/04_motion_ai/ |

---

## ⚠️ 不能直接双击打开网页文件

这几个网页都用到 **Web Serial API**（浏览器直接读硬件串口），这个功能**只在"安全环境"下才能用**——双击 HTML 文件打开（网址栏显示 `file://`）不算安全环境，点连接按钮不会有反应。

上面的 GitHub Pages 网址是 `https://`，天然满足要求，**这是首选方式**。

**没网络时的备用方案**：在项目文件夹里开终端运行 `python3 -m http.server 8000`，然后浏览器打开 `http://localhost:8000/01_tilt_ball/`。
（注意：Windows 上 8000 端口可能被系统权限挡住，报 WinError 10013，换成 8080 或 5500 试试。）

每个网页顶部都有自动检测：万一还是双击打开了，页面会弹红色提示条，不会是"点了没反应"式的沉默失败。

---

## 硬件准备（换电脑就要重做一遍）

1. 装 [Arduino IDE](https://www.arduino.cc/en/software)
2. Arduino IDE 里加 Seeed 板卡地址：`https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json`
3. 板卡管理器里装 **Seeed nRF52 mbed-enabled Boards**
4. 库管理器里装 **Seeed Arduino LSM6DS3**
5. 打开 `firmware/imu_stream/imu_stream.ino`，板子选 **XIAO nRF52840 Sense**，烧录
6. 打开串口监视器确认能看到 `x,y,z` 数字在跳动，**然后关掉串口监视器**（串口同时只能被一个程序占用，监视器开着的话网页连不上）
7. 用 Chrome 或 Edge 打开上面的网址（Web Serial **不支持 Safari**，Mac 上记得手动换浏览器）

**已在 Windows 上实测通过**：编译占 11% 存储空间，烧录成功，板子识别为 COM5（VID_2886 / PID_8045）。

---

## 文件结构

```
IMU-AI-课程/
├── README.md                  本文件（中文，给老师看）
├── firmware/
│   └── imu_stream/
│       └── imu_stream.ino     烧到板子上的固件，四步共用同一份
│                              （.ino 必须放在同名文件夹里，这是 Arduino 的硬性要求）
├── 01_tilt_ball/index.html      开场秀：歪板子控制球滚动
├── 02_see_the_data/index.html   看懂动作变成的 x/y/z 数字和波形
├── 03_step_counter/index.html   不用 AI，靠阈值规则计步
├── 04_motion_ai/index.html      真正的机器学习：采集→训练→识别
└── 教案/
    ├── 计步器课教案.md          对应 01+02+03 三步（一节课，约 60-70 分钟）
    └── 动作分类课教案.md        对应 04（单独一节课，110-130 分钟）
```

---

## 上课前检查清单

- [ ] 按"硬件准备"在上课那台电脑上重新装好 Arduino 环境并烧录
- [ ] 用 Chrome/Edge 打开上面四个网址各测一次
- [ ] USB 线确认是**数据线**不是纯充电线（这是最经典的坑）
- [ ] 串口监视器已关闭
- [ ] 教室网络能访问 github.io（有些机构网络会拦，提前测）
