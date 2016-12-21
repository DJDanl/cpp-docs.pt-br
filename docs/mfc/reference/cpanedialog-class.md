---
title: "Classe de CPaneDialog | Microsoft Docs"
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
  - "CPaneDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPaneDialog"
  - "Construtor de CPaneDialog"
  - "Método de CPaneDialog::CreateObject"
  - "Método de CPaneDialog::OnEraseBkgnd"
  - "Método de CPaneDialog::OnLButtonDblClk"
  - "Método de CPaneDialog::OnLButtonDown"
  - "Método de CPaneDialog::OnUpdateCmdUI"
  - "Método de CPaneDialog::OnWindowPosChanging"
ms.assetid: 48a6bb91-4b92-40f5-8907-b3270b146cf6
caps.latest.revision: 27
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPaneDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CPaneDialog` suporta uma caixa de diálogo sem\-modo, encaixável.  
  
## Sintaxe  
  
```  
class CPaneDialog : public CDockablePane  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CPaneDialog::CPaneDialog`|Construtor padrão.|  
|`CPaneDialog::~CPaneDialog`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneDialog::Create](../Topic/CPaneDialog::Create.md)|Cria uma caixa de diálogo encaixável e anexá\-la a um objeto de `CPaneDialog` .|  
|`CPaneDialog::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|`CPaneDialog::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CPaneDialog::HandleInitDialog](../Topic/CPaneDialog::HandleInitDialog.md)|Trata a mensagem de [WM\_INITDIALOG](http://msdn.microsoft.com/library/windows/desktop/ms645428) .  \(Redefine `CBasePane::HandleInitDialog`.\)|  
|`CPaneDialog::OnEraseBkgnd`|Trata a mensagem de [WM\_ERASEBKGND](http://msdn.microsoft.com/library/windows/desktop/ms648055) .  \(Redefine [CWnd::OnEraseBkgnd](../Topic/CWnd::OnEraseBkgnd.md).\)|  
|`CPaneDialog::OnLButtonDblClk`|Trata a mensagem de [WM\_LBUTTONDBLCLK](http://msdn.microsoft.com/library/windows/desktop/ms645606) .  \(Redefine [CWnd::OnLButtonDblClk](../Topic/CWnd::OnLButtonDblClk.md).\)|  
|`CPaneDialog::OnLButtonDown`|Trata a mensagem de [WM\_LBUTTONDOWN](http://msdn.microsoft.com/library/windows/desktop/ms645607) .  \(Redefine [CWnd::OnLButtonDown](../Topic/CWnd::OnLButtonDown.md).\)|  
|`CPaneDialog::OnUpdateCmdUI`|Chamado pela estrutura para atualizar a janela da caixa de diálogo.  Overrides \( [CDockablePane::OnUpdateCmdUI](http://msdn.microsoft.com/pt-br/5dd61606-1c12-40d4-b024-f3839aa5e2e0).\)|  
|`CPaneDialog::OnWindowPosChanging`|Trata a mensagem de [WM\_WINDOWPOSCHANGING](http://msdn.microsoft.com/library/windows/desktop/ms632653) .  \(Redefine [CWnd::OnWindowPosChanging](../Topic/CWnd::OnWindowPosChanging.md).\)|  
|[CPaneDialog::SetOccDialogInfo](../Topic/CPaneDialog::SetOccDialogInfo.md)|Especifica o modelo para uma caixa de diálogo que é um contêiner controlador do OLE.|  
  
## Comentários  
 Construir um objeto de `CPaneDialog` em duas etapas.  Primeiro, construir o objeto no seu código.  Segundo, [CPaneDialog::Create](../Topic/CPaneDialog::Create.md)chamada.  Você deve especificar um identificador válido do nome do modelo de recurso ou modelo e passar um ponteiro para a janela pai.  Caso contrário, o processo de criação falhar.  A caixa de diálogo deve especificar o estilo WS\_CHILD e de WS\_VISIBLE.  Recomendamos que você também especifica os estilos de WS\_CLIPCHILDREN e de WS\_CLIPSIBLINGS.  Para mais informações, consulte [Estilos de janela](../Topic/Window%20Styles.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CDockablePane](../Topic/CDockablePane%20Class.md)  
  
 [CPaneDialog](../../mfc/reference/cpanedialog-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxpanedialog.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CDockablePane](../Topic/CDockablePane%20Class.md)   
 [Estilos de janela](../Topic/Window%20Styles.md)