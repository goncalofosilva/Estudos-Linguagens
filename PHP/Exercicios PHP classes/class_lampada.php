<?php

class Lampada {
    var $ligada = false;
    var $potencia;

    function ligar(){
        $this->ligada = true;
    }

    function desligar(){
        $this->ligada = false;
    }

    function mostrarEstado(){
        if($this->ligada == true){
            echo "<p>A lâmpada está ligada.</p>";
        }
        else{
            echo "<p>A lâmpada está desligada.</p>";
        }
    }
}

$lampada = new Lampada();

$lampada -> potencia = "60W";
$lampada -> ligar();
$lampada -> mostrarEstado();
$lampada -> desligar();
$lampada -> mostrarEstado();

?>