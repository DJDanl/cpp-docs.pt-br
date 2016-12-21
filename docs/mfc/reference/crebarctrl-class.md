---
title: "Classe de CReBarCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CReBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CReBarCtrl"
  - "controles do rebar, barra de controle"
  - "controles do rebar, Classe de CReBarCtrl"
ms.assetid: 154570d7-e48c-425d-8c7e-c64542bcb4cc
caps.latest.revision: 23
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CReBarCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula funcionalidade de um controle rebar, que é um contêiner para uma janela filho.  
  
## Sintaxe  
  
```  
class CReBarCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CReBarCtrl::CReBarCtrl](../Topic/CReBarCtrl::CReBarCtrl.md)|Constrói um objeto de `CReBarCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CReBarCtrl::BeginDrag](../Topic/CReBarCtrl::BeginDrag.md)|Coloca o controle rebar no modo de arrastar e soltar.|  
|[CReBarCtrl::Create](../Topic/CReBarCtrl::Create.md)|Cria o controle rebar e anexá\-la ao objeto de `CReBarCtrl` .|  
|[CReBarCtrl::CreateEx](../Topic/CReBarCtrl::CreateEx.md)|Cria um controle rebar com os estilos estendidos o windows especificados e anexá\-la a um objeto de `CReBarCtrl` .|  
|[CReBarCtrl::DeleteBand](../Topic/CReBarCtrl::DeleteBand.md)|Exclui uma faixa de um controle rebar.|  
|[CReBarCtrl::DragMove](../Topic/CReBarCtrl::DragMove.md)|Atualiza a posição de arrastar o controle rebar após uma chamada a `BeginDrag`.|  
|[CReBarCtrl::EndDrag](../Topic/CReBarCtrl::EndDrag.md)|Finaliza a operação de arrastar e soltar o controle rebar.|  
|[CReBarCtrl::GetBandBorders](../Topic/CReBarCtrl::GetBandBorders.md)|Recupera as bordas de uma faixa.|  
|[CReBarCtrl::GetBandCount](../Topic/CReBarCtrl::GetBandCount.md)|Recupera a contagem das faixas no controle rebar.|  
|[CReBarCtrl::GetBandInfo](../Topic/CReBarCtrl::GetBandInfo.md)|Recupera informações sobre uma faixa especificada em um controle rebar.|  
|[CReBarCtrl::GetBandMargins](../Topic/CReBarCtrl::GetBandMargins.md)|Recupera as margens de uma faixa.|  
|[CReBarCtrl::GetBarHeight](../Topic/CReBarCtrl::GetBarHeight.md)|Recupera a altura do controle rebar.|  
|[CReBarCtrl::GetBarInfo](../Topic/CReBarCtrl::GetBarInfo.md)|Recupera informações sobre o controle rebar e a lista de imagem que usa.|  
|[CReBarCtrl::GetBkColor](../Topic/CReBarCtrl::GetBkColor.md)|Recupera a cor do plano de fundo padrão de um controle rebar.|  
|[CReBarCtrl::GetColorScheme](../Topic/CReBarCtrl::GetColorScheme.md)|Recupera a estrutura de [COLORSCHEME](http://msdn.microsoft.com/library/windows/desktop/bb775502) associada com o controle rebar.|  
|[CReBarCtrl::GetDropTarget](../Topic/CReBarCtrl::GetDropTarget.md)|Recupera o ponteiro de interface de `IDropTarget` de um controle rebar.|  
|[CReBarCtrl::GetExtendedStyle](../Topic/CReBarCtrl::GetExtendedStyle.md)|Obtém o estilo estendidas do controle atual do rebar.|  
|[CReBarCtrl::GetImageList](../Topic/CReBarCtrl::GetImageList.md)|Recupera a lista de imagem associada com um controle rebar.|  
|[CReBarCtrl::GetPalette](../Topic/CReBarCtrl::GetPalette.md)|Recupera a paleta atual do controle rebar.|  
|[CReBarCtrl::GetRect](../Topic/CReBarCtrl::GetRect.md)|Recupera o retângulo delimitador para uma determinada faixa em um controle rebar.|  
|[CReBarCtrl::GetRowCount](../Topic/CReBarCtrl::GetRowCount.md)|Retorna o número de linhas de faixa em um controle rebar.|  
|[CReBarCtrl::GetRowHeight](../Topic/CReBarCtrl::GetRowHeight.md)|Recupera a altura de uma linha especificada em um controle rebar.|  
|[CReBarCtrl::GetTextColor](../Topic/CReBarCtrl::GetTextColor.md)|Recupera o texto da cor padrão de um controle rebar.|  
|[CReBarCtrl::GetToolTips](../Topic/CReBarCtrl::GetToolTips.md)|Recupera o identificador a qualquer controle dica de ferramenta associada com o controle rebar.|  
|[CReBarCtrl::HitTest](../Topic/CReBarCtrl::HitTest.md)|Determina qual parte de uma faixa do rebar está em um determinado ponto na tela, se uma faixa do rebar existe em esse ponto.|  
|[CReBarCtrl::IDToIndex](../Topic/CReBarCtrl::IDToIndex.md)|Converte um identificador \(ID\) de faixa a um índice de faixa em um controle rebar.|  
|[CReBarCtrl::InsertBand](../Topic/CReBarCtrl::InsertBand.md)|Insere uma nova faixa em um controle rebar.|  
|[CReBarCtrl::MaximizeBand](../Topic/CReBarCtrl::MaximizeBand.md)|Redimensionar uma faixa em um controle rebar ao seu tamanho maior.|  
|[CReBarCtrl::MinimizeBand](../Topic/CReBarCtrl::MinimizeBand.md)|Redimensionar uma faixa em um controle rebar ao seu tamanho menor.|  
|[CReBarCtrl::MoveBand](../Topic/CReBarCtrl::MoveBand.md)|Move uma faixa de um índice para outro.|  
|[CReBarCtrl::PushChevron](../Topic/CReBarCtrl::PushChevron.md)|Pressiona programaticamente uma viga.|  
|[CReBarCtrl::RestoreBand](../Topic/CReBarCtrl::RestoreBand.md)|Redimensionar uma faixa em um controle rebar ao seu tamanho ideal.|  
|[CReBarCtrl::SetBandInfo](../Topic/CReBarCtrl::SetBandInfo.md)|Define características de uma faixa existente em um controle rebar.|  
|[CReBarCtrl::SetBandWidth](../Topic/CReBarCtrl::SetBandWidth.md)|Defina a largura de faixa entrada especificada no controle atual do rebar.|  
|[CReBarCtrl::SetBarInfo](../Topic/CReBarCtrl::SetBarInfo.md)|Defina as características de um controle rebar.|  
|[CReBarCtrl::SetBkColor](../Topic/CReBarCtrl::SetBkColor.md)|Define a cor do plano de fundo padrão de um controle rebar.|  
|[CReBarCtrl::SetColorScheme](../Topic/CReBarCtrl::SetColorScheme.md)|Defina o esquema de cores para os botões em um controle rebar.|  
|[CReBarCtrl::SetExtendedStyle](../Topic/CReBarCtrl::SetExtendedStyle.md)|Define estilos estendidos para o controle atual do rebar.|  
|[CReBarCtrl::SetImageList](../Topic/CReBarCtrl::SetImageList.md)|Define a lista de imagem de um controle rebar.|  
|[CReBarCtrl::SetOwner](../Topic/CReBarCtrl::SetOwner.md)|Define a janela do proprietário de um controle rebar.|  
|[CReBarCtrl::SetPalette](../Topic/CReBarCtrl::SetPalette.md)|Defina a paleta atual do controle rebar.|  
|[CReBarCtrl::SetTextColor](../Topic/CReBarCtrl::SetTextColor.md)|Define a cor do texto padrão de um controle rebar.|  
|[CReBarCtrl::SetToolTips](../Topic/CReBarCtrl::SetToolTips.md)|Associa um controle dica de ferramenta com o controle rebar.|  
|[CReBarCtrl::SetWindowTheme](../Topic/CReBarCtrl::SetWindowTheme.md)|Defina o estilo visual do controle rebar.|  
|[CReBarCtrl::ShowBand](../Topic/CReBarCtrl::ShowBand.md)|Mostra ou oculta uma determinada faixa em um controle rebar.|  
|[CReBarCtrl::SizeToRect](../Topic/CReBarCtrl::SizeToRect.md)|Couber um controle rebar a um retângulo especificado.|  
  
## Comentários  
 O aplicativo no qual o controle rebar reside atribui a janela filho contida pelo controle rebar a faixa do rebar.  a janela filho é geralmente um outro controle comum.  
  
 Os controles do Rebar contém uma ou mais faixas.  Cada faixa pode conter uma combinação de uma barra de alça, um bitmap, de um rótulo de texto, e uma janela filho.  A faixa pode conter somente um de cada um de esses itens.  
  
 O controle rebar pode exibir a janela filho em um bitmap em segundo plano especificado.  Todas as faixas de controle rebar podem ser redimensionadas, exceto aqueles que usam o estilo de **RBBS\_FIXEDSIZE** .  Porque você reposiciona ou redimensionar uma faixa de controle rebar, o controle rebar gerencia o tamanho e a posição da janela filho atribuído à faixa.  Para redimensionar ou alterar a ordem de faixas dentro do controle, de clique e arraste a alça de uma barra de faixa.  
  
 A ilustração a seguir mostra um controle rebar que tem três faixas:  
  
-   A faixa 0 contém um plano, controle de barra de ferramentas transparente.  
  
-   A faixa 1 contém o padrão transparente e os botões lista transparente.  
  
-   A faixa 2 contém uma caixa de combinação e quatro botões padrão.  
  
     ![Tela de RebarMenuSample](../../mfc/reference/media/vc4scc1.png "vc4SCC1")  
  
## Controle Rebar  
 Suporte do Rebar:  
  
-   Listas de imagem.  
  
-   Gerenciamento de mensagens.  
  
-   Funcionalidade personalizada de desenho.  
  
-   Uma variedade de estilos de controle além de estilos de janela padrão.  Para obter uma lista de esses estilos, consulte [Estilos de controle Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774377) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações, consulte [usando CReBarCtrl](../Topic/Using%20CReBarCtrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CReBarCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)