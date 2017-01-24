---
title: "Classe de CControlBar | Microsoft Docs"
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
  - "CControlBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CControlBar"
  - "barras de controle [C++], classe base"
  - "barras da caixa de diálogo, classe base"
  - "O OLE redimensiona barras"
  - "O OLE redimensiona barras, classe base"
  - "barras de status, classe base"
  - "barras de ferramentas [C++], classe base"
ms.assetid: 4d668c55-9b42-4838-97ac-cf2b3000b82c
caps.latest.revision: 22
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CControlBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base para a barra de controle classe [CStatusBar](../../mfc/reference/cstatusbar-class.md), [CToolBar](../../mfc/reference/ctoolbar-class.md), [CDialogBar](../../mfc/reference/cdialogbar-class.md), [CReBar](../../mfc/reference/crebar-class.md), e [COleResizeBar](../../mfc/reference/coleresizebar-class.md).  
  
## Sintaxe  
  
```  
class CControlBar : public CWnd  
```  
  
## Membros  
  
### Construtores Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CControlBar::CControlBar](../Topic/CControlBar::CControlBar.md)|Constrói um objeto `CControlBar`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CControlBar::CalcDynamicLayout](../Topic/CControlBar::CalcDynamicLayout.md)|Retorna o tamanho de uma barra de controle dinâmico como um objeto de [CSize](../../atl-mfc-shared/reference/csize-class.md) .|  
|[CControlBar::CalcFixedLayout](../Topic/CControlBar::CalcFixedLayout.md)|Retorna o tamanho da barra de controle como um objeto de [CSize](../../atl-mfc-shared/reference/csize-class.md) .|  
|[CControlBar::CalcInsideRect](../Topic/CControlBar::CalcInsideRect.md)|Retorna as dimensões atuais da área da barra de controle; incluindo as bordas.|  
|[CControlBar::DoPaint](../Topic/CControlBar::DoPaint.md)|Processa as bordas e a alça da barra de controle.|  
|[CControlBar::DrawBorders](../Topic/CControlBar::DrawBorders.md)|Processa as bordas da barra de controle.|  
|[CControlBar::DrawGripper](../Topic/CControlBar::DrawGripper.md)|Processa a alça da barra de controle.|  
|[CControlBar::EnableDocking](../Topic/CControlBar::EnableDocking.md)|Permite que uma barra de controle é entrada ou flutuante.|  
|[CControlBar::GetBarStyle](../Topic/CControlBar::GetBarStyle.md)|Recupera as configurações de estilo de barra de controle.|  
|[CControlBar::GetBorders](../Topic/CControlBar::GetBorders.md)|Recupera os valores da borda da barra de controle.|  
|[CControlBar::GetCount](../Topic/CControlBar::GetCount.md)|Retorna o número de elementos que não são de`HWND` na barra de controle.|  
|[CControlBar::GetDockingFrame](../Topic/CControlBar::GetDockingFrame.md)|Retorna um ponteiro para o quadro a que uma barra de controle é entrada.|  
|[CControlBar::IsFloating](../Topic/CControlBar::IsFloating.md)|Retorna um valor diferente de zero se a barra de controle em questão é uma barra de controle de flutuante.|  
|[CControlBar::OnUpdateCmdUI](../Topic/CControlBar::OnUpdateCmdUI.md)|Chamar manipuladores de interface de usuário de comando.|  
|[CControlBar::SetBarStyle](../Topic/CControlBar::SetBarStyle.md)|Altera as configurações de estilo de barra de controle.|  
|[CControlBar::SetBorders](../Topic/CControlBar::SetBorders.md)|Defina os valores da borda da barra de controle.|  
|[CControlBar::SetInPlaceOwner](../Topic/CControlBar::SetInPlaceOwner.md)|Altera o proprietário no lugar de uma barra de controle.|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CControlBar::m\_bAutoDelete](../Topic/CControlBar::m_bAutoDelete.md)|Se for diferente de zero, o objeto de `CControlBar` é excluído quando a barra de controle do Windows é destruída.|  
|[CControlBar::m\_pInPlaceOwner](../Topic/CControlBar::m_pInPlaceOwner.md)|O proprietário no lugar da barra de controle.|  
  
## Comentários  
 Uma barra de controle é uma janela que é alinhada normalmente a esquerda ou direita de uma janela de quadro.  Pode conter itens filhos que são um ou outros controles com base em `HWND`, que são janelas que gerenciar e respondem às mensagens do Windows, ou itens que não são baseadas em`HWND`, que não são janelas e são gerenciados pelo código do aplicativo ou pelo código de estrutura.  Caixas de listagem e controles de edição são exemplos de controles com base em `HWND`; os painéis de barra de status e botões de bitmap são exemplos de controles com base em não\- de`HWND`.  
  
 As janelas de barra de controle são geralmente janelas filho de uma janela pai do quadro e geralmente são irmãos para modo de cliente ou o cliente MDI da janela do quadro.  Um objeto de `CControlBar` usa informações sobre o retângulo pai do cliente da janela para posicionar si.  Informa na janela pai a respeito do quanto espaço restante não na área pai do cliente da janela.  
  
 Para obter mais informações sobre a `CControlBar`, consulte:  
  
-   [Barras de Controle](../Topic/Control%20Bars.md)  
  
-   [Observação técnica 31: Barras de controle](../../mfc/tn031-control-bars.md).  
  
-   Artigo de Base de Dados de Conhecimento Q242577: PRB: Os manipuladores de interface de usuário de comando de atualização não funciona para o menu anexado a uma caixa de diálogo  
  
## Hierarquia de Herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CControlBar`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [Exemplo CTRLBARS MFC](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CToolBar](../../mfc/reference/ctoolbar-class.md)   
 [Classe de CDialogBar](../../mfc/reference/cdialogbar-class.md)   
 [Classe de CStatusBar](../../mfc/reference/cstatusbar-class.md)   
 [Classe de CReBar](../../mfc/reference/crebar-class.md)