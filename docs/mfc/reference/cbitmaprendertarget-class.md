---
title: "Classe de CBitmapRenderTarget | Microsoft Docs"
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
  - "afxrendertarget/CBitmapRenderTarget"
  - "CBitmapRenderTarget"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CBitmapRenderTarget"
ms.assetid: c89a4437-812e-4943-acb2-b429a04cc4d2
caps.latest.revision: 16
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CBitmapRenderTarget
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para ID2D1BitmapRenderTarget.  
  
## Sintaxe  
  
```  
class CBitmapRenderTarget : public CRenderTarget;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBitmapRenderTarget::CBitmapRenderTarget](../Topic/CBitmapRenderTarget::CBitmapRenderTarget.md)|Constrói um objeto de CBitmapRenderTarget.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBitmapRenderTarget::Attach](../Topic/CBitmapRenderTarget::Attach.md)|A existência dos anexa processa a interface de destino para o objeto|  
|[CBitmapRenderTarget::Detach](../Topic/CBitmapRenderTarget::Detach.md)|Detaches processa a interface de destino do objeto|  
|[CBitmapRenderTarget::GetBitmap](../Topic/CBitmapRenderTarget::GetBitmap.md)|Recupera o bitmap para isso processam o destino.  o bitmap retornado pode ser usado desenhando operações.|  
|[CBitmapRenderTarget::GetBitmapRenderTarget](../Topic/CBitmapRenderTarget::GetBitmapRenderTarget.md)|Interface de retorna ID2D1BitmapRenderTarget|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBitmapRenderTarget::operator ID2D1BitmapRenderTarget\*](../Topic/CBitmapRenderTarget::operator%20ID2D1BitmapRenderTarget*.md)|Interface de retorna ID2D1BitmapRenderTarget|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBitmapRenderTarget::m\_pBitmapRenderTarget](../Topic/CBitmapRenderTarget::m_pBitmapRenderTarget.md)|Um ponteiro para um objeto de ID2D1BitmapRenderTarget.|  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CRenderTarget](../../mfc/reference/crendertarget-class.md)  
  
 [CBitmapRenderTarget](../../mfc/reference/cbitmaprendertarget-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)