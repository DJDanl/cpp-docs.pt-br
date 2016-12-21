---
title: "Classe de CLinearTransition | Microsoft Docs"
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
  - "CLinearTransition"
  - "afxanimationcontroller/CLinearTransition"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CLinearTransition"
ms.assetid: 7fcb2dba-beb8-4933-9f5d-3b7fb1585ef0
caps.latest.revision: 18
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CLinearTransition
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula uma transição linear.  
  
## Sintaxe  
  
```  
class CLinearTransition : public CBaseTransition;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLinearTransition::CLinearTransition](../Topic/CLinearTransition::CLinearTransition.md)|Constrói um objeto de transição linear e inicializá\-la com duração e valor final.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLinearTransition::Create](../Topic/CLinearTransition::Create.md)|Chama a biblioteca de transição para criar o objeto COM encapsulado de transição.  Overrides \( [CBaseTransition::Create](../Topic/CBaseTransition::Create.md).\)|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLinearTransition::m\_dblFinalValue](../Topic/CLinearTransition::m_dblFinalValue.md)|O valor da variável de animação no final de transição.|  
|[CLinearTransition::m\_duration](../Topic/CLinearTransition::m_duration.md)|A duração de transição.|  
  
## Comentários  
 Durante uma transição linear, o valor da variável de animação faz a transição linear do seu valor inicial para um valor final especificado.  Como todas as transições são desmarcadas automaticamente, é recomendável atribuiu\-as que usam o novo operador.  O IUIAnimationTransition que encapsulado o objeto COM é criado por CAnimationController::AnimateGroup até lá, ele é NULO.  Alterando variáveis de membro após a criação de esse objeto COM não tem efeito.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CLinearTransition](../../mfc/reference/clineartransition-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)