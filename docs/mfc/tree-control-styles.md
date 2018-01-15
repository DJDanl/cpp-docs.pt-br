---
title: "Estilos de controle de árvore | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- TVS_SINGLEEXPAND
- TVS_LINESATROOT
- TVS_HASBUTTONS
- TVS_NOTOOLTIPS
- TVS_HASLINES
dev_langs: C++
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
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c141a2b0db673f8d3c5f2c116de5b5d2ec81a8ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tree-control-styles"></a>Estilos de controle da árvore
Controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) estilos controlam aspectos da aparência de um controle de árvore. Você definir os estilos inicias quando você cria o controle de árvore. Você pode recuperar e alterar os estilos depois de criar o controle de árvore usando o [GetWindowLong](http://msdn.microsoft.com/library/windows/desktop/ms633584) e [SetWindowLong](http://msdn.microsoft.com/library/windows/desktop/ms633591) funções do Windows, especificando **GWL_STYLE** para o `nIndex` parâmetro. Para obter uma lista completa de estilos, consulte [estilos de janela de controle de exibição de árvore](http://msdn.microsoft.com/library/windows/desktop/bb760013) no SDK do Windows.  
  
 O **TVS_HASLINES** estilo aprimora a representação gráfica da hierarquia de um controle de árvore, desenhar linhas que se vincular itens filho a seu item pai correspondente. Este estilo não vincular itens na raiz da hierarquia. Para fazer isso, você precisa combinar o **TVS_HASLINES** e **TVS_LINESATROOT** estilos.  
  
 O usuário pode expandir ou recolher a lista de um item pai de itens filho clicando duas vezes o item pai. Um controle de árvore que tem o **TVS_SINGLEEXPAND** estilo faz com que o item selecionado para expandir e o item que está sendo desmarcada para recolher. Se o mouse é usado para o item selecionado de clique simples e esse item é fechado, ela será expandida. Se o item selecionado é único clicado quando ele é aberto, ele será recolhido.  
  
 Um controle de árvore que tem o **TVS_HASBUTTONS** estilo adiciona um botão à esquerda de cada item pai. O usuário pode clicar no botão para expandir ou recolher os itens filhos como uma alternativa para duas vezes no item pai. **TVS_HASBUTTONS** não adicionar botões de itens na raiz da hierarquia. Para fazer isso, você deve combinar **TVS_HASLINES**, **TVS_LINESATROOT**, e **TVS_HASBUTTONS**.  
  
 O **TVS_EDITLABELS** estilo possibilita que o usuário edite os rótulos de itens de controle de árvore. Para obter mais informações sobre como editar rótulos, consulte [edição de rótulo de controle de árvore](../mfc/tree-control-label-editing.md) mais adiante neste tópico.  
  
 O **TVS_NOTOOLTIPS** estilo desabilita o recurso de dica de ferramenta automática dos controles de exibição de árvore. Esse recurso automaticamente exibe uma dica de ferramenta que contém o título do item sob o cursor do mouse, se o título completo não estiver visível no momento.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

