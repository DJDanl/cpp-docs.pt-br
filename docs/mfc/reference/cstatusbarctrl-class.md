---
title: "Classe de CStatusBarCtrl | Microsoft Docs"
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
  - "CStatusBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CStatusBarCtrl"
  - "controles statusbar"
  - "Controles comuns do Windows [C++], CStatusBarCtrl"
ms.assetid: 8504ad38-7b91-4746-aede-ac98886eb47b
caps.latest.revision: 20
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStatusBarCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade comum de controle statusbar do windows.  
  
## Sintaxe  
  
```  
class CStatusBarCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStatusBarCtrl::CStatusBarCtrl](../Topic/CStatusBarCtrl::CStatusBarCtrl.md)|Constrói um objeto de `CStatusBarCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStatusBarCtrl::Create](../Topic/CStatusBarCtrl::Create.md)|Cria um controle de barra de status e anexá\-la a um objeto de `CStatusBarCtrl` .|  
|[CStatusBarCtrl::CreateEx](../Topic/CStatusBarCtrl::CreateEx.md)|Cria um controle de barra de status com os estilos estendidos o windows especificados e anexá\-la a um objeto de `CStatusBarCtrl` .|  
|[CStatusBarCtrl::DrawItem](../Topic/CStatusBarCtrl::DrawItem.md)|Chamado quando uma aparência visual de alterações de controle de barra de status do proprietário.|  
|[CStatusBarCtrl::GetBorders](../Topic/CStatusBarCtrl::GetBorders.md)|Recupera as larguras atuais das bordas horizontais e verticais de um controle statusbar.|  
|[CStatusBarCtrl::GetIcon](../Topic/CStatusBarCtrl::GetIcon.md)|Recupera o ícone para uma parte \(também conhecida como um painel\) no controle atual da barra de status.|  
|[CStatusBarCtrl::GetParts](../Topic/CStatusBarCtrl::GetParts.md)|Recupera uma contagem de partes em um controle statusbar.|  
|[CStatusBarCtrl::GetRect](../Topic/CStatusBarCtrl::GetRect.md)|Recupera o retângulo delimitador de uma parte em um controle statusbar.|  
|[CStatusBarCtrl::GetText](../Topic/CStatusBarCtrl::GetText.md)|Recupera o texto de uma determinada parte de um controle statusbar.|  
|[CStatusBarCtrl::GetTextLength](../Topic/CStatusBarCtrl::GetTextLength.md)|Recuperar o tamanho, em, caracteres de texto de uma determinada parte de um controle statusbar.|  
|[CStatusBarCtrl::GetTipText](../Topic/CStatusBarCtrl::GetTipText.md)|Recupera o texto de dica de ferramenta para um painel em uma barra de status.|  
|[CStatusBarCtrl::IsSimple](../Topic/CStatusBarCtrl::IsSimple.md)|Verifica um controle da janela de status para determinar se está no modo simples.|  
|[CStatusBarCtrl::SetBkColor](../Topic/CStatusBarCtrl::SetBkColor.md)|Define a cor do plano de fundo em uma barra de status.|  
|[CStatusBarCtrl::SetIcon](../Topic/CStatusBarCtrl::SetIcon.md)|Define o ícone para um painel em uma barra de status.|  
|[CStatusBarCtrl::SetMinHeight](../Topic/CStatusBarCtrl::SetMinHeight.md)|Defina a altura mínima da área de desenho de um controle statusbar.|  
|[CStatusBarCtrl::SetParts](../Topic/CStatusBarCtrl::SetParts.md)|Define o número de partes em um controle de barra de status e a coordenada da borda direita de cada parte.|  
|[CStatusBarCtrl::SetSimple](../Topic/CStatusBarCtrl::SetSimple.md)|Especifica se um controle statusbar exibe o texto simples ou exibe todas as partes de controle definidas por uma chamada anterior a `SetParts`.|  
|[CStatusBarCtrl::SetText](../Topic/CStatusBarCtrl::SetText.md)|Define o texto na parte fornecida de um controle statusbar.|  
|[CStatusBarCtrl::SetTipText](../Topic/CStatusBarCtrl::SetTipText.md)|Define o texto de dica de ferramenta para um painel em uma barra de status.|  
  
## Comentários  
 Um controle de “status bar é uma janela horizontal, normalmente exibida na parte inferior da janela pai, em que um aplicativo pode exibir vários tipos de informações de status.  O controle statusbar pode ser dividido em partes para exibir mais de um tipo de informações.  
  
 Este controle \(e portanto a classe de `CStatusBarCtrl` \) estão disponíveis somente para programas que executam na versão 3,51 do \/98 Windows 95 e Windows NT e posterior.  
  
 Para obter mais informações sobre como usar `CStatusBarCtrl`, consulte [Controles](../../mfc/controls-mfc.md) e [usando CStatusBarCtrl](../../mfc/using-cstatusbarctrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CStatusBarCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md)