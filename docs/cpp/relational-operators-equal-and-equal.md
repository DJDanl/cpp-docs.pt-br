---
title: "Operadores relacionais: &lt;, &gt;, &lt;=, and &gt;= | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "<"
  - ">"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador <"
  - "Operador <="
  - "Operador >"
  - "Operador >="
  - "operadores greater than"
  - "operadores greater than or equal to"
  - "Operador less than"
  - "Operador less than or equal to"
  - "operadores relacionais, sintaxe"
ms.assetid: d346b53d-f14d-4962-984f-89d39a17ca0f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores relacionais: &lt;, &gt;, &lt;=, and &gt;=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
        expression < expression  
expression > expression  
expression <= expression  
expression >= expression  
```  
  
## Comentários  
 Os operadores relacionais binários determinam as seguintes relações:  
  
-   Menor que \(**\<**\)  
  
-   Maior que \(**\>**\)  
  
-   Menor que ou igual a \(**\<\=**\)  
  
-   Maior que ou igual a \(**\>\=**\)  
  
 Esses operadores relacionais possuem associatividade da esquerda para a direita.  Ambos os operandos de operadores relacionais devem ser do tipo aritmético ou de ponteiro.  Eles resultam em valores do tipo `bool`.  O valor retornado é **false** \(0\) se a relação na expressão for falsa; caso contrário, o valor retornado é **true** \(1\).  
  
## Exemplo  
  
```  
// expre_Relational_Operators.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
  
int main() {  
   cout  << "The true expression 3 > 2 yields: "  
         << (3 > 2) << endl  
         << "The false expression 20 < 10 yields: "  
         << (20 < 10) << endl;  
}  
```  
  
 As expressões no exemplo anterior devem ser colocadas entre parênteses porque o operador de inserção de fluxo \(**\<\<**\) tem precedência maior do que os operadores relacionais.  Portanto, a primeira expressão sem parênteses seria avaliada como:  
  
```  
(cout << "The true expression 3 > 2 yields: " << 3) < (2 << "\n");  
```  
  
 As conversões aritméticas usuais cobertas em [Conversões aritméticas](../misc/arithmetic-conversions.md) são aplicadas aos operandos de tipos aritméticos.  
  
## Comparando ponteiros  
 Quando dois ponteiros para objetos do mesmo tipo são comparados, o resultado é determinado pelo local dos objetos apontados no espaço de endereço do programa.  Os ponteiros também podem ser comparados a uma expressão constante que é avaliada como 0 ou a um ponteiro do tipo nulo \*.  Se uma comparação de ponteiros for feita em relação a um ponteiro do tipo nulo \*, o outro ponteiro será convertido implicitamente no tipo nulo \*.  Então, a comparação será feita.  
  
 Dois ponteiros de tipos diferentes não podem ser comparados, a menos que:  
  
-   Um tipo é um tipo de classe derivado de outro tipo.  
  
-   Pelo menos um dos ponteiros é convertido explicitamente \(conversão\) no tipo nulo \*.  \(O outro ponteiro é implicitamente convertido no tipo nulo \* para a conversão.\)  
  
 Dois ponteiros do mesmo tipo que apontam para o mesmo objeto são obrigatoriamente comparados como iguais.  Se dois ponteiros para membros não estáticos de um objeto são comparados, as seguintes regras se aplicam:  
  
-   Se o tipo de classe não é uma união e se os dois membros não são separados por um *access\-specifier*, como público, protegido ou particular, o ponteiro para o membro declarado por último será comparado como maior do que o ponteiro para o membro declarado anteriormente.  \(Para obter informações sobre *access\-specifier*, consulte a seção Sintaxe em [Especificadores de acesso](../misc/access-specifiers.md).\)  
  
-   Se os dois membros são separados por um *access\-specifier*, os resultados são indefinidos.  
  
-   Se o tipo de classe for uma união, os ponteiros para membros de dados diferentes nessa união serão comparados como iguais.  
  
 Se dois ponteiros apontarem para elementos da mesma matriz ou para o elemento além do final da matriz, o ponteiro para o objeto com o subscrito mais alto será comparado como superior.  A comparação dos ponteiros é garantida como válida somente quando os ponteiros se referem a objetos na mesma matriz ou ao local após o término da matriz.  
  
## Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores relacionais e de igualdade C](../c-language/c-relational-and-equality-operators.md)