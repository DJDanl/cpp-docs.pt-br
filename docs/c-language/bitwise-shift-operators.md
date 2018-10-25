---
title: Operadores shift bit a bit | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], bitwise
- shift operators, bitwise
- bitwise-shift operators
- operators [C++], shift
ms.assetid: d0485785-5c72-47e1-a7c0-0adde03ade23
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b1abcfa37373702df371b42efbf228fe748bfc45
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49808193"
---
# <a name="bitwise-shift-operators"></a>Operadores shift bit a bit

Os operadores shift deslocam o primeiro operando da esquerda (**&lt;&lt;**) ou da direita (**>>**) pelo número de posições que o segundo operando especifica.

## <a name="syntax"></a>Sintaxe

*shift-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*additive-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*shift-expression* **&lt;&lt;** *additive-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*shift-expression* **>>** *additive-expression*

Ambos os operandos devem ser valores integrais. Esses operadores executam conversões aritméticas comuns; o tipo de resultado é o tipo do operando à esquerda após a conversão.

Para mudanças à esquerda, os bits vazios à direita são definidos como 0. Para a mudança à direita, os bits vazios à esquerda são preenchidos com base no tipo do primeiro operando após a conversão. Se o tipo for `unsigned`, eles são definidos como 0. Caso contrário, eles são preenchidos com cópias do bit de sinal. Para os operadores Left Shift sem estouro, a instrução

```C
expr1 << expr2
```

é equivalente à multiplicação por 2<sup>expr2</sup>. Para os operadores Right Shift,

```C
expr1 >> expr2
```

é equivalente à divisão por 2<sup>expr2</sup> se `expr1` não estiver assinado ou tiver um valor não negativo.

O resultado de uma operação de deslocamento é indefinido se o segundo operando for negativo, ou se o operando à direita for maior ou igual à largura em bits do operando promovido à esquerda.

Como as conversões executadas pelos operadores Shift não fornecem condições de estouro ou estouro negativo, as informações poderão ser perdidas se o resultado de uma operação de deslocamento não puder ser representado no tipo do primeiro operando após a conversão.

```C
unsigned int x, y, z;

x = 0x00AA;
y = 0x5500;

z = ( x << 8 ) + ( y >> 8 );
```

Neste exemplo, `x` é deslocado para a esquerda oito posições e `y` é deslocado para a direita oito posições. Os valores deslocados são adicionados, resultando em 0xAA55 e atribuídos a `z`.

O deslocamento de um valor negativo para a direita gera a metade do valor original, arredondado para baixo. Por exemplo, -253 (binário 11111111 00000011) com o deslocamento para a direita de um de bit produz -127 (11111111 10000001). Um deslocamento positivo de 253 para a direita gera +126.

Os deslocamentos para a direita preservam o bit de sinal. Quando um inteiro assinado é deslocado para a direita, o bit mais significativo permanece definido. Quando um inteiro não assinado é deslocado para a direita, o bit mais significativo é limpo.

## <a name="see-also"></a>Consulte também

[Operadores de deslocamento à esquerda e deslocamento à direita (>> e <<)](../cpp/left-shift-and-right-shift-operators-input-and-output.md)