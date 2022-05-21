<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"/>
    <title>Login</title>
    <link rel="stylesheet" href="styles\style_login.css"/>
</head>

<body>
  <div class="divStyle">
    <?php
      include "php_connection.php";
      session_start();

      if (isset($_POST['username'])) {
          $username=stripslashes($_REQUEST['username']);
          $username=mysqli_real_escape_string($con, $username);
          $password=stripslashes($_REQUEST['password']);
          $password=mysqli_real_escape_string($con, $password);
          $query= "SELECT * FROM `accounts` WHERE username='$username' AND password='" . md5($password) . "'";
          $result=mysqli_query($con, $query) or die(mysql_error());
          $rows=mysqli_num_rows($result);
          if ($rows == 1)
          {
              $_SESSION['username'] = $username;
              header("Location: homepage.php");
          }
          else
          {
              echo "<div>
                    <h3>Incorrect username or password.</h3><br/>
                    <p><a href='php_login.php' style='text-decoration:none;color:black'>Click here to try to login again</a></p>
                    </div>";
          }
      }
      else
      {
      ?>
      <table>
        <form method="post" name="login">
          <h1>Login</h1>
          <tr>
            <td>
              <input type="text" name="username" placeholder="Username" autofocus="true" required/>
            </td>
          </tr>
          <tr>
            <td>
              <input type="password" name="password" placeholder="Password" required/>
            </td>
          </tr>
          <tr>
            <td>
              <input type="submit" value="Log in" name="submit"/>
            </td>
          </tr>
        </form>
      </table>
      <p>Create an account</p>
      <a href="php_registration.php" class="createAccount">Click here</a>
    <?php
        }
    ?>
  </div>

</body>
</html>
