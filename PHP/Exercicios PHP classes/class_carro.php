<?php

class Carro {
    var $marca;
    var $modelo;
    var $velocidade = 0;

    function acelerar($valor){
        $this->velocidade += $valor;
    }

    function travar($valor){
        if($this->velocidade > $valor){
            $this->velocidade -= $valor;
        }
    }

    function mostrarVelocidade(){
        echo "<p>Velocidade atual: {$this->velocidade} Km/h</p>";
    }
}

$carro = new Carro;

$carro -> marca="Audi";
$carro -> modelo="A3";
$carro -> acelerar(70);
$carro -> travar(50);
$carro -> mostrarVelocidade();

?>