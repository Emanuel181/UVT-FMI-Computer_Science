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
