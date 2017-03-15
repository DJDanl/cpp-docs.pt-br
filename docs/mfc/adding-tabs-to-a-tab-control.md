---
title: "Adicionando guias a um controle de guia | Microsoft Docs"
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
  - "Classe CTabCtrl, adicionando guias"
  - "colocando guias em CTabCtrls"
  - "controles de guia, adicionando guias"
  - "guias, adicionando à classe CTabCtrl"
ms.assetid: 7f3d9340-e3c7-4c71-9912-be57534ecc78
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando guias a um controle de guia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Após criar o controle da guia \([CTabCtrl](../Topic/CTabCtrl%20Class.md)\), adicione quantos guias como você precisa.  
  
### Para adicionar um item da guia  
  
1.  Preparar uma estrutura de [TCITEM](http://msdn.microsoft.com/library/windows/desktop/bb760554) .  
  
2.  Chame [CTabCtrl::InsertItem](../Topic/CTabCtrl::InsertItem.md), passando a estrutura.  
  
3.  Repita as etapas 1 e 2 para itens adicionais da guia.  
  
 Para obter mais informações, consulte [Criando um controle da guia](http://msdn.microsoft.com/library/windows/desktop/bb760550) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)