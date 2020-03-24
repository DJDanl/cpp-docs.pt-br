---
title: Operadores bit a bit C
ms.date: 01/29/2018
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
ms.openlocfilehash: 50be8ae38f21d0a9f46c180abf179e1358b707cd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168767"
---
# <a name="c-bitwise-operators"></a>Operadores bit a bit C

Os operadores bit a bit executam as operações E bit a bit ( **&** ), OR exclusivo bit a bit ( **^** ) e OR inclusivo bit a bit ( **&#124;** ).

## <a name="syntax"></a>Sintaxe

*Expressão and*: &nbsp;&nbsp;*expressão de igualdade* &nbsp;&nbsp;*e-* Expression **&** *expressão de igualdade*

*Exclusive-ou-Expression*: &nbsp;&nbsp;*e-Expression* &nbsp;&nbsp;expressão- *ou-* **^** de expressão *and* exclusivas

*inclusivo-ou-expressão*: &nbsp;&nbsp;*expressão exclusiva* &nbsp;&nbsp;uma expressão de *inclusão* &#124; ou expressão *exclusiva*

Os operandos dos operadores bit a bit devem ter tipos integrais, mas seus tipos podem ser diferentes. Esses operadores executam conversões aritméticas comuns; o tipo do resultado é o tipo dos operandos após a conversão.

Os operadores bit a bit de C são descritos abaixo:

|Operador|DESCRIÇÃO|
|--------------|-----------------|
|**&**|O operador AND bit a bit compara cada bit do primeiro operando com o bit correspondente de seu segundo operando. Se ambos os bits forem 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente é definido como zero (0).|
|**^**|O operador OR exclusivo bit a bit compara cada bit do primeiro operando ao bit correspondente do seu segundo operando. Se um bit for 0 e o outro bit for 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente é definido como zero (0).|
|**&#124;**|O operador OR inclusivo bit a bit compara cada bit do primeiro operando com o bit correspondente de seu segundo operando. Se qualquer bit for 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente é definido como zero (0).|

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

## <a name="see-also"></a>Confira também

[Operador AND bit a bit: &](../cpp/bitwise-and-operator-amp.md)<br/>
[Operador OR exclusivo bit a bit: ^](../cpp/bitwise-exclusive-or-operator-hat.md)<br/>
[Bitwise Inclusive OR Operator: &#124;](../cpp/bitwise-inclusive-or-operator-pipe.md)
