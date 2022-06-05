<?php

if(isset($_POST['submit']))
{

  $con = mysqli_connect("localhost", "root", "", "studenti");

  if(!$con) {
    die("Eroare");
  }

  else {

      $f = fopen("stud.txt", "r") or die("EROARE");

      while(!feof($f)) {

      $line = fgets($f);
      $nume = strtok($line, ",");
      $specializare = strtok(",");
      $an = strtok(",");
      $nota1 = strtok(",");
      $nota2 = strtok(",");
      echo $nume." ".$specializare." ".$an." ".$nota1." ".$nota2."<br/>";

      $sql = "INSERT INTO `elevi` (`nume`, `specializare`, `an`, `nota1`, `nota2`) VALUES ('$nume', '$specializare', '$an', '$nota1', '$nota2')";

      $result = mysqli_query($con, $sql);

}
    }
      fclose($f);
      mysqli_close($con);

  }



 ?>
