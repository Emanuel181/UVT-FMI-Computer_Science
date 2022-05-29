<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"/>
    <title>Registration</title>
    <link rel="stylesheet" href="styles\style_registration.css"/>
</head>

<body>
    <div class="divStyle">
      <?php
      include "php_connection.php";

      if (isset($_REQUEST['username'])) {
        $select = mysqli_query($con, "SELECT * FROM `accounts` WHERE username = '".$_POST['username']."'");
        if(mysqli_num_rows($select)) {
          echo '<script type="text/javascript">';
          echo 'alert("The username introduced already exists");';
          echo 'window.location.href = "php_registration.php";';
          echo '</script>';
        }
        else{
          $username=stripslashes($_REQUEST['username']);
          $username=mysqli_real_escape_string($con, $username);
          $email=stripslashes($_REQUEST['email']);
          $email=mysqli_real_escape_string($con, $email);
          if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            echo '<script type="text/javascript">';
            echo 'alert("Email format is incorrect");';
            echo 'window.location.href = "php_registration.php";';
            echo '</script>';
          }
          else{
          $password=stripslashes($_REQUEST['password']);
          $password=mysqli_real_escape_string($con, $password);

          $query="INSERT into `accounts` (username, password, email) VALUES ('$username', '" . md5($password) . "', '$email')";
          $result=mysqli_query($con, $query);
          if ($result) {
            $file="textFiles\database.txt";
            $handle = fopen($file, "a");
            fwrite($handle, $username.",".md5($password)."".PHP_EOL);
            echo '<br>';
            fclose($handle);

              echo "<div>
                    <h3>You are registered successfully.</h3><br/>
                    <p><a href='php_login.php' style='text-decoration:none; color:black'>Click here to login</a></p>
                    <p><a href='index.html' style='text-decoration:none; color:black'>Click here to go to homepage</a></p>
                    </div>";
          } else {
              echo "<div>
                    <h3>The required fields are missing.</h3><br/>
                    <p><a href='php_registration.php' style='text-decoration:none;color:black'>Click here to registrate</a> again.</p>
                    <p><a href='index.html' style='text-decoration:none; color:black'>Click here to go to homepage</a></p>
                    </div>";
          }
        }
      }
      }
      else
      {
      ?>
      <table>
        <form action="" method="post">
            <h1>Registration</h1>
            <tr>
              <td>
                <input type="text"name="username" placeholder="Username" required />
              </td>
            </tr>
            <tr>
              <td>
                <input type="text" name="email" placeholder="Email" required />
              </td>
            </tr>
            <tr>
              <td>
                <input type="password" name="password" placeholder="Password" required />
              </td>
            </tr>
            <tr>
              <td>
                <input type="submit" name="submit" value="Register">
              </td>
            </tr>
        </form>
      </table>

      <p>Already having an account?</p>
      <a href="php_login.php" class="login">Click to login</a>

      <?php
        }
      ?>
    </div>

</body>
</html>
