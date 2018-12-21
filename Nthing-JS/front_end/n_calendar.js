const electron = require('electron');
const ipcRenderer = electron.ipcRenderer;

var events = [];

$(document).ready(function() {
    $('#calendar').fullCalendar({
        header: {
            left: 'prev,next,today',
            center: 'title',//年份，月份
            right: 'month,agendaWeek,agendaDay'
        },
        buttonText:{
            today:'Jump to current day'
        },
        editable: true,
        events: [],
        eventClick: function(calEvent, jsEvent, view) {
            var r=confirm("Is this Event(" + calEvent.title + ") have been done?");
            if (r==true)
            {
                if(calEvent.id)
                {
                    $('#calendar').fullCalendar( 'removeEvents' , calEvent.id )//要确保所有event都有id
                    alert("You pressed OK, delete event id : " + calEvent.id + "!");
                }
                else
                {
                    alert("You pressed OK, but calEvent.id is null! WTFFF?");
                }
            }
            else
            {
                alert("You pressed Cancel!");
            }
            //$(this).css('border-color', 'red');//可以用来显示已完成的不同颜色
        }
    });
});

function on_add_event(){
    var dateStr = $("#input_date").val();
    var date = moment(dateStr);

    if (date.isValid()) {
        on_add_event_i({
            id: Date().getTime(),//毫秒级时间戳
            title: $("#input_title").val(),
            start: date,
            allDay: false
        });
        alert('Great. Now, update your database...');
    } else {
        alert('Invalid date.');
    }
}

function on_add_event_i(event){
    $('#calendar').fullCalendar('renderEvent', event);
}

function on_init_event(){
    //ipcRenderer.sendSync('synchronous-message', 'ping')//同步发送
    ipcRenderer.send('init_event')//异步发送
}


// 异步监听 codeCookie
ipcRenderer.on('init_event_reply', (e, msg) => {
    events = msg;
    console.log('接受主进程发送的events: '+events);
    for(i = 0; i != events.length ; ++i)
    {
        on_add_event_i(events[i]);
    }
});
