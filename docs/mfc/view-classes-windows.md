---
title: Classes de exibição (Windows)
ms.date: 09/17/2019
f1_keywords:
- vc.classes.view
helpviewer_keywords:
- form and record views [MFC]
- splitter window classes [MFC]
- view classes [MFC], Windows
ms.assetid: b11683fb-9f43-4de3-9499-2b55775f9870
ms.openlocfilehash: a3e0f837bc13c022bec91bfff6e38c1513abaf16
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74302966"
---
# <a name="view-classes-windows"></a>Classes de exibição (Windows)

`CView` e suas classes derivadas são janelas filhas que representam a área do cliente de uma janela do quadro. Exibições mostram dados e aceitam entrada para um documento.

Uma classe de exibição é associada a uma classe de documento e a uma classe de janela de quadro usando um objeto Document-Template.

[Cvisualização](../mfc/reference/cview-class.md)<br/>
A classe base para exibições específicas do aplicativo dos dados de um documento. Exibições exibem dados e aceitam entrada do usuário para editar ou selecionar os dados. Derive sua classe ou classes de exibição de `CView`.

[CScrollView](../mfc/reference/cscrollview-class.md)<br/>
A classe base para exibições com recursos de rolagem. Derive sua classe de exibição de `CScrollView` para rolagem automática.

## <a name="form-and-record-views"></a>Exibições de formulário e de registro

Os modos de exibição de formulário também estão rolando exibições. Elas se baseiam em um modelo de caixa de diálogo.

As exibições de registro são derivadas de exibições de formulário. Além do modelo de caixa de diálogo, eles também têm uma conexão com um banco de dados.

[CFormView](../mfc/reference/cformview-class.md)<br/>
Uma exibição de rolagem cujo layout é definido em um modelo de caixa de diálogo. Derive uma classe de `CFormView` para implementar uma interface do usuário com base em um modelo de caixa de diálogo.

[CDaoRecordView](../mfc/reference/cdaorecordview-class.md)<br/>
Fornece uma exibição de formulário diretamente conectada a um objeto Recordset do objeto de acesso a dados (DAO). Como todos os modos de exibição de formulário, um `CDaoRecordView` é baseado em um modelo de caixa de diálogo. O DAO é usado com bancos de dados do Access e tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.

[CRecordView](../mfc/reference/crecordview-class.md)<br/>
Fornece uma exibição de formulário diretamente conectada a um objeto Recordset Open Database Connectivity (ODBC). Como todos os modos de exibição de formulário, um `CRecordView` é baseado em um modelo de caixa de diálogo.

[CHtmlEditView](../mfc/reference/chtmleditview-class.md)<br/>
Um modo de exibição de formulário que fornece a funcionalidade da plataforma de edição HTML do WebBrowser.

## <a name="control-views"></a>Exibições de controle

Exibições de controle exibem um controle como sua exibição.

[CCtrlView](../mfc/reference/cctrlview-class.md)<br/>
A classe base para todas as exibições associadas aos controles do Windows. As exibições baseadas em controles são descritas abaixo.

[CEditView](../mfc/reference/ceditview-class.md)<br/>
Uma exibição que contém um controle de edição padrão do Windows (consulte [CEdit](../mfc/reference/cedit-class.md)). Os controles de edição dão suporte à edição de texto, pesquisa, substituição e recursos de rolagem.

[CRichEditView](../mfc/reference/cricheditview-class.md)<br/>
Uma exibição que contém um controle de edição Rich do Windows (consulte [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Além dos recursos de um controle de edição, os controles de edição avançados dão suporte a fontes, cores, formatação de parágrafo e objetos OLE incorporados.

[CListView](../mfc/reference/clistview-class.md)<br/>
Uma exibição que contém um controle de lista do Windows (consulte [CListCtrl](../mfc/reference/clistctrl-class.md)). Um controle de lista exibe uma coleção de itens, cada um consistindo em um ícone e um rótulo, de forma semelhante ao painel direito do explorador de arquivos.

[CTreeView](../mfc/reference/ctreeview-class.md)<br/>
Uma exibição que contém um controle de árvore do Windows (consulte [CTreeCtrl](../mfc/reference/ctreectrl-class.md)). Um controle de árvore exibe uma lista hierárquica de ícones e rótulos organizados de uma maneira semelhante ao painel esquerdo do explorador de arquivos.

## <a name="related-classes"></a>Classes relacionadas

`CSplitterWnd` permite que você tenha várias exibições em uma única janela de quadro. `CPrintDialog` e `CPrintInfo` dão suporte à capacidade da visualização de impressão e impressão de modos de exibição. `CRichEditDoc` e `CRichEditCntrItem` são usados com `CRichEditView` para implementar recursos de contêiner OLE.

[CSplitterWnd](../mfc/reference/csplitterwnd-class.md)<br/>
Uma janela que o usuário pode dividir em vários painéis. Esses painéis podem ser redimensionáveis pelo usuário ou pelo tamanho fixo.

[CPrintDialog](../mfc/reference/cprintdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para imprimir um arquivo.

[CPrintInfo](../mfc/reference/cprintinfo-structure.md)<br/>
Uma estrutura que contém informações sobre um trabalho de impressão ou de visualização de impressão. Usado pela arquitetura de impressão de `CView`.

[CRichEditDoc](../mfc/reference/cricheditdoc-class.md)<br/>
Mantém a lista de itens de cliente OLE que estão em um `CRichEditView`.

[CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md)<br/>
Fornece acesso do lado do cliente a um item OLE armazenado em um `CRichEditView`.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
