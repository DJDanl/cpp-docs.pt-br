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
ms.openlocfilehash: 9b49d34d7276d3c9260488f23d1821b9708d2481
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227316"
---
# <a name="naked-function-calls"></a>Chamadas de função naked

**Específico da Microsoft**

Funções declaradas com o **`naked`** atributo são emitidas sem o prólogo ou código epílogo, permitindo que você escreva suas próprias sequências de prólogo/epílogo personalizadas usando o [montador embutido](../assembler/inline/inline-assembler.md). As funções naked são fornecidas como um recurso avançado. Elas permitem declarar uma função que está sendo chamada de um contexto diferente de C/C++ e, portanto, fazer suposições diferentes sobre onde estão os parâmetros ou quais registros são preservados. Os exemplos incluem rotinas como manipuladores de interrupção. Esse recurso é particularmente útil para gravadores de drivers de dispositivos virtuais (VxDs).

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [naked](../cpp/naked-cpp.md)

- [Regras e limitações para funções Naked](../cpp/rules-and-limitations-for-naked-functions.md)

- [Considerações para escrever código prólogo/epílogo](../cpp/considerations-for-writing-prolog-epilog-code.md)

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Convenções de chamada](../cpp/calling-conventions.md)
