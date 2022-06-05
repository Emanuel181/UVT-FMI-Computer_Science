<?php

if (isset($_POST["submit"])) {
  $con = mysqli_connect("localhost", "root", "", "ex2");

  if(!$con)
  {
    die("Fail!".con->connection_error);
  } else{

    function test_input($data) {
      $data = trim($data);
      $data = stripslashes($data);
      $data = htmlspecialchars($data);
      return $data;
    }

    function test_nume($nume)
    {
      if (!preg_match ("/^[a-zA-z]*$/", $nume) ) {
          echo "Only alphabets and whitespace are allowed pentru specializare";
    }
  }

    function test_specializare($specializare)
    {
      if(!preg_match("/^[a-zA-z]*$/", $specializare)){
        echo "Only alphabets and whitespace are allowed pentru specializare";
      }
    }

    function test_an($an)
    {
      if(strlen($an) > 1){
        echo "Trebuie introdusa o singura cifra!";
      }
      else if(!preg_match("/^[0-9]*$/", $an)){
        echo "Numai cifre la an!";
      }
    }

    function test_nota($nota)
    {
      if(!is_numeric($nota)){
        echo "Notele trebuie sa fie numere !";
      }
    }

    $nume=test_input($_POST["nume"]);
    test_nume($nume);
    $specializare=test_input($_POST["specializare"]);
    test_specializare($specializare);
    $an=test_input($_POST["an"]);
    test_an($an);
    $nota1=test_input($_POST["nota1"]);
    $nota2=test_input($_POST["nota2"]);
    test_nota($nota1);
    test_nota($nota2);


    $medie = ($nota1 + $nota2) / 2;



    if($medie >= 5){
    $promovat = "promovat";
    $sql = "INSERT INTO `elevi` (`nume`, `specializare`, `an`, `nota1`, `nota2`, `media`, `promo`) VALUES ('$nume', '$specializare', '$an', '$nota1', '$nota2', '$medie', '$promovat')";

      if (mysqli_query($con, $sql)) {
      echo "New record created successfully";
      } else {
      echo "Error: " . $sql . "<br>" . mysqli_error($con);
      }

    mysqli_close($con);
  }else {
    $promovat = "nepromovat";
    $sql = "INSERT INTO `elevi` (`nume`, `specializare`, `an`, `nota1`, `nota2`, `media`, `promo`) VALUES ('$nume', '$specializare', '$an', '$nota1', '$nota2', '$medie', '$promovat')";

      if (mysqli_query($con, $sql)) {
      echo "New record created successfully";
      } else {
      echo "Error: " . $sql . "<br>" . mysqli_error($con);
      }

    mysqli_close($con);
  }

 }
}

 ?>
