---
title: Classes de exibição derivadas disponíveis no MFC
ms.date: 11/04/2016
helpviewer_keywords:
- CView class [MFC], classes derived from
- classes [MFC], derived
- derived classes [MFC], view classes
- view classes [MFC], derived
ms.assetid: dba42178-7459-4ccc-b025-f3d9b8a4b737
ms.openlocfilehash: 12b31074e4fcc2ed6a83e3669e1044f5b9caedab
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373497"
---
# <a name="derived-view-classes-available-in-mfc"></a>Classes de exibição derivadas disponíveis no MFC

A tabela a seguir mostra as classes de visão da MFC e seus relacionamentos entre si. As capacidades da sua classe de visualização dependem da classe de exibição Do MFC da qual ela deriva.

### <a name="view-classes"></a>Ver aulas

|Classe|Descrição|
|-----------|-----------------|
|[CView](../mfc/reference/cview-class.md)|Classe base de todas as vistas.|
|[Cctrlview](../mfc/reference/cctrlview-class.md)|Classe base `CTreeView` `CListView`de `CEditView`, `CRichEditView`, e . Essas classes permitem que você use arquitetura de documento/exibição com os controles comuns do Windows indicados.|
|[CEditView](../mfc/reference/ceditview-class.md)|Uma visão simples com base no controle da caixa de edição do Windows. Permite a entrada e edição de texto e pode ser usado como base para um simples aplicativo de editor de texto. Consulte também `CRichEditView`.|
|[CRichEditView](../mfc/reference/cricheditview-class.md)|Uma exibição contendo um objeto [CRichEditCtrl.](../mfc/reference/cricheditctrl-class.md) Esta classe é `CEditView`análoga, `CRichEditView` mas ao contrário, `CEditView`lida com texto formatado.|
|[CListView](../mfc/reference/clistview-class.md)|Uma exibição contendo um objeto [CListCtrl.](../mfc/reference/clistctrl-class.md)|
|[Ctreeview](../mfc/reference/ctreeview-class.md)|Uma exibição contendo um objeto [CTreeCtrl,](../mfc/reference/ctreectrl-class.md) para visualizações que se assemelham à janela Solution Explorer no Visual C++.|
|[CScrollView](../mfc/reference/cscrollview-class.md)|Classe base `CFormView` `CRecordView`de `CDaoRecordView`, e . Implementa a rolagem do conteúdo da exibição.|
|[CFormView](../mfc/reference/cformview-class.md)|Uma exibição de formulário, uma visão que contém controles. Um aplicativo baseado em formulários fornece uma ou mais dessas interfaces de formulário.|
|[Chtmlview](../mfc/reference/chtmlview-class.md)|Uma visualização do navegador da Web com a qual o usuário do aplicativo pode navegar em sites na World Wide Web, bem como pastas no sistema de arquivos local e em uma rede. A exibição do navegador da Web também pode funcionar como um contêiner de documento Ativo.|
|[CRecordView](../mfc/reference/crecordview-class.md)|Uma exibição de formulário que exibe registros de banco de dados ODBC em controles. Se você selecionar o suporte ao ODBC em `CRecordView`seu projeto, a classe base da exibição será . A visão está `CRowset` conectada a um objeto.|
|[Cdaorecordview](../mfc/reference/cdaorecordview-class.md)|Uma exibição de formulário que exibe registros de banco de dados DAO em controles. Se você selecionar suporte ao DAO em seu `CDaoRecordView`projeto, a classe base da exibição será . A visão está `CDaoRecordset` conectada a um objeto.|
|[COleDBRecordView](../mfc/reference/coledbrecordview-class.md)|Uma exibição de formulário que exibe registros oLE DB em controles. Se você selecionar o suporte ao OLE DB em `COleDBRecordView`seu projeto, a classe base da exibição será . A visão está `CRowset` conectada a um objeto.|

> [!NOTE]
> A partir da versão 4.0 do MFC, `CEditView` é derivada de `CCtrlView`.

Para usar essas classes em sua aplicação, obtenha as classes de exibição do aplicativo a partir delas. Para obter informações relacionadas, consulte ['Rolagem e escalar visualizações 'Visualizações de rolagem .](../mfc/scrolling-and-scaling-views.md) Para obter mais informações sobre as classes de banco de dados, consulte [Visão geral: Programação de banco de dados](../data/data-access-programming-mfc-atl.md).

## <a name="see-also"></a>Confira também

[Usando visualizações](../mfc/using-views.md)
