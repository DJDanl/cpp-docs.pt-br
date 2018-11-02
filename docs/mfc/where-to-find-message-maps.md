---
title: Onde encontrar mapas de mensagens
ms.date: 11/04/2016
helpviewer_keywords:
- macros, message map
- locating message maps
- message classes [MFC], finding
- message-map macros
ms.assetid: bf59fbc8-b222-42d3-b5d3-0a79aa3cb923
ms.openlocfilehash: ab21369cecfa977a8397e7e2a7e68394e86e6927
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50533465"
---
# <a name="where-to-find-message-maps"></a>Onde encontrar mapas de mensagens

Quando você cria um novo aplicativo de esqueleto com o Assistente de aplicativo, o Assistente para aplicativo grava um mapa de mensagem para cada classe de destino do comando, que ele cria para você. Isso inclui seu aplicativo derivado, documento, exibição e classes de janela do quadro. Alguns desses mapas de mensagem já possuem as entradas fornecidas pelo Assistente de aplicativo para determinadas mensagens e comandos predefinidos, e alguns são apenas espaços reservados para manipuladores que serão adicionados.

Mapa de mensagens de uma classe está localizado na. Arquivo CPP da classe. Trabalhando com os mapas de mensagem básico criado pelo Assistente de aplicativo, use a janela Propriedades para adicionar entradas para as mensagens e comandos que cada classe serão tratadas. Um mapa de mensagem típico pode parecer com o seguinte depois de adicionar algumas entradas:

[!code-cpp[NVC_MFCMessageHandling#1](../mfc/codesnippet/cpp/where-to-find-message-maps_1.cpp)]

Mapa de mensagens consiste em uma coleção de macros. Macros de duas [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) e [END_MESSAGE_MAP](reference/message-map-macros-mfc.md#end_message_map), colchete de mapa de mensagens. Outras macros, como `ON_COMMAND`, preencha o conteúdo do mapa de mensagem.

> [!NOTE]
>  As macros de mapa de mensagens não são seguidas por ponto e vírgula.

Quando você usar o Assistente para Adicionar classe para criar uma nova classe, ele fornece um mapa de mensagem para a classe. Como alternativa, você pode criar um mapa de mensagens manualmente usando o editor de código fonte.

## <a name="see-also"></a>Consulte também

[Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)

