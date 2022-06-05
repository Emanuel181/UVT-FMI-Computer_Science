<?php

$con = mysqli_connect("localhost", "root", "", "ex3");


$sql = "SELECT * FROM pacienti";

$result = $con->query($sql);

while($row = $result->fetch_assoc())
{
  echo $row['nume']." ".$row['sex']." ".$row['mail']." ".$row['sectie']." ".$row['cod']."<br>";
}

$con->close();


 ?>
