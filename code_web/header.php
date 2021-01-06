<?php include 'config.php';

$bdd = NULL;
try {
    $bdd = new PDO('mysql:host=' . $adresse . '; dbname=' . $dbName . '; charset=utf8', $login, $mdp);
} catch (Exception $erreur) {
    echo 'Erreur : ' . $erreur->getMessage();
}

$isconnect = false;

if (isset($_SESSION['connect'])) {

    $isconnect = true;
} else {
    $isconnect = false;
}


