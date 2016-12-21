---
title: "Classe de CLinearTransitionFromSpeed | Microsoft Docs"
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
  - "afxanimationcontroller/CLinearTransitionFromSpeed"
  - "CLinearTransitionFromSpeed"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CLinearTransitionFromSpeed"
ms.assetid: 8f159a1c-8893-4017-951e-09e5758aba7d
caps.latest.revision: 18
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CLinearTransitionFromSpeed
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula uma transição de linear\- velocidade.  
  
## Sintaxe  
  
```  
class CLinearTransitionFromSpeed : public CBaseTransition;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLinearTransitionFromSpeed::CLinearTransitionFromSpeed](../Topic/CLinearTransitionFromSpeed::CLinearTransitionFromSpeed.md)|Constrói um objeto de transição de linear\- velocidade e inicializá\-la com velocidade e valor final.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLinearTransitionFromSpeed::Create](../Topic/CLinearTransitionFromSpeed::Create.md)|Chama a biblioteca de transição para criar o objeto COM encapsulado de transição.  Overrides \( [CBaseTransition::Create](../Topic/CBaseTransition::Create.md).\)|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLinearTransitionFromSpeed::m\_dblFinalValue](../Topic/CLinearTransitionFromSpeed::m_dblFinalValue.md)|O valor da variável de animação no final de transição.|  
|[CLinearTransitionFromSpeed::m\_dblSpeed](../Topic/CLinearTransitionFromSpeed::m_dblSpeed.md)|O valor absoluto da velocidade da variável.|  
  
## Comentários  
 Durante uma transição de linear\- velocidade, o valor da variável de animação alterações em uma taxa especificada.  A duração de transição é determinada pela diferença entre o valor inicial e o valor final especificado.  Como todas as transições são desmarcadas automaticamente, é recomendável atribuiu\-as que usam o novo operador.  O IUIAnimationTransition que encapsulado o objeto COM é criado por CAnimationController::AnimateGroup até lá, ele é NULO.  Alterando variáveis de membro após a criação de esse objeto COM não tem efeito.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CLinearTransitionFromSpeed](../../mfc/reference/clineartransitionfromspeed-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)