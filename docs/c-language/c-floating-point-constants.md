---
title: Constantes de ponto flutuante C
ms.date: 11/04/2016
helpviewer_keywords:
- types [C], constants
- floating-point numbers, floating-point constants
- constants, floating-point
- floating-point constants
- floating-point constants, about floating-point constants
- double data type, floating-point constants
ms.assetid: e1bd9b44-d6ab-470c-93e5-07142c7a2062
ms.openlocfilehash: d7879f3382016e098db0c8073322b99d596e8f83
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50664913"
---
# <a name="c-floating-point-constants"></a>Constantes de ponto flutuante C

Uma "constante de ponto flutuante" é um número decimal que representa um número real assinado. A representação de um número real assinado inclui uma parte inteira, uma parte fracionária e um expoente. Use as constantes de ponto flutuante para representar os valores de ponto flutuante que não podem ser alterados.

## <a name="syntax"></a>Sintaxe

*floating-point-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*fractional-constant* *exponent-part*<sub>opt</sub> *floating-suffix*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence* *exponent-part* *floating-suffix*<sub>opt</sub>

*fractional-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence*<sub>opt</sub> **.** *digit-sequence*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence*  **.**

*exponent-part*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**e** *sign*<sub>opt</sub> *digit-sequence*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**E** *sign*<sub>opt</sub> *digit-sequence*

*sign*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**+ -**

*digit-sequence*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence* *digit*

*floating-suffix*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**f l F L**

Você pode omitir os dígitos anteriores ao ponto decimal (a parte inteira do valor) ou posteriores (a parte fracionária), mas não ambos. Você pode retirar o ponto decimal apenas se incluir um expoente. Nenhum caractere de espaço em branco pode separar os dígitos ou caracteres da constante.

Os exemplos a seguir ilustram alguns formatos de constantes de ponto flutuante e expressões:

```
15.75
1.575E1   /* = 15.75   */
1575e-2   /* = 15.75   */
-2.5e-3   /* = -0.0025 */
25E-4     /* =  0.0025 */
```

As constantes de ponto flutuante são positivas a menos que sejam precedidas por um sinal de subtração (**-**). Nesse caso, o sinal de subtração é tratado como um operador aritmético unário de negação. As constantes de ponto flutuante têm o tipo `float`, `double` ou `long double`.

Uma constante de ponto flutuante sem **f**, **F**, **l** ou sufixo **L** tem o tipo `double`. Se a letra **f** ou **F** for o sufixo, a constante tem o tipo `float`. Se o sufixo for a letra **l** ou **L**, tem o tipo `long double`. Por exemplo:

```
100L  /* Has type long double  */
100F  /* Has type float        */
```

Observe que o compilador Microsoft C representa internamente `long double` o mesmo tipo `double`. Consulte [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md) para obter mais informações sobre os tipos `double`, `float` e `long double`.

Você pode omitir a parte inteira da constante de ponto flutuante, como mostrado nos seguintes exemplos. O número .75 pode ser expressado de várias maneiras, incluindo:

```
.0075e2
0.075e1
.075e1
75e-2
```

## <a name="see-also"></a>Consulte também

[Constantes C](../c-language/c-constants.md)
