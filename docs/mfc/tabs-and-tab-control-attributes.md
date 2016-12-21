---
title: "Guias e atributos de controle da guia | Microsoft Docs"
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
  - "atributos [C++], tópicos de referência"
  - "Classe CTabCtrl, atributo de controle de tabulação"
  - "controles de guia, atributos"
  - "guias"
  - "guias, atributos"
ms.assetid: ecf190cb-f323-4751-bfdb-766dbe6bb553
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Guias e atributos de controle da guia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você tem controle consideráveis sobre a aparência e o comportamento das guias que compõem um controle da guia \([CTabCtrl](../Topic/CTabCtrl%20Class.md)\).  Cada guia pode ter um rótulo, um ícone, um estado do item, e um valor de 32 bits definido pelo aplicativo associado a ela.  Para cada guia, você pode exibir o ícone, o rótulo, ou ambos.  
  
 Além disso, cada item da guia pode ter três estados possíveis: pressionada, folgado, ou realçado.  Esse estado pode ser definido apenas alterando um item existente da guia.  Para alterar um item existente da guia, recuperá\-lo com uma chamada a [GetItem](../Topic/CTabCtrl::GetItem.md), modifique\-o a estrutura de `TCITEM` \(especificamente os membros de dados de **dwState** e de **dwStateMask** \), e o retorna na estrutura de `TCITEM` alterada por uma chamada a [SetItem](../Topic/CTabCtrl::SetItem.md).  Se você precisar desmarque os estados do item de todos os itens da guia em `CTabCtrl` objetos, faz uma chamada a [DeselectAll](../Topic/CTabCtrl::DeselectAll.md).  Essa função redefine o estado de todos os itens de guia ou de todos os itens a não ser que aquele selecionado no momento.  
  
 O código a seguir limpa o estado de todos os itens da guia e então altera o estado do terceiro item:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#32](../mfc/codesnippet/CPP/tabs-and-tab-control-attributes_1.cpp)]  
  
 Para obter mais informações sobre os atributos da guia, consulte [Guias e atributos da guia](http://msdn.microsoft.com/library/windows/desktop/bb760550) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  Para obter mais informações sobre como adicionar guias a um controle da guia, consulte [Adicionando guias a um controle da guia](../mfc/adding-tabs-to-a-tab-control.md) posteriormente neste tópico.  
  
## Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)