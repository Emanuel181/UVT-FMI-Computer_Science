<?php
$con = mysqli_connect("localhost", "root", "", "ex3");


$sql = "SELECT * from pacienti WHERE sex='M' ";

$result = $con->query($sql);

echo $result->num_rows;

$con->close();
 ?>
