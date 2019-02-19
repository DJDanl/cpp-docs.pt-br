---
title: Tipos de inteiro
ms.date: 11/04/2016
helpviewer_keywords:
- integer data type, integer types in C++
- integer constants
- integer types
- integers, types
ms.assetid: c8926a5e-0e98-4e37-9b05-ce97961379bd
ms.openlocfilehash: 23da055b56e2ae77fed796d9ba8e7f227e572a9f
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56146873"
---
# <a name="integer-types"></a>Tipos de inteiro

Cada constante de inteiro recebe um tipo baseado no seu valor e na forma como é expressa. Qualquer constante inteira pode ser forçada para o tipo **long** anexando a letra **l** ou **L** ao final da constante; é possível forçá-la para o tipo `unsigned` anexando **u** ou **U** ao valor. A letra minúscula **l** pode ser confundida com o dígito 1 e deve ser evitada. Estas são algumas formas de constantes de inteiro de **long**:

```
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

O tipo que você atribui a uma constante depende do valor que a constante representa. O valor de uma constante deve estar no intervalo de valores representáveis para o seu tipo. Um tipo de constante que determina quais conversões são executadas quando a constante é usada em uma expressão ou quando o sinal de subtração (**-**) é aplicado. Esta lista resume as regras de conversão para constantes de número inteiro.

- O tipo de constante decimal sem sufixo é `int`, **long int** ou **unsigned long int**. O primeiro destes três tipos em que o valor da constante pode ser representado é o tipo atribuído à constante.

- O tipo atribuído às constantes octais e hexadecimais sem sufixos é `int`, `unsigned int`, **long int** ou **unsigned long int**, dependendo do tamanho da constante.

- O tipo atribuído às constantes com sufixo **u** ou **U** é **unsigned int** ou **unsigned long int**, dependendo do tamanho.

- O tipo atribuído às constantes com sufixo **l** ou **L** é **long int** ou **unsigned long int**, dependendo do tamanho.

- O tipo atribuído às constantes com sufixo **u** ou **U** e **l** ou **L** é **unsigned long int**.

## <a name="see-also"></a>Consulte também

[Constantes de inteiro C](../c-language/c-integer-constants.md)
