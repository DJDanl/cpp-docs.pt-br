---
title: Conversões de atribuição
ms.date: 11/04/2016
helpviewer_keywords:
- conversions, assignment
- assignment conversions
ms.assetid: 4ee01013-de32-4aae-b12e-0051d0cde927
ms.openlocfilehash: f118c4a7fee493793b1410cb26f6a0af571c5fcc
ms.sourcegitcommit: c51b2c665849479fa995bc3323a22ebe79d9d7ce
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2019
ms.locfileid: "71998695"
---
# <a name="assignment-conversions"></a>Conversões de atribuição

Em operações de atribuição, o tipo do valor que está sendo atribuído é convertido no tipo da variável que recebe a atribuição. O C permite conversões por atribuição entre os tipos integrais e flutuantes, mesmo se as informações forem perdidas na conversão. O método de conversão usado depende dos tipos envolvidos na atribuição, conforme descrito em [Conversões aritméticas comuns](../c-language/usual-arithmetic-conversions.md) e nas seguintes seções:

- [Conversões de tipos integrais assinados](../c-language/conversions-from-signed-integral-types.md)

- [Conversões de tipos integral não assinados](../c-language/conversions-from-unsigned-integral-types.md)

- [Conversões de tipos de ponto flutuante](../c-language/conversions-from-floating-point-types.md)

- [Conversões de e para tipos de ponteiro](../c-language/conversions-to-and-from-pointer-types.md)

- [Conversões de outros tipos](../c-language/conversions-from-other-types.md)

Os qualificadores de tipo não afetam o capacidade de conversão, embora um valor l **const** não possa ser usado no lado esquerdo da atribuição.

## <a name="see-also"></a>Consulte também

[Conversões de tipo](../c-language/type-conversions-c.md)
