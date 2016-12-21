---
title: "Operador de nega&#231;&#227;o l&#243;gica: ! | Microsoft Docs"
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
  - "!"
  - "Not"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador !"
  - "negação lógica"
  - "Operador NOT"
ms.assetid: 650add9f-a7bc-426c-b01d-5fc6a81c8b62
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador de nega&#231;&#227;o l&#243;gica: !
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
! cast-expression  
```  
  
## Comentários  
 O operador de negação lógica \(**\!**\) inverte o significado do respectivo operando.  O operando deve ser do tipo aritmético ou ponteiro \(ou uma expressão que é avaliada para o tipo aritmético ou ponteiro\).  O operando é convertido implicitamente no tipo `bool`.  O resultado será **true** se o operando convertido for **false**; o resultado será **false** se o operando convertido for **true**.  O resultado é do tipo `bool`.  
  
 Para uma expressão *e*, a expressão unária **\!***e* é equivalente à expressão **\(***e* `==` 0\), exceto onde operadores sobrecarregados estão envolvidos.  
  
## Palavra\-chave de operador para \!  
 O operador **not** é o equivalente de texto de **\!**.  Há duas maneiras de acessar o operador **not** nos programas: incluir o arquivo de cabeçalho `iso646.h` ou compilar com a opção de compilador [\/Za](../build/reference/za-ze-disable-language-extensions.md) \(Desabilitar extensões de linguagem\).  
  
## Exemplo  
  
```  
// expre_Logical_NOT_Operator.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main() {  
   int i = 0;  
   if (!i)  
      cout << "i is zero" << endl;  
}  
```  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md)