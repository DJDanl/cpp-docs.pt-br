---
title: Constantes de Inteiros de C | Microsoft Docs
ms.custom: 
ms.date: 02/01/2018
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6c23e90d235e1ad2a8cca577c5cfbf2be55b52b6
ms.sourcegitcommit: 30ab99c775d99371ed22d1a46598e542012ed8c6
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/03/2018
---
# <a name="c-integer-constants"></a>Constantes de inteiro C

Uma "constante de inteiro" é um número decimal (base 10), octal (base 8) ou hexadecimal (base 16), que representa um valor integral. Use as constantes de inteiro para representar os valores de inteiro que não podem ser alterados.

## <a name="syntax"></a>Sintaxe

*integer-constant*:  
&nbsp;&nbsp;*decimal-constant* *integer-suffix*<sub>opt</sub>  
&nbsp;&nbsp;*octal-constant* *integer-suffix*<sub>opt</sub>  
&nbsp;&nbsp;*hexadecimal-constant* *integer-suffix*<sub>opt</sub>  

*decimal-constant*:  
&nbsp;&nbsp;*nonzero-digit*  
&nbsp;&nbsp;*decimal-constant* *digit*  

*octal-constant*:  
&nbsp;&nbsp;**0**  
&nbsp;&nbsp;*octal-constant* *octal-digit*  

*hexadecimal-constant*:  
&nbsp;&nbsp;**0x**  *hexadecimal-digit*  
&nbsp;&nbsp;**0X**  *hexadecimal-digit*  
&nbsp;&nbsp;*hexadecimal-constant* *hexadecimal-digit*  

*nonzero-digit*: one of  
&nbsp;&nbsp;**1 2 3 4 5 6 7 8 9**  

*octal-digit*: one of  
&nbsp;&nbsp;**0 1 2 3 4 5 6 7**  

*hexadecimal-digit*: one of  
&nbsp;&nbsp;**0 1 2 3 4 5 6 7 8 9**  
&nbsp;&nbsp;**a b c d e f**  
&nbsp;&nbsp;**A B C D E F**  
  
*integer-suffix*:  
&nbsp;&nbsp;*unsigned-suffix* *long-suffix*<sub>opt</sub>  
&nbsp;&nbsp;*long-suffix* *unsigned-suffix*<sub>opt</sub>  
&nbsp;&nbsp;*unsigned-suffix* *64-bit-integer-suffix*<sub>opt</sub>

*unsigned-suffix*: one of  
&nbsp;&nbsp;**u U**  

*long-suffix*: one of  
&nbsp;&nbsp;**l L**  
  
*64-bit-integer-suffix*: um de &nbsp;&nbsp;**i64 I64**  

As constantes de inteiro são positivas a menos que sejam precedidas por um sinal de subtração (**-**). O sinal de subtração é interpretado como o operador aritmético unário de negação. (Consulte [Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md) para obter informações sobre este operador.)

Se uma constante inteira começar com **0x** ou **0X**, ela é hexadecimal. Se ela começar com o dígito **0**, é octal. Caso contrário, pressupõe-se que é decimal.

As linhas de comando a seguir são equivalentes:

```C
0x1C   /* = Hexadecimal representation for decimal 28 */
034    /* = Octal representation for decimal 28 */
```

Nenhum caractere de espaço em branco pode separar os dígitos de uma constante de inteira. Esses exemplos mostram constantes decimais, octais e hexadecimais válidas.

```C
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
