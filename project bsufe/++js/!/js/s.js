var data;
    function f(filedata) {
        data = filedata;
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
    load_json("file.js");


    function unixtimetodate(uni) {
      var theDate = new Date(uni);
      theDate.setHours(theDate.getHours()-2);
      // theDate.setMonth(theDate.getMonth()-1);
      dateString = theDate.toLocaleString();

      // console.log(dateString);
      return dateString;
    }

    function max (filedata) {
      var m=data[0];
      for(var i=1;i<data.length;++i){
         if(data[i][1]>m[1]) 
          m=data[i];
      }
      document.getElementById('mValue').innerHTML='максимальная температура:'+'<b>'+m[1]+'</b></br>'+unixtimetodate(m[0]);
    }

    function min (filedata) {
      var m=data[0];
      for(var i=1;i<data.length;++i){
         if(data[i][1]<m[1]) 
          m=data[i];
      }
      document.getElementById('mValue').innerHTML='минимальная температура:'+'<b>'+m[1]+'</b></br>'+unixtimetodate(m[0]);
    }


//TODO:
     function asd(){
      console.log(document.getElementById(date1.value));
     }



    function compare(){

    }

    $(function () {
      $('#datetimepicker8').datetimepicker(
        {language: 'ru',minuteStepping:10}
      );
       $('#datetimepicker9').datetimepicker(
        {language: 'ru',minuteStepping:10}
      );
    });

    $(function() {
        //Инициализация datetimepicker8 и datetimepicker9
        $("#datetimepicker8").datetimepicker();
        $("#datetimepicker9").datetimepicker();
        //При изменении даты в 8 datetimepicker, она устанавливается как минимальная для 9 datetimepicker
        $("#datetimepicker8").on("dp.change", function(e) {
            $("#datetimepicker9").data("DateTimePicker").setMinDate(e.date);
        });
        //При изменении даты в 9 datetimepicker, она устанавливается как максимальная для 8 datetimepicker
        $("#datetimepicker9").on("dp.change", function(e) {
            $("#datetimepicker8").data("DateTimePicker").setMaxDate(e.date);
        });
    });

    $("#sectionMax").click(function () {
      var firstDate=$('#datetimepicker8').data("DateTimePicker").getDate()._d.toLocaleString();
      var secondDate=$('#datetimepicker9').data("DateTimePicker").getDate()._d.toLocaleString();
      var m;  
      var q=true;
        for(i=0;i<data.length;++i){
          if(unixtimetodate(data[i][0])>=firstDate){
             if(q){
              m=data[i];
              q=false;
             }
             if(data[i][1]>m[1]) 
                m=data[i];
          }
          if(unixtimetodate(data[i][0])>=secondDate){
            break;
          }
        }
        
      document.getElementById('mValue').innerHTML='максимальная температура на промежутке </br>'+firstDate+' - '+secondDate
      +' : '+'<b>'+m[1]+'</b></br>';
    });

    $("#sectionMin").click(function () {
      var firstDate=$('#datetimepicker8').data("DateTimePicker").getDate()._d.toLocaleString();
      var secondDate=$('#datetimepicker9').data("DateTimePicker").getDate()._d.toLocaleString();
      var m;  
      var q=true;
        for(i=0;i<data.length;++i){
          if(unixtimetodate(data[i][0])>=firstDate){
             if(q){
              m=data[i];
              q=false;
             }
             if(data[i][1]<m[1]) 
                m=data[i];
          }
          if(unixtimetodate(data[i][0])>=secondDate){
            break;
          }
        }
        
      document.getElementById('mValue').innerHTML='минимальная температура на промежутке </br>'+firstDate+' - '+secondDate
      +' : '+'<b>'+m[1]+'</b></br>';
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

