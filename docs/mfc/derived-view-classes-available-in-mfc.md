---
title: Classes de exibição derivadas disponíveis no MFC
ms.date: 11/04/2016
helpviewer_keywords:
- CView class [MFC], classes derived from
- classes [MFC], derived
- derived classes [MFC], view classes
- view classes [MFC], derived
ms.assetid: dba42178-7459-4ccc-b025-f3d9b8a4b737
ms.openlocfilehash: dc0f0b10ea291db32c576a7d36b7fc19728fa6ce
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616976"
---
# <a name="derived-view-classes-available-in-mfc"></a>Classes de exibição derivadas disponíveis no MFC

A tabela a seguir mostra as classes de exibição do MFC e suas relações entre si. Os recursos de sua classe de exibição dependem da classe de exibição do MFC da qual derivam.

### <a name="view-classes"></a>Exibir classes

|Class|Descrição|
|-----------|-----------------|
|[CView](reference/cview-class.md)|Classe base de todas as exibições.|
|[CCtrlView](reference/cctrlview-class.md)|Classe base de `CTreeView` , `CListView` , `CEditView` e `CRichEditView` . Essas classes permitem que você use a arquitetura de documento/exibição com os controles comuns do Windows indicados.|
|[CEditView](reference/ceditview-class.md)|Uma exibição simples com base no controle da caixa de edição do Windows. Permite inserir e editar texto e pode ser usado como base para um aplicativo de editor de texto simples. Consulte também `CRichEditView`.|
|[CRichEditView](reference/cricheditview-class.md)|Uma exibição que contém um objeto [CRichEditCtrl](reference/cricheditctrl-class.md) . Essa classe é análoga a `CEditView` , mas ao contrário `CEditView` de, lida com o `CRichEditView` texto formatado.|
|[CListView](reference/clistview-class.md)|Uma exibição que contém um objeto [CListCtrl](reference/clistctrl-class.md) .|
|[CTreeView](reference/ctreeview-class.md)|Uma exibição que contém um objeto [CTreeCtrl](reference/ctreectrl-class.md) , para exibições que se assemelham à janela de Gerenciador de Soluções no Visual C++.|
|[CScrollView](reference/cscrollview-class.md)|Classe base de `CFormView` , `CRecordView` e `CDaoRecordView` . Implementa a rolagem do conteúdo da exibição.|
|[CFormView](reference/cformview-class.md)|Uma exibição de formulário, uma exibição que contém controles. Um aplicativo baseado em formulários fornece uma ou mais interfaces de formulário.|
|[CHtmlView](reference/chtmlview-class.md)|Um modo de exibição de navegador da Web com o qual o usuário do aplicativo pode procurar sites na World Wide Web, bem como pastas no sistema de arquivos local e em uma rede. O modo de exibição de navegador da Web também pode funcionar como um contêiner de documento ativo.|
|[CRecordView](reference/crecordview-class.md)|Um modo de exibição de formulário que exibe registros de banco de dados ODBC em controles. Se você selecionar suporte ODBC em seu projeto, a classe base do modo de exibição será `CRecordView` . A exibição está conectada a um `CRowset` objeto.|
|[CDaoRecordView](reference/cdaorecordview-class.md)|Um modo de exibição de formulário que exibe registros de banco de dados DAO em controles. Se você selecionar suporte a DAO em seu projeto, a classe base do modo de exibição será `CDaoRecordView` . A exibição está conectada a um `CDaoRecordset` objeto.|
|[COleDBRecordView](reference/coledbrecordview-class.md)|Um modo de exibição de formulário que exibe OLE DB registros em controles. Se você selecionar OLE DB suporte em seu projeto, a classe base do modo de exibição será `COleDBRecordView` . A exibição está conectada a um `CRowset` objeto.|

> [!NOTE]
> A partir da versão 4,0 do MFC, `CEditView` é derivada de `CCtrlView` .

Para usar essas classes em seu aplicativo, derive as classes de exibição do aplicativo deles. Para obter informações relacionadas, consulte [rolagem e dimensionamento de exibições](scrolling-and-scaling-views.md). Para obter mais informações sobre as classes de banco de dados, consulte [visão geral: programação de banco de dados](../data/data-access-programming-mfc-atl.md).

## <a name="see-also"></a>Consulte também

[Usando exibições](using-views.md)
