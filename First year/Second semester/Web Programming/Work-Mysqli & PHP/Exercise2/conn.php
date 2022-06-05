<?php


if(isset($_POST['submit'])){
$con = mysqli_connect("localhost", "root", "", "ex3");


function test_nume($nume)
{
  if (preg_match ("/^[a-zA-z\s]+$/", $nume) == 0) {
    echo "Nume invalid";
    die();
  }
}


function test_sex($sex)
{
  if(strlen($sex) >= 2){
    echo "Sex invalid";
    die();
  }
  else if($sex[0] != "M" && $sex[0] != "F"){
    echo "Sex Invalid";
    die();
  }
}

function test_email($email)
{
  if(!filter_var($email, FILTER_VALIDATE_EMAIL)){
    echo "Email invalid";
    die();
  }
}


function test_cod($cod)
{
  if((int)$cod < 1 && (int)$cod > 100){
    echo "Cod invalid";
    die();
  }
}

$nume = $_POST['nume'];
test_nume($nume);

$sex = $_POST['sex'];
test_sex($sex);

$email = $_POST['email'];
test_email($email);

$sectie = $_POST['sectie'];

$cod = $_POST['cod'];
test_cod($cod);

$sql = "INSERT INTO `pacienti` (`nume`, `sex`, `mail`, `sectie`, `cod`) VALUES ('$nume', '$sex', '$email', '$sectie', '$cod')";

if (mysqli_query($con, $sql)) {
echo "New record created successfully";
} else {
echo "Error: " . $sql . "<br>" . mysqli_error($con);
}

mysqli_close($con);





}


 ?>
