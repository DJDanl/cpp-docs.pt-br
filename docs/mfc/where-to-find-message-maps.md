---
title: Onde encontrar mapas de mensagens
ms.date: 11/04/2016
helpviewer_keywords:
- macros, message map
- locating message maps
- message classes [MFC], finding
- message-map macros
ms.assetid: bf59fbc8-b222-42d3-b5d3-0a79aa3cb923
ms.openlocfilehash: eec0ae43546e3cc0c08e3178c4808e21fa48686a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360160"
---
# <a name="where-to-find-message-maps"></a>Onde encontrar mapas de mensagens

Quando você cria um novo aplicativo esqueleto com o Assistente de Aplicativo, o Assistente de Aplicativo grava um mapa de mensagem para cada classe de destino de comando que ele cria para você. Isso inclui as classes de aplicativo, documento, exibição e janela de quadros derivadas. Alguns desses mapas de mensagem já têm as entradas fornecidas pelo Assistente de Aplicativo para determinadas mensagens e comandos predefinidos, e alguns são apenas espaços reservados para manipuladores que você adicionará.

O mapa de mensagens de uma classe está localizado no . Arquivo CPP para a classe. Trabalhando com os mapas básicos de mensagem que o Assistente de Aplicativo cria, você usa o [Assistente de Classe](reference/mfc-class-wizard.md) para adicionar entradas para as mensagens e comandos que cada classe irá lidar. Um mapa de mensagem típico pode parecer o seguinte depois de adicionar algumas entradas:

[!code-cpp[NVC_MFCMessageHandling#1](../mfc/codesnippet/cpp/where-to-find-message-maps_1.cpp)]

O mapa de mensagens consiste em uma coleção de macros. Duas macros, [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) e [END_MESSAGE_MAP,](reference/message-map-macros-mfc.md#end_message_map)suporte o mapa da mensagem. Outras macros, `ON_COMMAND`como, preencher o conteúdo do mapa de mensagens.

> [!NOTE]
> As macros do mapa de mensagem não são seguidas por ponto e vírgula.

Quando você usa o assistente Adicionar classe para criar uma nova classe, ele fornece um mapa de mensagem para a classe. Alternativamente, você pode criar um mapa de mensagem manualmente usando o editor de código fonte.

## <a name="see-also"></a>Confira também

[Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)
