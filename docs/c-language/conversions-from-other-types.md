---
title: "Conversões de outros tipos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: cf77ffdca22d10f74e8f79b6e67eb120f85c92f0
ms.lasthandoff: 02/25/2017

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
