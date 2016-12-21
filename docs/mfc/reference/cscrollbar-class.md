---
title: "Classe de CScrollBar | Microsoft Docs"
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
  - "CScrollBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles [MFC], barra de rolagem"
  - "Classe de CScrollBar"
  - "barras de rolagem"
  - "Classe de janela de BARRA DE ROLAGEM"
  - "Controles comuns do Windows [C++], CScrollBar"
ms.assetid: f3735ca5-73ea-46dc-918b-4d824c9fe47f
caps.latest.revision: 21
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CScrollBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade de um controle barra de rolagem do windows.  
  
## Sintaxe  
  
```  
class CScrollBar : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CScrollBar::CScrollBar](../Topic/CScrollBar::CScrollBar.md)|Constrói um objeto de `CScrollBar` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CScrollBar::Create](../Topic/CScrollBar::Create.md)|Cria a barra de rolagem do windows e anexá\-la ao objeto de `CScrollBar` .|  
|[CScrollBar::EnableScrollBar](../Topic/CScrollBar::EnableScrollBar.md)|Habilita ou desabilita uma ou ambas a seta de uma barra de rolagem.|  
|[CScrollBar::GetScrollBarInfo](../Topic/CScrollBar::GetScrollBarInfo.md)|Recupera informações sobre a barra de rolagem usando uma estrutura de `SCROLLBARINFO` .|  
|[CScrollBar::GetScrollInfo](../Topic/CScrollBar::GetScrollInfo.md)|Recupera informações sobre a barra de rolagem.|  
|[CScrollBar::GetScrollLimit](../Topic/CScrollBar::GetScrollLimit.md)|Recupera o limite de barra de rolagem|  
|[CScrollBar::GetScrollPos](../Topic/CScrollBar::GetScrollPos.md)|Recupera a posição atual de uma caixa de rolagem.|  
|[CScrollBar::GetScrollRange](../Topic/CScrollBar::GetScrollRange.md)|Recupera as posições atual do mínimo e da barra de rolagem do máximo para a barra de rolagem fornecida.|  
|[CScrollBar::SetScrollInfo](../Topic/CScrollBar::SetScrollInfo.md)|Define informações sobre a barra de rolagem.|  
|[CScrollBar::SetScrollPos](../Topic/CScrollBar::SetScrollPos.md)|Define a posição atual de uma caixa de rolagem.|  
|[CScrollBar::SetScrollRange](../Topic/CScrollBar::SetScrollRange.md)|Define o mínimo e máximo valores de posição para a barra de rolagem fornecida.|  
|[CScrollBar::ShowScrollBar](../Topic/CScrollBar::ShowScrollBar.md)|Mostra ou oculta um a barra de rolagem.|  
  
## Comentários  
 Você cria um controle de barra de rolagem em duas etapas.  Primeiro, o construtor `CScrollBar` para construir o objeto de `CScrollBar` , então chamar a função de membro de [Criar](../Topic/CScrollBar::Create.md) para criar o controle barra de rolagem do windows para e anexá\-la ao objeto de `CScrollBar` .  
  
 Se você criar um objeto de `CScrollBar` de uma caixa de diálogo \(através de um recurso da caixa de diálogo\), `CScrollBar` é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um objeto de `CScrollBar` em uma janela, você também precisará destrui\-la.  
  
 Se você criar o objeto de `CScrollBar` na pilha, é automaticamente destruída.  Se você criar o objeto de `CScrollBar` no heap usando a função de **new** , você deve chamar **delete** no objeto para destrui\-lo quando o usuário termina a barra de rolagem do windows.  
  
 Se você atribuir qualquer memória do objeto de `CScrollBar` , substitua o destrutor de `CScrollBar` para descartar as alocações.  
  
 Para informações relacionadas sobre o uso de `CScrollBar`, consulte [Controles](../../mfc/controls-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CScrollBar`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Classe de CButton](../../mfc/reference/cbutton-class.md)   
 [Classe de CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Classe de CEdit](../Topic/CEdit%20Class.md)   
 [Classe de CListBox](../Topic/CListBox%20Class.md)   
 [Classe de CStatic](../Topic/CStatic%20Class.md)   
 [Classe de CDialog](../../mfc/reference/cdialog-class.md)