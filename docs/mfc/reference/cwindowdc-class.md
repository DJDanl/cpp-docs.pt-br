---
title: "Classe de CWindowDC | Microsoft Docs"
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
  - "CWindowDC"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CWindowDC"
  - "contextos de dispositivo, janela"
  - "classes de saída de tela"
ms.assetid: 876a3641-4cde-471c-b0d1-fe58b32af79c
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWindowDC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Derivada de `CDC`.  
  
## Sintaxe  
  
```  
class CWindowDC : public CDC  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWindowDC::CWindowDC](../Topic/CWindowDC::CWindowDC.md)|Constrói um objeto `CWindowDC`.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWindowDC::m\_hWnd](../Topic/CWindowDC::m_hWnd.md)|O `HWND` ao qual este `CWindowDC` está anexado.|  
  
## Comentários  
 Chama a função do Windows [GetWindowDC](http://msdn.microsoft.com/library/windows/desktop/dd144947\(v=vs.85\).aspx)no tempo de construção e [ReleaseDC](http://msdn.microsoft.com/library/windows/desktop/dd162920\(v=vs.85\).aspx) no tempo de destruição.  Isso significa que um objeto `CWindowDC` acessa a área da tela inteira de [CWnd](../Topic/CWnd%20Class.md) \(áreas de cliente e que não é destinada ao cliente\).  
  
 Para obter mais informações sobre o uso de `CWindowDC`, consulte [Contextos de dispositivo](../Topic/Device%20Contexts.md).  
  
## Hierarquia de Herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CDC](../Topic/CDC%20Class.md)  
  
 `CWindowDC`  
  
## Requisitos  
 Cabeçalho: afxwin.h  
  
## Consulte também  
 [CDC Class](../Topic/CDC%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CDC Class](../Topic/CDC%20Class.md)