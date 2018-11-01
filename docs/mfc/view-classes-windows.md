---
title: Classes de exibição (Windows)
ms.date: 11/04/2016
f1_keywords:
- vc.classes.view
helpviewer_keywords:
- form and record views [MFC]
- splitter window classes [MFC]
- view classes [MFC], Windows
ms.assetid: b11683fb-9f43-4de3-9499-2b55775f9870
ms.openlocfilehash: 5fc08ec23e0a2b2ba105aa3a633ee862dc452450
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50462290"
---
# <a name="view-classes-windows"></a>Classes de exibição (Windows)

`CView` e suas classes derivadas são janelas filho que representam a área de cliente de uma janela do quadro. Modos de exibição mostram dados e aceitam a entrada para um documento.

Uma classe de exibição está associada uma classe de documento e uma classe de janela de quadro usando um objeto de modelo de documento.

[CView](../mfc/reference/cview-class.md)<br/>
A classe base para modos de exibição específicos do aplicativo de dados de um documento. Modos de exibição exibem dados e aceitam a entrada do usuário para editar ou selecionar os dados. Derivar seu modo de exibição de classe ou classes de `CView`.

[CScrollView](../mfc/reference/cscrollview-class.md)<br/>
A classe base para exibições com recursos de rolagem. Derive sua classe de exibição da `CScrollView` para rolagem automática.

## <a name="form-and-record-views"></a>Formulário e exibições de registro

Exibições de formulário também são modos de exibição de rolagem. Elas são baseadas em um modelo de caixa de diálogo.

Exibições de registro são derivadas de modos de exibição de formulário. Além do modelo de caixa de diálogo, eles também têm uma conexão para um banco de dados.

[CFormView](../mfc/reference/cformview-class.md)<br/>
Um modo de exibição de rolagem cujo layout é definido em um modelo de caixa de diálogo. Derive uma classe de `CFormView` para implementar uma interface do usuário com base em um modelo de caixa de diálogo.

[CDaoRecordView](../mfc/reference/cdaorecordview-class.md)<br/>
Fornece um formulário de exibição diretamente conectada a um objeto de conjunto de registros do objeto de acesso de dados (DAO). Como todos os modos de exibição de formulário, um `CDaoRecordView` baseia-se em um modelo de caixa de diálogo.

[CRecordView](../mfc/reference/crecordview-class.md)<br/>
Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros de conectividade de banco de dados aberto (ODBC). Como todos os modos de exibição de formulário, um `CRecordView` baseia-se em um modelo de caixa de diálogo.

[CHtmlEditView](../mfc/reference/chtmleditview-class.md)<br/>
Um modo de exibição de formulário que fornece a funcionalidade da plataforma de edição WebBrowser HTML.

## <a name="control-views"></a>Modos de exibição de controle

Modos de exibição de controle exibem um controle como seu modo de exibição.

[CCtrlView](../mfc/reference/cctrlview-class.md)<br/>
A classe base para todas as exibições associados a controles do Windows. Os modos de exibição com base nos controles são descritos abaixo.

[CEditView](../mfc/reference/ceditview-class.md)<br/>
Controle de edição de uma exibição que contém um padrão do Windows (consulte [CEdit](../mfc/reference/cedit-class.md)). Edite a edição de texto de suporte com controles, pesquisa, substituindo e recursos de rolagem.

[CRichEditView](../mfc/reference/cricheditview-class.md)<br/>
Controle de edição de uma exibição que contém um avançado do Windows (consulte [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Além dos recursos de um controle de edição, edição avançada controles suporte fontes, cores, formatação de parágrafo e objetos OLE incorporados.

[CListView](../mfc/reference/clistview-class.md)<br/>
Uma exibição que contém um controle de lista do Windows (consulte [CListCtrl](../mfc/reference/clistctrl-class.md)). Um controle de lista exibe uma coleção de itens, cada uma consistindo em um ícone e um rótulo, de maneira semelhante para o painel direito do Explorador de arquivos.

[CTreeView](../mfc/reference/ctreeview-class.md)<br/>
Uma exibição que contém um controle de árvore do Windows (consulte [CTreeCtrl](../mfc/reference/ctreectrl-class.md)). Um controle de árvore exibe uma lista hierárquica de ícones e os rótulos organizados de maneira semelhante ao painel esquerdo do Explorador de arquivos.

## <a name="related-classes"></a>Classes relacionadas

`CSplitterWnd` permite que você tenha vários modos de exibição dentro de uma janela de quadro único. `CPrintDialog` e `CPrintInfo` oferecem suporte à capacidade de impressão e visualização de impressão dos modos de exibição. `CRichEditDoc` e `CRichEditCntrItem` são usados com `CRichEditView` para implementar recursos de contêiner OLE.

[CSplitterWnd](../mfc/reference/csplitterwnd-class.md)<br/>
Uma janela que o usuário pode ser dividida em vários painéis. Esses painéis podem ser redimensionáveis pelo usuário ou tamanho fixo.

[CPrintDialog](../mfc/reference/cprintdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para imprimir um arquivo.

[CPrintInfo](../mfc/reference/cprintinfo-structure.md)<br/>
Uma estrutura que contém informações sobre um trabalho de impressão ou visualização de impressão. Usado pelo `CView`arquitetura de impressão do.

[CRichEditDoc](../mfc/reference/cricheditdoc-class.md)<br/>
Mantém a lista de itens de cliente OLE que estão em um `CRichEditView`.

[CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md)<br/>
Fornece acesso de cliente para uma OLE item armazenada em um `CRichEditView`.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

