<?php

class Retangulo {
    var $largura;
    var $altura;

    function calcularArea($l, $a){
        echo "<p>Area do retangulo: {$l * $a}</p>";
    }

    function calcularPerimetro($l, $a){
        var $perimetro;
        $perimetro = 2 * $l + $a;
        echo "<p>Perimetro do retangulo: {$perimetro}</p>";
    }
}

$retangulo = new Retangulo();

$retangulo->calcularArea(30,10);
$retangulo->calcularPerimetro(80,50);

?>