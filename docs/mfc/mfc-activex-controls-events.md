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
ms.openlocfilehash: e6c8ee059b4136ce1504117246abd12ac74a6233
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33348384"
---
# <a name="mfc-activex-controls-events"></a>Controles ActiveX MFC: eventos
Controles ActiveX usam eventos para notificar um contêiner que algo aconteceu com o controle. Exemplos comuns de eventos incluem cliques no controle, dados inseridos usando o teclado e as alterações no estado do controle. Quando essas ações ocorrem, o controle dispara um evento para alertar o contêiner.  
  
 Eventos também são chamados de mensagens.  
  
 MFC dá suporte a dois tipos de eventos: personalizados e ações. Eventos de estoque são os eventos que classe [COleControl](../mfc/reference/colecontrol-class.md) manipula automaticamente. Para obter uma lista completa de eventos de estoque, consulte o artigo [controles ActiveX MFC: adicionando eventos de estoque](../mfc/mfc-activex-controls-adding-stock-events-to-an-activex-control.md). Eventos personalizados permitem que um controle a capacidade notificar o contêiner quando ocorre uma ação específica para esse controle. Alguns exemplos seria uma alteração no estado interno de um controle ou no recebimento de uma determinada mensagem de janela.  
  
 Para o controle disparar eventos corretamente, sua classe de controle deve mapear cada evento do controle para uma função de membro que deve ser chamada quando ocorre o evento relacionado. Esse mecanismo de mapeamento (chamado de um mapa de eventos) centraliza informações sobre o evento e permite que o Visual Studio acessar facilmente e manipular eventos de controle. Este mapa de evento é declarado com a macro a seguir, localizada no cabeçalho (. H) o arquivo da declaração de classe do controle:  
  
 [!code-cpp[NVC_MFC_AxUI#2](../mfc/codesnippet/cpp/mfc-activex-controls-events_1.h)]  
  
 Após ter sido declarado do mapa de evento, ele deverá ser definido na implementação do controle (. Arquivo CPP). Linhas de código a seguir definem o mapa de evento, permitindo que o controle para acionar eventos específicos:  
  
 [!code-cpp[NVC_MFC_AxUI#3](../mfc/codesnippet/cpp/mfc-activex-controls-events_2.cpp)]  
[!code-cpp[NVC_MFC_AxUI#4](../mfc/codesnippet/cpp/mfc-activex-controls-events_3.cpp)]  
  
 Se você usar o Assistente de controle ActiveX MFC para criar o projeto, ele adiciona automaticamente essas linhas. Se você não usar o Assistente de controle ActiveX MFC, você deve adicionar essas linhas manualmente.  
  
 Com a exibição de classe, você pode adicionar suportados pela classe de eventos de estoque `COleControl` ou eventos personalizados que você definir. Para cada novo evento, o modo de exibição de classe adiciona automaticamente a entrada correta para mapa de evento do controle e o controle. Arquivo IDL.  
  
 Dois outros artigos discutem eventos detalhadamente:  
  
-   [Controles ActiveX MFC: Adicionando eventos de estoque](../mfc/mfc-activex-controls-adding-stock-events-to-an-activex-control.md)  
  
-   [Controles ActiveX do MFC: adicionando eventos personalizados](../mfc/mfc-activex-controls-adding-custom-events.md)  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md)   
 [Classe COleControl](../mfc/reference/colecontrol-class.md)
