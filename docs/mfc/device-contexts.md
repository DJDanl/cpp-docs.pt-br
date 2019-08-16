---
title: Contextos de dispositivo
ms.date: 11/04/2016
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
ms.openlocfilehash: d5337e8d8b83a641458a15612803feeec3b6361c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508664"
---
# <a name="device-contexts"></a>Contextos de dispositivo

Um contexto de dispositivo é uma estrutura de dados do Windows que contém informações sobre os atributos de desenho de um dispositivo, como uma exibição ou uma impressora. Todas as chamadas de desenho são feitas por meio de um objeto de contexto de dispositivo, que encapsula as APIs do Windows para desenhar linhas, formas e texto. Os contextos de dispositivo permitem o desenho independente de dispositivo no Windows. Contextos de dispositivo podem ser usados para desenhar a tela, para a impressora ou para um metarquivo.

Os objetos [CPaintDC](../mfc/reference/cpaintdc-class.md) encapsulam o idioma comum do Windows, chamando `BeginPaint` a função, depois desenhando no contexto do dispositivo e `EndPaint` , em seguida, chamando a função. O `CPaintDC` construtor chama `BeginPaint` para você e as chamadas `EndPaint`de destruidor. O processo simplificado é criar o objeto [CDC](../mfc/reference/cdc-class.md) , desenhar e, em seguida, `CDC` destruir o objeto. Na estrutura, muito de mesmo esse processo é automatizado. Em particular, sua `OnDraw` função é passada uma `CPaintDC` já preparada (via `OnPrepareDC`) e você simplesmente desenha nela. Ele é destruído pela estrutura e o contexto de dispositivo subjacente é liberado para o Windows no retorno da chamada para sua `OnDraw` função.

Os objetos [CClientDC](../mfc/reference/cclientdc-class.md) encapsulam o trabalho com um contexto de dispositivo que representa apenas a área do cliente de uma janela. O `CClientDC` construtor chama a `GetDC` função e o destruidor chama a `ReleaseDC` função. Os objetos [CWindowDC](../mfc/reference/cwindowdc-class.md) encapsulam um contexto de dispositivo que representa a janela inteira, incluindo seu quadro.

Os objetos [CMetaFileDC](../mfc/reference/cmetafiledc-class.md) encapsulam o desenho em um metarquivo do Windows. Em contraste com o `CPaintDC` passado para `OnDraw`, você deve, nesse caso, chamar [OnPrepareDC](../mfc/reference/cview-class.md#onpreparedc) por conta própria.

## <a name="mouse-drawing"></a>Desenho do mouse

A maior parte do desenho em um programa de estrutura — e, portanto, a maior parte do trabalho do `OnDraw` contexto do dispositivo — é feita na função de membro da exibição. No entanto, você ainda pode usar objetos de contexto de dispositivo para outras finalidades. Por exemplo, para fornecer comentários de acompanhamento para o movimento do mouse em uma exibição, você precisa desenhar diretamente na exibição sem esperar `OnDraw` para ser chamado.

Nesse caso, você pode usar um objeto de contexto de dispositivo [CClientDC](../mfc/reference/cclientdc-class.md) para desenhar diretamente na exibição.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Contextos de dispositivo (definição)](/windows/win32/gdi/device-contexts)

- [Desenhando em uma exibição](../mfc/drawing-in-a-view.md)

- [Interpretando a entrada do usuário por meio de uma exibição](../mfc/interpreting-user-input-through-a-view.md)

- [Linhas e curvas](/windows/win32/gdi/lines-and-curves)

- [Formas preenchidas](/windows/win32/gdi/filled-shapes)

- [Fontes e texto](/windows/win32/gdi/fonts-and-text)

- [Cores](/windows/win32/gdi/colors)

- [Coordenar espaços e transformações](/windows/win32/gdi/coordinate-spaces-and-transformations)

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)
