---
title: Estilos de controle da árvore
ms.date: 11/04/2016
f1_keywords:
- TVS_SINGLEEXPAND
- TVS_LINESATROOT
- TVS_HASBUTTONS
- TVS_NOTOOLTIPS
- TVS_HASLINES
helpviewer_keywords:
- TVS_LINESATROOT [MFC]
- styles [MFC], CTreeCtrl
- styles [MFC], tree control
- TVS_HASLINES
- TVS_SINGLEEXPAND
- CTreeCtrl class [MFC], styles
- TVS_EDITLABELS [MFC]
- TVS_NOTOOLTIPS [MFC]
- TVS_HASBUTTONS [MFC]
- tree controls [MFC], styles
ms.assetid: f43faebd-a355-479e-888a-bf0673d5e1b4
ms.openlocfilehash: f5f28025d0349e9bcd95aba50d4110d304fed376
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510945"
---
# <a name="tree-control-styles"></a>Estilos de controle da árvore

Os estilos de controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) regem aspectos da aparência de um controle de árvore. Você define os estilos iniciais ao criar o controle de árvore. Você pode recuperar e alterar os estilos depois de criar o controle de árvore usando as funções do Windows [GetWindowLong](/windows/win32/api/winuser/nf-winuser-getwindowlongw) e [SetWindowLong](/windows/win32/api/winuser/nf-winuser-setwindowlongw) , especificando **GWL_STYLE** para o parâmetro *nIndex* . Para obter uma lista completa de estilos, consulte [estilos de janela de controle de exibição de árvore](/windows/win32/Controls/tree-view-control-window-styles) na SDK do Windows.

O estilo **TVS_HASLINES** aprimora a representação gráfica da hierarquia de um controle de árvore por meio do desenho de linhas que vinculam itens filho ao item pai correspondente. Esse estilo não vincula itens na raiz da hierarquia. Para fazer isso, você precisa combinar os estilos **TVS_HASLINES** e **TVS_LINESATROOT** .

O usuário pode expandir ou recolher a lista de itens filho de um item pai clicando duas vezes no item pai. Um controle de árvore que tem o estilo **TVS_SINGLEEXPAND** faz com que o item seja selecionado para expandir e o item que está sendo desmarcado para recolher. Se o mouse for usado para clicar uma vez no item selecionado e esse item for fechado, ele será expandido. Se o item selecionado tiver um clique único quando estiver aberto, ele será recolhido.

Um controle de árvore que tem o estilo **TVS_HASBUTTONS** adiciona um botão ao lado esquerdo de cada item pai. O usuário pode clicar no botão para expandir ou recolher os itens filho como uma alternativa para clicar duas vezes no item pai. **TVS_HASBUTTONS** não Adiciona botões a itens na raiz da hierarquia. Para fazer isso, você deve combinar **TVS_HASLINES**, **TVS_LINESATROOT**e **TVS_HASBUTTONS**.

O estilo **TVS_EDITLABELS** possibilita que o usuário edite os rótulos dos itens de controle de árvore. Para obter mais informações sobre como editar rótulos, consulte [edição de rótulo de controle de árvore](../mfc/tree-control-label-editing.md) mais adiante neste tópico.

O estilo **TVS_NOTOOLTIPS** desabilita o recurso dica de ferramenta automática de controles de exibição de árvore. Esse recurso exibe automaticamente uma dica de ferramenta, que contém o título do item sob o cursor do mouse, se o título inteiro não estiver visível no momento.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
