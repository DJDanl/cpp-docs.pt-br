---
title: Classes de roteamento de comando | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.command
dev_langs: C++
helpviewer_keywords:
- MFC, command routing
- command routing [MFC], classes
ms.assetid: 4b50e689-2c54-4e6c-90f0-37333e22b2a1
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 5e1fb5446a05b8b4227812be77124071abbed2b8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="command-routing-classes"></a>Classes de roteamento do comando
Como o usuário interage com o aplicativo escolhendo menus ou botões da barra de controle com o mouse, o aplicativo envia mensagens do objeto de interface do usuário afetado para um objeto de destino do comando apropriado. Destino do comando classes derivadas de `CCmdTarget` incluem [CWinApp](../mfc/reference/cwinapp-class.md), [CWnd](../mfc/reference/cwnd-class.md), [CDocTemplate](../mfc/reference/cdoctemplate-class.md), [CDocument](../mfc/reference/cdocument-class.md), [CView](../mfc/reference/cview-class.md), e as classes derivadas da parte deles. A estrutura oferece suporte a roteamento de comando automático para que os comandos podem ser tratados pelo objeto ativo no momento em que o aplicativo mais apropriado.  
  
 Um objeto da classe `CCmdUI` é passado para a interface de comando de atualização dos destinos de comando ([ON_UPDATE_COMMAND_UI](reference/message-map-macros-mfc.md#on_update_command_ui)) manipuladores para permitir que você atualize o estado da interface do usuário para um determinado comando (por exemplo, a seleção ou remover a seleção de itens de menu). Chamar funções de membro de `CCmdUI` objeto para atualizar o estado do objeto da interface do usuário. Esse processo é o mesmo se o objeto de interface do usuário associado a um determinado comando é um item de menu ou botão de um ou ambos.  
  
 [CCmdTarget](../mfc/reference/ccmdtarget-class.md)  
 Serve como a classe base para todas as classes de objetos que podem receber e responder a mensagens.  
  
 [CCmdUI](../mfc/reference/ccmdui-class.md)  
 Fornece uma interface programática para atualizar objetos de interface do usuário como itens de menu ou botões da barra de controle. O objeto de destino do comando habilita, desabilita, verifica e limpa o objeto de interface de usuário com este objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

