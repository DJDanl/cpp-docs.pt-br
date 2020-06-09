---
title: Manipulador OnCmdMsg
ms.date: 11/04/2016
f1_keywords:
- OnCmdMsg
helpviewer_keywords:
- messages, routing
- handlers [MFC]
- command routing [MFC], OnCmdMsg handler
- handlers, OnCmdMessage [MFC]
- OnCmdMessage method [MFC]
ms.assetid: 8df07024-506f-47e7-bba9-1c3bc5ad8ab6
ms.openlocfilehash: 5114fe53a5bac345eb6a55fb6c371f7bc1f698ef
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624022"
---
# <a name="oncmdmsg-handler"></a>Manipulador OnCmdMsg

Para realizar o roteamento de comandos, cada destino de comando chama a `OnCmdMsg` função de membro do próximo destino de comando na sequência. Os destinos de comando usam `OnCmdMsg` para determinar se eles podem manipular um comando e roteá-lo para outro destino de comando, caso não possam tratá-lo.

Cada classe de destino de comando pode substituir a `OnCmdMsg` função de membro. As substituições permitem que cada classe encaminhe comandos para um próximo destino específico. Uma janela de quadro, por exemplo, sempre roteia comandos para sua janela ou exibição filho atual, conforme mostrado na [rota de comando padrão](command-routing.md)da tabela.

A `CCmdTarget` implementação padrão do `OnCmdMsg` usa o mapa de mensagens da classe de destino de comando para pesquisar uma função de manipulador para cada mensagem de comando que recebe — da mesma forma que as mensagens padrão são pesquisadas. Se encontrar uma correspondência, ele chamará o manipulador. A pesquisa de mapa de mensagens é explicada em [como a estrutura pesquisa mapas de mensagens](how-the-framework-searches-message-maps.md).

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](how-the-framework-calls-a-handler.md)
