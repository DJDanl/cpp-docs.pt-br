---
title: "Operadores de incremento e de decremento p&#243;s-fixados: ++ e -- | Microsoft Docs"
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
  - "--"
  - "++"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador --, operadores de decremento de sufixo"
  - "Operador ++, operadores de incremento de sufixo"
  - "operadores de decremento"
  - "operadores de decremento, sintaxe"
  - "operadores de incremento, sintaxe"
  - "operadores de seleção de membro"
  - "operadores [C++], sufixo"
  - "operadores de sufixo"
ms.assetid: 0204d5c8-51b0-4108-b8a1-074c5754d89c
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores de incremento e de decremento p&#243;s-fixados: ++ e --
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
      postfix-expression   
      ++  
postfix-expression ––  
```  
  
## Comentários  
 O C\+\+ fornece operadores de incremento e decremento de prefixo e sufixo; esta seção descreve somente os operadores de incremento e decremento de sufixo. \(Para obter mais informações, consulte [Operadores de incremento e decremento de prefixo](../Topic/Prefix%20Increment%20and%20Decrement%20Operators:%20++%20and%20--.md).\) A diferença entre os dois é que, na notação do sufixo, o operador aparece depois da *expressão do sufixo*, enquanto a notação do prefixo, o operador aparece antes da *expressão*. O exemplo a seguir mostra um operador de incremento de sufixo:  
  
```  
i++;  
```  
  
 O efeito de aplicar o operador de incremento de sufixo \(`++`\) é que o valor do operando é gerado por uma unidade do tipo apropriado.  Da mesma forma, o efeito de aplicar o operador de decremento de sufixo \(**––**\) é que o valor do operado é diminuído em uma unidade do tipo apropriado.  
  
 É importante observar que uma expressão de incremento ou decremento de sufixo é avaliada no valor da expressão **antes** da aplicação do respectivo operador.  A operação de incremento ou decremento ocorre **depois** que o operando é avaliada.  Esse problema surge apenas quando a operação de incremento ou decremento de sufixo ocorre no contexto de uma expressão maior.  
  
 Quando um operador de sufixo é aplicado a um argumento de função, o valor do argumento não tem garantia de incremento ou decremento antes de ser passada para a função.  Consulte a seção 1.9.17 no padrão C\+\+ para obter mais informações.  
  
 Aplicar o operador de incremento de sufixo a um ponteiro para uma matriz de objetos do tipo **long** adiciona quatro à representação interna do ponteiro.  Esse comportamento faz com que o ponteiro, referido anteriormente como o *n*º elemento da matriz, consulte o elemento \(*n*\+1\)º.  
  
 Os operandos de incremento e decremento de sufixo devem ser valor I modificáveis \(não **const**\) de tipo aritmético ou ponteiro.  O tipo do resultado é o mesmo da *expressão de sufixo*, mas não é mais um valor l.  
  
 O operando de um operador de incremento de sufixo também pode ser do tipo `bool`, caso em que o operando é avaliado e depois definido como **true**.  O operando de um operador de decremento de sufixo não pode ser do tipo `bool`.  
  
 O código a seguir ilustra o operador de incremento de sufixo:  
  
```  
// expre_Postfix_Increment_and_Decrement_Operators.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main() {  
   int i = 10;  
   cout << i++ << endl;  
   cout << i << endl;  
}  
```  
  
 As operações postincrement e postdecrement em tipos enumerados não têm suporte:  
  
```  
enum Compass { North, South, East, West );  
Compass myCompass;  
for( myCompass = North; myCompass != West; myCompass++ ) // Error  
```  
  
## Consulte também  
 [Expressões pós\-fixadas](../cpp/postfix-expressions.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores de incremento e de decremento pós\-fixados C](../c-language/c-postfix-increment-and-decrement-operators.md)