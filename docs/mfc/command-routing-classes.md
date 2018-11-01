---
title: Classes de roteamento do comando
ms.date: 11/04/2016
f1_keywords:
- vc.classes.command
helpviewer_keywords:
- MFC, command routing
- command routing [MFC], classes
ms.assetid: 4b50e689-2c54-4e6c-90f0-37333e22b2a1
ms.openlocfilehash: 637f2056b76b7d55933b43a8e0822ec00212301a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50574753"
---
# <a name="command-routing-classes"></a>Classes de roteamento do comando

Conforme o usuário interage com o aplicativo escolhendo menus ou botões da barra de controle com o mouse, o aplicativo envia mensagens do objeto de interface do usuário afetado para um objeto de destino do comando apropriado. Destino do comando classes derivadas de `CCmdTarget` incluem [CWinApp](../mfc/reference/cwinapp-class.md), [CWnd](../mfc/reference/cwnd-class.md), [CDocTemplate](../mfc/reference/cdoctemplate-class.md), [CDocument](../mfc/reference/cdocument-class.md), [CView](../mfc/reference/cview-class.md), e as classes derivadas deles. O framework oferece suporte a roteamento de comando automática para que os comandos podem ser tratados por objeto mais apropriado atualmente ativo no aplicativo.

Um objeto da classe `CCmdUI` é passado para o comando de atualização dos destinos de comando da interface do usuário ([ON_UPDATE_COMMAND_UI](reference/message-map-macros-mfc.md#on_update_command_ui)) manipuladores para permitir que você atualizar o estado da interface do usuário para um determinado comando (por exemplo, a seleção ou remover a seleção de itens de menu). Você chama funções de membro a `CCmdUI` objeto para atualizar o estado do objeto da interface do usuário. Esse processo é o mesmo se o objeto de interface do usuário associado a um determinado comando é um item de menu ou um botão ou ambos.

[CCmdTarget](../mfc/reference/ccmdtarget-class.md)<br/>
Serve como a classe base para todas as classes de objetos que podem receber e responder às mensagens.

[CCmdUI](../mfc/reference/ccmdui-class.md)<br/>
Fornece uma interface programática para atualizar objetos de interface do usuário, como itens de menu ou botões da barra de controle. O objeto de destino do comando habilita, desabilita, verifica e limpa o objeto de interface do usuário com esse objeto.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

