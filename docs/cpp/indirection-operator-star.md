---
title: "Operador de indire&#231;&#227;o: * | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador *"
  - "Operador de indireção"
  - "Operador de indireção, sintaxe"
  - "operadores [C++], indireção"
ms.assetid: c50309e1-6c02-4184-9fcb-2e13c1f4ac03
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador de indire&#231;&#227;o: *
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
* cast-expression  
```  
  
## Comentários  
 O operador unário de indireção \(**\***\) removerá a referência de um ponteiro; ou seja, ele converterá um valor de ponteiro para um l\-value.  O operando do operador de indireção deve ser um ponteiro para um tipo.  O resultado da expressão de indireção é o tipo do qual o tipo do ponteiro é derivado.  O uso do operador **\*** nesse contexto é diferente do seu significado como operador binário, que é de multiplicação.  
  
 Se o operando apontar para uma função, o resultado será um designador de função.  Se ele apontar para um local de armazenamento, o resultado será um valor l que designa o local de armazenamento.  
  
 O operador de indireção pode ser usado cumulativamente para retirar as referências dos ponteiros para os ponteiros.  Por exemplo:  
  
```  
// expre_Indirection_Operator.cpp  
// compile with: /EHsc  
// Demonstrate indirection operator  
#include <iostream>  
using namespace std;  
int main() {  
   int n = 5;  
   int *pn = &n;  
   int **ppn = &pn;  
  
   cout  << "Value of n:\n"  
         << "direct value: " << n << endl  
         << "indirect value: " << *pn << endl  
         << "doubly indirect value: " << **ppn << endl  
         << "address of n: " << pn << endl  
         << "address of n via indirection: " << *ppn << endl;  
}  
```  
  
 Se o valor do ponteiro for inválido, o resultado será indefinido.  A lista a seguir inclui algumas das condições mais comuns que invalidam um valor de ponteiro.  
  
-   O ponteiro é um ponteiro nulo.  
  
-   O ponteiro especifica o endereço de um item local que não está visível no momento da referência.  
  
-   O ponteiro especifica um endereço que está alinhado de forma inadequada para o tipo do objeto apontado.  
  
-   O ponteiro especifica um endereço não usado pelo programa em execução.  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operador Address\-of: &](../cpp/address-of-operator-amp.md)   
 [Operadores de indireção e endereço de](../c-language/indirection-and-address-of-operators.md)