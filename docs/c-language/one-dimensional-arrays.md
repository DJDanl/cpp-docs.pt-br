---
title: "Matrizes unidimensionais | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "matrizes [C++], de uma dimensão"
  - "colchetes [ ]"
  - "colchetes [ ], matrizes"
  - "matrizes de uma dimensão"
  - "colchetes [ ]"
  - "colchetes [ ], matrizes"
  - "expressões subscritas"
ms.assetid: e28536e5-3b77-46b5-97fd-9b938c771816
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Matrizes unidimensionais
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma expressão de pós\-fixação seguida por uma expressão entre colchetes \(**\[ \]**\) é uma representação assinada de um elemento de um objeto da matriz.  Uma expressão subscrita representa o valor no endereço que é a *expressão* posiciona além de *postfix\-expression* quando expresso como  
  
```  
  
postfix-expression [ expression ]  
```  
  
 Geralmente, o valor representado por *postfix\-expression* é um valor do ponteiro, como um identificador de matriz, e *a expressão* é um valor integral.  No entanto, tudo o que é necessário sintaticamente é que uma das expressões seja do tipo ponteiro e a outra seja do tipo integral.  Assim o valor completo pode estar na posição de *postfix\-expression* e o valor do ponteiro pode estar entre colchetes *na expressão* ou na posição "subscrito".  Por exemplo, esse código é válido:  
  
```  
// one_dimensional_arrays.c  
int sum, *ptr, a[10];  
int main() {  
   ptr = a;  
   sum = 4[ptr];  
}  
```  
  
 As expressões subscritas geralmente são usadas para se referir a elementos da matriz, mas você pode aplicar um subscrito a qualquer ponteiro.  Independente da ordem dos valores, a *expressão* deve estar entre colchetes \(**\[ \]**\).  
  
 A expressão subscrita é avaliada adicionando o valor integral ao valor do ponteiro, então aplicando o operador de nomes indiretos \(**\***\) ao resultado. \(Consulte [Nomes indiretos e endereços de operadores](../c-language/indirection-and-address-of-operators.md) para obter uma discussão do operador de nomes indiretos.\) De fato, para uma matriz unidimensional, as quatro expressões a seguir são equivalentes, supondo que `a` é um ponteiro e `b` é um inteiro:  
  
```  
a[b]  
*(a + b)  
*(b + a)  
b[a]  
```  
  
 De acordo com as regras de conversão para o operador de adição \(determinado em [Operadores aditivos](../c-language/c-additive-operators.md)\), o valor integral é convertido em um deslocamento do endereço pela multiplicação dele pelo comprimento do tipo resolvido pelo ponteiro.  
  
 Por exemplo, suponha que o identificador `line` faça referência a uma matriz de valores `int`.  O procedimento a seguir é usado para avaliar a expressão subscrita `line[ i ]`:  
  
1.  O valor inteiro `i` é multiplicado pelo número de bytes definidos como o comprimento de um item `int`.  O valor convertido de `i` representa as posições de `i``int`.  
  
2.  Este valor convertido é adicionado ao valor do ponteiro original \(`line`\) para produzir um endereço que é deslocado de posições de `i``int` de `line`.  
  
3.  O operador de indireção é aplicado ao novo endereço.  O resultado é o valor do elemento da matriz nessa posição \(intuitivamente, `line [ i ]`\).  
  
 A expressão subscrita `line[0]` representa o valor do primeiro elemento de linha, desde que o deslocamento de endereço representado por `line` seja 0.  Similarmente, uma expressão como `line[5]` se refere ao deslocamento de cinco posições do elemento da linha, ou o sexto elemento da matriz.  
  
## Consulte também  
 [Operador Subscript:](../Topic/Subscript%20Operator:.md)