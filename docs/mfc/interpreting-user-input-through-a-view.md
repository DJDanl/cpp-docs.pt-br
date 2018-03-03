---
title: "Interpretando a entrada do usuário por meio de uma exibição | Microsoft Docs"
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
- interpreting user input through views [MFC]
- views [MFC], user interface and input
- input [MFC], view class [MFC]
- CView class [MFC], interpreting user input
- user input [MFC], interpreting through view class [MFC]
ms.assetid: f0302a70-661f-4781-8fe7-78f082bef2a5
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 263afe7b444722174d1787594f869087d606a235
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="interpreting-user-input-through-a-view"></a>Interpretando a entrada do usuário por meio de uma exibição
Outras funções de membro da exibição de tratarem e interpretam todas as entrada do usuário. Normalmente, você definirá funções de membro de manipulador de mensagens em sua classe de exibição para processar:  
  
-   Windows [mensagens](../mfc/messages.md) gerado por ações de mouse e teclado.  
  
-   [Comandos](../mfc/user-interface-objects-and-command-ids.md) de menus, botões da barra de ferramentas e teclas de aceleração.  
  
 Essas funções de membro de manipulador de mensagens interpretam as seguintes ações como entrada de dados, a seleção ou a edição, incluindo a movimentação de dados para e da área de transferência:  
  
-   Movimentos do mouse e cliques, arrasta e clica duas vezes  
  
-   Pressionamentos de tecla  
  
-   Comandos de menu  
  
 As mensagens do Windows seus identificadores de exibição depende das necessidades do seu aplicativo.  
  
 [Manipulação e mapeamento de tópicos de mensagem](../mfc/message-handling-and-mapping.md) explica como atribuir itens de menu e outros objetos de interface do usuário para comandos e como associar os comandos a funções de manipulador. [Manipulação e mapeamento de tópicos de mensagem](../mfc/message-handling-and-mapping.md) também explica como o MFC roteia comandos e envia mensagens padrão do Windows para os objetos que contêm os manipuladores para eles.  
  
 Por exemplo, seu aplicativo precisará implementar direto do mouse na exibição de desenho. O exemplo de rabisco mostra como tratar o `WM_LBUTTONDOWN`, `WM_MOUSEMOVE`, e `WM_LBUTTONUP` mensagens respectivamente, para começar e o desenho de um segmento de linha. Por outro lado, às vezes, talvez seja necessário interpretar um clique do mouse no modo de exibição como uma seleção. O modo de exibição `OnLButtonDown` função do manipulador determina se o usuário foi desenho ou a seleção. Se você selecionar, o manipulador deve determinar se o clique foi dentro dos limites de um objeto no modo de exibição e, nesse caso, altere a exibição para mostrar o objeto selecionado.  
  
 O modo de exibição também pode tratar alguns comandos de menu, como aqueles no menu Editar para recortar, copiar, colar ou excluir os dados selecionados usando a área de transferência. Tal um manipulador de algumas do membro relacionadas a área de transferência chamaria funções da classe `CWnd` para transferir um item de dados selecionado ou para a área de transferência.  
  
## <a name="see-also"></a>Consulte também  
 [Usando exibições](../mfc/using-views.md)

