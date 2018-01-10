---
title: "Conversões de outros tipos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- values, converting
- type casts, conversion
ms.assetid: 30fbd974-8f5a-4b70-ac44-d3937b96b702
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8dbf2d3d269f5df3a028a5c416f8adca015be6dd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="conversions-from-other-types"></a>Conversões de outros tipos
Como um valor `enum` é um valor `int` por definição, as conversões de e para um valor `enum` são do mesmo tipo de `int`. Para o compilador Microsoft C, um inteiro é o mesmo que um **long**.  
  
 **Seção específica da Microsoft**  
  
 Nenhuma conversão entre os tipos de estrutura ou união é permitida.  
  
 Qualquer valor pode ser convertido no tipo `void`, mas o resultado dessa conversão pode ser usado somente em um contexto onde um valor da expressão é descartado, como em uma instrução expression.  
  
 O tipo `void` não tem valor, por definição. Portanto, não pode ser convertido em qualquer outro tipo, e outros tipos não podem ser convertidos em `void` por atribuição. Contudo, você pode converter explicitamente um valor no tipo `void`, como descrito em [Conversões Type-Cast](../c-language/type-cast-conversions.md).  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Conversões de atribuição](../c-language/assignment-conversions.md)