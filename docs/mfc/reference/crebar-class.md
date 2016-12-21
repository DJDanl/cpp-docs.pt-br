---
title: "Classe de CReBar | Microsoft Docs"
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
  - "CReBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CReBar"
  - "Controles comuns do Internet Explorer 4.0"
  - "controles do rebar, barra de controle"
ms.assetid: c1ad2720-1d33-4106-8e4e-80aa84f93559
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CReBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma barra de controle que fornece o layout, a persistência, e as informações do estado de controles do rebar.  
  
## Sintaxe  
  
```  
  
class CReBar : public CControlBar  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CReBar::AddBar](../Topic/CReBar::AddBar.md)|Adiciona uma faixa a um rebar.|  
|[CReBar::Create](../Topic/CReBar::Create.md)|Cria o controle rebar e anexá\-la ao objeto de `CReBar` .|  
|[CReBar::GetReBarCtrl](../Topic/CReBar::GetReBarCtrl.md)|Permite acesso direto ao controle comum subjacente.|  
  
## Comentários  
 Um objeto do rebar pode conter uma variedade de janelas filho, geralmente outros controles, incluindo caixas de edição, barras de ferramentas, e caixas de listagem.  Um objeto do rebar pode exibir suas janelas\-filho em um bitmap especificado.  Seu aplicativo pode redimensionar automaticamente o rebar, ou o usuário pode redimensionar manualmente o rebar clicando em ou arrastando sua barra de alça.  
  
 ![Tela de RebarMenuSample](../../mfc/reference/media/vc4sc61.png "vc4SC61")  
  
## Controle Rebar  
 Um objeto do rebar se comporta de forma semelhante a um objeto da barra de ferramentas.  Um rebar usa o mecanismo de clique\-e\- arraste para redimensionar as faixas.  Um controle rebar pode conter uma ou mais faixas, com cada faixa que tem qualquer combinação de uma barra de alça, um bitmap, de um rótulo de texto, e uma janela filho.  Em o entanto, as faixas não podem conter mais de uma janela filho.  
  
 **CReBar** usa a classe de [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) para fornecer sua implementação.  Você pode acessar o controle rebar com [GetReBarCtrl](../Topic/CReBar::GetReBarCtrl.md) para tirar proveito das opções de personalização do controle.  Para obter mais informações sobre controles do rebar, consulte `CReBarCtrl`.  Para obter mais informações sobre controles do rebar, consulte [usando CReBarCtrl](../Topic/Using%20CReBarCtrl.md).  
  
> [!CAUTION]
>  Os objetos do Rebar e do controle rebar não suportam o encaixe da barra de controle MFC.  Se **CRebar::EnableDocking** é chamado, seu aplicativo afirmará.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CReBar`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [Exemplo MFCIE MFC](../../top/visual-cpp-samples.md)   
 [Classe de CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)