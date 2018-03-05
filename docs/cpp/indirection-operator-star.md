---
title: "Operador de indireção: * | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- '* operator'
- indirection operator
- operators [C++], indirection
- indirection operator [C++], syntax
ms.assetid: c50309e1-6c02-4184-9fcb-2e13c1f4ac03
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2c87c279ae1f45899dfa4525c3bdc65bfa5acc2c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="indirection-operator-"></a>Operador de indireção: *
## <a name="syntax"></a>Sintaxe  
  
```  
  
* cast-expression  
```  
  
## <a name="remarks"></a>Comentários  
 O operador de indireção unário (**\***) cancela a referência de um ponteiro; ou seja, ele converte um valor de ponteiro para um l-value. O operando do operador de indireção deve ser um ponteiro para um tipo. O resultado da expressão de indireção é o tipo do qual o tipo do ponteiro é derivado. O uso do  **\***  operador neste contexto é diferente de seu significado como um operador binário, que é de multiplicação.  
  
 Se o operando apontar para uma função, o resultado será um designador de função. Se ele apontar para um local de armazenamento, o resultado será um valor l que designa o local de armazenamento.  
  
 O operador de indireção pode ser usado cumulativamente para retirar as referências dos ponteiros para os ponteiros. Por exemplo:  
  
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
  
 Se o valor do ponteiro for inválido, o resultado será indefinido. A lista a seguir inclui algumas das condições mais comuns que invalidam um valor de ponteiro.  
  
-   O ponteiro é um ponteiro nulo.  
  
-   O ponteiro especifica o endereço de um item local que não está visível no momento da referência.  
  
-   O ponteiro especifica um endereço que está alinhado de forma inadequada para o tipo do objeto apontado.  
  
-   O ponteiro especifica um endereço não usado pelo programa em execução.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operador address-of: &](../cpp/address-of-operator-amp.md)   
 [Operadores de indireção e address-of](../c-language/indirection-and-address-of-operators.md)