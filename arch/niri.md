# niri

## 在 niri 下用嵌套合成器包裹问题窗口

niri 是严格的平铺 Wayland 合成器，部分窗口可能行为异常。除 `xwayland-satellite` 处理 X11 兼容外，可用嵌套合成器把问题窗口“包”起来运行。

---

## labwc：堆叠式小桌面

**定位**：传统堆叠式 Wayland 合成器，在 niri 里作为普通窗口打开，内部可管理多个窗口。

**安装**：

```bash
sudo pacman -S labwc
```

**使用**：

```bash
labwc
```

niri 屏幕上出现 labwc 窗口后，在内部运行问题应用：

```bash
env DISPLAY=:0 <问题应用命令>
```

也可在 labwc 内用默认快捷键（通常 `Super + Enter`）开终端再启动应用。

**适用场景**：需要多窗口协作的复杂程序；需要传统窗口定位行为的 X11 应用。

**注意**：默认配置精简，快捷键或自启动可改 `~/.config/labwc/` 下配置文件。关掉 labwc 窗口即回到 niri 正常状态。

---

## cage：单应用 Kiosk 牢笼

**定位**：极简 Kiosk 合成器，一次只全屏显示一个应用，阻止与外部交互。

**安装**：

```bash
sudo pacman -S cage
```

**使用**：

```bash
cage -- <问题应用命令>
```

例：

```bash
cage -- problem-app
```

niri 弹出新窗口，应用全屏独占运行。

**常用选项**：

```bash
cage -s -- problem-app
```

`-s` 允许 VT 切换，应用捕获所有按键时可用 `Ctrl+Alt+F2` 切回 TTY 救急。

**适用场景**：只需自己运行、不需要多窗口交互的单一程序；全屏游戏、信息亭终端、特殊 X11 工具。

---

## 选择建议

| 需求 | 选择 |
|---|---|
| 需要多窗口、传统堆叠桌面 | labwc |
| 单应用全屏独占、最小干扰 | cage |
| 仅 X11 兼容问题 | 先确认 xwayland-satellite 正常 |
