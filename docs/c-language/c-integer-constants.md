---
title: Constantes de Inteiros de C | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- integer constants
ms.assetid: fcf6b83c-2038-49ec-91ca-3d5ca1f83037
caps.latest.revision: 10
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
ms.translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: dab1cb72b5914901808dc51f3a173a62a8924cfb
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="c-integer-constants"></a>Constantes de inteiro C
Uma "constante de inteiro" é um número decimal (base 10), octal (base 8) ou hexadecimal (base 16), que representa um valor integral. Use as constantes de inteiro para representar os valores de inteiro que não podem ser alterados.  
  
## <a name="syntax"></a>Sintaxe  
 *integer-constant*:  
 *decimal-constant integer-suffix* opt  
  
 *octal-constant integer-suffix* opt  
  
 *hexadecimal-constant integer-suffix* opt  
  
 *decimal-constant*:  
 *nonzero-digit*  
  
 *decimal-constant digit*  
  
 *octal-constant*:  
 **0**  
  
 *octal-constant octal-digit*  
  
 *hexadecimal-constant*:  
 **0x**  *hexadecimal-digit*  
  
 **0X**  *hexadecimal-digit*  
  
 *hexadecimal-constant hexadecimal-digit*  
  
 *nonzero-digit*: one of  
 **1 2 3 4 5 6 7 8 9**  
  
 *octal-digit*: one of  
 **0 1 2 3 4 5 6 7**  
  
 *hexadecimal-digit*: one of  
 **0 1 2 3 4 5 6 7 8 9**  
  
 **a b c d e f**  
  
 **A B C D E F**  
  
 *integer-suffix*:  
 *unsigned-suffix long-suffix* opt  
  
 *long-suffix unsigned-suffix* opt  
  
 *unsigned-suffix*: one of  
 **u U**  
  
 *long-suffix*: one of  
 **l L**  
  
 *64-bit integer-suffix*:  
 **i64**  
  
 As constantes de inteiro são positivas a menos que sejam precedidas por um sinal de subtração (**-**). O sinal de subtração é interpretado como o operador aritmético unário de negação. (Consulte [Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md) para obter informações sobre este operador.)  
  
 Se uma constante inteira começar com **0x** ou **0X**, ela é hexadecimal. Se ela começar com o dígito **0**, é octal. Caso contrário, pressupõe-se que é decimal.  
  
 As linhas de comando a seguir são equivalentes:  
  
```  
0x1C   /* = Hexadecimal representation for decimal 28 */  
034    /* = Octal representation for decimal 28 */  
```  
  
 Nenhum caractere de espaço em branco pode separar os dígitos de uma constante de inteira. Esses exemplos mostram constantes decimais, octais e hexadecimais válidas.  
  
```  
/* Decimal Constants */  
10  
132  
32179  
  
/* Octal Constants */  
012  
0204  
076663  
  
/* Hexadecimal Constants */  
0xa or 0xA  
0x84  
0x7dB3 or 0X7DB3  
```  
  
## <a name="see-also"></a>Consulte também  
 [Constantes C](../c-language/c-constants.md)
