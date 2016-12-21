---
title: "Classe de CAnimationStoryboardEventHandler | Microsoft Docs"
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
  - "afxanimationcontroller/CAnimationStoryboardEventHandler"
  - "CAnimationStoryboardEventHandler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationStoryboardEventHandler"
ms.assetid: 10a7e86b-c02d-4124-9a2e-61ecf8ac62fc
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationStoryboardEventHandler
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um retorno de chamada, que é chamado pela animação API quando o status de um storyboard é modificado ou um storyboard é atualizado.  
  
## Sintaxe  
  
```  
class CAnimationStoryboardEventHandler : public CUIAnimationStoryboardEventHandlerBase<CAnimationStoryboardEventHandler>;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationStoryboardEventHandler::CAnimationStoryboardEventHandler](../Topic/CAnimationStoryboardEventHandler::CAnimationStoryboardEventHandler.md)|Constrói um objeto de `CAnimationStoryboardEventHandler` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationStoryboardEventHandler::CreateInstance](../Topic/CAnimationStoryboardEventHandler::CreateInstance.md)|Cria uma instância de retorno de chamada de `CAnimationStoryboardEventHandler` .|  
|[CAnimationStoryboardEventHandler::OnStoryboardStatusChanged](../Topic/CAnimationStoryboardEventHandler::OnStoryboardStatusChanged.md)|Trata os eventos de `OnStoryboardStatusChanged` , que ocorrem quando o status de um storyboard muda \( `CUIAnimationStoryboardEventHandlerBase::OnStoryboardStatusChanged`alternativas.\)|  
|[CAnimationStoryboardEventHandler::OnStoryboardUpdated](../Topic/CAnimationStoryboardEventHandler::OnStoryboardUpdated.md)|Trata os eventos de `OnStoryboardUpdated` , que ocorrem quando um storyboard é atualizado \(Substitui `CUIAnimationStoryboardEventHandlerBase::OnStoryboardUpdated`\).|  
|[CAnimationStoryboardEventHandler::SetAnimationController](../Topic/CAnimationStoryboardEventHandler::SetAnimationController.md)|Armazena um ponteiro para o controlador de animação para rotear eventos.|  
  
## Comentários  
 Este manipulador de eventos é criado e passado para o método de `IUIAnimationStoryboard::SetStoryboardEventHandler` , quando você chama `CAnimationController::EnableStoryboardEventHandler`.  
  
## Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationStoryboardEventHandlerBase`  
  
 `CAnimationStoryboardEventHandler`  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)