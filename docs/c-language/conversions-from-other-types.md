---
title: "Conversões de outros tipos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
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
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: ed56c0c9ab3186200d3cbb47224dedc60adddb2f
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
