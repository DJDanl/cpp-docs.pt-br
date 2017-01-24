---
title: "Classe de CSliderCtrl | Microsoft Docs"
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
  - "CSliderCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSliderCtrl"
  - "Classe de CSliderCtrl, controles comuns"
  - "controles slider, Classe de CSliderCtrl"
  - "Controles comuns do Windows [C++], CSliderCtrl"
ms.assetid: dd12b084-4eda-4550-a810-8f3cfb06b871
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSliderCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle deslizante comuns.  
  
## Sintaxe  
  
```  
class CSliderCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSliderCtrl::CSliderCtrl](../Topic/CSliderCtrl::CSliderCtrl.md)|Constrói um objeto de `CSliderCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSliderCtrl::ClearSel](../Topic/CSliderCtrl::ClearSel.md)|Limpa a seleção atual em um controle slider.|  
|[CSliderCtrl::ClearTics](../Topic/CSliderCtrl::ClearTics.md)|Remove as marcas atual de um controle deslizante.|  
|[CSliderCtrl::Create](../Topic/CSliderCtrl::Create.md)|Cria um controle deslizante e anexá\-la a um objeto de `CSliderCtrl` .|  
|[CSliderCtrl::CreateEx](../Topic/CSliderCtrl::CreateEx.md)|Cria um controle deslizante com os estilos estendidos o windows especificados e anexá\-la a um objeto de `CSliderCtrl` .|  
|[CSliderCtrl::GetBuddy](../Topic/CSliderCtrl::GetBuddy.md)|Recupera a alça a uma janela de amigo de controle slider em um local especificado.|  
|[CSliderCtrl::GetChannelRect](../Topic/CSliderCtrl::GetChannelRect.md)|Retorna o tamanho do canal de controle slider.|  
|[CSliderCtrl::GetLineSize](../Topic/CSliderCtrl::GetLineSize.md)|Recupera a linha tamanho de um controle deslizante.|  
|[CSliderCtrl::GetNumTics](../Topic/CSliderCtrl::GetNumTics.md)|Retorna o número de marcas em um controle slider.|  
|[CSliderCtrl::GetPageSize](../Topic/CSliderCtrl::GetPageSize.md)|Retorna o tamanho de página de um controle deslizante.|  
|[CSliderCtrl::GetPos](../Topic/CSliderCtrl::GetPos.md)|Recupera a posição atual de controle slider.|  
|[CSliderCtrl::GetRange](../Topic/CSliderCtrl::GetRange.md)|Recupera as posições de mínimo e máximo para um controle deslizante.|  
|[CSliderCtrl::GetRangeMax](../Topic/CSliderCtrl::GetRangeMax.md)|Recupera a posição máximo para um controle deslizante.|  
|[CSliderCtrl::GetRangeMin](../Topic/CSliderCtrl::GetRangeMin.md)|Recupera a posição mínima para um controle deslizante.|  
|[CSliderCtrl::GetSelection](../Topic/CSliderCtrl::GetSelection.md)|Retorna o intervalo de seleção atual.|  
|[CSliderCtrl::GetThumbLength](../Topic/CSliderCtrl::GetThumbLength.md)|Retorna o tamanho do controle deslizante no controle trackbar atual.|  
|[CSliderCtrl::GetThumbRect](../Topic/CSliderCtrl::GetThumbRect.md)|Retorna o tamanho thumb de controle slider.|  
|[CSliderCtrl::GetTic](../Topic/CSliderCtrl::GetTic.md)|Retorna a posição da marca de escala especificado.|  
|[CSliderCtrl::GetTicArray](../Topic/CSliderCtrl::GetTicArray.md)|Recupera a matriz de posições de escala de marca para um controle deslizante.|  
|[CSliderCtrl::GetTicPos](../Topic/CSliderCtrl::GetTicPos.md)|Retorna a posição da marca de escala especificada, em coordenadas do cliente.|  
|[CSliderCtrl::GetToolTips](../Topic/CSliderCtrl::GetToolTips.md)|Recupera a alça ao controle de tooltip atribuído ao controle deslizante, se houver.|  
|[CSliderCtrl::SetBuddy](../Topic/CSliderCtrl::SetBuddy.md)|Atribui uma janela como a janela autorizado para um controle deslizante.|  
|[CSliderCtrl::SetLineSize](../Topic/CSliderCtrl::SetLineSize.md)|Define a linha tamanho de um controle deslizante.|  
|[CSliderCtrl::SetPageSize](../Topic/CSliderCtrl::SetPageSize.md)|Defina o tamanho de página de um controle deslizante.|  
|[CSliderCtrl::SetPos](../Topic/CSliderCtrl::SetPos.md)|Define a posição atual de controle slider.|  
|[CSliderCtrl::SetRange](../Topic/CSliderCtrl::SetRange.md)|Defina as posições de mínimo e máximo para um controle deslizante.|  
|[CSliderCtrl::SetRangeMax](../Topic/CSliderCtrl::SetRangeMax.md)|Define a posição máximo para um controle deslizante.|  
|[CSliderCtrl::SetRangeMin](../Topic/CSliderCtrl::SetRangeMin.md)|Define a posição mínima para um controle deslizante.|  
|[CSliderCtrl::SetSelection](../Topic/CSliderCtrl::SetSelection.md)|Define o intervalo de seleção atual.|  
|[CSliderCtrl::SetThumbLength](../Topic/CSliderCtrl::SetThumbLength.md)|Defina o tamanho do controle deslizante no controle trackbar atual.|  
|[CSliderCtrl::SetTic](../Topic/CSliderCtrl::SetTic.md)|Define a posição da marca de escala especificado.|  
|[CSliderCtrl::SetTicFreq](../Topic/CSliderCtrl::SetTicFreq.md)|Define a freqüência de marcas por incremento de controle slider.|  
|[CSliderCtrl::SetTipSide](../Topic/CSliderCtrl::SetTipSide.md)|Posiciona um controle de tooltip usado por um controle trackbar.|  
|[CSliderCtrl::SetToolTips](../Topic/CSliderCtrl::SetToolTips.md)|Atribui um controle de tooltip a um controle deslizante.|  
  
## Comentários  
 Um “slider” \(também conhecido como um trackbar\) é uma janela que contém um controle deslizante e as marcas opcionais.  Quando o usuário move o controle deslizante, usando o mouse ou teclas de direção, o controle envia notificações para indicar a alteração.  
  
 Os controles slider são úteis quando você deseja que o usuário selecione um valor discreto ou um conjunto de valores consecutivos em um intervalo.  Por exemplo, você pode usar um controle deslizante para permitir que o usuário definia a taxa de repetição do teclado movendo o controle deslizante um marca de escala determinada.  
  
 Este controle \(e portanto a classe de `CSliderCtrl` \) estão disponíveis somente para programas que executam na versão 3,51 do \/98 Windows 95 e Windows NT e posterior.  
  
 Move o controle deslizante em incrementos que você especifica quando você os cria.  Por exemplo, se você especificar que o controle slider deve ter um intervalo de cinco, o controle deslizante só pode ocupar seis posições: uma posição no lado esquerdo de controle slider e uma posição para cada incremento no intervalo.  Normalmente, cada uma de essas posições é identificada por uma marca de escala.  
  
 Você cria um controle deslizante usando o construtor e a função de membro de **Criar** de `CSliderCtrl`.  Uma vez que você criou um controle deslizante, você pode usar funções de membro em `CSliderCtrl` para alterar muitas das suas propriedades.  Alterações que você pode fazer para incluir definir as posições de mínimo e máximo para o controle deslizante, desenhar marcas, defina um intervalo de seleção, e o reposicionamento de controle slider.  
  
 Para obter mais informações sobre como usar `CSliderCtrl`, consulte [Controles](../../mfc/controls-mfc.md) e [usando CSliderCtrl](../../mfc/using-csliderctrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CSliderCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [O MFC exemplos CMNCTRL2](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CProgressCtrl](../../mfc/reference/cprogressctrl-class.md)