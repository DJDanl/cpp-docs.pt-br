---
title: Classes de exibição (arquitetura)
ms.date: 11/04/2016
f1_keywords:
- vc.classes.view
helpviewer_keywords:
- form and record views [MFC]
- view classes [MFC]
- control views [MFC]
- view classes [MFC], architecture
ms.assetid: 8894579a-1436-441e-b985-83711061e495
ms.openlocfilehash: 15b120f0354c483480351b8d3abf995334779411
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62352665"
---
# <a name="view-classes-architecture"></a>Classes de exibição (arquitetura)

`CView` e suas classes derivadas são janelas filho que representam a área de cliente de uma janela do quadro. Modos de exibição mostram dados e aceitam a entrada para um documento.

Uma classe de exibição está associada uma classe de documento e uma classe de janela de quadro usando um objeto de modelo de documento.

[CView](../mfc/reference/cview-class.md)<br/>
A classe base para modos de exibição específicos do aplicativo de dados de um documento. Modos de exibição exibem dados e aceitam a entrada do usuário para editar ou selecionar os dados. Derive sua classe de exibição (s) de `CView`.

[CScrollView](../mfc/reference/cscrollview-class.md)<br/>
A classe base para exibições com recursos de rolagem. Derive sua classe de exibição da `CScrollView` para rolagem automática.

## <a name="form-and-record-views"></a>Formulário e exibições de registro

Exibições de formulário também são modos de exibição de rolagem. Elas são baseadas em um modelo de caixa de diálogo.

Exibições de registro são derivadas de modos de exibição de formulário. Além do modelo de caixa de diálogo, eles também têm uma conexão para um banco de dados.

[CFormView](../mfc/reference/cformview-class.md)<br/>
Um modo de exibição de rolagem cujo layout é definido em um modelo de caixa de diálogo. Derive uma classe de `CFormView` para implementar uma interface do usuário com base em um modelo de caixa de diálogo.

[CDaoRecordView](../mfc/reference/cdaorecordview-class.md)<br/>
Fornece um formulário de exibição diretamente conectada a um objeto de conjunto de registros do objeto de acesso de dados (DAO). Como todos os modos de exibição de formulário, um `CDaoRecordView` baseia-se em um modelo de caixa de diálogo.

[CHtmlView](../mfc/reference/chtmlview-class.md)<br/>
Dá suporte a um controle de navegação na Web em um aplicativo. O controle dá suporte a HTML dinâmico no MFC.

[COLEDBRecordView](../mfc/reference/coledbrecordview-class.md)<br/>
Fornece suporte de OLE DB MFC para modos de exibição de formulário.

[CRecordView](../mfc/reference/crecordview-class.md)<br/>
Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros de conectividade de banco de dados aberto (ODBC). Como todos os modos de exibição de formulário, um `CRecordView` baseia-se em um modelo de caixa de diálogo.

## <a name="control-views"></a>Modos de exibição de controle

Modos de exibição de controle exibem um controle como seu modo de exibição.

[CCtrlView](../mfc/reference/cctrlview-class.md)<br/>
A classe base para todas as exibições associados a controles do Windows. Os modos de exibição com base nos controles são descritos abaixo.

[CEditView](../mfc/reference/ceditview-class.md)<br/>
Controle de edição de uma exibição que contém um padrão do Windows (consulte [CEdit](../mfc/reference/cedit-class.md)). Edite a edição de texto de suporte com controles, pesquisa, substituindo e recursos de rolagem.

[CRichEditView](../mfc/reference/cricheditview-class.md)<br/>
Controle de edição de uma exibição que contém um avançado do Windows (consulte [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Além dos recursos de um controle de edição, edição avançada controles suporte fontes, cores, formatação de parágrafo e objetos OLE incorporados.

[CListView](../mfc/reference/clistview-class.md)<br/>
Uma exibição que contém um controle de lista do Windows (consulte [CListCtrl](../mfc/reference/clistctrl-class.md)). Um controle de lista exibe ícones e cadeias de caracteres de maneira semelhante para o painel direito do Explorador de arquivos.

[CTreeView](../mfc/reference/ctreeview-class.md)<br/>
Uma exibição que contém um controle de árvore do Windows (consulte [CTreeCtrl](../mfc/reference/ctreectrl-class.md)). Um controle de árvore exibe ícones e organizadas em uma hierarquia de maneira semelhante ao painel esquerdo do Explorador de arquivos de cadeias de caracteres.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
