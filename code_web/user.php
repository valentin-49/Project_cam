<?php
class user
{
    //propriétes:*
    private $_bdd;
    private $_idUser;
    private $_login;  //log et mot de passe de co pour la page d'acceuil
    private $_mdp;

    //méthodes:


    public function __construct($bdd, $idUser) // constructeur récupère toutes les tuples de la table user dans les attributs privé du user
    {
        $data = $bdd->query('SELECT * FROM `user` WHERE id = ' . $idUser . '');
        $tabdata = $data->fetch();

        $this->_bdd = $bdd;
        $this->_idUser = $tabdata['id'];
        $this->_login = $tabdata['login'];
        $this->mdp = $tabdata['mdp'];
        
    }

    public function verifPassword($login, $mdp)
    {
        $data = $this->_bdd->query('SELECT * FROM `user` WHERE login = "' . $login . '" && mdp = "' . $mdp . '"');
        if ($data->rowcount() >= 1) {
            return true;
        } else {
            return false;
        }
    }
}
