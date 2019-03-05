---
title: 'Como: Atualizar os objetos de Interface do usuário'
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
ms.openlocfilehash: 0dee9bb48c11cf061af60ebaf9a80c0123d339be
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57289696"
---
# <a name="how-to-update-user-interface-objects"></a>Como: Atualizar os objetos de Interface do usuário

Normalmente, os itens de menu e botões da barra de ferramentas têm mais de um estado. Por exemplo, um item de menu é cinza (esmaecido) se ele estiver indisponível no presente contexto. Itens de menu também podem ser marcado ou desmarcado. Um botão de barra de ferramentas também pode ser desabilitado se não estiver disponível, ou ele pode ser verificado.

Quem atualiza o estado desses itens, como alteração de condições do programa logicamente, se um item de menu gerar um comando que é manipulado por, digamos, um documento, faz sentido ter o documento a atualizar o item de menu. Provavelmente, o documento contém as informações no qual a atualização se baseia.

Se um comando tiver vários objetos de interface do usuário (talvez um item de menu e um botão de barra de ferramentas), ambos são roteadas para a mesma função de manipulador. Isso encapsula o código de atualização de interface do usuário para todos os objetos de interface do usuário equivalente em um único lugar.

O framework fornece uma interface conveniente para atualizar automaticamente os objetos de interface do usuário. Você pode optar por fazer a atualização de alguma outra maneira, mas a interface fornecida é eficiente e fácil de usar.

Os tópicos a seguir explicam o uso de manipuladores de atualização:

- [Quando manipuladores de atualização são chamados](../mfc/when-update-handlers-are-called.md)

- [A macro ON_UPDATE_COMMAND_UI](../mfc/on-update-command-ui-macro.md)

- [A classe CCmdUI](../mfc/the-ccmdui-class.md)

## <a name="see-also"></a>Consulte também

[Menus](../mfc/menus-mfc.md)
