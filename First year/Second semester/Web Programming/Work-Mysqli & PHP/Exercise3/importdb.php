<?php

if(isset($_POST['submit']))
{
  $con = mysqli_connect("localhost", "root", "", "test");

  if(!$con){
    die("Fail!". con->connect_error);
  } else{
    $sql = "SELECT id, name, email from reg";
    $result = $con->query($sql);

    while($row = $result-> fetch_assoc()){
      echo "<tr><td><br>". $row["id"]. "<tr><td><br>". $row["name"]. "<tr><td><br>".$row["email"]."</td></tr>";

    }

    echo "</table>";
  }
}


?>
