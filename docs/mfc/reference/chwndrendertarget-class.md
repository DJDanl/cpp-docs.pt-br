---
title: "Classe de CHwndRenderTarget | Microsoft Docs"
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
  - "CHwndRenderTarget"
  - "afxrendertarget/CHwndRenderTarget"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CHwndRenderTarget"
ms.assetid: aa65b69f-7202-46ea-af81-ef325da0b840
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CHwndRenderTarget
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para ID2D1HwndRenderTarget.  
  
## Sintaxe  
  
```  
class CHwndRenderTarget : public CRenderTarget;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHwndRenderTarget::CHwndRenderTarget](../Topic/CHwndRenderTarget::CHwndRenderTarget.md)|Constrói um objeto de CHwndRenderTarget de HWND.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHwndRenderTarget::Attach](../Topic/CHwndRenderTarget::Attach.md)|A existência dos anexa processa a interface de destino para o objeto|  
|[CHwndRenderTarget::CheckWindowState](../Topic/CHwndRenderTarget::CheckWindowState.md)|Indica se os HWND associados com este processam o destino são fechados.|  
|[CHwndRenderTarget::Create](../Topic/CHwndRenderTarget::Create.md)|Cria um destino processar associado com a janela|  
|[CHwndRenderTarget::Detach](../Topic/CHwndRenderTarget::Detach.md)|Detaches processa a interface de destino do objeto|  
|[CHwndRenderTarget::GetHwnd](../Topic/CHwndRenderTarget::GetHwnd.md)|Retorna o HWND associado com este processam o destino.|  
|[CHwndRenderTarget::GetHwndRenderTarget](../Topic/CHwndRenderTarget::GetHwndRenderTarget.md)|Interface de retorna ID2D1HwndRenderTarget.|  
|[CHwndRenderTarget::ReCreate](../Topic/CHwndRenderTarget::ReCreate.md)|Recria um destino processar associado com a janela|  
|[CHwndRenderTarget::Resize](../Topic/CHwndRenderTarget::Resize.md)|Altera o tamanho de destino processar o tamanho especificado de pixel|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHwndRenderTarget::operator ID2D1HwndRenderTarget\*](../Topic/CHwndRenderTarget::operator%20ID2D1HwndRenderTarget*.md)|Interface de retorna ID2D1HwndRenderTarget.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHwndRenderTarget::m\_pHwndRenderTarget](../Topic/CHwndRenderTarget::m_pHwndRenderTarget.md)|Um ponteiro para um objeto de ID2D1HwndRenderTarget.|  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CRenderTarget](../../mfc/reference/crendertarget-class.md)  
  
 [CHwndRenderTarget](../../mfc/reference/chwndrendertarget-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)