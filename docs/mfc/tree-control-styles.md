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
ms.openlocfilehash: 59cbed32d9be8fac84284b621bd4d1e17d5d92cf
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50453453"
---
# <a name="tree-control-styles"></a>Estilos de controle da árvore

Controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) estilos controlam aspectos da aparência de um controle de árvore. Você definir os estilos inicias quando você cria o controle de árvore. Você pode recuperar e alterar os estilos depois de criar o controle de árvore usando o [GetWindowLong](/windows/desktop/api/winuser/nf-winuser-getwindowlonga) e [SetWindowLong](/windows/desktop/api/winuser/nf-winuser-setwindowlonga) funções do Windows, especificando **GWL_STYLE** para o *nIndex* parâmetro. Para obter uma lista completa de estilos, consulte [estilos de janela de controle de exibição de árvore](/windows/desktop/Controls/tree-view-control-window-styles) no SDK do Windows.

O **TVS_HASLINES** estilo aprimora a representação gráfica da hierarquia de um controle de árvore, desenhar linhas que vinculam os itens filho para o item pai correspondente. Esse estilo não vincular itens na raiz da hierarquia. Para fazer isso, você precisará combinar as **TVS_HASLINES** e **TVS_LINESATROOT** estilos.

O usuário pode expandir ou recolher a lista de um item pai dos itens filhos clicando duas vezes no item pai. Um controle de árvore que tem o **TVS_SINGLEEXPAND** estilo faz com que o item que está sendo selecionado para expandir e o item que está sendo desmarcada para recolher. Se o mouse é usado para o item selecionado com um único clique, e esse item for fechado, ela será expandida. Se o item selecionado é single-clicado quando ele é aberto, ele será recolhido.

Um controle de árvore que tem o **TVS_HASBUTTONS** estilo adiciona um botão à esquerda de cada item pai. O usuário pode clicar no botão para expandir ou recolher os itens filho como uma alternativa ao clicar duas vezes o item pai. **TVS_HASBUTTONS** não adiciona botões de itens na raiz da hierarquia. Para fazer isso, você deve combinar **TVS_HASLINES**, **TVS_LINESATROOT**, e **TVS_HASBUTTONS**.

O **TVS_EDITLABELS** estilo possibilita que o usuário edite os rótulos dos itens de controle de árvore. Para obter mais informações sobre como editar rótulos, consulte [edição de rótulos de controle de árvore](../mfc/tree-control-label-editing.md) mais adiante neste tópico.

O **TVS_NOTOOLTIPS** estilo desabilita o recurso de dica de ferramenta automática dos controles de exibição de árvore. Esse recurso exibe automaticamente uma dica de ferramenta, que contém o título do item sob o cursor do mouse, se o título inteiro não é visível no momento.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

