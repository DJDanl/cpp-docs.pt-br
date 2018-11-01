---
title: Quando manipuladores de atualização são chamados
ms.date: 11/04/2016
helpviewer_keywords:
- updating user interface objects [MFC]
- command routing [MFC], update commands
- toolbar buttons [MFC], enabling
- disabling toolbar buttons
- menus [MFC], initializing
- update handlers [MFC]
- disabling menu items
- toolbars [MFC], updating
- menus [MFC], updating as context changes
- toolbar controls [MFC], updated during OnIdle method [MFC]
- menu items, enabling
- command routing [MFC], update handlers
- update handlers, calling
ms.assetid: 7359f6b1-4669-477d-bd99-690affed08d9
ms.openlocfilehash: 036476ecc7a0528692e6fd3e3d69a2efeef6fd4b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50454841"
---
# <a name="when-update-handlers-are-called"></a>Quando manipuladores de atualização são chamados

Suponha que o usuário clica com o mouse no menu Arquivo, que gera uma mensagem WM_INITMENUPOPUP. O mecanismo de atualização da estrutura coletivamente atualiza todos os itens no menu Arquivo, antes que o menu suspenso para que o usuário possa vê-lo.

Para fazer isso, as rotas de framework atualizar comandos para todos os itens de menu no menu pop-up ao longo de roteamento de comando padrão. Destinos de comando sobre o roteamento tem a oportunidade de atualizar os itens de menu correspondendo o comando update com uma entrada de mapa de mensagem apropriado (do formulário `ON_UPDATE_COMMAND_UI`) e chamar uma função de "manipulador de atualização". Portanto, para um menu com seis itens de menu, seis comandos de atualização são enviados. Se houver um manipulador de atualização para a ID do item de menu de comando, ele é chamado para fazer a atualização. Caso contrário, o framework verifica a existência de um manipulador para essa ID de comando e habilita ou desabilita o item de menu conforme apropriado.

Se não encontrar a estrutura de um `ON_UPDATE_COMMAND_UI` entrada durante o roteamento de comando, ele habilita automaticamente o objeto de interface do usuário se não houver um `ON_COMMAND` entrada em algum lugar com a mesma ID de comando. Caso contrário, ele desabilita o objeto de interface do usuário. Portanto, para garantir que um objeto de interface do usuário está habilitado, fornecer um manipulador para o comando que gera o objeto ou fornecer um manipulador de atualização para ele. Veja a figura no tópico [objetos de Interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md).

É possível desabilitar a desabilitação de padrão de objetos de interface do usuário. Para obter mais informações, consulte o [m_bAutoMenuEnable](../mfc/reference/cframewnd-class.md#m_bautomenuenable) membro da classe `CFrameWnd` no *referência da MFC*.

Inicialização de menu é automática no framework, que ocorre quando o aplicativo recebe uma mensagem WM_INITMENUPOPUP. Durante o loop ocioso, o framework pesquisa o roteamento de comando para manipuladores de atualização do botão da mesma forma como faz para menus.

## <a name="see-also"></a>Consulte também

[Como atualizar objetos da interface do usuário](../mfc/how-to-update-user-interface-objects.md)

