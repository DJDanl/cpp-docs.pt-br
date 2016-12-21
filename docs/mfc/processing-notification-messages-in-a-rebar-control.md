---
title: "Processando mensagens de notifica&#231;&#227;o em um controle rebar | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CReBarCtrl, mensagens de notificação envidas por"
  - "notificações, CReBarCtrl"
  - "mensagens de notificação RBN_"
  - "mensagens de notificação RBN_, descrição de"
ms.assetid: 40f43a60-0c18-4d8d-8fab-213a095624f9
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Processando mensagens de notifica&#231;&#227;o em um controle rebar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na classe pai do controle de rebar, crie uma função de manipulador de `OnChildNotify` com uma instrução switch de todas as notificações de rebar\- controle \(\)`CReBarCtrl`você queira manipular.  As notificações são enviadas para a janela pai quando o usuário arrasta objetos sobre o controle de rebar, alterar o layout das faixas de rebar, exclui faixas de controle de rebar, e assim por diante.  
  
 As seguintes notificações podem ser enviadas pelo objeto de controle de rebar:  
  
-   **RBN\_AUTOSIZE** enviados por um controle de rebar \(criado com o estilo de **RBS\_AUTOSIZE** \) quando o rebar se é redimensionado automaticamente.  
  
-   **RBN\_BEGINDRAG** enviados por um controle de rebar quando o usuário inicia a arraste uma faixa.  
  
-   **RBN\_CHILDSIZE** enviados por um controle de rebar quando a janela filho de uma linha distribuída é redimensionada.  
  
-   **RBN\_DELETEDBAND** enviados por um controle de rebar depois que uma faixa foi excluída.  
  
-   **RBN\_DELETINGBAND** enviados por um controle de rebar quando uma faixa está prestes a ser excluída.  
  
-   **RBN\_ENDDRAG** enviados por um controle de rebar quando o usuário para de arrastar uma faixa.  
  
-   **RBN\_GETOBJECT** enviados por um controle de rebar \(criado com o estilo de **RBS\_REGISTERDROP** \) quando um objeto é arrastado para uma faixa no controle.  
  
-   **RBN\_HEIGHTCHANGE** enviados por um controle de rebar quando sua altura foi alterado.  
  
-   **RBN\_LAYOUTCHANGED** enviados por um controle de rebar quando o usuário alterar o layout das faixas de controle.  
  
 Para obter mais informações sobre essas mensagens de notificação, consulte [Referência de controle de Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774375) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CReBarCtrl](../Topic/Using%20CReBarCtrl.md)   
 [Controles](../mfc/controls-mfc.md)