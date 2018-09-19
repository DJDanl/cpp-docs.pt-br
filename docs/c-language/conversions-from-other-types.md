---
title: Conversões de outros tipos | Microsoft Docs
ms.custom: ''
ms.date: 01/29/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- values, converting
- type casts, conversion
ms.assetid: 30fbd974-8f5a-4b70-ac44-d3937b96b702
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b443526248eb09accce8b35133235c71c06c2627
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46094573"
---
# <a name="conversions-from-other-types"></a>Conversões de outros tipos

Como um valor **enum** é um valor **int** por definição, as conversões de e para um valor **enum** são do mesmo tipo de **int**. Para o compilador Microsoft C, um inteiro é o mesmo que um **long**.

**Seção específica da Microsoft**

Nenhuma conversão entre os tipos de estrutura ou união é permitida.

Qualquer valor pode ser convertido no tipo **void**, mas o resultado dessa conversão pode ser usado somente em um contexto em que um valor da expressão é descartado, como em uma instrução expression.

O tipo **void** não tem valor, por definição. Portanto, não pode ser convertido em qualquer outro tipo, e outros tipos não podem ser convertidos em **void** por atribuição. Contudo, você pode converter explicitamente um valor no tipo **void**, como descrito em [Conversões de conversão de tipo](../c-language/type-cast-conversions.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Conversões de atribuição](../c-language/assignment-conversions.md)
