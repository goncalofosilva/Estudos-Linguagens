<?php

class Livro {
var $titulo;
var $autor;
var $numPaginas;

function mostrarDetalhes(){
    echo "<p>O livro {$this->titulo} de {$this->autor} tem {$this->páginas}.</p>";
} 

}

$livro = new Livro;

$livro -> titulo = "Aventuras da carochinha"
$livro -> autor = "Ana Mendes";
$livro -> numpaginas = 50
$livro -> mostrarDetalhes();

?>