---
title: 'Como: atualizar objetos de Interface do usuário | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 422be3d80614c526c7e634d22a0930458e4b4e26
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33346201"
---
# <a name="how-to-update-user-interface-objects"></a>Como atualizar objetos de interface do usuário
Normalmente, os itens de menu e botões de barra de ferramentas tem mais de um estado. Por exemplo, um item de menu estará inativa (esmaecido), se ele não está disponível no contexto atual. Itens de menu também podem ser marcada ou desmarcada. Um botão de barra de ferramentas também pode ser desabilitado se não estiver disponível, ou ele pode ser verificado.  
  
 Que atualizará o estado desses itens, como alteração de condições de programa logicamente, se um item de menu gera um comando que é manipulado pelo, digamos, um documento, faz sentido que o documento a atualizar o item de menu. Provavelmente, o documento contém as informações no qual a atualização se baseia.  
  
 Se um comando tiver vários objetos de interface do usuário (talvez um item de menu e um botão de barra de ferramentas), ambos são roteadas para a mesma função de manipulador. Isso encapsula o código de atualização de interface do usuário para todos os objetos de interface do usuário equivalente em um único lugar.  
  
 A estrutura fornece uma interface conveniente para atualizar automaticamente os objetos de interface do usuário. Você pode optar por fazer a atualização de alguma outra maneira, mas a interface fornecida é eficiente e fácil de usar.  
  
 Os tópicos a seguir explicam o uso de manipuladores de atualização:  
  
-   [Quando são chamados de manipuladores de atualização](../mfc/when-update-handlers-are-called.md)  
  
-   [A macro ON_UPDATE_COMMAND_UI](../mfc/on-update-command-ui-macro.md)  
  
-   [A classe CCmdUI](../mfc/the-ccmdui-class.md)  
  
## <a name="see-also"></a>Consulte também  
 [Menus](../mfc/menus-mfc.md)

