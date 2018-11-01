---
title: Trabalhando com objetos de janela
ms.date: 11/04/2016
helpviewer_keywords:
- child windows [MFC], working with
- window objects [MFC], working with
ms.assetid: f73aa254-90e3-46a9-8e9b-d78b7054a331
ms.openlocfilehash: 66656fceec2005f7e789bf1cd68ffe52651aacc7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50526526"
---
# <a name="working-with-window-objects"></a>Trabalhando com objetos de janela

Trabalhando com chamadas de windows para dois tipos de atividade:

- Tratamento de mensagens do Windows

- Na janela de desenho

Para tratar mensagens do Windows em qualquer janela, incluindo suas próprias janelas filho, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md) para mapear as mensagens à sua classe de janela C++. Em seguida, escreva manipulador de mensagens funções de membro em sua classe.

A maioria dos desenhando em um aplicativo framework ocorre no modo de exibição, cuja [OnDraw](../mfc/reference/cview-class.md#ondraw) função de membro é chamada sempre que o conteúdo da janela deve ser desenhado. Se a janela é um filho do modo de exibição, você pode delegar algumas das desenho do modo de exibição para a janela filho tendo `OnDraw` chamar uma das funções de membro da sua janela.

Em qualquer caso, você precisará de um contexto de dispositivo para o desenho. Você pode usar a caneta de estoque, Pincel e outros objetos gráficos contidos no contexto de dispositivo associado a sua janela. Ou você pode modificar esses objetos para obter os efeitos de desenho que você precisa. Com o seu contexto de dispositivo configurado como desejar, chame funções membro da classe [CDC](../mfc/reference/cdc-class.md) (classe de contexto de dispositivo) para desenhar linhas, formas e texto; Use cores; e para trabalhar com um sistema de coordenadas.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Mapeamento e manipulação de mensagens](../mfc/message-handling-and-mapping.md)

- [Desenhando uma exibição](../mfc/drawing-in-a-view.md)

- [Contextos de dispositivo](../mfc/device-contexts.md)

- [Objetos gráficos](../mfc/graphic-objects.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)

