//该文件为electron应用程序入口，启动浏览器后加载index.html
const electron = require('electron')
const { app, BrowserWindow } = require('electron')

function createWindow () {   
  // 创建浏览器窗口
  // 日历模块基本是1:1
  var window_size = 800;
  win = new BrowserWindow({ width: window_size, height: window_size })

  // 然后加载应用的 index.html。
  win.loadFile('index.html')
}

app.on('ready', createWindow)