---
title: Conversões de outros tipos
ms.date: 01/29/2018
helpviewer_keywords:
- values, converting
- type casts, conversion
ms.assetid: 30fbd974-8f5a-4b70-ac44-d3937b96b702
ms.openlocfilehash: bd00bbb8944a0273163fa0c5952be510c9dd697c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87200329"
---
# <a name="conversions-from-other-types"></a>Conversões de outros tipos

Como um **`enum`** valor é um **`int`** valor por definição, conversões de e para um **`enum`** valor são as mesmas do **`int`** tipo. Para o compilador do Microsoft C, um inteiro é o mesmo que um **`long`** .

**Específico da Microsoft**

Nenhuma conversão entre os tipos de estrutura ou união é permitida.

Qualquer valor pode ser convertido para **`void`** o tipo, mas o resultado de tal conversão pode ser usado somente em um contexto em que um valor de expressão é Descartado, como em uma instrução de expressão.

O **`void`** tipo não tem valor, por definição. Portanto, ele não pode ser convertido em nenhum outro tipo, e outros tipos não podem ser convertidos **`void`** por atribuição. No entanto, você pode converter explicitamente um valor para tipo **`void`** , como discutido em [conversões de conversão de tipo](../c-language/type-cast-conversions.md).

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Conversões de atribuição](../c-language/assignment-conversions.md)
