---
title: "Operadores de conversão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: 'index-page '
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], casting
- casting operators [C++]
ms.assetid: 16240348-26bc-4f77-8eab-57253f00ce52
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: a516297b687db349a6bcc867fc94dcd85118a8a5
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
