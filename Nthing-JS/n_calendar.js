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
        events: getInitEvens(),
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
        $('#calendar').fullCalendar('renderEvent', {
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

function getInitEvens(){
	var date = new Date();
	var d = date.getDate();
	var m = date.getMonth();
	var y = date.getFullYear();
    var events = [
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
    return events;
}
