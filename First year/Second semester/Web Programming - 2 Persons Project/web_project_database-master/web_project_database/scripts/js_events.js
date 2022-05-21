var topButton=document.getElementById("goToTopButton");
window.onscroll=function() {scroll()};

function scroll(){
  if(document.body.scrollTop>40 || document.documentElement.scrollTop>40)
    topButton.style.display="block";
  else
    topButton.style.display="none";
}

function goToTop(){
  document.body.scrollTop=0;
  document.documentElement.scrollTop=0;
}
