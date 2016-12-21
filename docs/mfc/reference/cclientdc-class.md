---
title: "Classe de CClientDC | Microsoft Docs"
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
  - "CClientDC"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CClientDC"
  - "Classe de CDC, contextos de dispositivo para áreas cliente"
  - "contexto de dispositivo da área cliente"
  - "contextos de dispositivo, a área cliente"
ms.assetid: 8a871d6b-06f8-496e-9fa3-9a5780848369
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CClientDC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cuida do chamar funções do windows [GetDC](http://msdn.microsoft.com/library/windows/desktop/dd144871) em tempo de compilação e [ReleaseDC](http://msdn.microsoft.com/library/windows/desktop/dd162920) no momento da destruição.  
  
## Sintaxe  
  
```  
  
class CClientDC : public CDC  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CClientDC::CClientDC](../Topic/CClientDC::CClientDC.md)|Constrói um objeto de `CClientDC` conectado a `CWnd`.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CClientDC::m\_hWnd](../Topic/CClientDC::m_hWnd.md)|`HWND` da janela para que este `CClientDC` é válido.|  
  
## Comentários  
 Isso significa que o contexto de dispositivo associado a um objeto de `CClientDC` é a área cliente de uma janela.  
  
 Para obter mais informações sobre `CClientDC`, consulte [Contextos de dispositivo](../Topic/Device%20Contexts.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CDC](../Topic/CDC%20Class.md)  
  
 `CClientDC`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC prova MDI](../../top/visual-cpp-samples.md)   
 [CDC Class](../Topic/CDC%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CDC Class](../Topic/CDC%20Class.md)