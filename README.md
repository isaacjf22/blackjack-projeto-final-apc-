<h1 align="center">
   >EXPLODE 21< 
</h1>

<p align="center">
  <b>Projeto Final de Algoritmos e Programação de Computadores (APC) - UnB</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c">
  <img src="https://img.shields.io/badge/IDE-VS%20Code-blueviolet?style=for-the-badge&logo=visual-studio-code">
  <img src="https://img.shields.io/badge/Status-Finalizado-success?style=for-the-badge">
</p>

---

## Identificação
* **Aluno:** Isaac José Oliveira Ferreira
* **Matrícula:** 252014288
* **Professor:** Clenio Emidio
* **Semestre:** 2025/2

---

## Sobre o Projeto
Este é um simulador simples do jogo de cartas **Blackjack** (popularmente conhecido como **21**), desenvolvido puramente na linguagem C.

A ideia foi criar um jogo rodando no terminal onde o jogador desafia a máquina, tentando chegar o mais próximo possível de 21 pontos sem "estourar".

### O que o jogo faz:
* **Baralho Simulado:** Sorteia cartas de 1 a 13 aleatoriamente.
* **Pontuação Dinâmica:**
    * Cartas 2 a 9 valem o número delas.
    * Figuras (10, J, Q, K) valem 10.
    * Ás vale 1.
* **Turno da Máquina:** A "Banca" joga automaticamente após o jogador, seguindo a regra clássica de parar apenas quando tiver 17 pontos ou mais.
* **Interface Visual:** Uso de caracteres ASCII para desenhar as cartas e menus no terminal.

---

## 🛠️ Tecnologias e Técnicas

### 💻 Tecnologias
* **Linguagem C:** O projeto foi desenvolvido inteiramente em C padrão.
* **Compilador:** GCC (MinGW).
* **IDE:** Visual Studio Code.
* **Controle de Versão:** Git e GitHub.

### 📚 Bibliotecas Utilizadas
* **`<stdio.h>`**: Para entrada e saída de dados (o básico do jogo).
* **`<stdlib.h>`**: Usada para geração de números aleatórios (`rand`, `srand`) e comandos do sistema (`system`).
* **`<time.h>`**: Essencial para criar a "semente" do gerador aleatório, garantindo que cada partida tenha cartas diferentes.
* **`<conio.h>`**: Utilizada para a função `getch()`, permitindo capturar teclas instantaneamente no menu (sem precisar apertar Enter).
* **`<windows.h>`**: Usada para funções de manipulação do console, como `Sleep()` (para criar suspense nas cartas) e limpeza de tela.

### 🧠 Técnicas de Programação
* **Modularização:** O código foi dividido em funções específicas (`desenharCarta`, `rodada`, `menu`) para manter a organização e facilitar a leitura.
* **Validação de Entrada:** Implementação de "loops de proteção" nos menus, impedindo que o jogo quebre se o usuário digitar teclas erradas.
* **Máquina de Estados Simples:** Lógica para controlar os turnos (Vez do Jogador -> Vez da Máquina -> Resultado).
* **Manipulação de Strings/ASCII:** Uso criativo de caracteres para desenhar a interface gráfica no terminal.
