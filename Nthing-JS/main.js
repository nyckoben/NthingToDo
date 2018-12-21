//该文件为electron应用程序入口，启动浏览器后加载index.html
const electron = require('electron')
const { ipcMain } = require('electron')
const { app, BrowserWindow } = require('electron')

function createWindow() {
  // 创建浏览器窗口
  // 日历模块基本是1:1
  var window_size = 800;
  win = new BrowserWindow({ width: window_size, height: window_size })
  win.webContents.openDevTools()

  // 然后加载应用的 index.html。
  win.loadFile('front_end/index.html')

  //win.webContents.send('init_event',events)

}

app.on('ready', createWindow)


//ipc收前端消息
ipcMain.on('init_event', (event) => {
  console.log("main get init event") // prints "ping"

	var date = new Date();
	var d = date.getDate();
	var m = date.getMonth();
	var y = date.getFullYear();
  events = [
    {
        title: 'All Day Event',
        start: new Date(y, m, 1)
    },
    {
        title: 'Long Event',
        start: new Date(y, m, d-5),
        end: new Date(y, m, d-2)
    },
    {
        id: 999,
        title: 'Repeating Event',
        start: new Date(y, m, d-3, 16, 0),
        allDay: false
    },
    {
        id: 999,
        title: 'Repeating Event',
        start: new Date(y, m, d+4, 16, 0),
        allDay: false
    },
    {
        id: 111,
        title: 'Meeting',
        start: new Date(y, m, d, 10, 30),
        allDay: false
    },
    {
        title: 'Lunch',
        start: new Date(y, m, d, 12, 0),
        end: new Date(y, m, d, 14, 0),
        allDay: false
    },
    {
        title: 'Birthday Party',
        start: new Date(y, m, d+1, 19, 0),
        end: new Date(y, m, d+1, 22, 30),
        allDay: false
    },
    {
        title: 'Click for Google',
        start: new Date(y, m, 28),
        end: new Date(y, m, 29),
        url: '../../google.com/default.htm'
    }
  ];
  event.sender.send('init_event_reply', events)//异步方法
  //event.returnValue = 'pong'//同步方法
})



// var file = "NtingToDo.db";
// var sqliteDB = new SqliteDB(file);
// var createTableSql = "create table if not exists t_nthing_events("
//     + "row_id integer NOT NULL AUTO_INCREMENT,"
//     + "gmt_time integer UNSIGNED NOT NULL,"
//     + "title varchar(64)"
//     + "stime integer UNSIGNED NOT NULL,"
//     + "etime integer UNSIGNED NOT NULL,"
//     + "PRIMARY KEY (row_id)"
//     + ");";
// sqliteDB.createTable(createTableSql);


// var querySql = 'select * from t_nthing_events;';
// sqliteDB.queryData(querySql, getInitEvens_i);

// return events;
// }



// function getInitEvens_i(objects){
// for(var i = 0; i < objects.length; ++i)
// {
//     console.log(objects[i]);
// }
