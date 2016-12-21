---
title: "Classe de CAccelerateDecelerateTransition | Microsoft Docs"
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
  - "CAccelerateDecelerateTransition"
  - "afxanimationcontroller/CAccelerateDecelerateTransition"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAccelerateDecelerateTransition"
ms.assetid: b1f31ee8-bb11-4ccc-b124-365fb02b025c
caps.latest.revision: 16
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAccelerateDecelerateTransition
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa uma transição de acelerar\- retardamento.  
  
## Sintaxe  
  
```  
class CAccelerateDecelerateTransition : public CBaseTransition;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAccelerateDecelerateTransition::CAccelerateDecelerateTransition](../Topic/CAccelerateDecelerateTransition::CAccelerateDecelerateTransition.md)|Constrói um objeto de transição.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAccelerateDecelerateTransition::Create](../Topic/CAccelerateDecelerateTransition::Create.md)|Chama a biblioteca de transição para criar o objeto COM encapsulado de transição.  Overrides \( [CBaseTransition::Create](../Topic/CBaseTransition::Create.md).\)|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAccelerateDecelerateTransition::m\_accelerationRatio](../Topic/CAccelerateDecelerateTransition::m_accelerationRatio.md)|A taxa de gasta acelerando a duração de tempo.|  
|[CAccelerateDecelerateTransition::m\_decelerationRatio](../Topic/CAccelerateDecelerateTransition::m_decelerationRatio.md)|A taxa de tempo gastou o retardamento a duração.|  
|[CAccelerateDecelerateTransition::m\_duration](../Topic/CAccelerateDecelerateTransition::m_duration.md)|A duração de transição.|  
|[CAccelerateDecelerateTransition::m\_finalValue](../Topic/CAccelerateDecelerateTransition::m_finalValue.md)|O valor da variável de animação no final de transição.|  
  
## Comentários  
 Durante uma transição de acelerar\- retardamento, a variável de animação acelerar e desacelera em na duração de transição, finalizando em um valor especificado.  Você pode controlar como rapidamente a variável acelera e desacelera independente, especificando taxas diferentes de aceleração e a desaceleração.  Quando a velocidade de início é zero, a taxa de aceleração é a fração de duração que a variável gastará aceleração; também com a taxa de latência.  Se a velocidade de início é diferente de zero, é a fração de tempo entre velocidade de zero e atingir o final da transição.  A taxa de aceleração e a taxa da desaceleração devem somar um máximo de 1,0.  Como todas as transições são desmarcadas automaticamente, é recomendável atribuiu\-as que usam o novo operador.  O IUIAnimationTransition que encapsulado o objeto COM é criado por CAnimationController::AnimateGroup até lá, ele é NULO.  Alterando variáveis de membro após a criação de esse objeto COM não tem efeito.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CAccelerateDecelerateTransition](../../mfc/reference/cacceleratedeceleratetransition-class1.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)