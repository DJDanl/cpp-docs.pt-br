---
title: Quando inicializar objetos CWnd
ms.date: 11/04/2016
helpviewer_keywords:
- window objects [MFC], when to initialize CWnd
- initializing CWnd objects [MFC]
- initializing objects [MFC], CWnd
- CWnd objects [MFC], when HWND is attached
- HWND, when attached to CWnd object
- CWnd objects [MFC], when to initialize
ms.assetid: 4d31bcb1-73db-4f2f-b71c-89b087569a10
ms.openlocfilehash: c75745547846fbf6c7e01ecf473d4d6f366bd264
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548541"
---
# <a name="when-to-initialize-cwnd-objects"></a>Quando inicializar objetos CWnd

Você não pode criar seu próprio filho do windows ou chamar quaisquer funções de API do Windows no construtor de uma `CWnd`-objeto derivado. Isso ocorre porque o `HWND` para o `CWnd` objeto ainda não foi criado. Inicialização do Windows mais específicos, como a adição de janelas filho, deve ser feita em uma [OnCreate](../mfc/reference/cwnd-class.md#oncreate) manipulador de mensagens.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Criando janelas com moldura de documento](../mfc/creating-document-frame-windows.md)

- [Criação de documento/exibição](../mfc/document-view-creation.md)

## <a name="see-also"></a>Consulte também

[Usando janelas com moldura](../mfc/using-frame-windows.md)

