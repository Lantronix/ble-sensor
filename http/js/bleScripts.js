
  var getSensors = function() {
    $.ajax({
      type: 'GET',
      url: 'bleScan/getScanResults',
      dataType: 'json',
      success: function(response) {
        $("#sensorDisplay").empty();
        $.each(response, function(idx, value) {
          var d = $("#templateDisplay").clone();
          d.prop('id', value.address)
              .appendTo("#sensorDisplay");
          d.find(".bleName").append(value.name);
          d.find(".bleRssi").append(value.rssi);
          d.find(".hrDisplay").text(value.heartrate);
          d.data("appearance",value.appearance);
          d.show();
        });
        toggleFilter(false);
      }
    })
  }

  var toggleFilter = (function() {
      var filtered = false;

      return function(toggle) {
        if (typeof(toggle) === 'undefined') toggle = true;
        filtered = (toggle ? filtered : !filtered);

        if (filtered == false) {
          $(".deviceBlock").each(function() {
            var appearance = $(this).data("appearance");
            if (appearance != 832 && appearance != 833) {
              $(this).hide();
            }
          });
          $("#filterSensors").attr("value","Show all sensors")
              .removeClass("btn-primary")
              .addClass("btn-secondary");
          filtered = true;
        } else {
          $("#sensorDisplay").find(".deviceBlock").show();
          $("#filterSensors").attr("value","Show only heart rate sensors")
                .removeClass("btn-secondary")
                .addClass("btn-primary");
           filtered = false;
        }
      };
  })();


$(function() {
  $("#filterSensors").on('click', function() {toggleFilter();});
  window.setInterval(getSensors,1000);
});
