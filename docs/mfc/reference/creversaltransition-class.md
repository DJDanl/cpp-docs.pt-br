---
title: "Classe de CReversalTransition | Microsoft Docs"
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
  - "afxanimationcontroller/CReversalTransition"
  - "CReversalTransition"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CReversalTransition"
ms.assetid: e89516be-2d07-4885-95a8-fc278f46e3ad
caps.latest.revision: 18
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CReversalTransition
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula uma transição de reversão.  
  
## Sintaxe  
  
```  
class CReversalTransition : public CBaseTransition;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CReversalTransition::CReversalTransition](../Topic/CReversalTransition::CReversalTransition.md)|Constrói um objeto de transição de reversão e inicializa sua duração.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CReversalTransition::Create](../Topic/CReversalTransition::Create.md)|Chama a biblioteca de transição para criar o objeto COM encapsulado de transição.  Overrides \( [CBaseTransition::Create](../Topic/CBaseTransition::Create.md).\)|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CReversalTransition::m\_duration](../Topic/CReversalTransition::m_duration.md)|A duração de transição.|  
  
## Comentários  
 Uma transição de reversão altera suavemente a direção em uma duração determinada.  O valor final será o mesmo como o valor inicial e final a velocidade serão negativo a velocidade inicial.  Como todas as transições são desmarcadas automaticamente, é recomendável atribuiu\-as que usam o novo operador.  O IUIAnimationTransition que encapsulado o objeto COM é criado por CAnimationController::AnimateGroup até lá, ele é NULO.  Alterando variáveis de membro após a criação de esse objeto COM não tem efeito.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CReversalTransition](../../mfc/reference/creversaltransition-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)