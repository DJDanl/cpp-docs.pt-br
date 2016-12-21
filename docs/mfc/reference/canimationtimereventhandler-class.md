---
title: "Classe de CAnimationTimerEventHandler | Microsoft Docs"
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
  - "afxanimationcontroller/CAnimationTimerEventHandler"
  - "CAnimationTimerEventHandler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationTimerEventHandler"
ms.assetid: 188dea3b-4b5e-4f6b-8df9-09d993a21619
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationTimerEventHandler
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um retorno de chamada, que é chamado pela API animação ocorrem quando os eventos de tempo.  
  
## Sintaxe  
  
```  
class CAnimationTimerEventHandler : public CUIAnimationTimerEventHandlerBase<CAnimationTimerEventHandler>;  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationTimerEventHandler::CreateInstance](../Topic/CAnimationTimerEventHandler::CreateInstance.md)|Cria uma instância de retorno de chamada de `CAnimationTimerEventHandler` .|  
|[CAnimationTimerEventHandler::OnPostUpdate](../Topic/CAnimationTimerEventHandler::OnPostUpdate.md)|Trata os eventos que ocorrem após uma atualização de animação é concluída.  Overrides \( `CUIAnimationTimerEventHandlerBase::OnPostUpdate`.\)|  
|[CAnimationTimerEventHandler::OnPreUpdate](../Topic/CAnimationTimerEventHandler::OnPreUpdate.md)|Trata os eventos que ocorrem antes que uma atualização de animação começa.  Overrides \( `CUIAnimationTimerEventHandlerBase::OnPreUpdate`.\)|  
|[CAnimationTimerEventHandler::OnRenderingTooSlow](../Topic/CAnimationTimerEventHandler::OnRenderingTooSlow.md)|Trata os eventos que ocorrem quando a taxa de quadros renderizados para uma animação ficar sob a taxa de quadros desejável mínima.  Overrides \( `CUIAnimationTimerEventHandlerBase::OnRenderingTooSlow`.\)|  
|[CAnimationTimerEventHandler::SetAnimationController](../Topic/CAnimationTimerEventHandler::SetAnimationController.md)|Armazena um ponteiro para o controlador de animação para rotear eventos.|  
  
## Comentários  
 Este manipulador de eventos é criado e passado para IUIAnimationTimer::SetTimerEventHandler quando você chama CAnimationController::EnableAnimationTimerEventHandler.  
  
## Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationTimerEventHandlerBase`  
  
 `CAnimationTimerEventHandler`  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)