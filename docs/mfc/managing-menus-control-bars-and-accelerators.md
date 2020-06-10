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
ms.openlocfilehash: 9945dc68ffd46bbf5e114a79467299e4b67e3659
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621325"
---
# <a name="managing-menus-control-bars-and-accelerators"></a>Gerenciando menus, barras de controle e aceleradores

A janela do quadro gerencia a atualização de objetos da interface do usuário, incluindo menus, botões da barra de ferramentas, a barra de status e aceleradores. Ele também gerencia o compartilhamento da barra de menus em aplicativos MDI.

## <a name="managing-menus"></a>Gerenciando menus

A janela do quadro participa da atualização de itens da interface do usuário usando o mecanismo de ON_UPDATE_COMMAND_UI descrito em [como atualizar objetos da interface do usuário](how-to-update-user-interface-objects.md). Os botões nas barras de ferramentas e outras barras de controle são atualizados durante o loop ocioso. Os itens de menu nos menus suspensos na barra de menus são atualizados logo antes de o menu cair.

Para aplicativos MDI, a janela de quadro MDI gerencia a barra de menus e a legenda. Uma janela de quadro MDI possui um menu padrão que é usado como a barra de menus quando não há janelas filho MDI ativas. Quando há filhos ativos, a barra de menus da janela de quadro MDI é assumida pelo menu da janela filho MDI ativa. Se um aplicativo MDI oferecer suporte a vários tipos de documentos, como documentos de gráfico e planilha, cada tipo colocará seus próprios menus na barra de menus e alterará a legenda da janela do quadro principal.

O [CMDIFrameWnd](reference/cmdiframewnd-class.md) fornece implementações padrão para os comandos padrão no menu janela que aparece para aplicativos MDI. Em particular, o comando de nova janela (ID_WINDOW_NEW) é implementado para criar uma nova janela de quadro e exibir no documento atual. Você precisará substituir essas implementações somente se precisar de personalização avançada.

Várias janelas filhas MDI do mesmo tipo de documento compartilham recursos de menu. Se várias janelas filhas MDI forem criadas pelo mesmo modelo de documento, todas poderão usar o mesmo recurso de menu, salvando os recursos do sistema no Windows.

## <a name="managing-the-status-bar"></a>Gerenciando a barra de status

A janela do quadro também posiciona a barra de status dentro de sua área do cliente e gerencia os indicadores da barra de status. A janela do quadro limpa e atualiza a área da mensagem na barra de status conforme necessário e exibe cadeias de caracteres de aviso, pois o usuário seleciona itens de menu ou botões da barra de ferramentas, conforme descrito em [como exibir informações de comando na barra de status](how-to-display-command-information-in-the-status-bar.md).

## <a name="managing-accelerators"></a>Gerenciando aceleradores

Cada janela do quadro mantém uma tabela de acelerador opcional que faz a tradução do acelerador de teclado para você automaticamente. Esse mecanismo facilita a definição de teclas de aceleração (também chamadas de teclas de atalho) que invocam comandos de menu.

## <a name="see-also"></a>Consulte também

[Usando janelas de quadros](using-frame-windows.md)
