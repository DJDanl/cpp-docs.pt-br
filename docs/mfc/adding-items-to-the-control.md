---
title: "Adicionando itens ao controle | Microsoft Docs"
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
  - "Classe CListCtrl, adicionando itens"
ms.assetid: 715994bd-340d-4ad2-9882-411654137830
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando itens ao controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para adicionar itens à lista[CListCtrl](../Topic/CListCtrl%20Class.md)controlam \(\), chame várias versões da função de membro de [InsertItem](../Topic/CListCtrl::InsertItem.md) , dependendo de quais você tem informações.  Uma versão usa uma estrutura de [LV\_ITEM](http://msdn.microsoft.com/library/windows/desktop/bb774760) que você preparar.  Como a estrutura de `LV_ITEM` contém muitos membros, você tem maior controle sobre os atributos do item do controle da lista.  
  
 Dois membros importantes \(com relação à exibição de relatório\) da estrutura de `LV_ITEM` são membros de `iItem` e de `iSubItem` .  O membro de `iItem` é o índice de base zero do item que está referenciando a estrutura e o membro de `iSubItem` é o índice de um subitem, ou nulo se a estrutura contém informações sobre um item.  Com esses dois membros você determina, cada um, o tipo e o valor de informações do subitem que será exibida quando o controle da lista estiver na exibição do relatório.  Para obter mais informações, consulte [CListCtrl::SetItem](../Topic/CListCtrl::SetItem.md).  
  
 Os membros adicionais especificam o texto do item, o ícone, o estado, e os dados de item. “Dos dados item” é um valor definido pelo aplicativo associado a um item de exibição de lista.  Para obter mais informações sobre a estrutura de `LV_ITEM` , consulte [CListCtrl::GetItem](../Topic/CListCtrl::GetItem.md).  
  
 Outras versões de `InsertItem` têm um ou mais valores separados, correspondente aos membros da estrutura de `LV_ITEM` , permitindo que você inicialize apenas aqueles membros que você deseja dar suporte.  Geralmente, o controle da lista gerencia o armazenamento para itens de lista, mas pode armazenar algumas das informações em seu aplicativo por outro lado, usando “itens retorno de chamada”. Para obter mais informações, consulte [Itens de retorno de chamada e a máscara de retorno de chamada](../mfc/callback-items-and-the-callback-mask.md) neste tópico e [Itens de retorno de chamada e a máscara de retorno de chamada](http://msdn.microsoft.com/library/windows/desktop/bb774736) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações, consulte [Adicionando itens e subitens de exibição de lista](http://msdn.microsoft.com/library/windows/desktop/bb774736).  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)