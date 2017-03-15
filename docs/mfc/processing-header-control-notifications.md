---
title: "Processando notifica&#231;&#245;es de controle do cabe&#231;alho | Microsoft Docs"
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
  - "Classe CHeaderCtrl, processando notificações"
  - "controles [MFC], cabeçalho"
  - "notificações de controle de cabeçalho"
  - "controles de cabeçalho, processando notificações"
  - "notificações, processando para CHeaderCtrl"
ms.assetid: e6c6af7c-d458-4d33-85aa-48014ccde5f6
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Processando notifica&#231;&#245;es de controle do cabe&#231;alho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na exibição ou a classe da caixa de diálogo, use a janela Propriedades para criar uma função de manipulador de [OnChildNotify](../Topic/CWnd::OnChildNotify.md) com uma instrução switch de todas as notificações de cabeçalho\- controle \(\)[CHeaderCtrl](../Topic/CHeaderCtrl%20Class.md)você queira manipular [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)\(consulte\).  As notificações são enviadas para a janela pai quando o usuário clica em ou clique duas vezes em um item de cabeçalho, arraste um divisor entre itens, e assim por diante.  
  
 As notificações associadas a um controle de cabeçalho são listadas em [Referência de controle de cabeçalho](http://msdn.microsoft.com/library/windows/desktop/bb775239) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)   
 [Controles](../mfc/controls-mfc.md)