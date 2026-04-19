var cnavas = document.getElementById("mycanvas").getContext("2d");
cnavas.fillRect(0,0,175,75);

cnavas.beginPath();
cnavas.arc(95,50,40,0,2*Math.PI);
cnavas.stroke();
