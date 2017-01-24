---
title: "Classe de CAnimationVariableChangeHandler | Microsoft Docs"
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
  - "afxanimationcontroller/CAnimationVariableChangeHandler"
  - "CAnimationVariableChangeHandler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationVariableChangeHandler"
ms.assetid: 2ea4996d-5c04-4dfc-be79-d42d55050795
caps.latest.revision: 19
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationVariableChangeHandler
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um retorno de chamada, que é chamado pela animação API quando o valor de uma variável de animação é alterado.  
  
## Sintaxe  
  
```  
class CAnimationVariableChangeHandler : public CUIAnimationVariableChangeHandlerBase<CAnimationVariableChangeHandler>;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CAnimationVariableChangeHandler::CAnimationVariableChangeHandler`|Constrói um objeto de `CAnimationVariableChangeHandler` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CAnimationVariableChangeHandler::CreateInstance`|Cria uma instância do objeto de `CAnimationVariableChangeHandler` .|  
|[CAnimationVariableChangeHandler::OnValueChanged](../Topic/CAnimationVariableChangeHandler::OnValueChanged.md)|Chamado quando um valor de uma variável de animação alterar.  Overrides \( `CUIAnimationVariableChangeHandlerBase::OnValueChanged`.\)|  
|[CAnimationVariableChangeHandler::SetAnimationController](../Topic/CAnimationVariableChangeHandler::SetAnimationController.md)|Armazena um ponteiro para o controlador de animação para rotear eventos.|  
  
## Comentários  
 Este manipulador de eventos é criado e passado para o método de `IUIAnimationVariable::SetVariableChangeHandler` , quando você chama `CAnimationVariable::EnableValueChangedEvent` ou `CAnimationBaseObject::EnableValueChangedEvent` \(que permite que este evento para quaisquer variáveis de animação encapsulados em um objeto de animação.\)  
  
## Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationVariableChangeHandlerBase`  
  
 `CAnimationVariableChangeHandler`  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)