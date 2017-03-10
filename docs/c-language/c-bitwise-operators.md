---
title: Operadores bit a bit C | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- '| operator, bitwise operators'
- bitwise operators, Visual C
- bitwise operators
- operators [C], bitwise
- ^ operator, bitwise operators
- AND operator
- ampersand operator (&)
- ^ operator
- '& operator, bitwise operators'
ms.assetid: e22127b1-9a2d-4876-b01d-c8f72cec3317
caps.latest.revision: 8
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 217d63247ea6c18c405a443510e52dac12707d69
ms.lasthandoff: 02/25/2017

---
# <a name="c-bitwise-operators"></a>Operadores bit a bit C
Os operadores bit a bit executam as operações E bit a bit (**&**), OR exclusivo bit a bit (**^**) e OR inclusivo bit a bit (**&#124;**).  
  
 **Sintaxe**  
  
 *AND-expression*:  
 *equality-expression*  
  
 *AND-expression*  **&**  *equality-expression*  
  
 *exclusive-OR-expression*:  
 *AND-expression*  
  
 *exclusive-OR-expression*  **^**  *AND-expression*  
  
 *inclusive-OR-expression*:  
 *exclusive-OR-expression*  
  
 *inclusive-OR-expression* &#124; *exclusive-OR-expression*  
  
 Os operandos dos operadores bit a bit devem ter tipos integrais, mas seus tipos podem ser diferentes. Esses operadores executam conversões aritméticas comuns; o tipo do resultado é o tipo dos operandos após a conversão.  
  
 Os operadores bit a bit de C são descritos abaixo:  
  
|Operador|Descrição|  
|--------------|-----------------|  
|**&**|O operador AND bit a bit compara cada bit do primeiro operando com o bit correspondente de seu segundo operando. Se os dois bits forem 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.|  
|**^**|O operador OR exclusivo bit a bit compara cada bit do primeiro operando ao bit correspondente do seu segundo operando. Se um bit for 0 e o outro bit for 1, o bit resultante correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.|  
|**&#124;**|O operador OR inclusivo bit a bit compara cada bit do primeiro operando com o bit correspondente de seu segundo operando. Se um bit for 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.|  
  
## <a name="examples"></a>Exemplos  
 Essas declarações são usadas para os três exemplos a seguir:  
  
```  
short i = 0xAB00;  
short j = 0xABCD;  
short n;  
  
n = i & j;  
```  
  
 O resultado atribuído a `n` neste primeiro exemplo é o mesmo que `i` (0xAB00 hexadecimal).  
  
```  
n = i | j;  
  
n = i ^ j;  
```  
  
 O operador OR inclusivo bit a bit no segundo exemplo resulta no valor 0xABCD (hexadecimal), enquanto o OU exclusivo bit a bit no terceiro exemplo gerencia 0xCD (hexadecimal).  
  
 **Seção específica da Microsoft**  
  
 Os resultados de operação bit a bit em números inteiros assinados é definido pela implementação de acordo com o padrão ANSI C. Para o compilador C da Microsoft, as operações bit a bit em números inteiros assinados funcionam da mesma forma que as operações bit a bit em inteiros não assinados. Por exemplo, `-16 & 99` pode ser expresso em binário como  
  
```  
  11111111 11110000  
& 00000000 01100011  
  _________________  
  00000000 01100000  
```  
  
 O resultado do E bit a bit é decimal 96.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Bitwise AND Operator: &](../cpp/bitwise-and-operator-amp.md)   
 [Bitwise Exclusive OR Operator: ^](../cpp/bitwise-exclusive-or-operator-hat.md)   
 [Bitwise Inclusive OR Operator: &#124;](../cpp/bitwise-inclusive-or-operator-pipe.md)
