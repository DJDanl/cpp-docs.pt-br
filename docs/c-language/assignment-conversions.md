---
title: Conversões de atribuição
ms.date: 11/04/2016
helpviewer_keywords:
- conversions, assignment
- assignment conversions
ms.assetid: 4ee01013-de32-4aae-b12e-0051d0cde927
ms.openlocfilehash: fb3da57af62171ef9670267f94f01ccc097e5942
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50649105"
---
# <a name="assignment-conversions"></a>Conversões de atribuição

Em operações de atribuição, o tipo do valor que está sendo atribuído é convertido no tipo da variável que recebe a atribuição. O C permite conversões por atribuição entre os tipos integrais e flutuantes, mesmo se as informações forem perdidas na conversão. O método de conversão usado depende dos tipos envolvidos na atribuição, conforme descrito em [Conversões aritméticas comuns](../c-language/usual-arithmetic-conversions.md) e nas seguintes seções:

- [Conversões de tipos integrais com sinal](../c-language/conversions-from-signed-integral-types.md)

- [Conversões de tipos integrais sem sinal](../c-language/conversions-from-unsigned-integral-types.md)

- [Conversões de tipos de ponto flutuante](../c-language/conversions-from-floating-point-types.md)

- [Conversões de e em tipos de ponteiro](../c-language/conversions-to-and-from-pointer-types.md)

- [Conversões de outros tipos](../c-language/conversions-from-other-types.md)

Os qualificadores de tipo não afetam o capacidade de conversão, embora um valor l **const** não possa ser usado no lado esquerdo da atribuição.

## <a name="see-also"></a>Consulte também

[Conversões de Tipo](../c-language/type-conversions-c.md)