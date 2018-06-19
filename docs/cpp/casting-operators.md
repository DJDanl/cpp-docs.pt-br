---
title: Operadores de conversão | Microsoft Docs
ms.custom: index-page
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], casting
- casting operators [C++]
ms.assetid: 16240348-26bc-4f77-8eab-57253f00ce52
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bf4204e55811cd33fa48e2b3a07d3058100729ac
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32411641"
---
# <a name="casting-operators"></a>Operadores de conversão
Há vários operadores de conversão específicos à linguagem C++. Esses operadores são destinados a remover qualquer ambiguidade e perigo inerente no estilo antigo de conversões da linguagem C. Esses operadores são:  
  
-   [dynamic_cast](../cpp/dynamic-cast-operator.md) usada para a conversão de tipos polimórficos.  
  
-   [static_cast](../cpp/static-cast-operator.md) usada para a conversão de tipos nonpolymorphic.  
  
-   [const_cast](../cpp/const-cast-operator.md) usado para remover o `const`, `volatile`, e `__unaligned` atributos.  
  
-   [reinterpret_cast](../cpp/reinterpret-cast-operator.md) usado para reinterpretation simple de bits.  
  
-   [Safe_cast](../windows/safe-cast-cpp-component-extensions.md) usado para gerar MSIL verificável.  
  
 Use `const_cast` e `reinterpret_cast` como último recurso, pois esses operadores apresentam os mesmos perigos das conversões antigas. No entanto, ainda são necessários para substituir completamente as conversões antigas.  
  
## <a name="see-also"></a>Consulte também  
 [Conversão](../cpp/casting.md)