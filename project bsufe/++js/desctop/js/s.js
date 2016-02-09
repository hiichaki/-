var data1;
var data2;
var data3;
    function f(filedata) {
        data1 = filedata;
    }
     function ff(filedata) {
        data2 = filedata;
    }
     function fff(filedata) {
        data3 = filedata;
    }

    
    function postloadfunction() {

    }

    function load_json(src) {
      var head = document.getElementsByTagName('head')[0];

      //use class, as we can't reference by id
      var element = head.getElementsByClassName("json")[0];

      try {
        element.parentNode.removeChild(element);
      } catch (e) {
        
      }

      var script = document.createElement('script');
      script.type = 'text/javascript';
      script.src = src;
      script.className = "json";
      script.async = false;
      head.appendChild(script);

      //call the postload function after a slight delay to allow the json to load
      window.setTimeout(postloadfunction, 100);
    }

    load_json("file1.js");
    load_json("file2.js");
    load_json("file3.js");


    function unixtimetodate(uni) {
      var theDate = new Date(uni);
      theDate.setHours(theDate.getHours()-2);
      // theDate.setMonth(theDate.getMonth()-1);
      dateString = theDate.toLocaleString();

      return dateString;
    }

    function maxData1 (filedata) {
      document.getElementById('mValue').innerHTML='';
      var m=data1[0];
      for(var i=1;i<data1.length;++i){
         if(data1[i][1]>m[1]) 
          m=data1[i];
      }
      document.getElementById('mValue').innerHTML='max t: <b>'+unixtimetodate(m[0])+' '+m[1]+'°</b> ';
    }

    function minData1 (filedata) {
      document.getElementById('mValue').innerHTML='';
      var m=data1[0];
      for(var i=1;i<data1.length;++i){
         if(data1[i][1]<m[1]) 
          m=data1[i];
      }
      document.getElementById('mValue').innerHTML='min t: <b>'+unixtimetodate(m[0])+' '+m[1]+'°</b> ';
    }

     function maxData2 (filedata) {
      document.getElementById('mValue').innerHTML='';
      var m=data2[0];
      for(var i=1;i<data2.length;++i){
         if(data2[i][1]>m[1]) 
          m=data2[i];
      }
      document.getElementById('mValue').innerHTML='max дж/м2: <b>'+unixtimetodate(m[0])+' '+m[1]+'°</b> ';
    }

    function minData2 (filedata) {
      document.getElementById('mValue').innerHTML='';
      var m=data2[0];
      for(var i=1;i<data2.length;++i){
         if(data2[i][1]<m[1]) 
          m=data2[i];
      }
      document.getElementById('mValue').innerHTML='min дж/м2: <b>'+unixtimetodate(m[0])+' '+m[1]+'°</b> ';
    }

     function maxData3 (filedata) {
      document.getElementById('mValue').innerHTML='';
      var m=data3[0];
      for(var i=1;i<data3.length;++i){
         if(data3[i][1]>m[1]) 
          m=data3[i];
      }
      document.getElementById('mValue').innerHTML='max E: <b>'+unixtimetodate(m[0])+' '+m[1]+'°</b> ';
    }

    function minData3 (filedata) {
      document.getElementById('mValue').innerHTML='';
      var m=data3[0];
      for(var i=1;i<data3.length;++i){
         if(data3[i][1]<m[1]) 
          m=data3[i];
      }
      document.getElementById('mValue').innerHTML='min E: <b>'+unixtimetodate(m[0])+' '+m[1]+'°</b> ';
    }

    // function foo(){
    //   for(i=0;i<data1.length;++i)
    //   console.log(data1[i][1]);
    // }

    $(function () {
      $('#datetimepicker8').datetimepicker(
        {language: 'ru',minuteStepping:10}
      );
       $('#datetimepicker9').datetimepicker(
        {language: 'ru',minuteStepping:10}
      );
    });

    $(function() {
        
        $("#datetimepicker8").datetimepicker();
        $("#datetimepicker9").datetimepicker();
        
        $("#datetimepicker8").on("dp.change", function(e) {
            $("#datetimepicker9").data("DateTimePicker").setMinDate(e.date);
        });

        $("#datetimepicker9").on("dp.change", function(e) {
            $("#datetimepicker8").data("DateTimePicker").setMaxDate(e.date);
        });
    });


    $("#sectionMaxData1").click(function () {
      document.getElementById('mValue').innerHTML='';
      var firstDate=$('#datetimepicker8').data("DateTimePicker").getDate()._d.toLocaleString();
      var secondDate=$('#datetimepicker9').data("DateTimePicker").getDate()._d.toLocaleString();
      var m;  
      var q=true;
        for(i=0;i<data1.length;++i){
          if(unixtimetodate(data1[i][0])>=firstDate){
             if(q){
              m=data1[i];
              q=false;
             }
             if(data1[i][1]>m[1]) 
                m=data1[i];
          }
          if(unixtimetodate(data1[i][0])>=secondDate){
            break;
          }
        }    
      document.getElementById('mValue').innerHTML='max t на промежутке </br>'+firstDate+' - '+secondDate+ ' : <b>'+unixtimetodate(m[0])+' '+m[1]+'°</b></br>';
    });

    $("#sectionMinData1").click(function () {
      document.getElementById('mValue').innerHTML='';
      var firstDate=$('#datetimepicker8').data("DateTimePicker").getDate()._d.toLocaleString();
      var secondDate=$('#datetimepicker9').data("DateTimePicker").getDate()._d.toLocaleString();
      var m;  
      var q=true;
        for(i=0;i<data1.length;++i){
          if(unixtimetodate(data1[i][0])>=firstDate){
             if(q){
              m=data1[i];
              q=false;
             }
             if(data1[i][1]<m[1]) 
                m=data1[i];
          }
          if(unixtimetodate(data1[i][0])>=secondDate){
            break;
          }
        }
      document.getElementById('mValue').innerHTML='min t на промежутке </br>'+firstDate+' - '+secondDate+' : '+'<b>'+unixtimetodate(m[0])+' '+m[1]+'°</b></br>';
    });


    $("#sectionMaxData2").click(function () {
      document.getElementById('mValue').innerHTML='';
      var firstDate=$('#datetimepicker8').data("DateTimePicker").getDate()._d.toLocaleString();
      var secondDate=$('#datetimepicker9').data("DateTimePicker").getDate()._d.toLocaleString();
      var m;  
      var q=true;
        for(i=0;i<data2.length;++i){
          if(unixtimetodate(data2[i][0])>=firstDate){
             if(q){
              m=data2[i];
              q=false;
             }
             if(data2[i][1]>m[1]) 
                m=data2[i];
          }
          if(unixtimetodate(data2[i][0])>=secondDate){
            break;
          }
        }    
      document.getElementById('mValue').innerHTML='max дж/м2 на промежутке </br>'+firstDate+' - '+secondDate+ ' : <b>'+unixtimetodate(m[0])+' '+m[1]+'°</b></br>';
    });

    $("#sectionMinData2").click(function () {
      document.getElementById('mValue').innerHTML='';
      var firstDate=$('#datetimepicker8').data("DateTimePicker").getDate()._d.toLocaleString();
      var secondDate=$('#datetimepicker9').data("DateTimePicker").getDate()._d.toLocaleString();
      var m;  
      var q=true;
        for(i=0;i<data2.length;++i){
          if(unixtimetodate(data2[i][0])>=firstDate){
             if(q){
              m=data2[i];
              q=false;
             }
             if(data2[i][1]<m[1]) 
                m=data2[i];
          }
          if(unixtimetodate(data2[i][0])>=secondDate){
            break;
          }
        }
      document.getElementById('mValue').innerHTML='min дж/м2 на промежутке </br>'+firstDate+' - '+secondDate+' : '+'<b>'+unixtimetodate(m[0])+' '+m[1]+'°</b></br>';
    });


    $("#sectionMaxData3").click(function () {
      document.getElementById('mValue').innerHTML='';
      var firstDate=$('#datetimepicker8').data("DateTimePicker").getDate()._d.toLocaleString();
      var secondDate=$('#datetimepicker9').data("DateTimePicker").getDate()._d.toLocaleString();
      var m;  
      var q=true;
        for(i=0;i<data3.length;++i){
          if(unixtimetodate(data3[i][0])>=firstDate){
             if(q){
              m=data3[i];
              q=false;
             }
             if(data3[i][1]>m[1]) 
                m=data3[i];
          }
          if(unixtimetodate(data3[i][0])>=secondDate){
            break;
          }
        }    
      document.getElementById('mValue').innerHTML='max E на промежутке </br>'+firstDate+' - '+secondDate+ ' : <b>'+unixtimetodate(m[0])+' '+m[1]+'°</b></br>';
    });

    $("#sectionMinData3").click(function () {
      document.getElementById('mValue').innerHTML='';
      var firstDate=$('#datetimepicker8').data("DateTimePicker").getDate()._d.toLocaleString();
      var secondDate=$('#datetimepicker9').data("DateTimePicker").getDate()._d.toLocaleString();
      var m;  
      var q=true;
        for(i=0;i<data3.length;++i){
          if(unixtimetodate(data3[i][0])>=firstDate){
             if(q){
              m=data3[i];
              q=false;
             }
             if(data3[i][1]<m[1]) 
                m=data3[i];
          }
          if(unixtimetodate(data3[i][0])>=secondDate){
            break;
          }
        }
      document.getElementById('mValue').innerHTML='min E на промежутке </br>'+firstDate+' - '+secondDate+' : '+'<b>'+unixtimetodate(m[0])+' '+m[1]+'°</b></br>';
    });

      $("#clear").click(function () {
      $('#datetimepicker8').data("DateTimePicker").setValue('');
      $('#datetimepicker9').data("DateTimePicker").setValue('');
      $("#datetimepicker9").data("DateTimePicker").setMinDate(new Date("01.01.2015"));
      $("#datetimepicker8").data("DateTimePicker").setMaxDate(new Date("01.01.3015"));
      document.getElementById('mValue').innerHTML='';
        
      
    });

// var q=false;
// var x = document.getElementById('frame1');
// $(document).on('click','.push-to-stop',function(){
//   q=false;
//   $('.push-to-start').show();
//   $('.push-to-stop').hide();
// });
// $(document).on('click','.push-to-start',function(){
//   q=true;
//   setInterval(function() {
//     if(q){
//      x.src=x.src;
//     }
//   }, 10000);  
//   $('.push-to-start').hide();
//   $('.push-to-stop').show();
// });


// var w=false;
// var y = document.getElementById('frame2');
// $(document).on('click','.push-to-stop2',function(){
//   w=false;
//   $('.push-to-start2').show();
//   $('.push-to-stop2').hide();
// });
// $(document).on('click','.push-to-start2',function(){
//   w=true;
//   setInterval(function() {
//     if(w){
//      y.src=y.src;
//     }
//   }, 10000);  
//   $('.push-to-start2').hide();
//   $('.push-to-stop2').show();
// });

// function doIt(bId){
//     var fireOnThis = document.getElementById(bId);
//     var evObj = document.createEvent('MouseEvents');
//     evObj.initEvent( 'click', true, true );
//     if((q&&bId=='b1')||(w&&bId=='b2')){
//       fireOnThis.dispatchEvent(evObj);
//     }
// }   

