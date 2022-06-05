<?php

  if(isset($_POST['submit']))
  {
    function test_nume($nume)
    {
        if (!preg_match ("/^[a-zA-z\s]+$/", $nume)) {
          echo "Nume invalid";
          die();
      }
    }

    function test_specializare($specializare)
    {
        if (!preg_match ("/^[A-z]+$/", $specializare)) {
          echo "Nume specializare invalid";
          die();
      }
    }


        function test_an($an)
        {
            if(((int)$an < 1 && (int)$an > 3)){
              echo "An invalid";
              die();
            }
        }

        function test_nota($nota)
        {
          if($nota == NULL) $nota = 5;
            else if(((int)$nota < 1 && (int)$nota > 10)){
              echo "Nota invalid";
              die();
            }
        }

      $nume = $_POST['nume'];
      test_nume($nume);
      $specializare = $_POST['specializare'];
      test_specializare($specializare);
      $an = $_POST['an'];
      test_an($an);
      $nota1 = $_POST['nota1'];
      $nota2 = $_POST['nota2'];
      test_nota($nota1);
      test_nota($nota2);

      $f = fopen("stud.txt", 'a');

      $line = $nume. ",".$specializare.",".$an.",".$nota1.",".$nota2.PHP_EOL;

      fwrite($f, $line);
      fclose($f);

  }

 ?>
