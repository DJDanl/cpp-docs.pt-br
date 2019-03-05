---
title: Classes de exibição derivadas disponíveis no MFC
ms.date: 11/04/2016
helpviewer_keywords:
- CView class [MFC], classes derived from
- classes [MFC], derived
- derived classes [MFC], view classes
- view classes [MFC], derived
ms.assetid: dba42178-7459-4ccc-b025-f3d9b8a4b737
ms.openlocfilehash: 61b38f6147a8bde4f6eb42cd144f9f64dac8dbd8
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57269286"
---
# <a name="derived-view-classes-available-in-mfc"></a>Classes de exibição derivadas disponíveis no MFC

A tabela a seguir mostra as classes de exibição do MFC e suas relações uns aos outros. Os recursos da sua classe de exibição dependem da classe de exibição do MFC da qual ela deriva.

### <a name="view-classes"></a>Classes de exibição

|Classe|Descrição|
|-----------|-----------------|
|[CView](../mfc/reference/cview-class.md)|Classe base de todas as exibições.|
|[CCtrlView](../mfc/reference/cctrlview-class.md)|Classe de base `CTreeView`, `CListView`, `CEditView`, e `CRichEditView`. Essas classes permitem que você usar a arquitetura de documento/exibição com os controles comuns do Windows indicados.|
|[CEditView](../mfc/reference/ceditview-class.md)|Uma exibição simples com base no Windows Editar controle de caixa. Permite inserir e editar texto e pode ser usado como base para um aplicativo de editor de texto simples. Consulte também `CRichEditView`.|
|[CRichEditView](../mfc/reference/cricheditview-class.md)|Uma exibição que contém um [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md) objeto. Essa classe é análoga à `CEditView`, mas diferentemente `CEditView`, `CRichEditView` texto formatado de identificadores.|
|[CListView](../mfc/reference/clistview-class.md)|Uma exibição que contém um [CListCtrl](../mfc/reference/clistctrl-class.md) objeto.|
|[CTreeView](../mfc/reference/ctreeview-class.md)|Uma exibição que contém um [CTreeCtrl](../mfc/reference/ctreectrl-class.md) objeto para modos de exibição que se assemelhem a janela Gerenciador de soluções no Visual C++.|
|[CScrollView](../mfc/reference/cscrollview-class.md)|Classe de base `CFormView`, `CRecordView`, e `CDaoRecordView`. Implementa o conteúdo da exibição de rolagem.|
|[CFormView](../mfc/reference/cformview-class.md)|Uma exibição de formulário, um modo de exibição que contém controles. Um aplicativo baseado em formulários fornece um ou mais essas interfaces de formulário.|
|[CHtmlView](../mfc/reference/chtmlview-class.md)|Uma exibição de navegador da Web com o qual usuário o aplicativo do pode navegar em sites na World Wide Web, bem como pastas no sistema de arquivos local e em uma rede. A exibição de navegador da Web também pode funcionar como um contêiner de documento ativo.|
|[CRecordView](../mfc/reference/crecordview-class.md)|Um modo de exibição de formulário que exibe registros de banco de dados ODBC em controles. Se você selecionar o suporte a ODBC em seu projeto, a classe de base da exibição é `CRecordView`. O modo de exibição está conectado a um `CRowset` objeto.|
|[CDaoRecordView](../mfc/reference/cdaorecordview-class.md)|Um modo de exibição de formulário que exibe registros de banco de dados DAO em controles. Se você selecionar o suporte do DAO em seu projeto, a classe de base da exibição é `CDaoRecordView`. O modo de exibição está conectado a um `CDaoRecordset` objeto.|
|[COleDBRecordView](../mfc/reference/coledbrecordview-class.md)|Um modo de exibição de formulário que exibe registros de OLE DB em controles. Se você selecionar o suporte de OLE DB em seu projeto, a classe de base da exibição é `COleDBRecordView`. O modo de exibição está conectado a um `CRowset` objeto.|

> [!NOTE]
>  A partir da versão 4.0, do MFC `CEditView` é derivado de `CCtrlView`.

Para usar essas classes em seu aplicativo, derive classes de exibição do aplicativo deles. Para obter informações relacionadas, consulte [rolagem e dimensionando exibições](../mfc/scrolling-and-scaling-views.md). Para obter mais informações sobre as classes de banco de dados, consulte [visão geral: Programação de banco de dados](../data/data-access-programming-mfc-atl.md).

## <a name="see-also"></a>Consulte também

[Usando exibições](../mfc/using-views.md)
