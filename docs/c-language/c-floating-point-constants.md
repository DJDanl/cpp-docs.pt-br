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
ms.openlocfilehash: 8777f04b047516ef29ae7bf67ddaf4195e3aaf6e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228018"
---
# <a name="c-floating-point-constants"></a>Constantes de ponto flutuante C

Uma "constante de ponto flutuante" é um número decimal que representa um número real assinado. A representação de um número real assinado inclui uma parte inteira, uma parte fracionária e um expoente. Use as constantes de ponto flutuante para representar os valores de ponto flutuante que não podem ser alterados.

## <a name="syntax"></a>Sintaxe

*floating-point-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*fractional-constant* *exponent-part*<sub>opt</sub> *floating-suffix*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence* *exponent-part* *floating-suffix*<sub>opt</sub>

*fractional-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*aceitar sequência de dígitos*<sub>opt</sub> **.** *digit-sequence*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sequência de dígitos*  **.**

*expoente – parte*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sequência de dígitos de* *sinal* **e** <sub>aceitação</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Sequência de dígitos de* *sinal* **E** <sub>aceitação</sub>

*sign*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**+ -**

*sequência de dígitos*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*dígito*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*digit-sequence* *digit*

*floating-suffix*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**f l F L**

Você pode omitir os dígitos anteriores ao ponto decimal (a parte inteira do valor) ou posteriores (a parte fracionária), mas não ambos. Você pode retirar o ponto decimal apenas se incluir um expoente. Nenhum caractere de espaço em branco pode separar os dígitos ou caracteres da constante.

Os exemplos a seguir ilustram alguns formatos de constantes de ponto flutuante e expressões:

```C
15.75
1.575E1   /* = 15.75   */
1575e-2   /* = 15.75   */
-2.5e-3   /* = -0.0025 */
25E-4     /* =  0.0025 */
```

As constantes de ponto flutuante são positivas, a menos que sejam precedidas por um sinal de subtração ( **-** ). Nesse caso, o sinal de subtração é tratado como um operador aritmético unário de negação. As constantes de ponto flutuante têm tipo **`float`** , **`double`** ou **`long double`** .

Uma constante de ponto flutuante sem um sufixo **f**, **f**, **l**ou **l** tem o tipo **`double`** . Se a letra **f** ou **f** for o sufixo, a constante terá o tipo **`float`** . Se for sufixado pela letra **l** ou **l**, ele terá o tipo **`long double`** . Por exemplo:

```C
10.0L  /* Has type long double  */
10.0F  /* Has type float        */
```

Observe que o compilador do Microsoft C representa internamente **`long double`** o mesmo que o tipo **`double`** . Consulte [armazenamento de tipos básicos](../c-language/storage-of-basic-types.md) para obter informações sobre o tipo **`double`** , **`float`** e **`long double`** .

Você pode omitir a parte inteira da constante de ponto flutuante, como mostrado nos seguintes exemplos. O número .75 pode ser expressado de várias maneiras, incluindo:

```C
.0075e2
0.075e1
.075e1
75e-2
```

## <a name="see-also"></a>Confira também

[Constantes C](../c-language/c-constants.md)
