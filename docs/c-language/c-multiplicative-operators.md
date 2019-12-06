---
title: Operadores multiplicativos C
ms.date: 11/04/2016
helpviewer_keywords:
- arithmetic operators [C++], multiplicative operators
- / operator
- / operator, multiplicative operators
- remainder operator (%)
- operators [C], multiplication
- '% operator'
- slash (/) operator
- multiplication operator [C++], multiplicative operators
ms.assetid: 495471c9-319b-4eb4-bd97-039a025fd3a9
ms.openlocfilehash: e06ef25c14f8073d2b8753b57c9593af7bb6c69f
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857119"
---
# <a name="c-multiplicative-operators"></a>Operadores multiplicativos C

Os operadores multiplicativos executam operações de multiplicação (<strong>\*</strong>), divisão ( **/** ) e restante ( **%** ).

## <a name="syntax"></a>Sintaxe

*multiplicative-expression*: &nbsp;&nbsp;&nbsp;&nbsp;*cast-expression* &nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression* <strong>\*</strong> *cast-expression* &nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression* **/** *cast-expression* &nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression* **%** *cast-expression*

Os operandos do operador de restante ( **%** ) devem ser integrais. Os operadores de multiplicação (<strong>\*</strong>) e de divisão ( **/** ) podem usar operandos do tipo integral ou flutuante; os tipos dos operandos podem ser diferentes.

Os operadores multiplicativos executam as conversões aritméticas comuns nos operandos. O tipo do resultado é o tipo dos operandos após conversão.

> [!NOTE]
>  Uma vez que as conversões executadas pelos operadores de multiplicação não fornecem condições de estouro ou estouro negativo, as informações poderão ser perdidas se o resultado de uma operação de multiplicação não puder ser representado no tipo dos operandos após a conversão.

Os operadores multiplicativos C são descritos abaixo:

|Operador|Descrição|
|--------------|-----------------|
|<strong>\*</strong>|O operador de multiplicação faz com que dois operandos sejam multiplicados.|
|**/**|O operador de divisão faz com que o primeiro operando seja dividido pelo segundo. Se dois operandos de inteiro forem divididos e o resultado não for um inteiro, ele será truncado de acordo com as seguintes regras:<br/><br/>- O resultado da divisão por 0 é indefinida de acordo com o padrão ANSI C. O compilador do Microsoft C gera um erro no tempo de compilação ou no tempo de execução.<br/><br/>- Se ambos os operandos forem positivos ou sem sinal, o resultado será truncado para 0.<br/><br/>- Se qualquer operando for negativo, se o resultado da operação for o maior inteiro menor ou igual ao quociente algébrico ou o menor inteiro maior ou igual ao quociente algébrico, ele será definido pela implementação. (Consulte a seção específica da Microsoft abaixo.)|
|**%**|O resultado do operador de restante é o restante quando o primeiro operando é dividido pelo segundo. Quando a divisão não é exata, o resultado é determinado pelas seguintes regras:<br/><br/>- Se o operando da direita for zero, o resultado será indefinido.<br/><br/>- Se ambos os operandos forem positivos ou sem sinal, o resultado será positivo.<br/><br/>- Se qualquer operando for negativo e o resultado não for exato, o resultado será definido para implementação. (Consulte a seção específica da Microsoft abaixo.)|

### <a name="microsoft-specific"></a>Específico da Microsoft

A divisão onde qualquer operando é negativo, a direção de truncamento é sentido a 0.

Se uma ou outra operação for negativa na divisão com o operador de restante, o resultado terá o mesmo sinal do dividendo (o primeiro operando na expressão).

## <a name="examples"></a>Exemplos

As declarações mostradas abaixo são usadas para os exemplos a seguir:

```
int i = 10, j = 3, n;
double x = 2.0, y;
```

Esta instrução usa o operador de multiplicação:

```
y = x * i;
```

Nesse caso, `x` é multiplicado por `i` para fornecer o valor 20,0. O resultado tem o tipo **double**.

```
n = i / j;
```

Nesse exemplo, 10 é dividido por 3. O resultado é truncado para 0, gerando um valor inteiro 3.

```
n = i % j;
```

Essa instrução aloca a `n` ao restante inteiro, 1, quando 10 é dividido por 3.

**Seção específica da Microsoft**

O sinal do restante é o mesmo sinal do dividendo. Por exemplo:

```
50 % -6 = 2
-50 % 6 = -2
```

Em cada caso, `50` e `2` têm o mesmo sinal.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Operadores multiplicativos e o operador de módulo](../cpp/multiplicative-operators-and-the-modulus-operator.md)
