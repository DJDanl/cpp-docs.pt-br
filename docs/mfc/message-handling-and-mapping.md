---
title: Manipulação e mapeamento de mensagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, messages
- message handling [MFC]
- message maps [MFC]
ms.assetid: 62fe2a1b-944c-449d-a0f0-63c11ee0a3cb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 66171c5df636597a2ff6be0438b558dc418b72af
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33348522"
---
# <a name="message-handling-and-mapping"></a>Manipulação e mapeamento de mensagem
Família este artigo descreve como mensagens e comandos são processados pela estrutura MFC e como conectá-los para suas funções de manipulador.  
  
 Programas tradicionais para Windows, as mensagens do Windows são tratadas em uma instrução switch grande em um procedimento de janela. Em vez disso, usa o MFC [mapas de mensagem](../mfc/message-categories.md) para mapear mensagens diretas a funções de membro de classe distintos. Mapas de mensagem são mais eficientes que funções virtuais para essa finalidade, e eles permitem que as mensagens sejam tratadas pelo objeto C++ mais apropriado, aplicativo, documento, exibição e assim por diante. Você pode mapear uma única mensagem ou um intervalo de mensagens, IDs de comando, ou IDs de controle.  
  
 **WM_COMMAND** mensagens — normalmente é gerado por menus, botões da barra de ferramentas ou aceleradores — também usam o mecanismo de mapa de mensagem. MFC define um padrão [roteamento](../mfc/command-routing.md) de mensagens de comando entre o aplicativo, quadro janela modo de exibição e documentos ativos em seu programa. Você pode substituir este roteamento se for necessário.  
  
 Mapas de mensagem também fornecem uma maneira de atualizar os objetos de interface do usuário (por exemplo, menus e botões de barra de ferramentas), habilitar ou desabilitá-las de acordo com o contexto atual.  
  
 Para obter informações gerais sobre as mensagens e filas de mensagens no Windows, consulte [mensagens e filas de mensagens](http://msdn.microsoft.com/library/windows/desktop/ms632590) no SDK do Windows.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)  
  
-   [Como o framework chama um manipulador de mensagens](../mfc/how-the-framework-calls-a-handler.md)  
  
-   [Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)  
  
-   [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)  
  
-   [Mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)  
  
-   [Como exibir informações de comando na barra de Status](../mfc/how-to-display-command-information-in-the-status-bar.md)  
  
-   [Atualização dinâmica de objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md)  
  
-   [Como criar um mapa de mensagem para uma classe de modelo](../mfc/how-to-create-a-message-map-for-a-template-class.md)  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Classe CWnd](../mfc/reference/cwnd-class.md)   
 [Classe CCmdTarget](../mfc/reference/ccmdtarget-class.md)
