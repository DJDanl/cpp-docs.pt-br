---
title: "Operadores de igualdade: == e != | Microsoft Docs"
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
  - "not_eq"
  - "!="
  - "=="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador !="
  - "Operador =="
  - "Operador equal to"
  - "Operador de igualdade"
  - "Operador de igualdade, sintaxe"
  - "Operador de comparação not equal to"
  - "Operador not_eq"
ms.assetid: ba4e9659-2392-4fb4-be5a-910a2a6df45a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores de igualdade: == e !=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
      expression == expression  
expression != expression  
```  
  
## Comentários  
 Operadores de igualdade binários comparam seus operandos em buscar de igualdades ou desigualdades estritas.  
  
 Os operadores de igualdade, igual a \(`==`\) e diferente de \(`!=`\), têm precedência mais baixa do que os operadores relacionais, mas se comportam de maneira semelhante.  O tipo do resultado desses operadores é `bool`.  
  
 O operador igual a \(`==`\) retorna **true** \(1\) se os dois operandos tiverem o mesmo valor; caso contrário, retorna **false** \(0\).  O operador diferente de \(`!=`\) retorna **true** \(1\) se os operandos não tiverem o mesmo valor; caso contrário, retorna **false**.  
  
## Palavra\-chave do operador para \!\=  
 O operador `not_eq` é o equivalente em texto a `!=`.  Há duas maneiras de acessar o operador `not_eq` em seus programas: incluindo o arquivo de cabeçalho `iso646.h` ou compilando com a opção de compilador [\/Za](../build/reference/za-ze-disable-language-extensions.md) \(Desativar extensões de linguagem\).  
  
## Exemplo  
  
```  
// expre_Equality_Operators.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
  
int main() {  
   cout  << boolalpha  
         << "The true expression 3 != 2 yields: "  
         << (3 != 2) << endl  
         << "The false expression 20 == 10 yields: "  
         << (20 == 10) << endl;  
}  
```  
  
 Os operadores de igualdade podem comparar ponteiros a membros do mesmo tipo.  Nessa comparação, as conversões ponteiro para membro, como discutido em [Conversões de ponteiro em membro](../misc/pointer-to-member-conversions.md), são executadas.  Os ponteiros para membros também podem ser comparados a uma expressão constante que é avaliada como 0.  
  
## Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores relacionais e de igualdade C](../c-language/c-relational-and-equality-operators.md)