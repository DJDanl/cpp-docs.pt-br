---
title: "Ordenando itens no controle de cabe&#231;alho | Microsoft Docs"
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
  - "DS_DRAGDROP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DS_DRAGDROP (notificação)"
  - "Método GetOrderArray"
  - "controles de cabeçalho, ordenando itens"
  - "Método OrderToIndex"
  - "sequência"
  - "sequência, itens de controle de cabeçalho"
  - "Método SetOrderArray"
ms.assetid: 5aaef872-75b5-49c5-8fed-6f9a81fca812
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ordenando itens no controle de cabe&#231;alho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você tem [itens adicionados a um controle de cabeçalho](../mfc/adding-items-to-the-header-control.md), você poderá manipular ou obter informações sobre o pedido com as seguintes funções:  
  
-   [CHeaderCtrl::GetOrderArray](../Topic/CHeaderCtrl::GetOrderArray.md) e [CHeaderCtrl::SetOrderArray](../Topic/CHeaderCtrl::SetOrderArray.md)  
  
     Recupera e define a ordem da esquerda para a direita de itens de cabeçalho.  
  
-   [CHeaderCtrl::OrderToIndex](../Topic/CHeaderCtrl::OrderToIndex.md).  
  
     Recupera o valor de índice para um item específico de cabeçalho.  
  
 Além das funções de membro anteriores, o estilo de `HDS_DRAGDROP` permite que o usuário arrasta e remover itens de cabeçalho no controle de cabeçalho.  Para obter mais informações, consulte [Fornecendo suporte de arrastar e soltar para itens de cabeçalho](../mfc/providing-drag-and-drop-support-for-header-items.md).  
  
## Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)