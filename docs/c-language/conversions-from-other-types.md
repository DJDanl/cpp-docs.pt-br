---
title: "Conversões de outros tipos | Microsoft Docs"
ms.custom: 
ms.date: 01/29/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- values, converting
- type casts, conversion
ms.assetid: 30fbd974-8f5a-4b70-ac44-d3937b96b702
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 30021ad4058eed7d9fbca31b8e3d3141a55987f2
ms.sourcegitcommit: 30ab99c775d99371ed22d1a46598e542012ed8c6
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/03/2018
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
