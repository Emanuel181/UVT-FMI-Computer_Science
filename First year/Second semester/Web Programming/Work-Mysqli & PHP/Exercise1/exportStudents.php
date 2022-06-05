<?php

if(isset($_POST['submit'])){
$con = mysqli_connect("localhost", "root", "", "ex2");

$sql = "SELECT nume, specializare, an, nota1, nota2, media, promo FROM elevi WHERE media >= 8";

$result = $con->query($sql);

while($row = $result->fetch_assoc()) {
    echo $row["nume"]. " " . $row["specializare"]. " ". $row["an"]. " ". $row["nota1"]. " ". $row["nota2"]. " ". $row["media"]. " "."<br>";
  }
$con->close();
}
 ?>
