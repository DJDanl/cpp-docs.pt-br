---
title: "Itens de cabe&#231;alho em um controle de cabe&#231;alho | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Classe CHeaderCtrl, itens de cabeçalho em"
  - "controles [MFC], cabeçalho"
  - "controles de cabeçalho, itens de cabeçalho em"
  - "Itens de cabeçalho em controles de cabeçalho"
ms.assetid: ac79ef1f-a671-4ab2-93e9-b1aa016a48bf
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Itens de cabe&#231;alho em um controle de cabe&#231;alho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você tem controle consideráveis sobre a aparência e o comportamento dos itens de cabeçalho que compõem um controle de cabeçalho \([CHeaderCtrl](../Topic/CHeaderCtrl%20Class.md)\).  Cada item do cabeçalho pode ter uma cadeia de caracteres, uma imagem de bitmap, uma imagem de uma lista associado à imagem, ou um valor de 32 bits definido pelo aplicativo associado a ela.  A cadeia de caracteres, o bitmap, ou a imagem são exibidos no item de cabeçalho.  
  
 Você pode personalizar a aparência e o conteúdo de novos itens quando são criados para fazer uma chamada [CHeaderCtrl::InsertItem](../Topic/CHeaderCtrl::InsertItem.md) ou alterando um item existente, com uma chamada a [CHeaderCtrl::GetItem](../Topic/CHeaderCtrl::GetItem.md) e a [CHeaderCtrl::SetItem](../Topic/CHeaderCtrl::SetItem.md).  
  
## Que você deseja saber mais?  
  
-   [Personalizando a aparência do item de cabeçalho](../Topic/Customizing%20the%20Header%20Item's%20Appearance.md)  
  
-   [Classificando itens no controle de cabeçalho](../mfc/ordering-items-in-the-header-control.md)  
  
-   [Fornecendo suporte de arrastar e soltar para itens de cabeçalho](../mfc/providing-drag-and-drop-support-for-header-items.md)  
  
-   [Usando listas da imagem com controles de cabeçalho](../mfc/using-image-lists-with-header-controls.md)  
  
## Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)