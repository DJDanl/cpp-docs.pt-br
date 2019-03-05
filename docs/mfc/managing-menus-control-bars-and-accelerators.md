---
title: Gerenciando menus, barras de controle e aceleradores
ms.date: 11/04/2016
helpviewer_keywords:
- MDI [MFC], frame windows
- control bars [MFC], updating in frame windows
- menus [MFC], updating as context changes
- user interface objects [MFC], updating
- accelerator tables [MFC]
- sharing menus [MFC]
- updating user-interface objects [MFC]
- frame windows [MFC], updating
- status bars [MFC], updating
ms.assetid: 97ca1997-06df-4373-b023-4f7ecd81047b
ms.openlocfilehash: 9a089829658265cd835a8c7344aa5bc45fbc109a
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57293804"
---
# <a name="managing-menus-control-bars-and-accelerators"></a>Gerenciando menus, barras de controle e aceleradores

A janela do quadro gerencia atualizando objetos de interface do usuário, incluindo menus, botões de barra de ferramentas, a barra de status e os aceleradores. Ele também gerencia o compartilhamento de barra de menus em aplicativos MDI.

## <a name="managing-menus"></a>Gerenciando Menus

A janela do quadro participa Atualizando itens de interface do usuário usando o mecanismo ON_UPDATE_COMMAND_UI descrito na [como objetos de atualização de Interface do usuário](../mfc/how-to-update-user-interface-objects.md). Botões em barras de ferramentas e outras barras de controle são atualizadas durante o loop ocioso. Itens de menu nos menus suspensos na barra de menus são atualizadas antes que o menu suspenso.

Para aplicativos MDI, a janela de quadro MDI gerencia a barra de menus e a legenda. Uma janela de quadro MDI possui um menu padrão que é usado como a barra de menus quando nenhuma janela de filho MDI ativo. Quando houver filhos do Active Directory, barra de menus da janela de quadro MDI é controlada no menu para a janela filho MDI ativo. Se um aplicativo MDI dá suporte a vários tipos de documento, como documentos de gráfico e a planilha, cada tipo coloca seus próprios menus na barra de menus e altera a legenda da janela principal do quadro.

[CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) fornece implementações padrão para os comandos padrão no menu de janela que aparece para aplicativos MDI. Em particular, o comando nova janela (ID_WINDOW_NEW) é implementado para criar uma nova janela de quadro e o modo de exibição no documento atual. Você precisa substituir essas implementações somente se você precisar de personalização avançada.

Várias janelas MDI filho do mesmo tipo de documento compartilham recursos de menu. Se várias janelas filho na MDI são criadas pelo mesmo modelo de documento, todas podem usar o mesmo recurso de menu, salvando nos recursos do sistema no Windows.

## <a name="managing-the-status-bar"></a>Gerenciando a barra de Status

A janela do quadro também posiciona a barra de status dentro de sua área de cliente e gerencia o status de indicadores da barra. Limpa a janela do quadro e atualiza a área de mensagem na barra de status conforme necessário e exibe o prompt de cadeias de caracteres conforme o usuário seleciona itens de menu ou botões da barra de ferramentas, conforme descrito em [como exibir informações de comando na barra de Status](../mfc/how-to-display-command-information-in-the-status-bar.md).

## <a name="managing-accelerators"></a>Gerenciamento de aceleradores

Cada janela de quadro mantém uma tabela de aceleradores opcional que teclado tradução de acelerador para você automaticamente. Esse mecanismo torna fácil definir as teclas de aceleração (também chamadas de teclas de atalho) que invocam comandos de menu.

## <a name="see-also"></a>Consulte também

[Usando janelas com moldura](../mfc/using-frame-windows.md)
