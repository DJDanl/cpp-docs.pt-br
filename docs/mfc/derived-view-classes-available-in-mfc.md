---
title: "Classes de exibição disponíveis no MFC derivadas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- CView class [MFC], classes derived from
- classes [MFC], derived
- derived classes [MFC], view classes
- view classes [MFC], derived
ms.assetid: dba42178-7459-4ccc-b025-f3d9b8a4b737
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2426f3e547da6eaab6a4b38bb5199e87c93ef933
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="derived-view-classes-available-in-mfc"></a>Classes de exibição derivadas disponíveis no MFC
A tabela a seguir mostra as classes de exibição do MFC e suas relações uns aos outros. Os recursos de sua classe de exibição dependem de classe MFC de exibição da qual deriva.  
  
### <a name="view-classes"></a>Classes de exibição  
  
|Classe|Descrição|  
|-----------|-----------------|  
|[CView](../mfc/reference/cview-class.md)|Classe base de todas as exibições.|  
|[CCtrlView](../mfc/reference/cctrlview-class.md)|Classe de base `CTreeView`, `CListView`, `CEditView`, e `CRichEditView`. Essas classes permitem que você use arquitetura de documento/exibição com controles comuns do Windows indicados.|  
|[CEditView](../mfc/reference/ceditview-class.md)|Caixa controle de edição com uma exibição simples com base no Windows. Permite inserir e editar texto e pode ser usado como base para um aplicativo de editor de texto simples. Confira também `CRichEditView`.|  
|[CRichEditView](../mfc/reference/cricheditview-class.md)|Uma exibição que contém um [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md) objeto. Essa classe é análoga a `CEditView`, mas diferentemente `CEditView`, `CRichEditView` texto formatado de identificadores.|  
|[CListView](../mfc/reference/clistview-class.md)|Uma exibição que contém um [CListCtrl](../mfc/reference/clistctrl-class.md) objeto.|  
|[CTreeView](../mfc/reference/ctreeview-class.md)|Uma exibição que contém um [CTreeCtrl](../mfc/reference/ctreectrl-class.md) objeto para exibições que são semelhantes a janela Gerenciador de soluções no Visual C++.|  
|[CScrollView](../mfc/reference/cscrollview-class.md)|Classe de base `CFormView`, `CRecordView`, e `CDaoRecordView`. Implementa rolar o conteúdo da exibição.|  
|[CFormView](../mfc/reference/cformview-class.md)|Uma exibição de formulário, uma exibição que contém os controles. Um aplicativo baseado em formulários fornece um ou mais essas interfaces de formulário.|  
|[CHtmlView](../mfc/reference/chtmlview-class.md)|Uma exibição de navegador da Web com o qual usuário o aplicativo do pode procurar os sites na World Wide Web, bem como pastas no sistema de arquivos local e em uma rede. O modo de exibição do navegador da Web também pode funcionar como um contêiner de documento ativo.|  
|[CRecordView](../mfc/reference/crecordview-class.md)|Um modo de exibição de formulário que exibe os registros do banco de dados ODBC em controles. Se você selecionar o suporte a ODBC em seu projeto, a classe base da exibição é `CRecordView`. O modo de exibição está conectado a um `CRowset` objeto.|  
|[CDaoRecordView](../mfc/reference/cdaorecordview-class.md)|Um modo de exibição de formulário que exibe os registros do banco de dados DAO em controles. Se você selecionar suporte DAO em seu projeto, a classe base da exibição é `CDaoRecordView`. O modo de exibição está conectado a um `CDaoRecordset` objeto.|  
|[COleDBRecordView](../mfc/reference/coledbrecordview-class.md)|Um modo de exibição de formulário que exibe os registros de OLE DB em controles. Se você selecionar o suporte de OLE DB em seu projeto, a classe base da exibição é `COleDBRecordView`. O modo de exibição está conectado a um `CRowset` objeto.|  
  
> [!NOTE]
>  A partir de MFC versão 4.0, `CEditView` é derivado de `CCtrlView`.  
  
 Para usar essas classes em seu aplicativo, gerar classes de exibição do aplicativo a partir deles. Para obter informações relacionadas, consulte [rolagem e exibições de dimensionamento](../mfc/scrolling-and-scaling-views.md). Para obter mais informações sobre as classes de banco de dados, consulte [visão geral: programação do banco de dados](../data/data-access-programming-mfc-atl.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando exibições](../mfc/using-views.md)

