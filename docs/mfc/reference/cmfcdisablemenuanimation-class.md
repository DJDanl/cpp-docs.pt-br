---
title: "Classe de CMFCDisableMenuAnimation | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMFCDisableMenuAnimation"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCDisableMenuAnimation"
ms.assetid: c6eb07da-c382-43d6-8028-007f2320e50e
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCDisableMenuAnimation
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Desativa a animação de menus pop\-up.  
  
## Sintaxe  
  
```  
class CMFCDisableMenuAnimation  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCDisableMenuAnimation::CMFCDisableMenuAnimation`|Constrói um objeto de `CMFCDisableMenuAnimation` .|  
|`CMFCDisableMenuAnimation::~CMFCDisableMenuAnimation`|Destruidor.|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCDisableMenuAnimation::Restore](../Topic/CMFCDisableMenuAnimation::Restore.md)|Restaura a animação anterior que a estrutura usada para exibir um menu pop\-up.|  
  
### Membros de dados  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCDisableMenuAnimation::m_animType`|Armazena o tipo de animação anterior de menus pop\-up.|  
  
### Comentários  
 Use esta classe auxiliar para desativar temporariamente a animação de menus pop\-up \(por exemplo, quando você processa comandos do mouse ou teclado\).  
  
 Um objeto de `CMFCDisableMenuAnimation` desativa a animação de menus pop\-up durante seu ciclo de vida.  O construtor armazena a animação atual de menus pop\-up no campo e conjuntos de `m_animType` o tipo atual da animação `CMFCPopupMenu::NO_ANIMATION`.  O destrutor restaura o tipo de animação anterior.  
  
 Você pode criar um objeto de `CMFCDisableMenuAnimation` na pilha para a animação de menus pop\-up desative em todo uma única função.  Se você desejar desativar a animação de menu pop\-up entre as funções, crie um objeto de `CMFCDisableMenuAnimation` no heap e exclua\-o então quando você desejar restaurar a animação de menus pop\-up.  
  
## Exemplo  
 O exemplo a seguir mostra como usar a pilha para desativar temporariamente a animação do menu.  
  
 [!code-cpp[NVC_MFC_Misc#1](../../mfc/reference/codesnippet/CPP/cmfcdisablemenuanimation-class_1.h)]  
  
## Hierarquia de herança  
 [CMFCDisableMenuAnimation](../../mfc/reference/cmfcdisablemenuanimation-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxpopupmenu.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md)