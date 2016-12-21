---
title: "Classe de CMFCDesktopAlertDialog | Microsoft Docs"
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
  - "CMFCDesktopAlertDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCDesktopAlertDialog"
ms.assetid: a53c60aa-9607-485b-b826-ec64962075f6
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCDesktopAlertDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `CMFCDesktopAlertDialog` classe é usada junto com o [Classe de CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md) para exibir uma caixa de diálogo personalizada em uma janela pop\-up.  
  
## Sintaxe  
  
```  
class CMFCDesktopAlertDialog : public CDialogEx  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCDesktopAlertDialog::CreateFromParams](../Topic/CMFCDesktopAlertDialog::CreateFromParams.md)||  
|[CMFCDesktopAlertDialog::GetDlgSize](../Topic/CMFCDesktopAlertDialog::GetDlgSize.md)||  
|[CMFCDesktopAlertDialog::HasFocus](../Topic/CMFCDesktopAlertDialog::HasFocus.md)||  
|[CMFCDesktopAlertDialog::PreTranslateMessage](../Topic/CMFCDesktopAlertDialog::PreTranslateMessage.md)|\(Substitui `CDialogEx::PreTranslateMessage`.\)|  
  
### Observações  
 Execute as seguintes etapas para exibir uma caixa de diálogo personalizada em uma janela pop\-up:  
  
1.  Derive uma classe de `CMFCDesktopAlertDialog`.  
  
2.  Crie um modelo de caixa de diálogo filho nos recursos do projeto.  
  
3.  Chamar [CMFCDesktopAlertWnd::Create](../Topic/CMFCDesktopAlertWnd::Create.md) com a ID de recurso do modelo de caixa de diálogo e um ponteiro para as informações de classe de tempo de execução da classe derivada como parâmetros.  
  
4.  A caixa de diálogo personalizada para manipular todas as notificações que vêm os controles hospedados de programas ou programar os controles hospedados para manipular essas notificações diretamente.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDialogEx](../../mfc/reference/cdialogex-class.md)  
  
 [CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxDesktopAlertDialog.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)   
 [Classe de CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)   
 [Classe de CDialogEx](../../mfc/reference/cdialogex-class.md)