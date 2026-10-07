<?php

// Criar métodos
class conta_bancaria {
    var $titular;
    var $saldo;


    function levantar($montante){
        if($this->saldo >= $montante){
            $this->saldo -= $montante;
        }
        else{
            echo"<p>Não têm saldo suficiente.</p>";
        }
    }

    function depositar($montante){
        $this->saldo += $montante;
    }

    function mostrarSaldo(){
        echo "<p>O/A titular {$this->titular} têm {$this->saldo} de saldo.</p>";
    }
}


// Criar um objeto
$conta = new conta_bancaria();

$conta -> titular = "João"
$conta -> depositar(100);
$conta -> levantar(50);
$conta -> mostrarSaldo();
$conta -> levantar(20);

?>