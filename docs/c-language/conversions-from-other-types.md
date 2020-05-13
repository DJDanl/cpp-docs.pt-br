---
title: Conversões de outros tipos
ms.date: 01/29/2018
helpviewer_keywords:
- values, converting
- type casts, conversion
ms.assetid: 30fbd974-8f5a-4b70-ac44-d3937b96b702
ms.openlocfilehash: f9f2d73e57c576dcf8afed008a74e5e7dd9b9d6f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62312460"
---
# <a name="conversions-from-other-types"></a>Conversões de outros tipos

Como um valor **enum** é um valor **int** por definição, as conversões de e para um valor **enum** são do mesmo tipo de **int**. Para o compilador Microsoft C, um inteiro é o mesmo que um **long**.

**Específico da Microsoft**

Nenhuma conversão entre os tipos de estrutura ou união é permitida.

Qualquer valor pode ser convertido no tipo **void**, mas o resultado dessa conversão pode ser usado somente em um contexto em que um valor da expressão é descartado, como em uma instrução expression.

O tipo **void** não tem valor, por definição. Portanto, não pode ser convertido em qualquer outro tipo, e outros tipos não podem ser convertidos em **void** por atribuição. Contudo, você pode converter explicitamente um valor no tipo **void**, como descrito em [Conversões de conversão de tipo](../c-language/type-cast-conversions.md).

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Conversões de atribuição](../c-language/assignment-conversions.md)
