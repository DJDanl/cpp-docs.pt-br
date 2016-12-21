---
title: "Classe de CSinusoidalTransitionFromVelocity | Microsoft Docs"
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
  - "CSinusoidalTransitionFromVelocity"
  - "afxanimationcontroller/CSinusoidalTransitionFromVelocity"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSinusoidalTransitionFromVelocity"
ms.assetid: cc885f17-b84b-45ee-8f1f-36a8bbb7adad
caps.latest.revision: 18
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSinusoidalTransitionFromVelocity
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula uma transição de sinusoidal\- velocidade que tenha uma amplitude que é determinada pela velocidade inicial da variável de animação.  
  
## Sintaxe  
  
```  
class CSinusoidalTransitionFromVelocity : public CBaseTransition;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSinusoidalTransitionFromVelocity::CSinusoidalTransitionFromVelocity](../Topic/CSinusoidalTransitionFromVelocity::CSinusoidalTransitionFromVelocity.md)|Constrói um objeto de transição.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSinusoidalTransitionFromVelocity::Create](../Topic/CSinusoidalTransitionFromVelocity::Create.md)|Chama a biblioteca de transição para criar o objeto COM encapsulado de transição.  Overrides \( [CBaseTransition::Create](../Topic/CBaseTransition::Create.md).\)|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSinusoidalTransitionFromVelocity::m\_duration](../Topic/CSinusoidalTransitionFromVelocity::m_duration.md)|A duração de transição.|  
|[CSinusoidalTransitionFromVelocity::m\_period](../Topic/CSinusoidalTransitionFromVelocity::m_period.md)|O período de oscilação de som tipo wave sinusoidaa em segundos.|  
  
## Comentários  
 O valor da variável de animação oscila em torno do valor inicial em toda a duração de uma transição de sinusoidal\- intervalo.  A amplitude de oscilação é determinada pela velocidade da variável de animação quando a transição começa.  Como todas as transições são desmarcadas automaticamente, é recomendável atribuiu\-as que usam o novo operador.  O IUIAnimationTransition que encapsulado o objeto COM é criado por CAnimationController::AnimateGroup até lá, ele é NULO.  Alterando variáveis de membro após a criação de esse objeto COM não tem efeito.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CSinusoidalTransitionFromVelocity](../../mfc/reference/csinusoidaltransitionfromvelocity-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)