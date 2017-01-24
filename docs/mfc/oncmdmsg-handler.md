---
title: "Manipulador OnCmdMsg | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "OnCmdMsg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "roteamento de comando, Manipulador OnCmdMsg"
  - "manipuladores"
  - "manipuladores, OnCmdMessage"
  - "mensagens, roteamento"
  - "Método OnCmdMessage"
ms.assetid: 8df07024-506f-47e7-bba9-1c3bc5ad8ab6
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipulador OnCmdMsg
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para executar o roteamento de comandos, cada destino de comando chama a função de membro de `OnCmdMsg` do próximo destino do comando na sequência.  Os destinos de comando usam `OnCmdMsg` para determinar se podem tratar um comando e o rotear a outro destino de comando se não podem tratar o.  
  
 Cada classe de comando\- destino pode substituir a função de membro de `OnCmdMsg` .  As substituições permitem que cada classe rotear comandos a seguir um destino específico.  Uma janela do quadro, por exemplo, o roteará sempre comandos à janela filho ou exibição atual, conforme mostrado na tabela [Rota padrão de comando](../mfc/command-routing.md).  
  
 A implementação padrão de `CCmdTarget` de `OnCmdMsg` usa o mapa da mensagem da classe de comando\- destino para pesquisar por uma função de manipulador para cada mensagem do comando que recebe — da mesma forma que as mensagens padrão serão pesquisadas.  Se encontra uma correspondência, chama o manipulador.  a pesquisa retornadas mapa será explicada em [Como a estrutura pesquisa mapas da mensagem](../mfc/how-the-framework-searches-message-maps.md).  
  
## Consulte também  
 [Como o Framework chama um identificador](../mfc/how-the-framework-calls-a-handler.md)