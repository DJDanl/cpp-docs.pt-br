---
title: Manipulador OnCmdMsg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: OnCmdMsg
dev_langs: C++
helpviewer_keywords:
- messages, routing
- handlers [MFC]
- command routing [MFC], OnCmdMsg handler
- handlers, OnCmdMessage [MFC]
- OnCmdMessage method [MFC]
ms.assetid: 8df07024-506f-47e7-bba9-1c3bc5ad8ab6
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 173741ef73cd4bf6426787ef56e8334f504d7c0e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="oncmdmsg-handler"></a>Manipulador OnCmdMsg
Para fazer o roteamento de comandos, cada destino do comando chama o `OnCmdMsg` a função de membro do próximo destino de comando na sequência. Comando destina-se usar `OnCmdMsg` para determinar se eles possam lidar com um comando e encaminhá-lo para outro destino de comando se ele não podem lidar com eles.  
  
 Cada classe de destino do comando pode substituir o `OnCmdMsg` função de membro. As substituições permitem que os comandos de rota cada classe para um destino específico de Avançar. Uma janela do quadro, por exemplo, sempre rotas comandos à sua janela filho atual ou o modo de exibição, conforme mostrado na tabela [rota de comando padrão](../mfc/command-routing.md).  
  
 O padrão `CCmdTarget` implementação de `OnCmdMsg` usa o mapa de mensagem da classe de destino de comando para procurar uma função de manipulador para cada mensagem de comando que recebe — da mesma forma que as mensagens padrão são pesquisadas. Se ele encontrar uma correspondência, ele chama o manipulador. Pesquisa de mapa de mensagem é explicado em [como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md).  
  
## <a name="see-also"></a>Consulte também  
 [Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

