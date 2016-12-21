---
title: "Operador OR l&#243;gico: || | Microsoft Docs"
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
  - "||"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador ||"
  - "Operador OR lógico"
  - "Operador OR"
  - "Operador OR, lógico"
ms.assetid: 31837c99-2655-4bf3-8ded-f13b7a9dc533
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador OR l&#243;gico: ||
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
logical-or-expression   
||  
 logical-and-expression  
  
```  
  
## Comentários  
 O operador OR lógico \(`||`\) retorna o valor booliano **true** se um ou ambos os operandos forem **true** e retorna **false** de outra forma.  Os operandos são convertidos implicitamente no tipo `bool` antes da avaliação, e o resultado é do tipo `bool`.  O OR lógico tem associatividade da esquerda para a direita.  
  
 Os operandos para o operador OR lógico não precisam ser do mesmo tipo, mas devem ser de tipo integral ou ponteiro.  Os operandos são geralmente expressões relacionais ou de igualdade.  
  
 O primeiro operando é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar a avaliação da expressão OR lógica.  
  
 O segundo operando é avaliado somente se o primeiro operando for avaliado como false \(0\).  Isso elimina a avaliação desnecessária do segundo operando quando a expressão OR lógica for true.  
  
```  
printf( "%d" , (x == w || x == y || x == z) );  
```  
  
 No exemplo acima, se `x` for igual a `w`, `y` ou `z`, o segundo argumento para a função `printf` será avaliado como true e o valor 1 será impresso.  Caso contrário, será avaliado como false, e o valor 0 será impresso.  Assim que uma das condições for avaliada como true, a avaliação é encerrada.  
  
## Palavra\-chave do operador para &#124;&#124;  
 O operador **or** é o equivalente de texto de `||`.  Há duas maneiras de acessar o operador **or** em seus programas: incluindo o arquivo de cabeçalho `iso646.h` ou compilando com a opção do compilador [\/Za](../build/reference/za-ze-disable-language-extensions.md) \(Desabilita Extensões de Linguagem\).  
  
## Exemplo  
  
```  
// expre_Logical_OR_Operator.cpp  
// compile with: /EHsc  
// Demonstrate logical OR  
#include <iostream>  
using namespace std;  
int main() {  
   int a = 5, b = 10, c = 15;  
   cout  << boolalpha  
         << "The true expression "  
         << "a < b || b > c yields "  
         << (a < b || b > c) << endl  
         << "The false expression "  
         << "a > b || b > c yields "  
         << (a > b || b > c) << endl;  
}  
```  
  
## Consulte também  
 [Operadores Lógicos](../misc/logical-operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores lógicos C](../c-language/c-logical-operators.md)