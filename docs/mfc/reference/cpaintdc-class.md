---
title: "Classe de CPaintDC | Microsoft Docs"
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
  - "CPaintDC"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPaintDC"
  - "Manipulador de OnPaint"
  - "Mensagem de WM_PAINT"
ms.assetid: 7e245baa-bf9b-403e-a637-7218adf28fab
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPaintDC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe derivada de dispositivo contexto de [CDC](../Topic/CDC%20Class.md).  
  
## Sintaxe  
  
```  
class CPaintDC : public CDC  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaintDC::CPaintDC](../Topic/CPaintDC::CPaintDC.md)|Constrói `CPaintDC` conectado a [CWnd](../Topic/CWnd%20Class.md)especificado.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaintDC::m\_ps](../Topic/CPaintDC::m_ps.md)|Contém [PAINTSTRUCT](../../mfc/reference/paintstruct-structure.md) usado para pintar a área cliente.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaintDC::m\_hWnd](../Topic/CPaintDC::m_hWnd.md)|`HWND` a que este objeto de `CPaintDC` é anexado.|  
  
## Comentários  
 Executa [CWnd::BeginPaint](../Topic/CWnd::BeginPaint.md) em tempo de compilação e [CWnd::EndPaint](../Topic/CWnd::EndPaint.md) no momento da destruição.  
  
 Um objeto de `CPaintDC` pode ser usado somente para responder a uma mensagem de [WM\_PAINT](http://msdn.microsoft.com/library/windows/desktop/dd145213) , geralmente na função de membro de mensagem\- manipulador de `OnPaint` .  
  
 Para obter mais informações sobre como usar `CPaintDC`, consulte [Contextos de dispositivo](../Topic/Device%20Contexts.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CDC](../Topic/CDC%20Class.md)  
  
 `CPaintDC`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC prova MDI](../../top/visual-cpp-samples.md)   
 [CDC Class](../Topic/CDC%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)