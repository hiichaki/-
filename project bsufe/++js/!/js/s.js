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