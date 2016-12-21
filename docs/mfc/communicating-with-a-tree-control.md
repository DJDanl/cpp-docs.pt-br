---
title: "Comunicando-se com um controle de &#225;rvore | Microsoft Docs"
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
  - "comunicações, controles em árvore"
  - "Classe CTreeCtrl, chamando funções de membro"
  - "controles em árvore"
  - "controles em árvore, comunicando com"
ms.assetid: 680ad9ee-b11f-452d-93fa-501ca7d7e069
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Comunicando-se com um controle de &#225;rvore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você usa métodos diferentes chamando funções de membro em um objeto de [CTreeCtrl](../mfc/reference/ctreectrl-class.md) dependendo de como o objeto foi criado:  
  
-   Se o controle de árvore está em uma caixa de diálogo, use uma variável de membro do tipo `CTreeCtrl` que você criou na classe da caixa de diálogo.  
  
-   Se o controle de árvore é uma janela filho, use o objeto de `CTreeCtrl` \(ou o ponteiro\) que você usou para criar o objeto.  
  
-   Se você estiver usando um objeto de `CTreeView` , use a função [CTreeView::GetTreeCtrl](../Topic/CTreeView::GetTreeCtrl.md) para obter uma referência ao controle de árvore.  Você pode inicializar outra referência a esse valor ou atribuir o endereço da referência a um ponteiro de `CTreeCtrl` .  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)