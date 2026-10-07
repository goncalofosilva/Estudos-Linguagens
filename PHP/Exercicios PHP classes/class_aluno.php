<?php

class Aluno {
    var $nome;
    var $nota1;
    var $nota2;

    function calcularMedia(){
        $media = ($this->nota1 + $this->nota2) / 2;
        echo "<p>Média das notas do aluno: {$media}</p>";
    }

    function verificarAprovacao($media){
        if ($media >= 9.5){
            echo "<p>Aprovado</p>";
        }
        else {
            echo "<p>Reprovado</p>";
        }
    }
}

$aluno = new Aluno();

$aluno -> nome = "João";
$aluno -> nota1 = 10;
$aluno -> nota2 = 20;
$aluno -> calcularMedia();
$aluno -> verificarAprovacao();

?>