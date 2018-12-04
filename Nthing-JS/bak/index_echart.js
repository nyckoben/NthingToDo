
var app = new Vue({
    el: '#app',
    data: {
        subject:"",
        etime:0,
        level:0,
        series_data: []
    },
    methods: {
        draw: function () {
            var option = {
                tooltip : {
                    trigger: 'axis',
                    axisPointer : {            // 坐标轴指示器，坐标轴触发有效
                        type : 'shadow'        // 默认为直线，可选为：'line' | 'shadow'
                    }
                },
                // legend: {
                //     data:['直接访问', '邮件营销','联盟广告','视频广告','搜索引擎']
                // },
                toolbox: {
                    show : true,
                    feature : {
                        //mark : {show: true},
                        //dataView : {show: true, readOnly: false},
                        magicType : {show: true, type: ['stack', 'tiled']},
                        //magicType : {show: true, type: ['line', 'bar', 'stack', 'tiled']},
                        //restore : {show: true},
                        //saveAsImage : {show: true}
                    }
                },
                calculable : true,
                xAxis : [
                    {
                        type : 'value'
                    }
                ],
                yAxis : [
                    {
                        type : 'category',
                        data : ['Today']
                    }
                ],
                series : this.series_data
            };           

            window.myChart = echarts.init(document.getElementById('echart'));
            window.myChart.setOption(option);
        },
        addEvent: function () {
            let item = {
                name: this.subject,
                type:'bar',
                stack: '总量',
                itemStyle : { normal: {label : {show: true, position: 'insideRight'}}},
                data:[this.etime]
            };
            this.series_data.push(item);
            this.draw();
        }
    },
    created: function () {
    },
    mounted: function () {
        this.draw();
    }
})
setInterval(function () {
    if(this.app.series_data.length == 0){

    }else{
        console.log(this.app.series_data[0].data[0]);
        this.app.series_data[0].data[0] = this.app.series_data[0].data[0] - 1;
        this.app.draw();
        if(this.app.series_data[0].data[0] == 0)
        {
            this.app.series_data.splice(0, 1);
        }
        
    }
}, 1000);