---
title: Onde encontrar mapas de mensagens
ms.date: 11/04/2016
helpviewer_keywords:
- macros, message map
- locating message maps
- message classes [MFC], finding
- message-map macros
ms.assetid: bf59fbc8-b222-42d3-b5d3-0a79aa3cb923
ms.openlocfilehash: c50c6fc1134f579859530972dc864103c4e0ebcf
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907365"
---
# <a name="where-to-find-message-maps"></a>Onde encontrar mapas de mensagens

Quando você cria um novo aplicativo de esqueleto com o assistente de aplicativo, o assistente de aplicativo grava um mapa de mensagem para cada classe de destino de comando que ele cria para você. Isso inclui suas classes derivadas de aplicativo, documento, exibição e janela de quadro. Alguns desses mapas de mensagem já têm as entradas fornecidas pelo assistente de aplicativo para determinadas mensagens e comandos predefinidos, e alguns são apenas espaços reservados para manipuladores que você adicionará.

O mapa de mensagens de uma classe está localizado no. Arquivo CPP para a classe. Trabalhando com os mapas básicos de mensagens que o assistente de aplicativo cria, você usa o [Assistente de classe](reference/mfc-class-wizard.md) para adicionar entradas para as mensagens e comandos que cada classe manipulará. Um mapa de mensagem típico pode ser semelhante ao seguinte depois que você adicionar algumas entradas:

[!code-cpp[NVC_MFCMessageHandling#1](../mfc/codesnippet/cpp/where-to-find-message-maps_1.cpp)]

O mapa de mensagens consiste em uma coleção de macros. Duas macros, [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) e [END_MESSAGE_MAP](reference/message-map-macros-mfc.md#end_message_map), têm o mapa da mensagem. Outras macros, `ON_COMMAND`como, preencham o conteúdo do mapa da mensagem.

> [!NOTE]
>  As macros do mapa de mensagens não são seguidas por ponto e vírgula.

Quando você usa o assistente para adicionar classe para criar uma nova classe, ela fornece um mapa de mensagens para a classe. Como alternativa, você pode criar um mapa de mensagens manualmente usando o editor de código-fonte.

## <a name="see-also"></a>Consulte também

[Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)
