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
ms.openlocfilehash: 242fe83807c6608a09492d0f1f817e3b6e50e530
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857392"
---
# <a name="naked-function-calls"></a>Chamadas de função naked

**Seção específica da Microsoft**

As funções declaradas com o atributo **Naked** são emitidas sem o prólogo ou código epílogo, permitindo que você escreva suas próprias sequências de prólogo/epílogo personalizadas usando o [montador embutido](../assembler/inline/inline-assembler.md). As funções naked são fornecidas como um recurso avançado. Elas permitem declarar uma função que está sendo chamada de um contexto diferente de C/C++ e, portanto, fazer suposições diferentes sobre onde estão os parâmetros ou quais registros são preservados. Os exemplos incluem rotinas como manipuladores de interrupção. Esse recurso é particularmente útil para gravadores de drivers de dispositivos virtuais (VxDs).

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [naked](../cpp/naked-cpp.md)

- [Regras e limitações para funções naked](../cpp/rules-and-limitations-for-naked-functions.md)

- [Considerações para escrever código de prólogo-epílogo](../cpp/considerations-for-writing-prolog-epilog-code.md)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Convenções de chamada](../cpp/calling-conventions.md)