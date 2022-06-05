<?php
if(isset($_POST['submit']))
{
    $con = mysqli_connect("localhost", "root", "", "test");

    if (!$con) {
      die("Connection failed: " . $con->connect_error);
    }
    else{
      $username=$_POST['name'];
      $adress=$_POST['adress'];
      $password=$_POST['password'];

      $sql = "INSERT INTO reg (name, email, password) VALUES ('$username', '$adress','".md5($password)."')";

      if (mysqli_query($con, $sql)) {
      echo "New record created successfully";
      } else {
      echo "Error: " . $sql . "<br>" . mysqli_error($con);
      }

    mysqli_close($con);
  }

}

?>
