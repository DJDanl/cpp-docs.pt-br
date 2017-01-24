---
title: "Classe de CBaseTransition | Microsoft Docs"
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
  - "CBaseTransition"
  - "afxanimationcontroller/CBaseTransition"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CBaseTransition"
ms.assetid: dfe84007-bbc5-43b7-b5b8-fae9145573bf
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CBaseTransition
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma transição básica.  
  
## Sintaxe  
  
```  
class CBaseTransition : public CObject;  
```  
  
## Membros  
  
### Enumerações públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Enumeração de CBaseTransition::TRANSITION\_TYPE](../Topic/CBaseTransition::TRANSITION_TYPE%20Enumeration.md)|Define os tipos de transição atualmente suportados pela implementação MFC de animação API do windows.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBaseTransition::CBaseTransition](../Topic/CBaseTransition::CBaseTransition.md)|Constrói um objeto de base de transtion.|  
|[CBaseTransition::~CBaseTransition](../Topic/CBaseTransition::~CBaseTransition.md)|O destrutor.  Chamado quando um objeto de transição é destruído.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBaseTransition::AddToStoryboard](../Topic/CBaseTransition::AddToStoryboard.md)|Adiciona uma transição para um storyboard.|  
|[CBaseTransition::AddToStoryboardAtKeyframes](../Topic/CBaseTransition::AddToStoryboardAtKeyframes.md)|Adiciona uma transição para um storyboard.|  
|[CBaseTransition::Clear](../Topic/CBaseTransition::Clear.md)|As versões encapsularam o objeto COM de IUIAnimationTransition.|  
|[CBaseTransition::Create](../Topic/CBaseTransition::Create.md)|Cria uma transição COM.|  
|[CBaseTransition::GetEndKeyframe](../Topic/CBaseTransition::GetEndKeyframe.md)|Keyframe inicial do.|  
|[CBaseTransition::GetRelatedVariable](../Topic/CBaseTransition::GetRelatedVariable.md)|Retorna um ponteiro a variável relacionados.|  
|[CBaseTransition::GetStartKeyframe](../Topic/CBaseTransition::GetStartKeyframe.md)|Keyframe inicial do.|  
|[CBaseTransition::GetTransition](../Topic/CBaseTransition::GetTransition.md)|Sobrecarregado.  Retorna um ponteiro para ser subjacente ao objeto de transição COM.|  
|[CBaseTransition::GetType](../Topic/CBaseTransition::GetType.md)|O retorna faz a transição do tipo.|  
|[CBaseTransition::IsAdded](../Topic/CBaseTransition::IsAdded.md)|Informa se uma transição foi adicionada a um storyboard.|  
|[CBaseTransition::SetKeyframes](../Topic/CBaseTransition::SetKeyframes.md)|Define keyframes para uma transição.|  
|[CBaseTransition::SetRelatedVariable](../Topic/CBaseTransition::SetRelatedVariable.md)|Estabelece uma relação entre a variável de animação e a transição.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBaseTransition::m\_bAdded](../Topic/CBaseTransition::m_bAdded.md)|Especifica se uma transição foi adicionada a um storyboard.|  
|[CBaseTransition::m\_pEndKeyframe](../Topic/CBaseTransition::m_pEndKeyframe.md)|Armazena um ponteiro para o keyframe que especifica o final da transição.|  
|[CBaseTransition::m\_pRelatedVariable](../Topic/CBaseTransition::m_pRelatedVariable.md)|Um ponteiro a uma variável de animação, que é animado com a transição armazenada no m\_transition.|  
|[CBaseTransition::m\_pStartKeyframe](../Topic/CBaseTransition::m_pStartKeyframe.md)|Armazena um ponteiro para o keyframe que especifica o início de transição.|  
|[CBaseTransition::m\_transition](../Topic/CBaseTransition::m_transition.md)|Armazena um ponteiro para IUIAnimationTransition.  ANULE se um objeto de transição COM não foi criado.|  
|[CBaseTransition::m\_type](../Topic/CBaseTransition::m_type.md)|Armazena o tipo de transição.|  
  
## Comentários  
 Essa classe encapsula a interface de IUIAnimationTransition e servir\-la como classe base para todas as transições.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)