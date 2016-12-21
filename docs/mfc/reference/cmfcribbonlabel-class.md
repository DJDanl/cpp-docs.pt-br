---
title: "Classe de CMFCRibbonLabel | Microsoft Docs"
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
  - "CMFCRibbonLabel"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonLabel"
ms.assetid: 0346c891-83bf-4f20-b8a1-c84cf2aadced
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonLabel
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um rótulo não clicável de texto para uma fita.  
  
## Sintaxe  
  
```  
class CMFCRibbonLabel : public CMFCRibbonButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonLabel::CMFCRibbonLabel](../Topic/CMFCRibbonLabel::CMFCRibbonLabel.md)|As compilações e inicializam um objeto de `CMFCRibbonLabel` com a cadeia de caracteres especificada.|  
|`CMFCRibbonLabel::~CMFCRibbonLabel`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCRibbonLabel::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|`CMFCRibbonLabel::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCRibbonLabel::SetACCData](../Topic/CMFCRibbonLabel::SetACCData.md)|Determina os dados de acessibilidade para o elemento atual do rótulo de fita.  Overrides \( [CMFCRibbonButton::SetACCData](../Topic/CMFCRibbonButton::SetACCData.md).\)|  
  
### Comentários  
 Depois de criar um rótulo de fita, adicione a um painel chamando [CMFCRibbonPanel::Add](../Topic/CMFCRibbonPanel::Add.md).  
  
 Você não pode adicionar um rótulo de fita a barra de ferramentas de acesso rápido.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonLabel](../../mfc/reference/cmfcribbonlabel-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxRibbonLabel.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)