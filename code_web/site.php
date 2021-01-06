<html>

<head>
    <link rel="icon" href="image/Sed-09-512.webp" />
    <title>Security Cam</title>
    <link rel="stylesheet" type="text/css" href="style.css">
    <link rel="stylesheet" type="text/css" href="fichier_bootstrap/bootstrap-4.5.3-dist/css/bootstrap.css">
</head>

<body class="background">
    <div>
        <div class="row">
            <div id="img2" class="header col-lg-8" align="center">
                <h1 id="title">SECURITY CAM</h1>
            </div>
            <div class="header col-lg-2" align="center">
                <form method="POST">
                    <input type="submit" name="serveur_co" value="Connexion serveur" class="submit-btn2" />
                </form>
            </div>
            <div class="header col-lg-2" align="center">
                <form method="POST" action="deconnexion.php">
                    <input type="submit" name="deco2" value="DECONNEXION" class="submit-btn2" />
                </form>
            </div>
        </div>
        <div class="row" align="center">
            <div class="form-box-on" align="center">
                <div class="row">
                    <div class="col-6" align="center">
                        <input type="submit" name="on" value="ALLUMER" class="submit-btn-on" />
                    </div>
                    <div class="col-6" align="center">
                        <input type="submit" name="off" value="ETEINDRE" class="submit-btn-on" />
                    </div>
                </div>
            </div>
        </div>
        <div class="row">
            <div class="form-box-zoom" align="center">
                <!-- bouton de zoom-->
                <form action="" method="POST">
                    <input type="submit" name="zoom_+" value="ZOOM +" class="submit-btn-zoom-in" />
                    <input type="submit" name="zoom_-" value="ZOOM -" class="submit-btn-zoom-out" />
                </form>
            </div>
            <div class="form-box-direction" align="center">
                <!-- bouton directionnel-->
                <form method="POST">
                    <div class="row">
                        <div class="col-12" align="center">
                            <input type="submit" name="up" value="HAUT" class="submit-btn-up" />
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-4" align="center">
                            <input type="submit" name="left" value="GAUCHE" class="submit-btn2" />
                        </div>
                        <div class="col-4" align="center">
                            <input type="submit" name="home" value="CENTRAGE" class="submit-btn2" />
                        </div>
                        <div class="col-4" align="center">
                            <input type="submit" name="right" value="DROITE" class="submit-btn2" />
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-12" align="center">
                            <input type="submit" name="down" value="BAS" class="submit-btn2" />
                        </div>
                    </div>
                </form>
            </div>
            <div class="form-box-balayage" align="center">
                <!-- bouton de balayage-->
                <form method="POST">
                    <input type="submit" name="balayage" value="Balayage" class="submit-btn-balayage" />
                    <input type="submit" name="stop" value="STOP" class="submit-btn-balayage" />
                </form>
            </div>
        </div>
    </div>
</body>

</html>


<?php 

$adress = "192.168.64.107";
$port = 1234;

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
$result = socket_connect($socket, $adress, $port);

if (isset($_POST['stop'])) {

    $socket = $connect->co_serveur();
    socket_send($socket, "S!", 2, 0);
}
if (isset($_POST['zoom_+'])) {

    socket_send($socket, "+!", 2, 0);
}
if (isset($_POST['zoom_-'])) {
    socket_send($socket, "-!", 2, 0);
}
if (isset($_POST['home'])) {
    socket_send($socket, "c!", 2, 0);
}
if (isset($_POST['up'])) {
    socket_send($socket, "h!", 2, 0);
}
if (isset($_POST['left'])) {
    socket_send($socket, "g!", 2, 0);
}
if (isset($_POST['right'])) {
    socket_send($socket, "d!", 2, 0);
}
if (isset($_POST['down'])) {
    socket_send($socket, "b!", 2, 0);
}
if (isset($_POST['on'])) {
    socket_send($socket, "a!", 2, 0);
}
if (isset($_POST['off'])) {
    socket_send($socket, "e!", 2, 0);
}
if (isset($_POST['balayage'])) {
    socket_send($socket, "y!", 2, 0);
}
?>