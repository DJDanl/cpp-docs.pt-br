---
title: "Classe de CAnimationColor | Microsoft Docs"
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
  - "CAnimationColor"
  - "afxanimationcontroller/CAnimationColor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationColor"
ms.assetid: 88bfabd4-efeb-4652-87e8-304253d8e48c
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationColor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a funcionalidade de uma cor cujo componentes vermelho, verde e azul, podem ser animadas.  
  
## Sintaxe  
  
```  
class CAnimationColor : public CAnimationBaseObject;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationColor::CAnimationColor](../Topic/CAnimationColor::CAnimationColor.md)|Sobrecarregado.  Constrói um objeto de cor da animação.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationColor::AddTransition](../Topic/CAnimationColor::AddTransition.md)|Adiciona as transições para componentes vermelho, verde e azul.|  
|[CAnimationColor::GetB](../Topic/CAnimationColor::GetB.md)|Fornece acesso a CAnimationVariable que representa o componente azul.|  
|[CAnimationColor::GetDefaultValue](../Topic/CAnimationColor::GetDefaultValue.md)|Retorna os valores padrão para componentes de cor.|  
|[CAnimationColor::GetG](../Topic/CAnimationColor::GetG.md)|Fornece acesso a CAnimationVariable que representa o componente verde.|  
|[CAnimationColor::GetR](../Topic/CAnimationColor::GetR.md)|Fornece acesso a CAnimationVariable que representa o componente vermelho.|  
|[CAnimationColor::GetValue](../Topic/CAnimationColor::GetValue.md)|Retorna o valor atual.|  
|[CAnimationColor::SetDefaultValue](../Topic/CAnimationColor::SetDefaultValue.md)|Defina o valor padrão.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationColor::GetAnimationVariableList](../Topic/CAnimationColor::GetAnimationVariableList.md)|Coloca as variáveis encapsulados de animação em uma lista.  Overrides \( [CAnimationBaseObject::GetAnimationVariableList](../Topic/CAnimationBaseObject::GetAnimationVariableList.md).\)|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationColor::operator COLORREF](../Topic/CAnimationColor::operator%20COLORREF.md)||  
|[CAnimationColor::operator\=](../Topic/CAnimationColor::operator=.md)|Atribuir a cor a CAnimationColor.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationColor::m\_bValue](../Topic/CAnimationColor::m_bValue.md)|A variável encapsulado de animação que representa o componente azul a cor da animação.|  
|[CAnimationColor::m\_gValue](../Topic/CAnimationColor::m_gValue.md)|A variável encapsulado de animação que representa o componente verde a cor da animação.|  
|[CAnimationColor::m\_rValue](../Topic/CAnimationColor::m_rValue.md)|A variável encapsulado de animação que representa o componente vermelho a cor da animação.|  
  
## Comentários  
 A classe encapsula de CAnimationColor três objetos de CAnimationVariable e pode representar uma cor em aplicativos.  Por exemplo, você pode usar esta classe para animar cores de qualquer objeto na tela \(como a cor do texto, a cor do plano de fundo etc.\).  Para usar esta classe no aplicativo, apenas criar uma instância de um objeto da classe, adicione\-o ao controlador de animação que usa CAnimationController::AddAnimationObject e chamar AddTransition para cada transição é aplicada a componentes vermelho, verde e azul.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
 [CAnimationColor](../../mfc/reference/canimationcolor-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)