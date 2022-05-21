var coll = document.getElementsByClassName("collapsible");
var i;

for (i = 0; i < coll.length; i++) {
  coll[i].addEventListener("click", function() {
    this.classList.toggle("active");
    var content = this.nextElementSibling;
    if (content.style.display === "block") {
      content.style.display = "none";
    } else {
      content.style.display = "block";
    }
  });
}

var topButton=document.getElementById("goToTopButton");
window.onscroll=function() {scroll()};

function scroll(){
  if(document.body.scrollTop>20 || document.documentElement.scrollTop>20)
    topButton.style.display="block";
  else
    topButton.style.display="none";
}

function goToTop(){
  document.body.scrollTop=0;
  document.documentElement.scrollTop=0;
}
