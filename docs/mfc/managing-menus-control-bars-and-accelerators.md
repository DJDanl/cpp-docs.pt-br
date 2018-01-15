---
title: Gerenciando Menus, barras de controle e aceleradores | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 74b026f273eec0bc689cc6959890b07beb570893
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="managing-menus-control-bars-and-accelerators"></a>Gerenciando menus, barras de controle e aceleradores
A janela do quadro gerencia atualizando objetos de interface do usuário, incluindo menus, botões da barra de ferramentas, a barra de status e aceleradores. Ele também gerencia o compartilhamento de barra de menu em aplicativos MDI.  
  
## <a name="managing-menus"></a>Gerenciando Menus  
 A janela do quadro participa Atualizando itens de interface do usuário usando o `ON_UPDATE_COMMAND_UI` mecanismo descrito em [como objetos de atualização de Interface do usuário](../mfc/how-to-update-user-interface-objects.md). Botões da barra de ferramentas e outras barras de controle são atualizadas durante o loop ocioso. Itens de menu nos menus de lista suspensa na barra de menu são atualizados imediatamente antes do menu suspenso.  
  
 Para aplicativos MDI, a janela do quadro MDI gerencia a barra de menus e a legenda. Uma janela de quadro MDI possui um menu padrão que é usado como a barra de menus quando nenhuma janela de filho MDI ativo. Quando há filhos ativos, barra de menus da janela de quadro MDI é controlada por menu para a janela filho MDI ativo. Se um aplicativo MDI dá suporte a vários tipos de documento, como documentos de planilha e de gráfico, cada tipo coloca seus próprios menus na barra de menus e altera a legenda da janela do quadro principal.  
  
 [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) fornece implementações padrão para os comandos padrão no menu janela que aparece para aplicativos MDI. Em particular, o comando nova janela (**ID_WINDOW_NEW**) é implementado para criar uma nova janela do quadro e o modo de exibição no documento atual. Você precisa substituir essas implementações somente se precisar de personalização avançada.  
  
 Várias janelas de filho MDI do mesmo tipo de documento compartilham recursos do menu. Se várias janelas de filho MDI são criadas pelo mesmo modelo de documento, todas elas poderão usar o mesmo recurso de menu, salvando nos recursos do sistema no Windows.  
  
## <a name="managing-the-status-bar"></a>Gerenciando a barra de Status  
 A janela do quadro também posiciona a barra de status na sua área de cliente e gerencia o status indicadores da barra. A janela do quadro limpa e atualiza a área de mensagem na barra de status conforme necessário e exibe o prompt de cadeias de caracteres como o usuário seleciona itens de menu ou botões da barra de ferramentas, conforme descrito em [como exibir informações de comando na barra de Status](../mfc/how-to-display-command-information-in-the-status-bar.md).  
  
## <a name="managing-accelerators"></a>Gerenciamento de aceleradores  
 Cada janela do quadro mantém uma tabela de aceleradores opcional que teclado tradução accelerator para você automaticamente. Esse mecanismo torna fácil definir as teclas de aceleração (também chamadas de teclas de atalho) que chamam os comandos de menu.  
  
## <a name="see-also"></a>Consulte também  
 [Usando janelas com moldura](../mfc/using-frame-windows.md)

