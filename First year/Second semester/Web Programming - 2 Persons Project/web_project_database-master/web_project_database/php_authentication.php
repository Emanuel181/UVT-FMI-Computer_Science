
    <?php
      include "php_connection.php";
      session_start();

      if (isset($_POST['username']))
      {
          $username=stripslashes($_REQUEST['username']);
          $username=mysqli_real_escape_string($con, $username);
          $password=stripslashes($_REQUEST['password']);
          $password=mysqli_real_escape_string($con, $password);

          $query="SELECT * FROM `accounts` WHERE username='$username' AND password='" . md5($password) . "'";
          $result = mysqli_query($con, $query) or die(mysql_error());
          $rows = mysqli_num_rows($result);
          if ($rows == 1)
          {
              $_SESSION['username'] = $username;
              header("Location: homepage.php");
          }
          else
          {
              echo "<div>
                    <h5>Incorrect username or password.</h5><br/>
                    <p><a href='php_login.html' style='text-decoration:none;color:black'>Click here to login again.</a></p>
                    </div>";
          }
      }
      else
      {
      ?>
        <table>
          <form method="post" name="login">
            <h1>Log in</h1>
            <tr>
              <td>
                <input type="text" name="username" placeholder="Username" autofocus="true"/>
              </td>
            </tr>
            <tr>
              <td>
                <input type="password" name="password" placeholder="Password"/>
              </td>
            </tr>
            <tr>
              <td>
                <input type="submit" value="Login" name="submit"/>
              </td>
            </tr>
          </form>
        </table>
        <p>Don't you have an account?</p>
        <a href="php_registration.php">Create one</a>
      <?php
          }
      ?>
