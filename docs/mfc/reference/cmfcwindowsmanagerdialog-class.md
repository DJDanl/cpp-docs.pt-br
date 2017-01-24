---
title: "Classe de CMFCWindowsManagerDialog | Microsoft Docs"
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
  - "CMFCWindowsManagerDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCWindowsManagerDialog"
ms.assetid: 35b4b0db-33c4-4b22-94d8-5e3396341340
caps.latest.revision: 25
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCWindowsManagerDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O objeto de `CMFCWindowsManagerDialog` permite que um usuário para gerenciar janelas filho MDI em um aplicativo MDI.  
  
## Sintaxe  
  
```  
class CMFCWindowsManagerDialog : public CDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCWindowsManagerDialog::CMFCWindowsManagerDialog](../Topic/CMFCWindowsManagerDialog::CMFCWindowsManagerDialog.md)|Constrói um objeto de `CMFCWindowsManagerDialog` .|  
  
## Comentários  
 `CMFCWindowsManagerDialog` contém uma lista de janelas filho MDI que estão abertas no aplicativo.  O usuário pode manualmente controlar o estado das janelas filho MDI usando esta caixa de diálogo.  
  
 `CMFCWindowsManagerDialog` é inserido em [Classe CMDIFrameWndEx](../Topic/CMDIFrameWndEx%20Class.md).  `CMFCWindowsManagerDialog` não é uma classe que você deve criar manualmente.  Em vez de isso, chame a função [CMDIFrameWndEx::ShowWindowsDialog](../Topic/CMDIFrameWndEx::ShowWindowsDialog.md), e criar e exibirá um objeto de `CMFCWindowsManagerDialog` .  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCWindowsManagerDialog` chamando `CMDIFrameWndEx::ShowWindowsDialog`.  Este trecho de código é parte de [Exemplo de demonstração do Visual Studio](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#18](../../mfc/reference/codesnippet/CPP/cmfcwindowsmanagerdialog-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxWindowsManagerDialog.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe CMDIFrameWndEx](../Topic/CMDIFrameWndEx%20Class.md)   
 [CMDIFrameWndEx::ShowWindowsDialog](../Topic/CMDIFrameWndEx::ShowWindowsDialog.md)