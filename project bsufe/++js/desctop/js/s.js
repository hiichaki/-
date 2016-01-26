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
      dateString = theDate.toLocaleString();

      console.log(dateString);
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

     $(function () {
        $('#datetimepicker6').datetimepicker();
        $('#datetimepicker7').datetimepicker({
            useCurrent: false //Important! See issue #1075
        });
        $("#datetimepicker6").on("dp.change", function (e) {
            $('#datetimepicker7').data("DateTimePicker").minDate(e.date);
        });
        $("#datetimepicker7").on("dp.change", function (e) {
            $('#datetimepicker6').data("DateTimePicker").maxDate(e.date);
        });
    });

    


// var q=1;
// function sr(){
//   var timerId; 
//   if(q){
//     timerId = setInterval(function() { location.reload(); }, 2000);
//     alert('123');
//     q=0;
//   }else{
//     clearInterval(timerId);
//     alert('azaza');
//     q=1;
//   }
// }

// $('body').append(
//        $('<button>').text('Start').addClass('push-to-start'));
// $('body').append(
//        $('<button>').text('Stop').addClass('push-to-stop'));
// $('.push-to-start').hide();
// $(document).on('click','push-to-stop',function(){
//   $('me').remove();
//   $('.push-to-start').show();
//   $('.push-to-stop').hide();
// });
// $(document).on('click','push-to-start',function(){
//   $('body').append(
//       $('<meta>').attr('http-equiv','refresh').attr('content','2').attr('id','me'));
//   $('.push-to-start').hide();
//   $('.push-to-stop').show();
// });