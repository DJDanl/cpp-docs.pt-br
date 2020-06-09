---
title: Como atualizar objetos de interface do usuário
ms.date: 11/04/2016
helpviewer_keywords:
- menus [MFC], updating as context changes
- user interface objects [MFC], updating
- user interface objects [MFC]
- update handlers [MFC]
- enabling UI elements [MFC]
- disabling menus [MFC]
- updating user-interface objects [MFC]
- disabling UI elements [MFC]
- commands [MFC], updating UI
- enabling menus [MFC]
ms.assetid: 82f09773-c978-427b-b321-05a6143b7369
ms.openlocfilehash: aec4067a7b5854ef872cfcef19a15db8438dd795
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626395"
---
# <a name="how-to-update-user-interface-objects"></a>Como atualizar objetos de interface do usuário

Normalmente, os itens de menu e os botões da barra de ferramentas têm mais de um estado. Por exemplo, um item de menu ficará acinzentado (esmaecido) se não estiver disponível no contexto atual. Os itens de menu também podem ser marcados ou desmarcados. Um botão da barra de ferramentas também pode ser desabilitado se estiver indisponível ou pode ser verificado.

Quem atualiza o estado desses itens conforme as condições do programa são alteradas logicamente, se um item de menu gerar um comando que é manipulado pelo, digamos, um documento, faz sentido fazer com que o documento atualize o item de menu. O documento provavelmente contém as informações nas quais a atualização se baseia.

Se um comando tiver vários objetos de interface do usuário (talvez um item de menu e um botão da barra de ferramentas), ambos serão roteados para a mesma função do manipulador. Isso encapsula o código de atualização da interface do usuário para todos os objetos equivalentes da interface do usuário em um único local.

A estrutura fornece uma interface conveniente para atualizar automaticamente os objetos da interface do usuário. Você pode optar por fazer a atualização de alguma outra maneira, mas a interface fornecida é eficiente e fácil de usar.

Os tópicos a seguir explicam o uso de manipuladores de atualização:

- [Quando os manipuladores de atualização são chamados](when-update-handlers-are-called.md)

- [A macro ON_UPDATE_COMMAND_UI](on-update-command-ui-macro.md)

- [A classe CCmdUI](the-ccmdui-class.md)

## <a name="see-also"></a>Consulte também

[Menus](menus-mfc.md)
