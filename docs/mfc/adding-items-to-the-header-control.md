---
title: "Adicionando itens ao controle de cabe&#231;alho | Microsoft Docs"
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
  - "Classe CHeaderCtrl, adicionando itens"
  - "controles [MFC], cabeçalho"
  - "controles de cabeçalho, adicionando itens a"
ms.assetid: 2e9a28b1-7302-4a93-8037-c5a4183e589a
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando itens ao controle de cabe&#231;alho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Depois de criar o seu controle de cabeçalho \([CHeaderCtrl](../Topic/CHeaderCtrl%20Class.md)\) na janela pai, adicione quantos itens “cabeçalho” como você precisa: geralmente um pela coluna.  
  
### Para adicionar um item de cabeçalho  
  
1.  Preparar uma estrutura de [HD\_ITEM](http://msdn.microsoft.com/library/windows/desktop/bb775247) .  
  
2.  Chame [CHeaderCtrl::InsertItem](../Topic/CHeaderCtrl::InsertItem.md), passando a estrutura.  
  
3.  Repita as etapas 1 e 2 para itens adicionais.  
  
 Para obter mais informações, consulte [Adicionar um item a um controle de cabeçalho](http://msdn.microsoft.com/library/windows/desktop/bb775238) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)   
 [Controles](../mfc/controls-mfc.md)