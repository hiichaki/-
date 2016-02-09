$(function () {
    $('#container').highcharts({
        chart: {
            zoomType: 'xy'
        },
        title:{
            text: 'График',
            x: -20 //center
        },
        subtitle: {
            text: 'текст',
            x: -20
        },
        xAxis: {
            type: 'datetime'
        },
        yAxis: {
            title: {
                text: 'Temperature (°C)'
            },
            plotLines: [{
                value: 0,
                width: 1,
                color: '#808080'
            }]
        },
        tooltip: {
            // valueSuffix: '°C',
            shared: true,
            crosshairs: true
        },
        legend: {
            layout: 'vertical',
            align: 'right',
            verticalAlign: 'middle',
            borderWidth: 0
        },
        series: [{
            name: 't',
            data: data1
        }, {
            name: 'дж/м2',
            data: data2
        }, {
            name: 'Е',
            data: data3
        }]
    });
});