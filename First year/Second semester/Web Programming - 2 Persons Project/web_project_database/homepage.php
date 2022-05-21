<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Homepage</title>
    <link rel="stylesheet" href="styles\style_homepage.css" />
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Lato&display=swap" rel="stylesheet">
</head>

<body>

  <div class="parallax">
    <a href="php_logout.php" class="logoutOption">Logout</a>
  </div>

  <div class="text">
    <p class="research-title">Research Center in Computer Science</p>
    <br>

    <div class="divMenu">
      <ul class="listMenu">
        <li class="listItem"><a href="staff.html">Staff</a></li>
        <li class="listItem"><a href="#">Projects</a>
          <div class="subMenu">
            <ul class="listSubMenu">
              <li class="listItem"><a href="currentProjects.html">Current Projects</a></li>
              <li class="listItem"><a href="formerProjects.html">Former Projects</a></li>
            </ul>
          </div>
        </li>
        <li class="listItem"><a href="publications.html">Publications</a></li>
        <li class="listItem"><a href="scientificSeminar.html">Scientific Seminar</a></li>
        <li class="listItem"><a href="events.html">Events</a></li>
        <li class="listItem"><a href="facilities.html">Facilities</a></li>
      </ul>
    </div>

    <br>

    <div class="btn-grad">Cloud Computing, High Performance Computing, and Internet of Things</div>
    <ul class="cloud-computing centrare">

      <li>Exascale Data Processing</li>
      <li>Monitoring data-intensive applications</li>
      <li>Portability in Clouds and open source Platform as a Service</li>
      <li>Cloud resources management and self-organization in heterogeneous cloud</li>
      <li>Data-intensive applications</li>
      <li>Ontologies for Cloud services</li>
      <li>Cloud governance</li>
      <li>HPC service exposure in the Cloud</li>
      <li>Empirical software engineering for cloud-based applications</li>
    </ul>

    <br>
    <br>


    <div class="btn-grad">Big Data Applications and Data Analysis</div>
    <div class="contentBDA">
    <ul class="cloud-computing">
      <li>
        Accelerating applications on clouds and HPC<ul >
          <li>Graph processing</li>
          <li>Astronomy image processing and object detection</li>
          <li>Satellite-based image processing</li>
          <li>Smart grids</li>
        </ul>
      </li>
      <li>
        Hybrid processing on clouds, IoT, and HPC<ul type='circle'>
          <li>
            Mixing GPUCPU, edge devices, and clouds for optimizing execution of large scale distributed applications
          </li>
        </ul>
      </li>
      <li>
        Scheduling algorithms for distributed systems<ul type='circle'>
          <li>
            Optimal and suboptimal heuristics with energy, cost and execution constraints
          </li>
        </ul>
      </li>
    </ul>
    </div>

    <br>
    <br>


    <div class="btn-grad">Theory of Computing</div>
    <ul class="cloud-computing centrare">
      <li>
        Theory of Computing
      </li>
      <li>
        Symbolic computation
      </li>
      <li>
        Unification and matching
      </li>
      <li>
        Constraint logic programming
      </li>
      <li>
        Proof-based algorithm synthesis
      </li>
    </ul>

    <br>
    <br>

    <div class="btn-grad">Computational and Applied Mathematics</div>
    <ul class="cloud-computing centrare">
      <li>
        Qualitative and quantitative aspects of Dynamical Systems (time-delayed systems, impulsive systems, fractional-order systems)
      </li>
      <li>
        Simulation of fractional-order systems using HPC
      </li>
      <li>
        Analysis of nonlinear and chaotic phenomena in: fractional-order neural networks models, complex-valued neural networks
      </li>
      <li>
        Applications of the theory of dynamical systems to: medicine, neuroscience, aerodynamics, economy
      </li>
    </ul>

  <br>
  <br>

  <br>
  <br>
  <br>
  <br>

  <div class="carduri">
    <div class = "card-base">
      <img class = "hero" src="styles\images\illustration-hero.svg" alt="">
      <p class = "nume-prenume">Alexandru Andrita</p>
      <p class="functie">Developer</p>
    </div>

    <div class = "card-base">
          <img class = "hero" src="styles\images\illustration-hero.svg" alt="">
          <p class = "nume-prenume">Emanuel Rusu</p>
          <p class="functie">Developer</p>
    </div>
  </div>

  <button onclick="goToTop()" id="goToTopButton" title="Go to Top Button">Top</button>

  <script src="scripts\js_staff.js"></script>


</body>
</html>
