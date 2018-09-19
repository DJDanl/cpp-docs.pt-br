---
title: Conversões de atribuição | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- conversions, assignment
- assignment conversions
ms.assetid: 4ee01013-de32-4aae-b12e-0051d0cde927
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 90e77f4bd1eddaa11762b9449a54cb7127498bae
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46038174"
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