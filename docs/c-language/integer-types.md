---
title: Tipos de inteiro
ms.date: 07/22/2020
helpviewer_keywords:
- integer data type, integer types in C++
- integer constants
- integer types
- integers, types
ms.assetid: c8926a5e-0e98-4e37-9b05-ce97961379bd
ms.openlocfilehash: 61ed64c613bc88ed5bf62999ba77fa4090c1ec4a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211795"
---
# <a name="integer-types"></a>Tipos de inteiro

Cada constante de inteiro recebe um tipo com base em seu valor e a forma como é expressa. Você pode forçar qualquer constante de inteiro para tipo **`long`** acrescentando a letra **`l`** ou **`L`** ao final da constante; você pode forçá-la a ser tipo **`unsigned`** acrescentando **`u`** ou **`U`** ao valor. A letra minúscula **`l`** pode ser confundida com o dígito 1 e deve ser evitada. Seguem algumas formas de **`long`** constantes de inteiro:

```C
/* Long decimal constants */
10L
79L

/* Long octal constants */
012L
0115L

/* Long hexadecimal constants */
0xaL or 0xAL
0X4fL or 0x4FL

/* Unsigned long decimal constant */
776745UL
778866LU
```

O tipo que você atribui a uma constante depende do valor que a constante representa. O valor de uma constante deve estar no intervalo de valores representáveis para o seu tipo. O tipo de uma constante determina quais conversões são executadas quando a constante é usada em uma expressão ou quando o sinal de subtração ( **`-`** ) é aplicado. Esta lista resume as regras de conversão para constantes de número inteiro.

- O tipo de uma constante decimal sem um sufixo é **`int`** , **`long int`** ou **`unsigned long int`** . O primeiro destes três tipos em que o valor da constante pode ser representado é o tipo atribuído à constante.

- O tipo atribuído às constantes octais e hexadecimal sem sufixos é **`int`** , **`unsigned int`** , **`long int`** ou **`unsigned long int`** dependendo do tamanho da constante.

- O tipo atribuído a constantes com um **`u`** **`U`** sufixo or é **`unsigned int`** ou **`unsigned long int`** dependendo do seu tamanho.

- O tipo atribuído a constantes com um **`l`** **`L`** sufixo or é **`long int`** ou **`unsigned long int`** dependendo do seu tamanho.

- O tipo atribuído a constantes com um **`u`** or **`U`** e um **`l`** **`L`** sufixo or é **`unsigned long int`** .

## <a name="see-also"></a>Confira também

[Constantes de inteiro C](../c-language/c-integer-constants.md)
