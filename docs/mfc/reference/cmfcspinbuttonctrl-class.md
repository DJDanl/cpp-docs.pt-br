---
title: "Classe de CMFCSpinButtonCtrl | Microsoft Docs"
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
  - "CMFCSpinButtonCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCSpinButtonCtrl"
ms.assetid: 8773f259-4d3f-4bca-a71c-09e0c71bc843
caps.latest.revision: 25
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCSpinButtonCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCSpinButtonCtrl` suporta um gerente visual que desenhar um controle de botão de rotação.  
  
## Sintaxe  
  
```  
class CMFCSpinButtonCtrl : public CSpinButtonCtrl  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCSpinButtonCtrl::CMFCSpinButtonCtrl`|Construtor padrão.|  
|`CMFCSpinButtonCtrl::~CMFCSpinButtonCtrl`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCSpinButtonCtrl::OnDraw](../Topic/CMFCSpinButtonCtrl::OnDraw.md)|Repintura o controle atual do botão de rotação.|  
  
## Comentários  
 Para usar um gerente visual para desenhar um botão de rotação controle em seu aplicativo, substituem todas as instâncias da classe de `CSpinButtonCtrl` com a classe de `CMFCSpinButtonCtrl` .  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto da classe de `CMFCSpinButtonCtrl` e usar o método de `Create` .  
  
 [!code-cpp[NVC_MFC_RibbonApp#25](../../mfc/reference/codesnippet/CPP/cmfcspinbuttonctrl-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CSpinButtonCtrl](../../mfc/reference/cspinbuttonctrl-class.md)  
  
 [CMFCSpinButtonCtrl](../../mfc/reference/cmfcspinbuttonctrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxspinbuttonctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)