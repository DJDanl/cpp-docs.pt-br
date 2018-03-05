---
title: "Chamadas de função naked | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- virtual device drivers
- VXD virtual device drivers
- virtual device drivers, naked function calls
- naked functions
- prolog code
- epilog code
- naked keyword [C++]
- naked keyword [C++], storage-class attribute
ms.assetid: 2a66847a-a43f-4541-a7be-c9f5f29b5fdb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: eed53718d211ac2152978c2a4d36e6a82c5c8024
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="naked-function-calls"></a>Chamadas de função naked
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Funções declaradas com o `naked` atributo são emitidos sem código de prólogo ou epílogo, permitindo que você escrever suas próprias sequências de prólogo/epílogo personalizado usando o [assembler embutido](../assembler/inline/inline-assembler.md). As funções naked são fornecidas como um recurso avançado. Elas permitem declarar uma função que está sendo chamada de um contexto diferente de C/C++ e, portanto, fazer suposições diferentes sobre onde estão os parâmetros ou quais registros são preservados. Os exemplos incluem rotinas como manipuladores de interrupção. Esse recurso é particularmente útil para gravadores de drivers de dispositivos virtuais (VxDs).  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [naked](../cpp/naked-cpp.md)  
  
-   [Regras e limitações para funções naked](../cpp/rules-and-limitations-for-naked-functions.md)  
  
-   [Considerações para escrever código de prólogo-epílogo](../cpp/considerations-for-writing-prolog-epilog-code.md)  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de chamada](../cpp/calling-conventions.md)