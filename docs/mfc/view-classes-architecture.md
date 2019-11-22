---
title: Classes de exibição (arquitetura)
ms.date: 09/17/2019
f1_keywords:
- vc.classes.view
helpviewer_keywords:
- form and record views [MFC]
- view classes [MFC]
- control views [MFC]
- view classes [MFC], architecture
ms.assetid: 8894579a-1436-441e-b985-83711061e495
ms.openlocfilehash: fda4e968a4761fcf1e2245964bd5dca3f41a82ad
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74302979"
---
# <a name="view-classes-architecture"></a>Classes de exibição (arquitetura)

`CView` e suas classes derivadas são janelas filhas que representam a área do cliente de uma janela do quadro. Exibições mostram dados e aceitam entrada para um documento.

Uma classe de exibição é associada a uma classe de documento e a uma classe de janela de quadro usando um objeto Document-Template.

[Cvisualização](../mfc/reference/cview-class.md)<br/>
A classe base para exibições específicas do aplicativo dos dados de um documento. Exibições exibem dados e aceitam entrada do usuário para editar ou selecionar os dados. Derive suas classes de exibição do `CView`.

[CScrollView](../mfc/reference/cscrollview-class.md)<br/>
A classe base para exibições com recursos de rolagem. Derive sua classe de exibição de `CScrollView` para rolagem automática.

## <a name="form-and-record-views"></a>Exibições de formulário e de registro

Os modos de exibição de formulário também estão rolando exibições. Elas se baseiam em um modelo de caixa de diálogo.

As exibições de registro são derivadas de exibições de formulário. Além do modelo de caixa de diálogo, eles também têm uma conexão com um banco de dados.

[CFormView](../mfc/reference/cformview-class.md)<br/>
Uma exibição de rolagem cujo layout é definido em um modelo de caixa de diálogo. Derive uma classe de `CFormView` para implementar uma interface do usuário com base em um modelo de caixa de diálogo.

[CDaoRecordView](../mfc/reference/cdaorecordview-class.md)<br/>
Fornece uma exibição de formulário diretamente conectada a um objeto Recordset do objeto de acesso a dados (DAO). Como todos os modos de exibição de formulário, um `CDaoRecordView` é baseado em um modelo de caixa de diálogo. O DAO é usado com bancos de dados do Access e tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.

[CHtmlView](../mfc/reference/chtmlview-class.md)<br/>
Dá suporte a um controle para navegação na Web dentro de um aplicativo. O controle oferece suporte a HTML dinâmico no MFC.

[COLEDBRecordView](../mfc/reference/coledbrecordview-class.md)<br/>
Fornece suporte do MFC OLE DB para exibições de formulário.

[CRecordView](../mfc/reference/crecordview-class.md)<br/>
Fornece uma exibição de formulário diretamente conectada a um objeto Recordset Open Database Connectivity (ODBC). Como todos os modos de exibição de formulário, um `CRecordView` é baseado em um modelo de caixa de diálogo.

## <a name="control-views"></a>Exibições de controle

Exibições de controle exibem um controle como sua exibição.

[CCtrlView](../mfc/reference/cctrlview-class.md)<br/>
A classe base para todas as exibições associadas aos controles do Windows. As exibições baseadas em controles são descritas abaixo.

[CEditView](../mfc/reference/ceditview-class.md)<br/>
Uma exibição que contém um controle de edição padrão do Windows (consulte [CEdit](../mfc/reference/cedit-class.md)). Os controles de edição dão suporte à edição de texto, pesquisa, substituição e recursos de rolagem.

[CRichEditView](../mfc/reference/cricheditview-class.md)<br/>
Uma exibição que contém um controle de edição Rich do Windows (consulte [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Além dos recursos de um controle de edição, os controles de edição avançados dão suporte a fontes, cores, formatação de parágrafo e objetos OLE incorporados.

[CListView](../mfc/reference/clistview-class.md)<br/>
Uma exibição que contém um controle de lista do Windows (consulte [CListCtrl](../mfc/reference/clistctrl-class.md)). Um controle de lista exibe ícones e cadeias de caracteres de maneira semelhante ao painel direito do explorador de arquivos.

[CTreeView](../mfc/reference/ctreeview-class.md)<br/>
Uma exibição que contém um controle de árvore do Windows (consulte [CTreeCtrl](../mfc/reference/ctreectrl-class.md)). Um controle de árvore exibe ícones e cadeias de caracteres organizados em uma hierarquia de maneira semelhante ao painel esquerdo do explorador de arquivos.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
