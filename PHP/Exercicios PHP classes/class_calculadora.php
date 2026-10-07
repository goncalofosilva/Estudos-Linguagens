<?php

class Calculadora {
    var $ultimoresultado;

    function somar($a,$b){
        $this -> ultimoresultado = $a + $b;
        echo "<p>Resultado: {$this->ultimoresultado}</p>";
    }

    function subtrair($a, $b){
        $this -> ultimoresultado = $a - $b;
        echo "<p>Resultado: {$this->ultimoresultado}</p>";
    }

    function multiplicar($a, $b){
        $this -> ultimoresultado = $a * $b;
        echo "<p>Resultado: {$this->ultimoresultado}</p>";
    }

    function dividir($a, $b){
        $this -> ultimoresultado = $a / $b;
        echo "<p>Resultado: {$this->ultimoresultado}</p>";
    }
}

$calculadora = new Calculadora();

$calculadora -> somar(6, 7);
$calculadora -> subtrair(7, 2);
$calculadora -> multiplicar(4, 6);
$calculadora -> dividir(4, 2);

?>