<?php
if(isset($_POST["submit"]))
{
     $connect = mysqli_connect("localhost", "root", "", "test");
     header('Content-Type: text/csv; charset=utf-8');
     header('Content-Disposition: attachment; filename=data.csv');
     $output = fopen('php://output', 'w' , "w");
     fputcsv($output, array('ID', 'Name', 'Address', 'Password'));
     $query = "SELECT * from reg ORDER BY id DESC";
     $result = mysqli_query($connect, $query);
     while($row = mysqli_fetch_assoc($result))
     {
          fputcsv($output, $row);
     }
     fclose($output);
}
?>
