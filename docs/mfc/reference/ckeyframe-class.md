---
title: "Classe de CKeyFrame | Microsoft Docs"
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
  - "afxanimationcontroller/CKeyFrame"
  - "CKeyFrame"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CKeyFrame"
ms.assetid: d050a562-20f6-4c65-8ce5-ccb3aef1a20e
caps.latest.revision: 18
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CKeyFrame
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa um de animação keyframe.  
  
## Sintaxe  
  
```  
class CKeyFrame : public CBaseKeyFrame;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CKeyFrame::CKeyFrame](../Topic/CKeyFrame::CKeyFrame.md)|Sobrecarregado.  Constrói um keyframe que depende do outro keyframe.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CKeyFrame::AddToStoryboard](../Topic/CKeyFrame::AddToStoryboard.md)|Adiciona um keyframe a um storyboard.  Overrides \( [CBaseKeyFrame::AddToStoryboard](../Topic/CBaseKeyFrame::AddToStoryboard.md).\)|  
|[CKeyFrame::AddToStoryboardAfterTransition](../Topic/CKeyFrame::AddToStoryboardAfterTransition.md)|Adiciona um keyframe ao storyboard após a transição.|  
|[CKeyFrame::AddToStoryboardAtOffset](../Topic/CKeyFrame::AddToStoryboardAtOffset.md)|Adiciona um keyframe ao storyboard deslocado.|  
|[CKeyFrame::GetExistingKeyframe](../Topic/CKeyFrame::GetExistingKeyframe.md)|Retorna um ponteiro para um keyframe que este keyframe depende.|  
|[CKeyFrame::GetOffset](../Topic/CKeyFrame::GetOffset.md)|Retorna um deslocamento de outro keyframe.|  
|[CKeyFrame::GetTransition](../Topic/CKeyFrame::GetTransition.md)|Retorna um ponteiro para uma transição que este keyframe depende.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CKeyFrame::m\_offset](../Topic/CKeyFrame::m_offset.md)|Especifica o deslocamento de este keyframe de um keyframe armazenado no m\_pExistingKeyFrame.|  
|[CKeyFrame::m\_pExistingKeyFrame](../Topic/CKeyFrame::m_pExistingKeyFrame.md)|Armazena um ponteiro para um keframe existente.  Este keyframe é adicionado ao storyboard com o m\_offset keyframe existente.|  
|[CKeyFrame::m\_pTransition](../Topic/CKeyFrame::m_pTransition.md)|Armazena um ponteiro para o transtion que começa em este keyframe.|  
  
## Comentários  
 Essa classe implementa um de animação keyframe.  Um keyframe representa um ponto no tempo em um storyboard e pode ser usado para especificar a hora de início e fim das transições.  Um keyframe pode ser baseado em outro keyframe e ter um deslocamento \(em segundos\), ou ele pode ser baseado em uma transição e representar um ponto no tempo quando essa transição termina.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CBaseKeyFrame](../Topic/CBaseKeyFrame%20Class.md)  
  
 [CKeyFrame](../../mfc/reference/ckeyframe-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)