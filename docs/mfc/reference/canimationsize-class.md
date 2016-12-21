---
title: "Classe de CAnimationSize | Microsoft Docs"
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
  - "afxanimationcontroller/CAnimationSize"
  - "CAnimationSize"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationSize"
ms.assetid: ea06d1b5-502c-44a3-82ca-8bd6ba6a9364
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationSize
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a funcionalidade de um objeto de tamanho cujas as dimensões podem ser animadas.  
  
## Sintaxe  
  
```  
class CAnimationSize : public CAnimationBaseObject;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationSize::CAnimationSize](../Topic/CAnimationSize::CAnimationSize.md)|Sobrecarregado.  Constrói um objeto de tamanho da animação.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationSize::AddTransition](../Topic/CAnimationSize::AddTransition.md)|Adiciona as transições para a largura e altura.|  
|[CAnimationSize::GetCX](../Topic/CAnimationSize::GetCX.md)|Fornece acesso a CAnimationVariable que representa a largura.|  
|[CAnimationSize::GetCY](../Topic/CAnimationSize::GetCY.md)|Fornece acesso a CAnimationVariable que representa a altura.|  
|[CAnimationSize::GetDefaultValue](../Topic/CAnimationSize::GetDefaultValue.md)|Retorna os valores padrão para a largura e altura.|  
|[CAnimationSize::GetValue](../Topic/CAnimationSize::GetValue.md)|Retorna o valor atual.|  
|[CAnimationSize::SetDefaultValue](../Topic/CAnimationSize::SetDefaultValue.md)|Defina o valor padrão.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationSize::GetAnimationVariableList](../Topic/CAnimationSize::GetAnimationVariableList.md)|Coloca as variáveis encapsulados de animação em uma lista.  Overrides \( [CAnimationBaseObject::GetAnimationVariableList](../Topic/CAnimationBaseObject::GetAnimationVariableList.md).\)|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationSize::operator CSize](../Topic/CAnimationSize::operator%20CSize.md)|Converte um CAnimationSize a um CSize.|  
|[CAnimationSize::operator\=](../Topic/CAnimationSize::operator=.md)|Atribui o szSrc a CAnimationSize.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationSize::m\_cxValue](../Topic/CAnimationSize::m_cxValue.md)|A variável encapsulado de animação que representa a largura do tamanho da animação.|  
|[CAnimationSize::m\_cyValue](../Topic/CAnimationSize::m_cyValue.md)|A variável encapsulado de animação que representa a altura do tamanho da animação.|  
  
## Comentários  
 A classe encapsula de CAnimationSize dois objetos de CAnimationVariable e pode representar um tamanho em aplicativos.  Por exemplo, você pode usar esta classe para animar um tamanho de qualquer objeto na tela bidimensional \(como o retângulo controle, etc.\).  Para usar esta classe no aplicativo, apenas criar uma instância de um objeto da classe, adicione\-o ao controlador de animação que usa CAnimationController::AddAnimationObject e chamar AddTransition para cada transição é aplicada à largura e\/ou altura.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
 [CAnimationSize](../../mfc/reference/canimationsize-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)