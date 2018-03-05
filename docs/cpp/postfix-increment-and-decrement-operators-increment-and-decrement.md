---
title: 'Operadores de incremento e decremento de sufixo: + + e -| Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- --
- ++
dev_langs:
- C++
helpviewer_keywords:
- increment operators [C++], syntax
- member-selection operators [C++]
- -- operator [C++], postfix decrement operators
- postfix operators [C++]
- ++ operator [C++], postfix increment operators
- decrement operators [C++], syntax
- operators [C++], postfix
- decrement operators [C++]
ms.assetid: 0204d5c8-51b0-4108-b8a1-074c5754d89c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5e1d6c13da3023073f3d8b3e9625fa141253ba2c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="postfix-increment-and-decrement-operators--and---"></a>Operadores de incremento e de decremento pós-fixados: ++ e --
## <a name="syntax"></a>Sintaxe  
  
```  
postfix-expression ++  
postfix-expression --  
```  
  
## <a name="remarks"></a>Comentários  
 O C++ fornece operadores de incremento e decremento de prefixo e sufixo; esta seção descreve somente os operadores de incremento e decremento de sufixo. (Para obter mais informações, consulte [prefixo operadores de incremento e decremento](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md).) A diferença entre os dois é que, na notação sufixo, o operador aparece depois *sufixo expressão*, enquanto na notação de prefixo, o operador aparecerá antes *expressão.* O exemplo a seguir mostra um operador de incremento de sufixo:  
  
```  
i++;  
```  
  
 O efeito de aplicar o operador de incremento de sufixo (`++`) é que o valor do operando é gerado por uma unidade do tipo apropriado. Da mesma forma, o efeito de aplicar o operador de decremento de sufixo (**--**) é que o valor do operando é reduzido em uma unidade do tipo apropriado.  
  
 É importante observar que um sufixo incrementar ou diminuir expressão é avaliada como o valor da expressão **antes de** aplicativo do respectivo operador. A operação de incremento ou decremento ocorre **depois** operando é avaliado. Esse problema surge apenas quando a operação de incremento ou decremento de sufixo ocorre no contexto de uma expressão maior.  
  
 Quando um operador de sufixo é aplicado a um argumento de função, o valor do argumento não tem garantia de incremento ou decremento antes de ser passada para a função.  Consulte a seção 1.9.17 no padrão C++ para obter mais informações.  
  
 Aplicar o operador de incremento de sufixo para um ponteiro para uma matriz de objetos do tipo **longo** realmente adiciona quatro para a representação interna do ponteiro. Isso faz com que o ponteiro, que anteriormente referido a  *n* elemento th da matriz, para referir-se a (*n*+ 1) elemento th.  
  
 Os operandos de operadores de incremento e decremento operadores de sufixo devem ser modificáveis (não **const**) l-valores do tipo aritmético ou ponteiro. O tipo do resultado é o mesmo que o *sufixo expressão*, mas não é mais um l-value.  
  
**Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): O operando de operadores de incremento ou decremento operador não pode ser do tipo `bool`.
  
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
  
## <a name="see-also"></a>Consulte também  
 [Expressões pós-fixadas](../cpp/postfix-expressions.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores de incremento e decremento pós-fixados C](../c-language/c-postfix-increment-and-decrement-operators.md)