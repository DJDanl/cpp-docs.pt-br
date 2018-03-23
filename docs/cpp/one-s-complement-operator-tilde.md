---
title: 'Um &#39; s operador de complemento individual: ~ | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- "~"
dev_langs:
- C++
helpviewer_keywords:
- tilde (~) one's complement operator
- one's complement operator
- bitwise-complement operator
- compl operator
- ~ operator [C++], syntax
ms.assetid: 4bf81967-34f7-4b4b-aade-fd03d5da0174
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 635a3e3b2d270d2164adc3f25a260085d7c50d60
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="one39s-complement-operator-"></a>Um &#39; s operador de complemento individual: ~
## <a name="syntax"></a>Sintaxe  
  
```  
  
~ cast-expression  
```  
  
## <a name="remarks"></a>Comentários  
 O operador de complemento de um (`~`), às vezes chamado de operador de “complemento bit a bit”, gera um complemento bit a bit de seu operando. Ou seja, cada bit que é 1 no operando, é 0 no resultado. De forma análoga, cada bit que é 0 no operando, é 1 no resultado. O operando para o operador de complemento de um deve ser um tipo integral.  
  
## <a name="operator-keyword-for-"></a>Palavra-chave do operador para ~  
 O operador `compl` é o equivalente de texto de `~`. Há duas maneiras para acessar o `compl` operador em seus programas: incluem o arquivo de cabeçalho `iso646.h`, ou compile com [/Za](../build/reference/za-ze-disable-language-extensions.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_One_Complement_Operator.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
  
int main () {  
   unsigned short y = 0xFFFF;  
   cout << hex << y << endl;  
   y = ~y;   // Take one's complement  
   cout << hex << y << endl;  
}  
```  
  
 Nesse exemplo, o novo valor atribuído a `y` é o complemento de um do valor sem sinal 0xFFFF, ou 0x0000.  
  
 A promoção de integral é executada em operandos integrais, e o tipo resultante é o tipo para o qual o operando é promovido. Consulte [conversões padrão](standard-conversions.md) para obter mais informações sobre como a promoção é feita.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md)