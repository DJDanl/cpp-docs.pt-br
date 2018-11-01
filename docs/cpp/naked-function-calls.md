---
title: Chamadas de função naked
ms.date: 11/04/2016
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
ms.openlocfilehash: f9d8a8747d4a808d040b814005782ed8187bf274
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50528265"
---
# <a name="naked-function-calls"></a>Chamadas de função naked

## <a name="microsoft-specific"></a>Específico da Microsoft

As funções declaradas com o **naked** atributo são emitidas sem código de prólogo ou epílogo, permitindo que você escrever suas próprias sequências de prólogo/epílogo personalizado usando o [assembler embutido](../assembler/inline/inline-assembler.md). As funções naked são fornecidas como um recurso avançado. Elas permitem declarar uma função que está sendo chamada de um contexto diferente de C/C++ e, portanto, fazer suposições diferentes sobre onde estão os parâmetros ou quais registros são preservados. Os exemplos incluem rotinas como manipuladores de interrupção. Esse recurso é particularmente útil para gravadores de drivers de dispositivos virtuais (VxDs).

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [naked](../cpp/naked-cpp.md)

- [Regras e limitações para funções naked](../cpp/rules-and-limitations-for-naked-functions.md)

- [Considerações para escrever código de prólogo-epílogo](../cpp/considerations-for-writing-prolog-epilog-code.md)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Convenções de chamada](../cpp/calling-conventions.md)