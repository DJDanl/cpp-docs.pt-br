---
title: Selecionando um objeto gráfico em um contexto de dispositivo
ms.date: 11/04/2016
helpviewer_keywords:
- graphic objects [MFC], selecting into device context
- SelectObject method [MFC]
- GDI objects [MFC], device contexts
- lifetime, graphic objects [MFC]
- device contexts, selecting graphic objects into
- device contexts, graphic objects [MFC]
ms.assetid: cf54a330-63ef-421f-83eb-90ec7bd82eef
ms.openlocfilehash: 7fb1507c1200da4cdf44627557ff6993e927d51e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62308518"
---
# <a name="selecting-a-graphic-object-into-a-device-context"></a>Selecionando um objeto gráfico em um contexto de dispositivo

Este tópico aplica-se ao uso de objetos gráficos no contexto de dispositivo de uma janela. Depois que você [criar um objeto de desenho](../mfc/one-stage-and-two-stage-construction-of-objects.md), você deve selecioná-lo no contexto de dispositivo no lugar do objeto padrão armazenado lá:

[!code-cpp[NVC_MFCDocViewSDI#7](../mfc/codesnippet/cpp/selecting-a-graphic-object-into-a-device-context_1.cpp)]

## <a name="lifetime-of-graphic-objects"></a>Tempo de vida de objetos gráficos

O objeto gráfico retornado por [SelectObject](../mfc/reference/cdc-class.md#selectobject) é "temporário". Ou seja, ele será excluído pela [OnIdle](../mfc/reference/cwinapp-class.md#onidle) função de membro da classe `CWinApp` na próxima vez que o programa obtém ocioso de tempo. Desde que você use o objeto retornado por `SelectObject` em uma única função sem devolver o controle para o loop de mensagem principal, você não terá nenhum problema.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Objetos gráficos](../mfc/graphic-objects.md)

- [Construção de um e dois estágios de objetos gráficos](../mfc/one-stage-and-two-stage-construction-of-objects.md)

- [Contextos de dispositivo](../mfc/device-contexts.md)

- [Desenhando em uma exibição](../mfc/drawing-in-a-view.md)

## <a name="see-also"></a>Consulte também

[Objetos gráficos](../mfc/graphic-objects.md)
