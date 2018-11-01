---
title: Manipulação e mapeamento de mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, messages
- message handling [MFC]
- message maps [MFC]
ms.assetid: 62fe2a1b-944c-449d-a0f0-63c11ee0a3cb
ms.openlocfilehash: 1b109a3f85ffd3311d08c3d749d543b1e625e77c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50628605"
---
# <a name="message-handling-and-mapping"></a>Manipulação e mapeamento de mensagem

Família este artigo descreve como as mensagens e comandos são processados pela estrutura MFC e como conectá-los às suas funções de manipulador.

Em programas tradicionais do Windows, as mensagens do Windows são tratadas em uma instrução switch grande em um procedimento de janela. Em vez disso, o MFC usa [mapas de mensagem](../mfc/message-categories.md) para mapear mensagens diretas a funções de membro de classe distintos. Mapas de mensagem são mais eficientes que funções virtuais para essa finalidade, e eles permitem que as mensagens sejam tratadas pelo objeto de C++ mais apropriado — aplicativo, documento, exibição e assim por diante. Você pode mapear uma única mensagem ou um intervalo de mensagens, IDs de comando, ou IDs de controle.

Mensagens WM_COMMAND — normalmente é gerado por menus, botões de barra de ferramentas ou aceleradores — também usam o mecanismo de mapa de mensagem. MFC define um padrão [roteamento](../mfc/command-routing.md) de mensagens de comando entre o aplicativo, de quadro janela, exibição e documentos ativos em seu programa. Você pode substituir esse roteamento, se você precisar.

Mapas de mensagem também fornecem uma maneira de atualizar os objetos de interface do usuário (por exemplo, menus e botões da barra de ferramentas), habilitando ou desabilitando-los de acordo com o contexto atual.

Para obter informações gerais sobre mensagens e filas de mensagens no Windows, consulte [mensagens e filas de mensagens](https://msdn.microsoft.com/library/windows/desktop/ms632590) no SDK do Windows.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

- [Como o framework chama um manipulador de mensagens](../mfc/how-the-framework-calls-a-handler.md)

- [Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)

- [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)

- [Mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)

- [Como exibir informações de comando na barra de Status](../mfc/how-to-display-command-information-in-the-status-bar.md)

- [Atualização dinâmica de objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md)

- [Como criar um mapa de mensagem para uma classe de modelo](../mfc/how-to-create-a-message-map-for-a-template-class.md)

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)<br/>
[Classe CWnd](../mfc/reference/cwnd-class.md)<br/>
[Classe CCmdTarget](../mfc/reference/ccmdtarget-class.md)
