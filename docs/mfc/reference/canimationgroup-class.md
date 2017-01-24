---
title: "Classe de CAnimationGroup | Microsoft Docs"
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
  - "afxanimationcontroller/CAnimationGroup"
  - "CAnimationGroup"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationGroup"
ms.assetid: 8bc18ceb-33a2-41d0-9731-71811adacab7
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationGroup
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um grupo de animação, que combina um storyboard de animação, a animação objetos, e faz a transição para definir uma animação.  
  
## Sintaxe  
  
```  
class CAnimationGroup;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationGroup::CAnimationGroup](../Topic/CAnimationGroup::CAnimationGroup.md)|Constrói um grupo de animação.|  
|[CAnimationGroup::~CAnimationGroup](../Topic/CAnimationGroup::~CAnimationGroup.md)|O destrutor.  Chamado quando um grupo de animação é destruído.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationGroup::Animate](../Topic/CAnimationGroup::Animate.md)|Anima um grupo.|  
|[CAnimationGroup::ApplyTransitions](../Topic/CAnimationGroup::ApplyTransitions.md)|Aplica as transições a objeto de animação.|  
|[CAnimationGroup::FindAnimationObject](../Topic/CAnimationGroup::FindAnimationObject.md)|Localiza um objeto de animação que contém a variável especificada de animação.|  
|[CAnimationGroup::GetGroupID](../Topic/CAnimationGroup::GetGroupID.md)|GroupID returns.|  
|[CAnimationGroup::RemoveKeyframes](../Topic/CAnimationGroup::RemoveKeyframes.md)|Remove destrói e opcionalmente todos os keyframes que pertencem a um grupo de animação.|  
|[CAnimationGroup::RemoveTransitions](../Topic/CAnimationGroup::RemoveTransitions.md)|Remove as transições de objetos de animação que pertencem a um grupo de animação.|  
|[CAnimationGroup::Schedule](../Topic/CAnimationGroup::Schedule.md)|Agenda uma animação nos momentos especificados.|  
|[CAnimationGroup::SetAutodestroyTransitions](../Topic/CAnimationGroup::SetAutodestroyTransitions.md)|Direciona todos os objetos de animação que pertencem para agrupar automaticamente destroem transições.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationGroup::AddKeyframes](../Topic/CAnimationGroup::AddKeyframes.md)|Um auxiliar que adiciona keyframes a um storyboard.|  
|[CAnimationGroup::AddTransitions](../Topic/CAnimationGroup::AddTransitions.md)|Um auxiliar que adiciona as transições a um storyboard.|  
|[CAnimationGroup::CreateTransitions](../Topic/CAnimationGroup::CreateTransitions.md)|Um auxiliar que cria a transição de COM objetos.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationGroup::m\_bAutoclearTransitions](../Topic/CAnimationGroup::m_bAutoclearTransitions.md)|Especifica como limpar as transições de objetos de animação que pertencem ao grupo.  Se esse membro é TRUE, as transições são removidos automaticamente quando uma animação foi agendada.  Se você não precisa remova manualmente as transições.|  
|[CAnimationGroup::m\_bAutodestroyAnimationObjects](../Topic/CAnimationGroup::m_bAutodestroyAnimationObjects.md)|Especifica como destruir objetos de animação.  Se esse parâmetro é TRUE, objetos de animação serão destruídos automaticamente quando o grupo for destruído.  Se não os objetos de animação devem ser destruídos manualmente.  o valor padrão é FALSO.  Definir esse valor PARA RECTIFICAR somente se todos os objetos de animação que pertencem ao grupo são atribuídos dinamicamente com o novo operador.|  
|[CAnimationGroup::m\_bAutodestroyKeyframes](../Topic/CAnimationGroup::m_bAutodestroyKeyframes.md)|Especifica como destruir keyframes.  Se esse valor é TRUE, todos os keyframes são removidos e destruídos; se não são removidos de lista somente.  O valor padrão é TRUE.|  
|[CAnimationGroup::m\_lstAnimationObjects](../Topic/CAnimationGroup::m_lstAnimationObjects.md)|Contém uma lista de objetos de animação.|  
|[CAnimationGroup::m\_lstKeyFrames](../Topic/CAnimationGroup::m_lstKeyFrames.md)|Contém uma lista de keyframes.|  
|[CAnimationGroup::m\_pStoryboard](../Topic/CAnimationGroup::m_pStoryboard.md)|Aponta para o storyboard de animação.  Esse ponteiro é válido somente após chamar animado.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationGroup::m\_nGroupID](../Topic/CAnimationGroup::m_nGroupID.md)|Um identificador exclusivo do grupo de animação.|  
|[CAnimationGroup::m\_pParentController](../Topic/CAnimationGroup::m_pParentController.md)|Um ponteiro para o controlador de animação este grupo pertence.|  
  
## Comentários  
 Grupos de animação são criados automaticamente pelo controlador de animação \(CAnimationController\) quando você adicionar objetos de animação usando CAnimationController::AddAnimationObject.  Um grupo de animação é identificado pelo GroupID, que geralmente é efetuado como um parâmetro manipular grupos de animação.  O GroupID é tirado do primeiro objeto de animação que está sendo adicionado a um novo grupo de animação.  Um storyboard encapsulado de animação é projetado depois de você chamar CAnimationController::AnimateGroup e pode ser acessado através de m\_pStoryboard de membro público.  
  
## Hierarquia de herança  
 [CAnimationGroup](../../mfc/reference/canimationgroup-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)