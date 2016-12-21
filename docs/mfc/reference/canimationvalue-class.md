---
title: "Classe de CAnimationValue | Microsoft Docs"
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
  - "afxanimationcontroller/CAnimationValue"
  - "CAnimationValue"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationValue"
ms.assetid: 78c5ae19-ede5-4f20-bfbe-68b467b603c2
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationValue
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a funcionalidade do objeto de animação que tem um valor.  
  
## Sintaxe  
  
```  
class CAnimationValue : public CAnimationBaseObject;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationValue::CAnimationValue](../Topic/CAnimationValue::CAnimationValue.md)|Sobrecarregado.  Constrói um objeto de CAnimationValue.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationValue::AddTransition](../Topic/CAnimationValue::AddTransition.md)|Adiciona uma transição para ser aplicada a um valor.|  
|[CAnimationValue::GetValue](../Topic/CAnimationValue::GetValue.md)|Sobrecarregado.  Recupera o valor atual.|  
|[CAnimationValue::GetVariable](../Topic/CAnimationValue::GetVariable.md)|Fornece acesso à variável encapsulado de animação.|  
|[CAnimationValue::SetDefaultValue](../Topic/CAnimationValue::SetDefaultValue.md)|Defina o valor padrão.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationValue::GetAnimationVariableList](../Topic/CAnimationValue::GetAnimationVariableList.md)|Coloca a variável encapsulado de animação em uma lista.  Overrides \( [CAnimationBaseObject::GetAnimationVariableList](../Topic/CAnimationBaseObject::GetAnimationVariableList.md).\)|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[DOBRO de CAnimationValue::operator](../Topic/CAnimationValue::operator%20DOUBLE.md)|Fornece a conversão entre CAnimationValue e DOBRO.|  
|[CAnimationValue::operator INT32](../Topic/CAnimationValue::operator%20INT32.md)|Fornece a conversão entre CAnimationValue e INT32.|  
|[CAnimationValue::operator\=](../Topic/CAnimationValue::operator=.md)|Sobrecarregado.  Atribui um valor INT32 a CAnimationValue.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationValue::m\_value](../Topic/CAnimationValue::m_value.md)|A variável encapsulado de animação que representa o valor da animação.|  
  
## Comentários  
 A classe de CAnimationValue encapsula um único objeto de CAnimationVariable e pode representar em aplicativos um único valor animado.  Por exemplo, você pode usar esta classe para transparência animado \(se o efeito de esmaecimento\), o ângulo \(para girar objetos\), ou para quaisquer outros casos quando você precisa criar uma animação como um único valor animado.  Para usar esta classe no aplicativo, apenas criar uma instância de um objeto da classe, adicione\-o ao controlador de animação que usa CAnimationController::AddAnimationObject e chamar AddTransition para cada transição é aplicada ao valor.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
 [CAnimationValue](../../mfc/reference/canimationvalue-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)