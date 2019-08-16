---
title: Manipulação e mapeamento de mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, messages
- message handling [MFC]
- message maps [MFC]
ms.assetid: 62fe2a1b-944c-449d-a0f0-63c11ee0a3cb
ms.openlocfilehash: 0321d98d8b92af0b80259bc49e84e69b987577a4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508239"
---
# <a name="message-handling-and-mapping"></a>Manipulação e mapeamento de mensagem

Esta família de artigos descreve como as mensagens e os comandos são processados pela estrutura do MFC e como você os conecta às suas funções de manipulador.

Em programas tradicionais para Windows, as mensagens do Windows são tratadas em uma grande instrução switch em um procedimento de janela. Em vez disso, o MFC usa [mapas de mensagens](../mfc/message-categories.md) para mapear mensagens diretas para funções de membro de classe distinta. Os mapas de mensagens são mais eficientes do que as funções virtuais para essa finalidade e permitem que as mensagens sejam tratadas C++ pelo objeto mais apropriado — aplicativo, documento, exibição e assim por diante. Você pode mapear uma única mensagem ou um intervalo de mensagens, IDs de comando ou IDs de controle.

As mensagens WM_COMMAND — geralmente geradas por menus, botões da barra de ferramentas ou aceleradores – também usam o mecanismo de mapa de mensagens. O MFC define um [Roteamento](../mfc/command-routing.md) padrão de mensagens de comando entre o aplicativo, janela de quadro, exibição e documentos ativos em seu programa. Você pode substituir esse roteamento se precisar.

Os mapas de mensagens também fornecem uma maneira de atualizar objetos da interface do usuário (como menus e botões da barra de ferramentas), habilitando ou desabilitando-os para se adequarem ao contexto atual.

Para obter informações gerais sobre mensagens e filas de mensagens no Windows, consulte [mensagens e filas](/windows/win32/winmsg/messages-and-message-queues) de mensagens no SDK do Windows.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

- [Como a estrutura chama um manipulador de mensagens](../mfc/how-the-framework-calls-a-handler.md)

- [Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)

- [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)

- [Mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)

- [Como exibir informações de comando na barra de status](../mfc/how-to-display-command-information-in-the-status-bar.md)

- [Atualização dinâmica de objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md)

- [Como: criar um mapa de mensagem para uma classe de modelo](../mfc/how-to-create-a-message-map-for-a-template-class.md)

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)<br/>
[Classe CWnd](../mfc/reference/cwnd-class.md)<br/>
[Classe CCmdTarget](../mfc/reference/ccmdtarget-class.md)
