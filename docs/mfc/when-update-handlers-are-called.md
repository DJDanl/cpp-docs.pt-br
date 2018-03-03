---
title: "Quando os manipuladores de atualização são chamados | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: eaf2773a2d9e393c783a39e01c75f8efa62796df
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="when-update-handlers-are-called"></a>Quando manipuladores de atualização são chamados
Suponha que o usuário clica com o mouse no menu Arquivo, o que gera um `WM_INITMENUPOPUP` mensagem. Mecanismo de atualização da estrutura coletivamente atualiza todos os itens no menu arquivo antes do menu suspenso para que o usuário pode vê-lo.  
  
 Para fazer isso, as rotas do framework atualizar comandos de todos os itens de menu no menu pop-up ao longo de roteamento de comando padrão. Destinos de comando sobre o roteamento terá a oportunidade de atualizar os itens de menu correspondendo o comando update com uma entrada de mapa de mensagem apropriado (no formato `ON_UPDATE_COMMAND_UI`) e chamar uma função de "manipulador de atualização". Portanto, para um menu com seis itens de menu, seis comandos de atualização são enviados. Se existir um manipulador de atualização para a ID do item de menu de comando, ele é chamado para fazer a atualização. Caso contrário, o framework verifica a existência de um manipulador para essa ID de comando e habilita ou desabilita o item de menu conforme apropriado.  
  
 Se a estrutura não encontrar um `ON_UPDATE_COMMAND_UI` entrada durante o roteamento de comando, ele habilita automaticamente o objeto de interface do usuário se houver um `ON_COMMAND` entrada em algum lugar com a mesma ID de comando. Caso contrário, ele desabilita o objeto de interface do usuário. Portanto, para garantir que um objeto de interface do usuário está habilitado, fornecer um manipulador para o comando que gera o objeto ou fornecer um manipulador de atualização para ele. Consulte a figura no tópico [objetos de Interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md).  
  
 É possível desabilitar a desabilitação de padrão de objetos de interface do usuário. Para obter mais informações, consulte o [m_bAutoMenuEnable](../mfc/reference/cframewnd-class.md#m_bautomenuenable) membro de classe `CFrameWnd` no *referência MFC*.  
  
 Inicialização de menu é automática no framework, que ocorrem quando o aplicativo recebe um `WM_INITMENUPOPUP` mensagem. Durante o loop ocioso, o framework pesquisa o roteamento de comando para manipuladores de atualização do botão muito da mesma maneira como faz para os menus.  
  
## <a name="see-also"></a>Consulte também  
 [Como atualizar objetos da interface do usuário](../mfc/how-to-update-user-interface-objects.md)

