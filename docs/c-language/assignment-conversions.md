---
title: Conversões de atribuição
ms.date: 11/04/2016
helpviewer_keywords:
- conversions, assignment
- assignment conversions
ms.assetid: 4ee01013-de32-4aae-b12e-0051d0cde927
ms.openlocfilehash: cc75bdd8227c09247f6d4270f1fc21235de2eb05
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211834"
---
# <a name="assignment-conversions"></a>Conversões de atribuição

Em operações de atribuição, o tipo do valor que está sendo atribuído é convertido no tipo da variável que recebe a atribuição. O C permite conversões por atribuição entre os tipos integrais e flutuantes, mesmo se as informações forem perdidas na conversão. O método de conversão usado depende dos tipos envolvidos na atribuição, conforme descrito em [Conversões aritméticas comuns](../c-language/usual-arithmetic-conversions.md) e nas seguintes seções:

- [Conversões de tipos integrais com sinal](../c-language/conversions-from-signed-integral-types.md)

- [Conversões de tipos integrais sem sinal](../c-language/conversions-from-unsigned-integral-types.md)

- [Conversões de tipos de ponto flutuante](../c-language/conversions-from-floating-point-types.md)

- [Conversões de e em tipos de ponteiro](../c-language/conversions-to-and-from-pointer-types.md)

- [Conversões de outros tipos](../c-language/conversions-from-other-types.md)

Os qualificadores de tipo não afetam a permissão da conversão, embora um **`const`** l-value não possa ser usado no lado esquerdo da atribuição.

## <a name="see-also"></a>Confira também

[Conversões de tipo](../c-language/type-conversions-c.md)
