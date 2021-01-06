<?php
session_start();

include 'user.php';
include 'header.php';

if (isset($_POST['login'], $_POST['mdp'])){

  $user = new user($bdd, 1);
  $result = $user->verifPassword($_POST['login'], $_POST['mdp']);
    if ($result == true) {
        $_SESSION['connect'] = 1;
    } else {
        echo "mot de passe incorrect";
    }
}
if (isset($_SESSION['connect'])) {
if($_SESSION['connect'] == 1) {
    include 'site.php';
} else {
    include 'login.php';
}
} else {
    include 'login.php';
}

