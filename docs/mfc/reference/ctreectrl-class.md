---
title: "Classe de CTreeCtrl | Microsoft Docs"
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
  - "CTreeCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTreeCtrl"
  - "listas de diretório"
  - "arquivo lista [C++]"
  - "controles de exibição de árvore"
ms.assetid: 96e20031-6161-4143-8c12-8d1816c66d90
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTreeCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle comum de modo de exibição de árvore do windows.  
  
## Sintaxe  
  
```  
class CTreeCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTreeCtrl::CTreeCtrl](../Topic/CTreeCtrl::CTreeCtrl.md)|Constrói um objeto de `CTreeCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTreeCtrl::Create](../Topic/CTreeCtrl::Create.md)|Cria um controle de exibição de árvore e anexá\-la a um objeto de `CTreeCtrl` .|  
|[CTreeCtrl::CreateDragImage](../Topic/CTreeCtrl::CreateDragImage.md)|Cria um bitmap arrastando para o item especificado modo de exibição de árvore.|  
|[CTreeCtrl::CreateEx](../Topic/CTreeCtrl::CreateEx.md)|Cria um controle de árvore com os estilos estendidos o windows especificados e anexá\-la a um objeto de `CTreeCtrl` .|  
|[CTreeCtrl::DeleteAllItems](../Topic/CTreeCtrl::DeleteAllItems.md)|Exclui todos os itens em um controle de exibição de árvore.|  
|[CTreeCtrl::DeleteItem](../Topic/CTreeCtrl::DeleteItem.md)|Exclui um novo item em um controle de exibição de árvore.|  
|[CTreeCtrl::EditLabel](../Topic/CTreeCtrl::EditLabel.md)|Editar um item específico de modo de exibição de árvore no lugar.|  
|[CTreeCtrl::EndEditLabelNow](../Topic/CTreeCtrl::EndEditLabelNow.md)|Cancelar a operação de edição no rótulo de um item de modo de exibição em árvore do controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::EnsureVisible](../Topic/CTreeCtrl::EnsureVisible.md)|Garante que um item de modo de exibição de árvore é visível no controle de exibição de árvore.|  
|[CTreeCtrl::Expand](../Topic/CTreeCtrl::Expand.md)|Expanda, ou recolhe, os itens filhos item especificado modo de exibição de árvore.|  
|[CTreeCtrl::GetBkColor](../Topic/CTreeCtrl::GetBkColor.md)|Recupera a cor do plano de fundo do controle atual.|  
|[CTreeCtrl::GetCheck](../Topic/CTreeCtrl::GetCheck.md)|Recupera o estado de verificação de um item de controle da árvore.|  
|[CTreeCtrl::GetChildItem](../Topic/CTreeCtrl::GetChildItem.md)|Recupera o filho de um item específico de modo de exibição de árvore.|  
|[CTreeCtrl::GetCount](../Topic/CTreeCtrl::GetCount.md)|Retorna o número de itens da árvore associados com um controle de exibição de árvore.|  
|[CTreeCtrl::GetDropHilightItem](../Topic/CTreeCtrl::GetDropHilightItem.md)|Recupera o destino de uma operação de arrastar e soltar.|  
|[CTreeCtrl::GetEditControl](../Topic/CTreeCtrl::GetEditControl.md)|Recupera a alça de controle edit usado para editar o item especificado modo de exibição de árvore.|  
|[CTreeCtrl::GetExtendedStyle](../Topic/CTreeCtrl::GetExtendedStyle.md)|Recupera os estilos estendidos que o controle atual do modo de exibição de árvore está usando.|  
|[CTreeCtrl::GetFirstVisibleItem](../Topic/CTreeCtrl::GetFirstVisibleItem.md)|Retorna o primeiro item visível de item especificado modo de exibição de árvore.|  
|[CTreeCtrl::GetImageList](../Topic/CTreeCtrl::GetImageList.md)|Recupera o identificador da lista de imagem associada a um controle de exibição de árvore.|  
|[CTreeCtrl::GetIndent](../Topic/CTreeCtrl::GetIndent.md)|Recupera o deslocamento \(em pixels\) de um item de modo de exibição de árvore de seu pai.|  
|[CTreeCtrl::GetInsertMarkColor](../Topic/CTreeCtrl::GetInsertMarkColor.md)|Recupera a cor usada para desenhar a marca de inserção para o modo de exibição de árvore.|  
|[CTreeCtrl::GetItem](../Topic/CTreeCtrl::GetItem.md)|Recupera os atributos de um item específico de modo de exibição de árvore.|  
|[CTreeCtrl::GetItemData](../Topic/CTreeCtrl::GetItemData.md)|Retorna o valor específico do aplicativo de 32 bits associados com um item.|  
|[CTreeCtrl::GetItemExpandedImageIndex](../Topic/CTreeCtrl::GetItemExpandedImageIndex.md)|Retorna o índice da imagem para exibir quando o item especificado do controle atual do modo de exibição de árvore está no estado expandido.|  
|[CTreeCtrl::GetItemHeight](../Topic/CTreeCtrl::GetItemHeight.md)|Recupera a altura atual dos itens em modo de exibição de árvore.|  
|[CTreeCtrl::GetItemImage](../Topic/CTreeCtrl::GetItemImage.md)|Recupera as imagens associados com um item.|  
|[CTreeCtrl::GetItemPartRect](../Topic/CTreeCtrl::GetItemPartRect.md)|Recupera o retângulo delimitador de uma parte específica de um item específico no controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::GetItemRect](../Topic/CTreeCtrl::GetItemRect.md)|Recupera o retângulo delimitador de um item modo de exibição de árvore.|  
|[CTreeCtrl::GetItemState](../Topic/CTreeCtrl::GetItemState.md)|Retorna o estado de um item.|  
|[CTreeCtrl::GetItemStateEx](../Topic/CTreeCtrl::GetItemStateEx.md)|Recupera o estado estendido de item especificado no controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::GetItemText](../Topic/CTreeCtrl::GetItemText.md)|Retorna o texto de um item.|  
|[CTreeCtrl::GetLastVisibleItem](../Topic/CTreeCtrl::GetLastVisibleItem.md)|Recupera o item expandido último no controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::GetLineColor](../Topic/CTreeCtrl::GetLineColor.md)|Recupera a linha atual cor para o controle de exibição de árvore.|  
|[CTreeCtrl::GetNextItem](../Topic/CTreeCtrl::GetNextItem.md)|Recuperar o próximo item modo de exibição de árvore que corresponde a uma relação especificada.|  
|[CTreeCtrl::GetNextSiblingItem](../Topic/CTreeCtrl::GetNextSiblingItem.md)|O exemplo a seguir recupera irmão de item especificado modo de exibição de árvore.|  
|[CTreeCtrl::GetNextVisibleItem](../Topic/CTreeCtrl::GetNextVisibleItem.md)|Recupera o item visível seguir de item especificado modo de exibição de árvore.|  
|[CTreeCtrl::GetParentItem](../Topic/CTreeCtrl::GetParentItem.md)|Recupera o pai de um item específico de modo de exibição de árvore.|  
|[CTreeCtrl::GetPrevSiblingItem](../Topic/CTreeCtrl::GetPrevSiblingItem.md)|Recupera o irmão anterior do item especificado modo de exibição de árvore.|  
|[CTreeCtrl::GetPrevVisibleItem](../Topic/CTreeCtrl::GetPrevVisibleItem.md)|Recupera o item anterior visível de item especificado modo de exibição de árvore.|  
|[CTreeCtrl::GetRootItem](../Topic/CTreeCtrl::GetRootItem.md)|Recupera a raiz do item especificado modo de exibição de árvore.|  
|[CTreeCtrl::GetScrollTime](../Topic/CTreeCtrl::GetScrollTime.md)|Recupera o tempo máximo de rolagem para o controle de exibição de árvore.|  
|[CTreeCtrl::GetSelectedCount](../Topic/CTreeCtrl::GetSelectedCount.md)|Retorna o número de itens selecionados no controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::GetSelectedItem](../Topic/CTreeCtrl::GetSelectedItem.md)|Recupera o item atualmente selecionado em modo de exibição de árvore.|  
|[CTreeCtrl::GetTextColor](../Topic/CTreeCtrl::GetTextColor.md)|Recupera a cor do texto atual do controle.|  
|[CTreeCtrl::GetToolTips](../Topic/CTreeCtrl::GetToolTips.md)|Recupera o identificador para o tipo de controle ToolTip filho usado por um controle de exibição de árvore.|  
|[CTreeCtrl::GetVisibleCount](../Topic/CTreeCtrl::GetVisibleCount.md)|Retorna o número de itens visíveis de árvore associados com um controle de exibição de árvore.|  
|[CTreeCtrl::HitTest](../Topic/CTreeCtrl::HitTest.md)|Retorna a posição atual do cursor relativo ao objeto de `CTreeCtrl` .|  
|[CTreeCtrl::InsertItem](../Topic/CTreeCtrl::InsertItem.md)|Insere um novo item em um controle de exibição de árvore.|  
|[CTreeCtrl::ItemHasChildren](../Topic/CTreeCtrl::ItemHasChildren.md)|Retorna diferente de zero se o item especificado possui itens filhos.|  
|[CTreeCtrl::MapAccIdToItem](../Topic/CTreeCtrl::MapAccIdToItem.md)|Mapeia o identificador especificado de acessibilidade manipular a um item de modo de exibição em árvore do controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::MapItemToAccID](../Topic/CTreeCtrl::MapItemToAccID.md)|Mapeia a alça especificada em um item de modo de exibição em árvore do controle atual do modo de exibição de árvore para um identificador de acessibilidade.|  
|[CTreeCtrl::Select](../Topic/CTreeCtrl::Select.md)|Seleciona, rola na exibição, ou redesenho item especificado um modo de exibição de árvore.|  
|[CTreeCtrl::SelectDropTarget](../Topic/CTreeCtrl::SelectDropTarget.md)|Redesenha a como o destino de uma operação de arrastar e soltar.|  
|[CTreeCtrl::SelectItem](../Topic/CTreeCtrl::SelectItem.md)|Seleciona um item específico de modo de exibição de árvore.|  
|[CTreeCtrl::SelectSetFirstVisible](../Topic/CTreeCtrl::SelectSetFirstVisible.md)|Seleciona um item específico de modo de exibição de árvore como o primeiro item visível.|  
|[CTreeCtrl::SetAutoscrollInfo](../Topic/CTreeCtrl::SetAutoscrollInfo.md)|Definir taxa de autoscroll do controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::SetBkColor](../Topic/CTreeCtrl::SetBkColor.md)|Define a cor do plano de fundo do controle.|  
|[CTreeCtrl::SetCheck](../Topic/CTreeCtrl::SetCheck.md)|Define o estado de verificação de um item de controle da árvore.|  
|[CTreeCtrl::SetExtendedStyle](../Topic/CTreeCtrl::SetExtendedStyle.md)|Define estilos estendidos para o controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::SetImageList](../Topic/CTreeCtrl::SetImageList.md)|Define o identificador da lista de imagem associada a um controle de exibição de árvore.|  
|[CTreeCtrl::SetIndent](../Topic/CTreeCtrl::SetIndent.md)|Define o deslocamento \(em pixels\) de um item de modo de exibição de árvore de seu pai.|  
|[CTreeCtrl::SetInsertMark](../Topic/CTreeCtrl::SetInsertMark.md)|Define a marca de inserção em um controle de exibição de árvore.|  
|[CTreeCtrl::SetInsertMarkColor](../Topic/CTreeCtrl::SetInsertMarkColor.md)|Define a cor usada para desenhar a marca de inserção para o modo de exibição de árvore.|  
|[CTreeCtrl::SetItem](../Topic/CTreeCtrl::SetItem.md)|Defina os atributos de um item específico de modo de exibição de árvore.|  
|[CTreeCtrl::SetItemData](../Topic/CTreeCtrl::SetItemData.md)|Defina o valor específico do aplicativo de 32 bits associados com um item.|  
|[CTreeCtrl::SetItemExpandedImageIndex](../Topic/CTreeCtrl::SetItemExpandedImageIndex.md)|Define o índice da imagem para exibir quando o item especificado do controle atual do modo de exibição de árvore está no estado expandido.|  
|[CTreeCtrl::SetItemHeight](../Topic/CTreeCtrl::SetItemHeight.md)|Defina a altura de itens modo de exibição de árvore.|  
|[CTreeCtrl::SetItemImage](../Topic/CTreeCtrl::SetItemImage.md)|Imagens de associados com um item.|  
|[CTreeCtrl::SetItemState](../Topic/CTreeCtrl::SetItemState.md)|Define o estado de um item.|  
|[CTreeCtrl::SetItemStateEx](../Topic/CTreeCtrl::SetItemStateEx.md)|Define o estado estendido de item especificado no controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::SetItemText](../Topic/CTreeCtrl::SetItemText.md)|Define o texto de um item.|  
|[CTreeCtrl::SetLineColor](../Topic/CTreeCtrl::SetLineColor.md)|Define a linha atual cor para o controle de exibição de árvore.|  
|[CTreeCtrl::SetScrollTime](../Topic/CTreeCtrl::SetScrollTime.md)|Define o tempo máximo de rolagem para o controle de exibição de árvore.|  
|[CTreeCtrl::SetTextColor](../Topic/CTreeCtrl::SetTextColor.md)|Define a cor do texto do controle.|  
|[CTreeCtrl::SetToolTips](../Topic/CTreeCtrl::SetToolTips.md)|Define o tipo de controle ToolTip filho de um controle de exibição de árvore.|  
|[CTreeCtrl::ShowInfoTip](../Topic/CTreeCtrl::ShowInfoTip.md)|Exibe o infotip para o item especificado no controle atual do modo de exibição de árvore.|  
|[CTreeCtrl::SortChildren](../Topic/CTreeCtrl::SortChildren.md)|Classifica os filhos de um item pai dado.|  
|[CTreeCtrl::SortChildrenCB](../Topic/CTreeCtrl::SortChildrenCB.md)|Classifica os filhos de um item pai dado usando uma função application\-defined do tipo.|  
  
## Comentários  
 “De um controle modo de exibição de árvore” é uma janela que exibe uma lista hierárquica de itens, como os títulos em um documento, as entradas em um índice, ou arquivos e pastas em disco.  Cada item consiste em um rótulo e uma imagem bitmap opcional, e cada item pode ter uma lista de subitens associados com ele.  Clique em um item, o usuário pode expandir e recolher a lista de subitens associado.  
  
 Este controle \(e portanto a classe de `CTreeCtrl` \) estão disponíveis somente para programas que executam na versão 4 do Windows 98 e Windows NT e posterior.  
  
 Para obter mais informações sobre como usar `CTreeCtrl`, consulte:  
  
-   [Controles](../../mfc/controls-mfc.md)  
  
-   [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)  
  
-   [Referência de controle de exibição de árvore](http://msdn.microsoft.com/library/windows/desktop/bb759988) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
-   Artigo de Base de Dados de Conhecimento Q222905: HOWTO: exibir um menu de contexto para CTreeCtrl  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CTreeCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [O MFC exemplos CMNCTRL1](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CImageList](../Topic/CImageList%20Class.md)