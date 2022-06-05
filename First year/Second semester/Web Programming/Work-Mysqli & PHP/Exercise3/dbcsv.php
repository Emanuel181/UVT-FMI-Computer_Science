<?php

if(isset($_POST["import"]))
{
  $con = mysqli_connect("localhost", "root", "", "test");

  if (!$con) {
    die("Connection failed: " . $con->connect_error);
  }
  else{
      $filename = $_FILES["file"]["tmp_name"];

      $file = fopen($filename, "r");

      while(($column = fgetcsv($file, 1000, ","))!== FALSE ){
        $sql = "INSERT INTO reg (name, email, password) VALUES ('$column[0]', '$column[1]', '$column[2]')";
      }

      if (mysqli_query($con, $sql)) {
      echo "New record created successfully";
      } else {
      echo "Error: " . $sql . "<br>" . mysqli_error($con);
      }

    mysqli_close($con);
  }
}
?>
