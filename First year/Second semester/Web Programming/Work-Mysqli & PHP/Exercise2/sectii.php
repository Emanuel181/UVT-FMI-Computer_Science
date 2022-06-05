<?php

$con = mysqli_connect("localhost", "root", "", "db_name");


$sql = "SELECT nume, sex, mail, sectie, cod from table_name WHERE sectie='ATI' ";

$result = $con->query($sql);

while($row = $result->fetch_assoc()) {
    echo $row["nume"]. " " . $row["sex"]. " ". $row["mail"]. " ". $row["sectie"]. " ". $row["cod"]. "<br>";
  }

$con->close();

 ?>
