---
title: 'Controles ActiveX MFC: eventos'
ms.date: 11/04/2016
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
ms.openlocfilehash: 129b805379fa68cb4f50ee1f8e3ac7d1b725d9ec
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622333"
---
# <a name="mfc-activex-controls-events"></a>Controles ActiveX MFC: eventos

Os controles ActiveX usam eventos para notificar um contêiner de que algo aconteceu com o controle. Exemplos comuns de eventos incluem cliques no controle, dados inseridos usando o teclado e alterações no estado do controle. Quando essas ações ocorrem, o controle dispara um evento para alertar o contêiner.

Os eventos também são chamados de mensagens.

O MFC dá suporte a dois tipos de eventos: estoque e personalizado. Os eventos de estoque são aqueles que a classe [COleControl](reference/colecontrol-class.md) manipula automaticamente. Para obter uma lista completa de eventos de estoque, consulte o artigo [controles ActiveX do MFC: adicionando eventos de estoque](mfc-activex-controls-adding-stock-events-to-an-activex-control.md). Os eventos personalizados permitem que um controle a capacidade de notificar o contêiner quando ocorre uma ação específica a esse controle. Alguns exemplos seriam uma alteração no estado interno de um controle ou recebimento de uma determinada mensagem de janela.

Para que seu controle acione eventos corretamente, sua classe Control deve mapear cada evento do controle para uma função membro que deve ser chamada quando o evento relacionado ocorrer. Esse mecanismo de mapeamento (chamado de mapa de eventos) centraliza informações sobre o evento e permite que o Visual Studio acesse e manipule facilmente os eventos do controle. Esse mapa de eventos é declarado pela macro a seguir, localizada no cabeçalho (. H) do arquivo da declaração de classe de controle:

[!code-cpp[NVC_MFC_AxUI#2](codesnippet/cpp/mfc-activex-controls-events_1.h)]

Depois que o mapa de eventos tiver sido declarado, ele deverá ser definido na implementação do seu controle (. CPP). As linhas de código a seguir definem o mapa de eventos, permitindo que seu controle dispare eventos específicos:

[!code-cpp[NVC_MFC_AxUI#3](codesnippet/cpp/mfc-activex-controls-events_2.cpp)]
[!code-cpp[NVC_MFC_AxUI#4](codesnippet/cpp/mfc-activex-controls-events_3.cpp)]

Se você usar o assistente de controle ActiveX do MFC para criar o projeto, ele adicionará automaticamente essas linhas. Se você não usar o assistente de controle ActiveX do MFC, deverá adicionar essas linhas manualmente.

Com Modo de Exibição de Classe, você pode adicionar eventos de estoque com suporte por classe `COleControl` ou eventos personalizados que você definir. Para cada novo evento, Modo de Exibição de Classe adiciona automaticamente a entrada apropriada ao mapa de eventos do controle e ao controle do. Arquivo IDL.

Dois outros artigos discutem eventos em detalhes:

- [Controles ActiveX do MFC: adicionando eventos de estoque](mfc-activex-controls-adding-stock-events-to-an-activex-control.md)

- [Controles ActiveX MFC: adicionando eventos personalizados](mfc-activex-controls-adding-custom-events.md)

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: métodos](mfc-activex-controls-methods.md)<br/>
[Classe COleControl](reference/colecontrol-class.md)
