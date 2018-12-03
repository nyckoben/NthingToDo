const { app, BrowserWindow , Menu, Tray} = require('electron')
  
function createWindow () {   
// 创建浏览器窗口
//https://electronjs.org/docs/api/frameless-window
win = new BrowserWindow({ width: 1600, height: 300 })

// 然后加载应用的 index.html。
win.loadFile('index.html')
}

function createTray () {
    let tray = null
    tray = new Tray('48X48.ico')
    const contextMenu = Menu.buildFromTemplate([
      {label: 'Item1', type: 'radio'},
      {label: 'Item2', type: 'radio'},
      {label: 'Item3', type: 'radio', checked: true},
      {label: 'Item4', type: 'radio'}
    ])
    tray.setToolTip('This is my application.')
    tray.setContextMenu(contextMenu)

}

function on_ready () {
    createTray()
    createWindow()
}

app.on('ready', on_ready)


////////////////////////////
