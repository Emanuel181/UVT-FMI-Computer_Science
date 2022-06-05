<?php
if(isset($_POST["export"]))
{
     $connect = mysqli_connect("localhost", "root", "", "ex2");
     header('Content-Type: text/csv; charset=utf-8');
     header('Content-Disposition: attachment; filename=data.csv');
     $output = fopen('php://output', 'w' , "w");
     fputcsv($output, array('ID', 'Nume', 'Specializare', 'An', 'Nota1', 'Nota2'));
     $query = "SELECT * from elevi ORDER BY id DESC";
     $result = mysqli_query($connect, $query);
     while($row = mysqli_fetch_assoc($result))
     {
          fputcsv($output, $row);
     }
     fclose($output);
}
?>
