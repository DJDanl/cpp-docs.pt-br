---
title: Chamadas de função naked | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e395bcb32858bc63b3e848f20a7d794156876e26
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402023"
---
# <a name="naked-function-calls"></a>Chamadas de função naked
## <a name="microsoft-specific"></a>Específico da Microsoft  
 As funções declaradas com o **naked** atributo são emitidas sem código de prólogo ou epílogo, permitindo que você escrever suas próprias sequências de prólogo/epílogo personalizado usando o [assembler embutido](../assembler/inline/inline-assembler.md). As funções naked são fornecidas como um recurso avançado. Elas permitem declarar uma função que está sendo chamada de um contexto diferente de C/C++ e, portanto, fazer suposições diferentes sobre onde estão os parâmetros ou quais registros são preservados. Os exemplos incluem rotinas como manipuladores de interrupção. Esse recurso é particularmente útil para gravadores de drivers de dispositivos virtuais (VxDs).  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [naked](../cpp/naked-cpp.md)  
  
-   [Regras e limitações para funções naked](../cpp/rules-and-limitations-for-naked-functions.md)  
  
-   [Considerações para escrever código de prólogo-epílogo](../cpp/considerations-for-writing-prolog-epilog-code.md)  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de chamada](../cpp/calling-conventions.md)