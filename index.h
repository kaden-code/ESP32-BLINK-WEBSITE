const char *HTML_CONTENT = R"=====(<!DOCTYPE html>
<html lang="en">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
    <meta name="viewport" content="width=device-width, initial-scale=0.7">
    <title>esp 32 led</title>
</head>
<body>
    <div class="blinkContainer">
        <h2>LED</h2>
        <div class = "ledState"></div>
        <button id="ledButton">ON</button>
    </div>
</body>
<style>

*{
    margin: 0;
    padding: 0;
    
}

body{
    display: flex;
  justify-content: center;
  background-color: beige;
}
    
.blinkContainer {
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  margin: 5%;
  border: 2px solid #007bff;
  align-self: center;
  width: 50%;
  height: 250px;
  border-radius: 25px;
  background-color: white;
}

.blinkContainer h2 {
  margin-bottom: 20px; /* Adjust as needed */
  color:#007bff;
  

}

.blinkContainer button {
  align-self: center;
  padding: 8px 30px;
  border: none;
  background-color: #007bff;
  color: white;
  border-radius: 5px;

}


.ledState{
  width: 45px;
  height: 45px;
  background-color: red;
  border-radius: 50%;
  margin-bottom: 20px ;
}


  
</style>
<script>

let ledState = false;
const ledStateDispaly = document.querySelector(".ledState");
const ledButton = document.querySelector("#ledButton");
const webSocket = new WebSocket("ws://" + window.location.host + ":81");

function changeState(){
    ledState = !ledState;
    if(ledState == false){
        ledStateDispaly.style = "background-color:red;";
        ledButton.innerText = "on";
    }
    if(ledState == true){
        ledStateDispaly.style = "background-color:blue;";
        ledButton.innerText = "off";

    }
}

ledButton.addEventListener("click",function(){
    changeState();
    webSocket.send(ledState);
})
</script>
</html>)=====";