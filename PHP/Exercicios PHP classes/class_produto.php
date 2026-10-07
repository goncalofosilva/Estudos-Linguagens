<?php

class Produto {
    var $nome;
    var $preco;
    var $stock;

    function adicionarStock($quantidade){
        $this->stock += $quantidade;
    }

    function removerStock($quantidade){
        if($this->stock >= $quantidade){
            $this->stock -= $quantidade;
        }
        else{
            echo "<p>Não há stock suficiente, a quantidade em stock é {$this->stock}.</p>";
        }
    }

    function aplicarDesconto($percentagem){
        $this->preco -= ($this->preco * ($percentagem/0.01));
        echo "<p>Preco com desconto: {$this->preco}</p>";
    }
}

$produto = new Produto();

$produto -> nome = "Beatriz Silva";
$produto -> preco = 80;
$produto -> stock = 108;
$produto -> adicionarStock(50);
$procuto -> removerStock(30);
$produto -> aplicarDesconto(80,50);
$produto -> aplicarDesconto(45, 5);

?>