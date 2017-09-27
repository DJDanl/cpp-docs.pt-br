---
title: 'Operador AND bit a bit: &amp; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- bitand
dev_langs:
- C++
helpviewer_keywords:
- AND operator
- bitwise operators, AND operator
- '& operator, bitwise operators'
ms.assetid: 76f40de3-c417-47b9-8a77-532f3fc990a5
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 99ff65f38abf5cfcac135e2cc54e3df6df5f336d
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="bitwise-and-operator-amp"></a>Operador AND bit a bit:&amp;
## <a name="syntax"></a>Sintaxe  
  
```  
  
expression   
&  
 expression  
  
```  
  
## <a name="remarks"></a>Comentários  
 As expressões podem ser outras expressões E, ou (sujeito às restrições de tipo mencionadas abaixo) expressões de igualdade, expressões relacionais, expressões aditivas, expressões multiplicativas, expressões de ponteiro para membro, expressões de conversão, expressões unárias, expressões pós-fixadas ou expressões primárias.  
  
 O operador AND bit a bit (**&**) compara cada bit do primeiro operando com o bit correspondente do segundo operando. Se os dois bits forem 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.  
  
 Os dois operandos do operador AND bit a bit devem ser de tipos integrais. Conversões aritméticas usuais abordados [conversões padrão](standard-conversions.md), são aplicadas para os operandos.  
  
## <a name="operator-keyword-for-"></a>Palavra-chave de operador para &  
 O `bitand` operador é equivalente a texto ** & **. Há duas maneiras para acessar o `bitand` operador em seus programas: incluem o arquivo de cabeçalho `iso646.h`, ou de compilação com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador (desabilitar extensões de linguagem).  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_Bitwise_AND_Operator.cpp  
// compile with: /EHsc  
// Demonstrate bitwise AND  
#include <iostream>  
using namespace std;  
int main() {  
   unsigned short a = 0xFFFF;      // pattern 1111 ...  
   unsigned short b = 0xAAAA;      // pattern 1010 ...  
  
   cout  << hex << ( a & b ) << endl;   // prints "aaaa", pattern 1010 ...  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operadores internos, precedência e associatividade C++](cpp-built-in-operators-precedence-and-associativity.md)  
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores bit a bit C](../c-language/c-bitwise-operators.md)
