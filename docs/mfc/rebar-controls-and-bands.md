---
title: "Controles rebar e bandas | Microsoft Docs"
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
  - "bandas, em controles rebar"
  - "controles rebar, trabalhando com bandas em"
ms.assetid: b647e7a5-9ea7-48b1-8e5f-096d104748f0
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles rebar e bandas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A principal finalidade de um controle de rebar é atuar como um contêiner para janelas filho, controla comuns da caixa de diálogo, menus, barras de ferramentas, e assim por diante.  Essa retenção é suportada pelo conceito de uma faixa “.” Cada a faixa de rebar pode conter qualquer combinação de uma barra de tipo, um bitmap, de um rótulo de texto, e uma janela filho.  
  
 A classe `CReBarCtrl` tem muitas funções de membro que você pode usar para recuperar e manipular informações, para uma faixa específica de rebar:  
  
-   [GetBandCount](../Topic/CReBarCtrl::GetBandCount.md) recupera o número de linhas atuais no controle de rebar.  
  
-   inicializa[GetBandInfo](../Topic/CReBarCtrl::GetBandInfo.md) uma estrutura de **REBARBANDINFO** com informações da faixa especificada.  Há uma função de membro correspondente de [SetBandInfo](../Topic/CReBarCtrl::SetBandInfo.md) .  
  
-   [GetRect](../Topic/CReBarCtrl::GetRect.md) recupera o retângulo delimitador de uma faixa especificada.  
  
-   [GetRowCount](../Topic/CReBarCtrl::GetRowCount.md) recupera o número de linhas de faixa em um controle de rebar.  
  
-   [IDToIndex](../Topic/CReBarCtrl::IDToIndex.md) recupera o índice de uma faixa especificada.  
  
-   [GetBandBorders](../Topic/CReBarCtrl::GetBandBorders.md) recupera as bordas de uma faixa.  
  
 Além da manipulação, várias funções de membro são contanto que permite funcionam em linhas específicas de rebar.  
  
 [InsertBand](../Topic/CReBarCtrl::InsertBand.md) e [DeleteBand](../Topic/CReBarCtrl::DeleteBand.md) adicionar e remover faixas de rebar.  [MinimizeBand](../Topic/CReBarCtrl::MinimizeBand.md) e [MaximizeBand](../Topic/CReBarCtrl::MaximizeBand.md) afetam o tamanho atual de uma faixa específica de rebar.  [MoveBand](../Topic/CReBarCtrl::MoveBand.md) altera o índice de uma faixa específica de rebar.  [ShowBand](../Topic/CReBarCtrl::ShowBand.md) mostra ou oculta uma faixa de rebar do usuário.  
  
 O exemplo a seguir demonstra como adicionar uma faixa da barra de ferramentas \(`m_wndToolBar`\) a um controle existente de rebar \(`m_wndReBar`\).  A faixa é descrita inicializando a estrutura de `rbi` e chamando a função de membro de `InsertBand` :  
  
 [!code-cpp[NVC_MFCControlLadenDialog#27](../mfc/codesnippet/CPP/rebar-controls-and-bands_1.cpp)]  
  
## Consulte também  
 [Usando CReBarCtrl](../Topic/Using%20CReBarCtrl.md)   
 [Controles](../mfc/controls-mfc.md)