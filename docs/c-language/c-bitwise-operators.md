---
title: Operadores bit a bit C | Microsoft Docs
ms.custom: ''
ms.date: 01/29/2018
ms.technology:
- cpp-language
ms.topic: language-reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9c5c360246282f8b6062d21061856a57bd2c7194
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="c-bitwise-operators"></a>Operadores bit a bit C

Os operadores bit a bit executam as operações E bit a bit (**&**), OR exclusivo bit a bit (**^**) e OR inclusivo bit a bit (**&#124;**).

## <a name="syntax"></a>Sintaxe

*AND-expression*:  
&nbsp;&nbsp;*equality-expression*  
&nbsp;&nbsp;*AND-expression* **&** *equality-expression*

*exclusive-OR-expression*:  
&nbsp;&nbsp;*AND-expression*  
&nbsp;&nbsp;*exclusive-OR-expression* **^** *AND-expression*

*inclusive-OR-expression*:  
&nbsp;&nbsp;*exclusive-OR-expression*  
&nbsp;&nbsp;*inclusive-OR-expression* &#124; *exclusive-OR-expression*

Os operandos dos operadores bit a bit devem ter tipos integrais, mas seus tipos podem ser diferentes. Esses operadores executam conversões aritméticas comuns; o tipo do resultado é o tipo dos operandos após a conversão.

Os operadores bit a bit de C são descritos abaixo:

|Operador|Descrição|
|--------------|-----------------|
|**&**|O operador AND bit a bit compara cada bit do primeiro operando com o bit correspondente de seu segundo operando. Se os dois bits forem 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.|
|**^**|O operador OR exclusivo bit a bit compara cada bit do primeiro operando ao bit correspondente do seu segundo operando. Se um bit for 0 e o outro bit for 1, o bit resultante correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.|
|**&#124;**|O operador OR inclusivo bit a bit compara cada bit do primeiro operando com o bit correspondente de seu segundo operando. Se um bit for 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.|

## <a name="examples"></a>Exemplos

Essas declarações são usadas para os três exemplos a seguir:

```C
short i = 0xAB00;
short j = 0xABCD;
short n;

n = i & j;
```

O resultado atribuído a `n` neste primeiro exemplo é o mesmo que `i` (0xAB00 hexadecimal).

```C
n = i | j;

n = i ^ j;
```

O operador OR inclusivo bit a bit no segundo exemplo resulta no valor 0xABCD (hexadecimal), enquanto o OU exclusivo bit a bit no terceiro exemplo gerencia 0xCD (hexadecimal).

**Seção específica da Microsoft**

Os resultados de operação bit a bit em números inteiros assinados é definido pela implementação de acordo com o padrão ANSI C. Para o compilador C da Microsoft, as operações bit a bit em números inteiros assinados funcionam da mesma forma que as operações bit a bit em inteiros não assinados. Por exemplo, `-16 & 99` pode ser expresso em binário como

```Expression
  11111111 11110000
& 00000000 01100011
  _________________
  00000000 01100000
```

O resultado do E bit a bit é decimal 96.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Operador AND bit a bit: &](../cpp/bitwise-and-operator-amp.md)  
[Operador OR exclusivo bit a bit: ^](../cpp/bitwise-exclusive-or-operator-hat.md)  
[Bitwise Inclusive OR Operator: &#124;](../cpp/bitwise-inclusive-or-operator-pipe.md)  