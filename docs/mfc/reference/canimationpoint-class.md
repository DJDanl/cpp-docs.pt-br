---
title: "Classe de CAnimationPoint | Microsoft Docs"
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
  - "CAnimationPoint"
  - "afxanimationcontroller/CAnimationPoint"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationPoint"
ms.assetid: 5dc4d46f-e695-4681-b15c-544b78b3e317
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationPoint
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a funcionalidade de um ponto cujas as coordenadas podem ser animadas.  
  
## Sintaxe  
  
```  
class CAnimationPoint : public CAnimationBaseObject;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationPoint::CAnimationPoint](../Topic/CAnimationPoint::CAnimationPoint.md)|Sobrecarregado.  Objeto de CAnimationPoint da compilação.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationPoint::AddTransition](../Topic/CAnimationPoint::AddTransition.md)|Adiciona as transições para coordenadas X e Y.|  
|[CAnimationPoint::GetDefaultValue](../Topic/CAnimationPoint::GetDefaultValue.md)|Retorna os valores padrão para coordenadas X e Y.|  
|[CAnimationPoint::GetValue](../Topic/CAnimationPoint::GetValue.md)|Retorna o valor atual.|  
|[CAnimationPoint::GetX](../Topic/CAnimationPoint::GetX.md)|Fornece acesso a CAnimationVariable para a coordenada X.|  
|[CAnimationPoint::GetY](../Topic/CAnimationPoint::GetY.md)|Fornece acesso a CAnimationVariable para a coordenada Y.|  
|[CAnimationPoint::SetDefaultValue](../Topic/CAnimationPoint::SetDefaultValue.md)|Defina o valor padrão.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationPoint::GetAnimationVariableList](../Topic/CAnimationPoint::GetAnimationVariableList.md)|Coloca as variáveis encapsulados de animação em uma lista.  Overrides \( [CAnimationBaseObject::GetAnimationVariableList](../Topic/CAnimationBaseObject::GetAnimationVariableList.md).\)|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationPoint::operator CPoint](../Topic/CAnimationPoint::operator%20CPoint.md)|Converte um CAnimationPoint a um CPoint.|  
|[CAnimationPoint::operator\=](../Topic/CAnimationPoint::operator=.md)|Atribui o ptSrc a CAnimationPoint.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationPoint::m\_xValue](../Topic/CAnimationPoint::m_xValue.md)|A variável encapsulado de animação que representa a coordenada X do ponto de animação.|  
|[CAnimationPoint::m\_yValue](../Topic/CAnimationPoint::m_yValue.md)|A variável encapsulado de animação que representa a coordenada Y do ponto de animação.|  
  
## Comentários  
 A classe encapsula de CAnimationPoint dois objetos de CAnimationVariable e pode representar em aplicativos um ponto.  Por exemplo, você pode usar esta classe para animar a posição de qualquer objeto na tela \(como a cadeia de caracteres de texto, circunde, aponte etc.\).  Para usar esta classe no aplicativo, apenas criar uma instância de um objeto da classe, adicione\-o ao controlador de animação que usa CAnimationController::AddAnimationObject e chamar AddTransition para cada transição é aplicada às coordenadas X e\/ou Y.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
 [CAnimationPoint](../../mfc/reference/canimationpoint-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)