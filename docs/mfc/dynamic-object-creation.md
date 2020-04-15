---
title: Criação de objeto dinâmico
ms.date: 03/27/2020
helpviewer_keywords:
- object creation [MFC], dynamically at run time
- CObject class [MFC], dynamic object creation
- objects [MFC], creating dynamically at run time
- dynamic object creation [MFC]
ms.assetid: 3e0f51cb-3e24-4231-817f-1c0ce9f2d5df
ms.openlocfilehash: 40a17d3ed458d0634fd5bf27b54d0a36a65e35b9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364803"
---
# <a name="dynamic-object-creation"></a>Criação de objeto dinâmico

Este artigo explica como criar um objeto dinamicamente em tempo de execução. O procedimento usa informações de classe em tempo de execução, conforme discutido no artigo [Acessando informações de classe de tempo de execução](../mfc/accessing-run-time-class-information.md).

#### <a name="dynamically-create-an-object-given-its-run-time-class"></a>Criar dinamicamente um objeto dada a sua classe de tempo de execução

1. Use o seguinte código para criar `CreateObject` dinamicamente um objeto usando a função do `CRuntimeClass`. No fracasso, `CreateObject` retorna **NULL** em vez de levantar uma exceção:

   [!code-cpp[NVC_MFCCObjectSample#6](../mfc/codesnippet/cpp/dynamic-object-creation_1.cpp)]

## <a name="see-also"></a>Confira também

[Destruindo objetos de janela](tn017-destroying-window-objects.md)
[usando cobject](using-cobject.md)
