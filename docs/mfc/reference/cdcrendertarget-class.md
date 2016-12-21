---
title: "Classe de CDCRenderTarget | Microsoft Docs"
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
  - "afxrendertarget/CDCRenderTarget"
  - "CDCRenderTarget"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDCRenderTarget"
ms.assetid: aa8059c9-08e6-49e4-9b8c-00fa54077a61
caps.latest.revision: 16
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDCRenderTarget
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para ID2D1DCRenderTarget.  
  
## Sintaxe  
  
```  
class CDCRenderTarget : public CRenderTarget;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDCRenderTarget::CDCRenderTarget](../Topic/CDCRenderTarget::CDCRenderTarget.md)|Constrói um objeto de CDCRenderTarget.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDCRenderTarget::Attach](../Topic/CDCRenderTarget::Attach.md)|A existência dos anexa processa a interface de destino para o objeto|  
|[CDCRenderTarget::BindDC](../Topic/CDCRenderTarget::BindDC.md)|Associa o destino processar para o contexto do dispositivo que controla a comandos de desenho|  
|[CDCRenderTarget::Create](../Topic/CDCRenderTarget::Create.md)|Cria um CDCRenderTarget.|  
|[CDCRenderTarget::Detach](../Topic/CDCRenderTarget::Detach.md)|Detaches processa a interface de destino do objeto|  
|[CDCRenderTarget::GetDCRenderTarget](../Topic/CDCRenderTarget::GetDCRenderTarget.md)|Interface de retorna ID2D1DCRenderTarget|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDCRenderTarget::operator ID2D1DCRenderTarget\*](../Topic/CDCRenderTarget::operator%20ID2D1DCRenderTarget*.md)|Interface de retorna ID2D1DCRenderTarget|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDCRenderTarget::m\_pDCRenderTarget](../Topic/CDCRenderTarget::m_pDCRenderTarget.md)|Um ponteiro para um objeto de ID2D1DCRenderTarget.|  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CRenderTarget](../../mfc/reference/crendertarget-class.md)  
  
 [CDCRenderTarget](../../mfc/reference/cdcrendertarget-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)