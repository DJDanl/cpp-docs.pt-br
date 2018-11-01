---
title: Criação de objeto dinâmico
ms.date: 11/04/2016
helpviewer_keywords:
- object creation [MFC], dynamically at run time
- CObject class [MFC], dynamic object creation
- objects [MFC], creating dynamically at run time
- dynamic object creation [MFC]
ms.assetid: 3e0f51cb-3e24-4231-817f-1c0ce9f2d5df
ms.openlocfilehash: 75d4a055f047abfcac4451c04bcd1cc75650c89a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50563716"
---
# <a name="dynamic-object-creation"></a>Criação de objeto dinâmico

Este artigo explica como criar um objeto dinamicamente em tempo de execução. O procedimento usa informações de classe de tempo de execução, conforme discutido no artigo [acessando informações de classe de tempo de execução](../mfc/accessing-run-time-class-information.md).

#### <a name="to-dynamically-create-an-object-given-its-run-time-class"></a>Para criar dinamicamente um objeto, considerando sua classe de tempo de execução

1. Use o seguinte código para criar dinamicamente um objeto usando o `CreateObject` função do `CRuntimeClass`. Observe que, em caso de falha, `CreateObject` retorna **nulo** em vez de gerar uma exceção:

   [!code-cpp[NVC_MFCCObjectSample#6](../mfc/codesnippet/cpp/dynamic-object-creation_1.cpp)]

## <a name="see-also"></a>Consulte também

[Usando CObject](../mfc/using-cobject.md)

