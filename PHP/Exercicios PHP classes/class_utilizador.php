<?php

class Utilizador {
    var $nome;
    var $email;
    var $palavraPasse;

    // num ciclo if || é OU
    // && significa "E"
    function autenticar($emailTestar, $palavraPasseTestar){
        if ($this->email == $emailTestar && $this->palavraPasse == $palavraPasseTestar){
            echo "<p>Acesso permitido.</p>";
        }
        else{
            echo "<p>Acesso negado.</p>";
        }
    }

    function alterarPalavraPasse($novaPalavraPasse){
        $this->palavraPasse = $novaPalavraPasse;
    }
}

$utilizador = new Utilizador();

$utilizador -> nome = "Tiago Silva";
$utilizador -> email = "tiagosilva@gmail.com";
$utilizador -> palavraPasse = "123programacao";
$utilizador -> autenticar("tiagosilva@gmail.com","123");
$utilizador -> autenticar("tiagosilva@gmail.com","123programacao");
$utilizador -> alterarPalavraPasse("12345teste");

?>