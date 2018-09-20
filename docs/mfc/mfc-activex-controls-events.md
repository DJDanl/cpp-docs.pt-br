---
title: 'Controles ActiveX MFC: Eventos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], events
- notifications [MFC], notifying containers of events
- custom events [MFC], adding to ActiveX controls
- events [MFC], mapping
- COleControl class [MFC], handling of events
- mappings [MFC], events
- stock events [MFC]
- container events [MFC]
- events [MFC], ActiveX controls
- OLE events [MFC]
ms.assetid: e1e57e0c-206b-4923-a0b5-682c26564f74
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a4c60c949832f03df6b7bb0e69cfdd95dfafc137
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46422864"
---
# <a name="mfc-activex-controls-events"></a>Controles ActiveX MFC: eventos

Controles ActiveX usam eventos para notificar um contêiner que algo aconteceu ao controle. Exemplos comuns de eventos incluem cliques no controle, dados inseridos usando o teclado e as alterações no estado do controle. Quando essas ações ocorrem, o controle dispara um evento para alertar o contêiner.

Eventos também são chamados de mensagens.

MFC dá suporte a dois tipos de eventos: estoque e personalizadas. Eventos de estoque são os eventos que a classe [COleControl](../mfc/reference/colecontrol-class.md) manipula automaticamente. Para obter uma lista completa de eventos de estoque, consulte o artigo [controles ActiveX MFC: adicionando eventos de estoque](../mfc/mfc-activex-controls-adding-stock-events-to-an-activex-control.md). Eventos personalizados permitem que um controle a capacidade de notificar o contêiner quando ocorre uma ação específica para esse controle. Alguns exemplos seriam uma alteração no estado interno de um controle ou no recebimento de uma determinada mensagem de janela.

Para o seu controle disparar eventos corretamente, sua classe de controle deve mapear cada evento do controle para uma função de membro que deve ser chamada quando ocorre o evento relacionado. Esse mecanismo de mapeamento (chamado de um mapa de eventos) centraliza informações sobre o evento e permite que o Visual Studio facilmente acessar e manipular os eventos do controle. Este mapa de evento é declarado com a seguinte macro, localizada no cabeçalho (. H) o arquivo da declaração de classe de controle:

[!code-cpp[NVC_MFC_AxUI#2](../mfc/codesnippet/cpp/mfc-activex-controls-events_1.h)]

Depois que o mapa de evento ter sido declarado, ele deve ser definido na implementação do seu controle (. Arquivo CPP). As seguintes linhas de código definem o mapa de evento, permitindo que seu controle acionar eventos específicos:

[!code-cpp[NVC_MFC_AxUI#3](../mfc/codesnippet/cpp/mfc-activex-controls-events_2.cpp)]
[!code-cpp[NVC_MFC_AxUI#4](../mfc/codesnippet/cpp/mfc-activex-controls-events_3.cpp)]

Se você usar o Assistente de controle de ActiveX do MFC para criar o projeto, ele automaticamente adiciona essas linhas. Se você não usar o Assistente de controle de ActiveX do MFC, você deve adicionar essas linhas manualmente.

Com o modo de exibição de classe, você pode adicionar eventos de estoque com suporte pela classe `COleControl` ou eventos personalizados que você definir. Para cada novo evento, modo de exibição de classe adiciona automaticamente a entrada apropriada para o mapa de evento do controle e o controle. Arquivo IDL.

Dois outros artigos abordam eventos detalhadamente:

- [Controles ActiveX MFC: Adicionando eventos de estoque](../mfc/mfc-activex-controls-adding-stock-events-to-an-activex-control.md)

- [Controles ActiveX do MFC: adicionando eventos personalizados](../mfc/mfc-activex-controls-adding-custom-events.md)

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
