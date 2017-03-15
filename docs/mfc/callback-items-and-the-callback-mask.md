---
title: "Itens e m&#225;scara de retorno de chamada | Microsoft Docs"
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
  - "itens de retorno de chamada na classe CListCtrl"
  - "Classe CListCtrl, item e máscara de retorno de chamada"
ms.assetid: 67c1f76f-6144-453e-9376-6712f89430ae
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Itens e m&#225;scara de retorno de chamada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para cada um dos itens, um controle de exibição de lista armazena normalmente o texto do rótulo, o índice na lista da imagem de ícones de item, e um conjunto de sinalizadores de bits para o estado do item.  Você pode definir itens individuais como os itens de retorno de chamada, que são úteis se seu aplicativo ainda armazena algumas das informações para um item.  
  
 Você define um item como um item de retorno de chamada especificando valores apropriados para os membros de `pszText` e de `iImage` da estrutura de **LV\_ITEM** \(consulte [CListCtrl::GetItem](../Topic/CListCtrl::GetItem.md)\).  Se o aplicativo mantiver o texto do item ou do subitem, especifique o valor de **LPSTR\_TEXTCALLBACK** para o membro de `pszText` .  Se o aplicativo mantiver se o controle do ícone do item, especifique o valor de **I\_IMAGECALLBACK** para o membro de `iImage` .  
  
 Além da definição de itens de retorno de chamada, você também pode alterar a máscara de retorno de chamada do controle.  Esta máscara é um conjunto de sinalizadores de bits que especificam os estados do item para o qual o aplicativo, em vez de usar o controle, o armazena os dados atuais.  A máscara de retorno de chamada se aplica aos itens de todo o controle, ao contrário da designação do item de retorno de chamada, que se aplica a um item específico.  A máscara de retorno de chamada é zero por padrão, o que significa que o controle rastreia todos os estados do item.  Para alterar este comportamento padrão, inicializando a máscara a qualquer combinação dos seguintes valores:  
  
-   `LVIS_CUT` o item é marcado para uma operação de utilizando recortar e colar.  
  
-   `LVIS_DROPHILITED` o item é realçado como um destino de arrastar e soltar.  
  
-   `LVIS_FOCUSED` o item tem o foco.  
  
-   `LVIS_SELECTED` o item é selecionado.  
  
-   **LVIS\_OVERLAYMASK** o aplicativo armazena o índice na lista da imagem da imagem atual da sobreposição de cada item.  
  
-   **LVIS\_STATEIMAGEMASK** o aplicativo armazena o índice na lista da imagem da imagem do estado atual de cada item.  
  
 Para obter mais informações sobre como recuperar e de definir esta máscara, consulte [CListCtrl::GetCallbackMask](../Topic/CListCtrl::GetCallbackMask.md) e [CListCtrl::SetCallbackMask](../Topic/CListCtrl::SetCallbackMask.md).  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)