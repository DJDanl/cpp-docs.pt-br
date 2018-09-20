---
title: Contextos de dispositivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OnPrepareDC method [MFC]
- windows [MFC], and device context
- drawing [MFC], device context
- CClientDC class [MFC], and GetDC method [MFC]
- drawing [MFC], in mouse and device contexts
- CDC class [MFC], objects
- device contexts [MFC]
- client areas
- CMetaFileDC class [MFC], and OnPrepareDC method [MFC]
- GDI objects [MFC], device contexts
- graphic objects [MFC], device contexts
- frame windows [MFC], device contexts
- metafiles and device contexts
- EndPaint method [MFC]
- printers [MFC], device contexts
- mouse [MFC], drawing and device contexts
- BeginPaint method, CPaintDC
- CPaintDC class [MFC], device context for painting
- windows [MFC], drawing directly into
- client areas, and device context
- device contexts [MFC], CDC class [MFC]
- user interface [MFC], device contexts
- device-independent drawing
- GetDC method and CClientDC class [MFC]
- CClientDC class [MFC], and ReleaseDC method [MFC]
- ReleaseDC method [MFC]
- device contexts [MFC], about device contexts
- drawing [MFC], directly into windows
- painting and device context
ms.assetid: d0cd51f1-f778-4c7e-bf50-d738d10433c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 27203b5b93d69c29df29e64f872efb8e5f1828e1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46437632"
---
# <a name="device-contexts"></a>Contextos de dispositivo

Um contexto de dispositivo é uma estrutura de dados do Windows que contém informações sobre os atributos de desenho de um dispositivo, como uma exibição ou uma impressora. Todas as chamadas de desenho são feitas por meio de um objeto de contexto de dispositivo, que encapsula as APIs do Windows para o desenho de linhas, formas e texto. Contextos de dispositivo permitem que o desenho independente de dispositivo no Windows. Contextos de dispositivo podem ser usados para desenhar na tela, para a impressora ou a um metarquivo.

[CPaintDC](../mfc/reference/cpaintdc-class.md) objetos encapsulam a linguagem comum do Windows, chamando o `BeginPaint` função, em seguida, desenhando no contexto de dispositivo e chamar o `EndPaint` função. O `CPaintDC` chamadas de construtor `BeginPaint` para você e o destruidor chama `EndPaint`. O processo simplificado é criar o [CDC](../mfc/reference/cdc-class.md) do objeto, desenhar e, em seguida, destrua o `CDC` objeto. No framework, grande parte do mesmo esse processo é automatizado. Em particular, sua `OnDraw` função é passada uma `CPaintDC` já foi preparado (via `OnPrepareDC`), e você simplesmente desenha nele. Ele é destruído pelo framework e o contexto de dispositivo subjacente é liberado para o Windows após o retorno da chamada para seu `OnDraw` função.

[CClientDC](../mfc/reference/cclientdc-class.md) objetos encapsulam trabalhar com um contexto de dispositivo que representa apenas a área de cliente de uma janela. O `CClientDC` construtor chama o `GetDC` função e o destruidor chama o `ReleaseDC` função. [CWindowDC](../mfc/reference/cwindowdc-class.md) objetos encapsulam um contexto de dispositivo que representa a janela inteira, incluindo seu quadro.

[CMetaFileDC](../mfc/reference/cmetafiledc-class.md) encapsulam a objetos de desenho em um metarquivo do Windows. Em contraste com o `CPaintDC` passado para `OnDraw`, nesse caso, você deve chamar [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc) por conta própria.

## <a name="mouse-drawing"></a>Desenho de mouse

Desenhando a maioria em um programa do framework — e, portanto, a maioria dos trabalho de contexto de dispositivo — é feito no modo de exibição `OnDraw` função de membro. No entanto, você ainda pode usar objetos de contexto de dispositivo para outras finalidades. Por exemplo, para fornecer comentários de acompanhamento de movimento do mouse em uma exibição, você precisa desenhar diretamente na exibição sem aguardar `OnDraw` a ser chamado.

Nesse caso, você pode usar um [CClientDC](../mfc/reference/cclientdc-class.md) objeto de contexto de dispositivo para desenhar diretamente na exibição.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Contextos de dispositivo (definição)](https://msdn.microsoft.com/library/windows/desktop/dd183553)

- [Desenhando em uma exibição](../mfc/drawing-in-a-view.md)

- [Interpretando a entrada do usuário por meio de uma exibição](../mfc/interpreting-user-input-through-a-view.md)

- [Linhas e curvas](https://msdn.microsoft.com/library/windows/desktop/dd145028)

- [Formas preenchidas](https://msdn.microsoft.com/library/windows/desktop/dd162714)

- [Fontes e texto](/windows/desktop/gdi/fonts-and-text)

- [Cores](https://msdn.microsoft.com/library/windows/desktop/dd183450)

- [Espaços de coordenadas e transformações](https://msdn.microsoft.com/library/windows/desktop/dd183475)

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)

