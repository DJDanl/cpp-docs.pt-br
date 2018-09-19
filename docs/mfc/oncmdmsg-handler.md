---
title: Manipulador OnCmdMsg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- OnCmdMsg
dev_langs:
- C++
helpviewer_keywords:
- messages, routing
- handlers [MFC]
- command routing [MFC], OnCmdMsg handler
- handlers, OnCmdMessage [MFC]
- OnCmdMessage method [MFC]
ms.assetid: 8df07024-506f-47e7-bba9-1c3bc5ad8ab6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6691e4935d46b32bc8f433823888bb7f53a36890
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46398827"
---
# <a name="oncmdmsg-handler"></a>Manipulador OnCmdMsg

Para fazer o roteamento de comandos, cada destino do comando chama o `OnCmdMsg` função de membro de destino do comando Avançar na sequência. Comando destina-se usar `OnCmdMsg` para determinar se eles podem lidar com um comando e encaminhá-lo para outro destino de comando se ele não podem lidar com eles.

Cada classe de destino do comando pode substituir o `OnCmdMsg` função de membro. As substituições permitem que os comandos de rota cada classe para um destino específico de Avançar. Uma janela do quadro, por exemplo, sempre roteia comandos em sua janela filho da atual ou o modo de exibição, conforme mostrado na tabela [rota de comando padrão](../mfc/command-routing.md).

O padrão `CCmdTarget` implementação de `OnCmdMsg` usa o mapa da mensagem da classe de destino de comando para procurar por uma função de manipulador para cada mensagem de comando, ele recebe — da mesma forma que as mensagens padrão serão pesquisadas. Se ele encontrar uma correspondência, ele chama o manipulador. Pesquisa de mapa de mensagem é explicado em [como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md).

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

