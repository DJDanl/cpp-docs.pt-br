---
title: "Criando as listas de imagens | Microsoft Docs"
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
  - "Classe CListCtrl, criando listas de imagens para"
  - "listas de imagens [C++], Criando para CListCtrl"
  - "listas [C++], imagem"
ms.assetid: c2768515-deba-49e8-a6f3-5be6482afb19
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando as listas de imagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Criar listas da imagem é a mesma se você usar [CListView](../mfc/reference/clistview-class.md) ou [CListCtrl](../Topic/CListCtrl%20Class.md).  
  
> [!NOTE]
>  Você precisa apenas listas de imagem se o controle da lista inclui o estilo de `LVS_ICON` .  
  
 Classe `CImageList` de uso para criar uma ou várias listas de imagem \(para ícones sem redução, ícones pequenos, e estados\).  Consulte [CImageList](../Topic/CImageList%20Class.md), consulte e [Listas da imagem da exibição de lista](http://msdn.microsoft.com/library/windows/desktop/bb774736) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
 Chame [CListCtrl::SetImageList](../Topic/CListCtrl::SetImageList.md) para cada lista de imagem; transmitir um ponteiro para o objeto apropriado de `CImageList` .  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)