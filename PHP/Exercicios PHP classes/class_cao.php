<?php

class Cao {
    var $nome;
    var $raca;
    var $idade;

    function latir(){
        echo "<p>Au au!</p>";
    }

    function fazerAniversario(){
        $this->idade += 1;
    }

    function mostrarIdade(){
        if($this->idade == 1){
            echo "<p>O/A {$this->nome} tem atualmente {$this->idade} ano.</p>";
        }
        else{
            echo "<p>O/A {$this->nome} tem atualmente {$this->idade} anos.</p>";
        }
    }
}

$cao = new Cao();

$cao->raca = "Pastor alemão";
$cao -> latir();
$cao -> fazerAniversario();
$cao -> mostrarIdade();

?>