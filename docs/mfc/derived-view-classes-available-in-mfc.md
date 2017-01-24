---
title: "Classes de exibi&#231;&#227;o derivadas dispon&#237;veis no MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes [C++], derivado"
  - "Classe CView, classes derivadas de"
  - "classes derivadas, classes de exibição"
  - "classes de exibição, derivado"
ms.assetid: dba42178-7459-4ccc-b025-f3d9b8a4b737
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de exibi&#231;&#227;o derivadas dispon&#237;veis no MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes de exibição de MFC seguir mostra a tabela e suas relações com outras um.  Os recursos da sua classe da exibição depende da classe da exibição de MFC que se deriva.  
  
### Classes de exibição  
  
|Classe|Descrição|  
|------------|---------------|  
|[CView](../Topic/CView%20Class.md)|Classe base de todas as exibições.|  
|[CCtrlView](../mfc/reference/cctrlview-class.md)|Classe base de `CTreeView`, de `CListView`, de `CEditView`, e de `CRichEditView`.  Essas classes permitem o uso da arquitetura do documento\/exibição com os controles \(indicados do windows.|  
|[CEditView](../Topic/CEditView%20Class.md)|Uma exibição simples com base no controle da caixa de edição do windows.  Permite inserir e editar textos e pode ser usado como base para um aplicativo do editor de texto simples.  Consulte também `CRichEditView`.|  
|[CRichEditView](../mfc/reference/cricheditview-class.md)|Uma exibição que contém um objeto de [CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md) .  Esta classe é análoga a `CEditView`, mas em vez de `CEditView`, texto formatado das alças de `CRichEditView` .|  
|[CListView](../mfc/reference/clistview-class.md)|Uma exibição que contém um objeto de [CListCtrl](../Topic/CListCtrl%20Class.md) .|  
|[CTreeView](../mfc/reference/ctreeview-class.md)|Uma exibição que contém um objeto de [CTreeCtrl](../mfc/reference/ctreectrl-class.md) , para as exibições semelhantes à janela de Solution Explorer no Visual C\+\+.|  
|[CScrollView](../mfc/reference/cscrollview-class.md)|Classe base de `CFormView`, de `CRecordView`, e de `CDaoRecordView`.  Vá que implementa o conteúdo da exibição.|  
|[CFormView](../mfc/reference/cformview-class.md)|Uma exibição de formulário, uma exibição que contém os controles.  Um aplicativo de autenticação baseado fornece um ou mais dessas interfaces de formulário.|  
|[CHtmlView](../mfc/reference/chtmlview-class.md)|Uma exibição de navegador da Web com que o usuário do aplicativo pode procurar sites na World Wide Web, bem como pastas no sistema de arquivos local e em uma rede.  A exibição de navegador da Web também pode funcionar como um contêiner ativa do documento.|  
|[CRecordView](../mfc/reference/crecordview-class.md)|Uma exibição de formulário que exibe registros de base de dados de ODBC em controles.  Se você selecionar o suporte de ODBC em seu projeto, a classe base da exibição é `CRecordView`.  A exibição está conectada a um objeto de `CRowset` .|  
|[CDaoRecordView](../mfc/reference/cdaorecordview-class.md)|Uma exibição de formulário que exibe registros de base de dados de DAO em controles.  Se você selecionar o suporte de DAO em seu projeto, a classe base da exibição é `CDaoRecordView`.  A exibição está conectada a um objeto de `CDaoRecordset` .|  
|[COleDBRecordView](../mfc/reference/coledbrecordview-class.md)|Uma exibição de formulário que exibe registros de OLE DB em controles.  Se você selecionar o suporte do OLE DB em seu projeto, a classe base da exibição é `COleDBRecordView`.  A exibição está conectada a um objeto de `CRowset` .|  
  
> [!NOTE]
>  A partir da versão 4,0, `CEditView` MFC é derivado de `CCtrlView`.  
  
 Para usar essas classes em seu aplicativo, derivar as classes de exibição do aplicativo deless.  Para obter informações relacionadas, consulte [Exibições de rolagem e de escala secundária](../mfc/scrolling-and-scaling-views.md).  Para obter mais informações sobre classes base de dados do, consulte [Visão geral: Programação do base de dados](../data/data-access-programming-mfc-atl.md).  
  
## Consulte também  
 [Usando exibições](../mfc/using-views.md)