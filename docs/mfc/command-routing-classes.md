---
title: Classes de roteamento do comando
ms.date: 11/04/2016
f1_keywords:
- vc.classes.command
helpviewer_keywords:
- MFC, command routing
- command routing [MFC], classes
ms.assetid: 4b50e689-2c54-4e6c-90f0-37333e22b2a1
ms.openlocfilehash: d7ff275d373cf50ab8ebe52ed454bd25cd473e11
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624833"
---
# <a name="command-routing-classes"></a>Classes de roteamento do comando

À medida que o usuário interage com o aplicativo escolhendo menus ou botões de barra de controle com o mouse, o aplicativo envia mensagens do objeto de interface do usuário afetado para um objeto de destino de comando apropriado. As classes de destino de comando derivadas de `CCmdTarget` incluem [CWinApp](reference/cwinapp-class.md), [CWnd](reference/cwnd-class.md), [CDocTemplate](reference/cdoctemplate-class.md), [CDocument](reference/cdocument-class.md), [cvisualização](reference/cview-class.md)e as classes derivadas delas. A estrutura dá suporte ao roteamento automático de comandos para que os comandos possam ser manipulados pelo objeto mais apropriado atualmente ativo no aplicativo.

Um objeto da classe `CCmdUI` é passado para os manipuladores da interface do usuário de comando Update ([ON_UPDATE_COMMAND_UI](reference/message-map-macros-mfc.md#on_update_command_ui)) de destinos de comando para permitir que você atualize o estado da interface para um determinado comando (por exemplo, para verificar ou remover a verificação de itens de menu). Você chama as funções de membro do `CCmdUI` objeto para atualizar o estado do objeto da interface do usuário. Esse processo é o mesmo se o objeto da interface do usuário associado a um comando específico for um item de menu ou um botão ou ambos.

[CCmdTarget](reference/ccmdtarget-class.md)<br/>
Serve como a classe base para todas as classes de objetos que podem receber e responder a mensagens.

[CCmdUI](reference/ccmdui-class.md)<br/>
Fornece uma interface programática para atualizar objetos da interface do usuário, como itens de menu ou botões de barra de controle. O objeto de destino de comando habilita, desabilita, verifica e/ou limpa o objeto de interface do usuário com esse objeto.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
